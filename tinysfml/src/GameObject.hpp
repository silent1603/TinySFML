#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP
#include "Core.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
namespace tinySFML
{
    template <typename T>
    class GameObject
    {
    public:
        GameObject();
        virtual void pos(sf::Vector2i pos);
        virtual void size(sf::Vector2u size);
        virtual void color(sf::Color c);
        virtual void color(uint8_t r, uint8_t g, uint8_t b);
        virtual void move(int sx, int sy);
        ~GameObject();

    private:
        T m_type;
        sf::Vector2i m_pos(0, 0);
        sf::Vector2u m_size(0, 0);
        bool m_visible;
        sf::Color m_color{sf::Color::Black};
    };

    template <>
    void GameObject<sf::CircleShape>::pos(sf::Vector2i pos)
    {
    }

    template <>
    void GameObject<sf::RectangleShape>::pos(sf::Vector2i pos)
    {
    }

    template <>
    void GameObject<sf::CircleShape>::color(sf::Color c)
    {
    }

    template <>
    void GameObject<sf::CircleShape>::color(uint8_t r, uint8_t g, uint8_t b)
    {
    }

    template <>
    void GameObject<sf::RectangleShape>::color(uint8_t r, uint8_t g, uint8_t b)
    {
    }

    template <>
    void GameObject<sf::RectangleShape>::color(sf::Color c)
    {
    }

    template <>
    void GameObject<sf::CircleShape>::move(int sx, int sy)
    {
    }

    template <>
    void GameObject<sf::RectangleShape>::move(int sx, int sy)
    {
    }

    template <>
    void GameObject<sf::CircleShape>::size(sf::Vector2u size)
    {
    }

    template <>
    void GameObject<sf::RectangleShape>::size(sf::Vector2u size)
    {
    }

}
#endif