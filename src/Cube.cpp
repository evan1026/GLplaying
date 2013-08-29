#include <SFML/System.hpp>
#include "Cube.hpp"

sf::Vector3f& Cube::getPosition(){
    return _position;
}
void Cube::setPosition(const sf::Vector3f& position){
    _position = position;
}
sf::Vector3f& Cube::getRotation(){
    return _rotation;
}
void Cube::setRotation(const sf::Vector3f& rotation){
    _rotation = rotation;
}

const float Cube::model[6][12] = {{-50.f, -50.f, -50.f,
                                   -50.f,  50.f, -50.f,
                                    50.f,  50.f, -50.f,
                                    50.f, -50.f, -50.f},
                                  {-50.f, -50.f,  50.f,
                                   -50.f,  50.f,  50.f,
                                    50.f,  50.f,  50.f,
                                    50.f, -50.f,  50.f},
                                  {-50.f, -50.f, -50.f,
                                   -50.f,  50.f, -50.f,
                                   -50.f,  50.f,  50.f,
                                   -50.f, -50.f,  50.f},
                                  { 50.f, -50.f, -50.f,
                                    50.f,  50.f, -50.f,
                                    50.f,  50.f,  50.f,
                                    50.f, -50.f,  50.f},
                                  {-50.f, -50.f,  50.f,
                                   -50.f, -50.f, -50.f,
                                    50.f, -50.f, -50.f,
                                    50.f, -50.f,  50.f},
                                  {-50.f,  50.f,  50.f,
                                   -50.f,  50.f, -50.f,
                                    50.f,  50.f, -50.f,
                                    50.f,  50.f,  50.f}};

const float Cube::color[6][3] = {{1.f, 0.f, 0.f},
                                 {1.f, 1.f, 0.f},
                                 {0.f, 1.f, 0.f},
                                 {0.f, 1.f, 1.f},
                                 {0.f, 0.f, 1.f},
                                 {1.f, 0.f, 1.f}};
