#include "Window.hpp"
#include <SFML/Window.hpp>
namespace tinySFML
{
    Window::Window(const std::string &title, int w, int h, bool vsync, int framelimit, uint32_t style, const sf::ContextSettings &settings)
        : m_title(title), m_size(w, h), m_vsync(vsync), m_frameLimit(framelimit), m_style(style), m_contextSettings(settings)
    {
    }

    Window::Window(const std::string &title, int w, int h, int x, int y, bool vsync, int framelimit, uint32_t style, const sf::ContextSettings &settings)
        : m_title(title), m_size(w, h), m_pos(x, y), m_vsync(vsync), m_frameLimit(framelimit), m_style(style), m_contextSettings(settings)
    {
        
    }

    Window::~Window()
    {
        quit();
    }

    void Window::init()
    {
        m_window.create(sf::VideoMode(m_size.x, m_size.y), m_title);
        m_window.setPosition(m_pos);
        m_window.setSize(m_size);
        m_window.setFramerateLimit(m_frameLimit);
        m_window.setVerticalSyncEnabled(m_vsync);
        m_focus = m_window.hasFocus();
    }

    void Window::render()
    {
        m_window.display();
    }

    void Window::quit()
    {
        m_window.close();
    }
}