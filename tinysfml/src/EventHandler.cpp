#include "EventHandler.hpp"

namespace tinySFML
{
   void EventHandler::process(sf::Window &w)
   {
      while (w.pollEvent(m_event))
      {
         switch (m_event.type)
         {
         case sf::Event::Closed:
            w.close();
            break;
         case sf::Event::KeyPressed:
            switch (m_event.key.code)
            {
            case sf::Keyboard::Escape:
               w.close();
               break;

            default:
               break;
            }
            break;
         case sf::Event::Resized:
            TINYSFML_INFO("New Size: ",m_event.size.width,m_event.size.height );
            break;
         case sf::Event::LostFocus:
            TINYSFML_INFO("Lost Focus");
            break;
         case sf::Event::GainedFocus:
            TINYSFML_INFO("Gained Focus");
            break;
         default:
            break;
         }
      }
   }
}