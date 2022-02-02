#ifndef APP_HPP
#define APP_HPP
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>
#include "Core.hpp"
#include "EventHandler.hpp"
#include "SceneIO.hpp"
#include "Window.hpp"
namespace tinySFML{
    class App{
        public:
        App();
        ~App();
        void init();
        void loop();
        void quit();
        private:
        std::unique_ptr<tinySFML::Window> m_windowhander;
        tinySFML::EventHandler m_event;
        nlohmann::json data;
    };
}
#endif