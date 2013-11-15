#include <iostream>
#include <sstream>
#include <Logger/Logger.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/System.hpp>
#include <cmath>
#include "Cube.hpp"
#include "main.hpp"

#define PI    3.14159265
#define SPEED 10

using namespace std;

int main(){
    
    logger.logNoEndl("Initializing window...");
    sf::ContextSettings settings;
    settings.depthBits = 24;
    sf::Window window(sf::VideoMode(800, 600), "GL", sf::Style::Default, settings);
    window.setVerticalSyncEnabled(true);
    logger.continueln("done!");
    
    logger.logNoEndl("Handling mouse...");
    screenMiddle = sf::Vector2i(window.getSize().x / 2, window.getSize().y / 2);
    sf::Mouse::setPosition(screenMiddle, window);
    window.setMouseCursorVisible(false);
    logger.continueln("done!");
 
    logger.logNoEndl("Setting up GL...");
    glClearDepth(1.f);
    glClearColor(0.f, 0.f, 0.f, 0.f);
   
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.f, 1.f, 1.f, 5000.f);
    logger.continueln("done!");

    logger.logNoEndl("Initializing cubes...");
    cubes.push_back(Cube(sf::Vector3f(0.f, 0.f, 0.f), sf::Vector3f(0.f, 0.f, 0.f)));
    cubes.push_back(Cube(sf::Vector3f(50.f, 50.f, 50.f), sf::Vector3f(20.f, 40.f, 60.f)));
    logger.continueln("done!");    

    logger.logNoEndl("Looping until told to stop...");
    bool running = true;
    while (running){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                running = false;
            }
            else if (event.type == sf::Event::Resized){
                glViewport(0, 0, event.size.width, event.size.height);
                screenMiddle = sf::Vector2i(window.getSize().x / 2, window.getSize().y / 2);
            }
            else if (event.type == sf::Event::LostFocus){
                focused = false;
            }
            else if (event.type == sf::Event::GainedFocus){
                focused = true;
                sf::Mouse::setPosition(screenMiddle, window);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            running = false;
        }
        if (focused){
            doTranslations(window);

            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            draw();
        }

        window.display();
    }
    logger.continueln("done!");
    logger.log("Exitting...goodbye!");
}

string intToString(int a){
    stringstream ss;
    ss << a;
    return ss.str();
}
string floatToString(float a){
    stringstream ss;
    ss << a;
    return ss.str();
}

void draw(){
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(cameraRot.x, 1.f, 0.f, 0.f);
    glRotatef(cameraRot.y, 0.f, 1.f, 0.f);
    glRotatef(cameraRot.z, 0.f, 0.f, 1.f);
    glTranslatef(cameraPos.x, cameraPos.y, cameraPos.z);

    for (int i = 0; i < cubes.size(); i++){
        glPushMatrix();

        glRotatef(cubes[i].getRotation().x, 1.f, 0.f, 0.f);
        glRotatef(cubes[i].getRotation().y, 0.f, 1.f, 0.f);
        glRotatef(cubes[i].getRotation().z, 0.f, 0.f, 1.f);        
        glTranslatef(cubes[i].getPosition().x,
                     cubes[i].getPosition().y,
                     cubes[i].getPosition().z);

        glBegin(GL_QUADS);
        
        for (int j = 0; j < 6; j++){
            glColor3f(Cube::color[j][0], Cube::color[j][1], Cube::color[j][2]);
            
            for (int k = 0; k < 12; k += 3){
                glVertex3f(Cube::model[j][k], Cube::model[j][k + 1], Cube::model[j][k + 2]);
            }   
        }
        glEnd();
        glPopMatrix();

    }
}

void doTranslations(sf::Window & window){
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2i diff = mousePos - screenMiddle;

    cameraRot += sf::Vector3f(diff.y, diff.x, 0.f);
    if (cameraRot.x > 90) cameraRot.x = 90;
    else if (cameraRot.x < -90) cameraRot.x = -90;
    
    sf::Mouse::setPosition(screenMiddle, window);

    bool left = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
    bool right = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
    bool up = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
    bool down = sf::Keyboard::isKeyPressed(sf::Keyboard::LShift);
    bool forward = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
    bool backward = sf::Keyboard::isKeyPressed(sf::Keyboard::S);

    cameraPos.y += (up) ? -SPEED : (down) ? SPEED : 0;
    if (forward){
        cameraPos.x += -SPEED * sinDeg(cameraRot.y);
        cameraPos.z += SPEED * cosDeg(cameraRot.y);
    }
    else if (backward){
        cameraPos.x -= -SPEED * sinDeg(cameraRot.y);
        cameraPos.z -= SPEED * cosDeg(cameraRot.y);
    }
    if (left){
        cameraPos.x += -SPEED * sinDeg(cameraRot.y - 90);
        cameraPos.z += SPEED * cosDeg(cameraRot.y - 90);
    }
    else if (right){
        cameraPos.x += -SPEED * sinDeg(cameraRot.y + 90);
        cameraPos.z += SPEED * cosDeg(cameraRot.y + 90);
    }
}

float sinDeg(float a){
    return sin(a * PI / 180.f);
}
float cosDeg(float a){
    return cos(a * PI / 180.f);
}
