#include "App.hpp"
#include <filesystem>
namespace tinySFML
{
    App::App()
    {
    }

    App::~App()
    {
        quit();
    }


    void App::init()
    {
        tinySFML::Logger::Init();
        TINYSFML_INFO(std::filesystem::current_path().string());
        data = tinySFML::SceneIO::Load("./resources/data/data.dat");
        int w = data["Window"]["width"].get<int>();
        int h = data["Window"]["height"].get<int>();
        std::string title = data["Window"]["title"].get<std::string>();
        m_windowhander =  std::make_unique<tinySFML::Window>(title,w,h);
        m_windowhander->init();
    }

    void App::loop()
    {
        sf::Window& window = m_windowhander->window();
        while(window.isOpen())
        {

            m_event.process(window);
            
            window.display();  
        }
    }

    void App::quit()
    {
    }
}
