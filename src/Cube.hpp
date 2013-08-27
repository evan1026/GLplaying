#ifndef CUBE_HPP
#define CUBE_HPP

class Cube{
    sf::Vector3f _position;
    sf::Vector3f _rotation;

    public:
        static const float model[6][12];
        static const float color[6][3];

        Cube(sf::Vector3f position, sf::Vector3f rotation) : 
            _position(position),_rotation(rotation) {}

        sf::Vector3f getPosition();
        void setPosition(sf::Vector3f position);
        sf::Vector3f getRotation();
        void setRotation(sf::Vector3f rotation);
        
};

#endif