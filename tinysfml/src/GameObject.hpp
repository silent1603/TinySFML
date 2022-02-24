#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP
#include "Core.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
namespace tinySFML
{
    
    class GameObject
    {
    public:
        GameObject();
        ~GameObject();
        virtual void pos(sf::Vector2i pos)  ;
        virtual void size(sf::Vector2u size) ;
        virtual void color(sf::Color c) ;
        virtual void move(sf::Vector2i m_pos);

    private:
        sf::Vector2i m_pos;
        sf::Vector2u m_size;
        bool m_visible;
        sf::Color m_color{sf::Color::Black};
    };


}
#endif