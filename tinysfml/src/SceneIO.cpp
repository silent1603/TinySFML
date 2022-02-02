#include "SceneIO.hpp"
#include <filesystem>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <sstream>
namespace tinySFML
{
    std::function<void(nlohmann::json &, std::fstream &)> m_fptr = nullptr;

    nlohmann::json SceneIO::Load(const std::string &file)
    {
        nlohmann::json j;
        std::fstream data(file, std::iostream::in | std::iostream::binary);
        if (data.is_open())
        {
            TINYSFML_INFO("load data success at" + file);
            bool result = true;
            try
            {
                data >> j;
            }
            catch (...)
            {
                result = false;
            }
            if (result)
            {
                TINYSFML_INFO("IS OBJECT");
            }
            else
            {
                data.seekg(0);
                TINYSFML_ERROR("NOT OBJECT");
                std::string name;

                while (data >> name)
                {
                    TINYSFML_INFO("NAME :" + name);
                    if (name.compare("Window") == 0)
                    {
                        LoadWindow(j, data);
                    }
                    if (name.compare("Circle") == 0)
                    {
                        LoadCircle(j, data);
                    }
                    if (name.compare("Rectangle") == 0)
                    {
                        LoadRect(j, data);
                    }
                    if (name.compare("Font") == 0)
                    {
                        LoadFont(j, data);
                    }
                    name.clear();
                }
            }
        }
        else
        {
            TINYSFML_FATAL("data load fail at " + file);
        }
        return j;
    }

    void SceneIO::Save(const nlohmann::json &data, const std::string &path)
    {
        std::fstream file(path, std::ostream::out);
        file << std::setw(4) << data << std::endl;
    }

    void SceneIO::LoadWindow(nlohmann::json &j, std::fstream &file)
    {
        std::string title{""};
        int width{0}, height{0};
        file >> title >> width >> height;
        std::stringstream ss;
        ss << "Load window " << title << " " << width << " " << height;
        TINYSFML_INFO(ss.str());
        j["Window"]["title"] = title;
        j["Window"]["width"] = width;
        j["Window"]["height"] = height;
    }

    void SceneIO::LoadCircle(nlohmann::json &j, std::fstream &file)
    {

        std::string name{""};
        int x{0}, y{0};
        float sx{0}, sy{0};
        int r{0}, g{0}, b{0};
        int radius{0};
        file >> name >> x >> y >> sx >> sy >> r >> g >> b >> radius;
        std::stringstream ss;
        ss << "Load Circle " << name << " " << x << " " << y << " " << sx << " " << sy << " " << r << " " << g << " " << b << " " << radius;
        TINYSFML_INFO(ss.str());
        
        j[name.c_str()]["position"]["x"] = x;
        j[name.c_str()]["position"]["y"] = y;
        j[name.c_str()]["velocity"]["x"] = sx;
        j[name.c_str()]["velocity"]["y"] = sx;
        j[name.c_str()]["color"]["r"] = r;
        j[name.c_str()]["color"]["g"] = g;
        j[name.c_str()]["color"]["b"] = b;
        j[name.c_str()]["radius"] = radius;
    }

    void SceneIO::LoadRect(nlohmann::json &j, std::fstream &file)
    {

        std::string name{""};
        int x{0}, y{0};
        float sx{0}, sy{0};
        int r{0}, g{0}, b{0};
        int w{0}, h{0};
        file >> name >> x >> y >> sx >> sy >> r >> g >> b >> w >> h;
        std::stringstream ss;
        ss << "Load Rect " << name << " " << x << " " << y << " " << sx << " " << sy << " " << r << " " << g << " " << b << " " << w << " " << h;
        TINYSFML_INFO(ss.str());

        j[name.c_str()]["position"]["x"] = x;
        j[name.c_str()]["velocity"]["x"] = sx;
        j[name.c_str()]["velocity"]["y"] = sx;
        j[name.c_str()]["color"]["r"] = r;
        j[name.c_str()]["color"]["g"] = g;
        j[name.c_str()]["color"]["b"] = b;
        j[name.c_str()]["size"]["width"] = w;
        j[name.c_str()]["size"]["height"] = h;
    }

    void SceneIO::LoadFont(nlohmann::json &j, std::fstream &file)
    {

        std::string font{""};
        int s{0};
        int r{0}, g{0}, b{0};
        file >> font >> s >> r >> g >> b;
        std::stringstream ss;
        ss << "Load font: " << font << " " << s << " " << r << " " << g << " " << b;
        TINYSFML_INFO(ss.str());
        j["Font"]["name"] = font;
        j["Font"]["size"] = s;
        j["Font"]["color"]["r"] = r;
        j["Font"]["color"]["g"] = g;
        j["Font"]["color"]["b"] = b;
    }

}
