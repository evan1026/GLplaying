#ifndef MAIN_HPP
#define MAIN_HPP

Logger logger;
sf::Vector3f cameraPos = sf::Vector3f(0.f, 0.f, -200.f);
sf::Vector3f cameraRot = sf::Vector3f(0.f, 0.f, 0.f);
sf::Vector2i screenMiddle;
std::vector<Cube> cubes;
bool focused = true;

std::string intToString(int a);
std::string floatToString(float a);
void draw();
void doTranslations(sf::Window & window);
float sinDeg(float a);
float cosDeg(float a);

#endif
