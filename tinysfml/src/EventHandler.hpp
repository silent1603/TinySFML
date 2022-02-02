#ifndef EVENTHANDER_HPP
#define EVENTHANDER_HPP
#include "Core.hpp"
#include "SFML/Graphics.hpp"
namespace tinySFML
{
    class EventHandler
    {
    public:
        void process(sf::Window& w);

    private:
        sf::Event m_event;
        
    };
} // namespace tinySFML

#endif