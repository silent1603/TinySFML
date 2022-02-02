#ifndef WINDOW_HPP
#define WINDOW_HPP
#include "Core.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window/ContextSettings.hpp>
#include <SFML/System/Vector2.hpp>
namespace tinySFML
{
    class Window
    {
    public:
        Window() = delete;
        Window(const std::string &title, int w, int h, bool vsync = false, int framelimit = 60, uint32_t style = sf::Style::Default, const sf::ContextSettings &settings = sf::ContextSettings());
        Window(const std::string &title, int w, int h, int x, int y, bool vsync = false, int framelimit = 60, uint32_t style = sf::Style::Default, const sf::ContextSettings &settings = sf::ContextSettings());
        virtual ~Window();
        void init();
        void render();
        void quit();
        inline void color(sf::Color c) { m_colorBg = c; }
        inline void vsync(bool value) { m_vsync = value; }
        inline void frame_limit(int value) { m_frameLimit = value; }
        inline sf::Window &window() { return m_window; }
        inline sf::Vector2i position() { return m_pos; }
        inline sf::Vector2u size() { return m_size; }

    private:
        sf::Window m_window;
        sf::Color m_colorBg = sf::Color::Black;
        std::string m_title = "app";
        uint32_t m_style = sf::Style::Default ;
        sf::ContextSettings m_contextSettings;
        int m_frameLimit{60};
        sf::Vector2u m_size{0,0};
        sf::Vector2i m_pos{static_cast<int>(sf::VideoMode::getDesktopMode().width / 2-m_size.x/2), static_cast<int>(sf::VideoMode::getDesktopMode().height / 2-m_size.y/2)};
        bool m_focus, m_vsync{false};
    };
}
#endif