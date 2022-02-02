#ifndef SCENEIO_HPP
#define SCENEIO_HPP
#include "Core.hpp"
#include <memory>
#include <nlohmann/json.hpp>
#include <functional>
#include <fstream>
namespace tinySFML
{
    class SceneIO
    {
    public:
        static void Save(const nlohmann::json& data,const std::string& path);
        static nlohmann::json Load(const std::string& file);
    private:
        static void LoadWindow( nlohmann::json& j, std::fstream& s);
        static void LoadCircle( nlohmann::json& j, std::fstream& s);
        static void LoadRect( nlohmann::json& j, std::fstream& s);
        static void LoadFont(nlohmann::json& j, std::fstream& s);
        static std::function<void( nlohmann::json&, std::fstream&)> m_fptr;
    };

}

#endif