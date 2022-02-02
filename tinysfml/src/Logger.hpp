#ifndef LOGGER_HPP
#define LOGGER_HPP
#include <memory>
#include <spdlog/spdlog.h>

namespace tinySFML{
    class Logger{
        public:
        static void Init();
        inline static std::shared_ptr<spdlog::logger> getLogger() {return s_Logger;}
        private:
        static std::shared_ptr<spdlog::logger> s_Logger;

    };
}

#define TINYSFML_FATAL(...) ::tinySFML::Logger::getLogger()->critical(__VA_ARGS__)
#define TINYSFML_ERROR(...) ::tinySFML::Logger::getLogger()->error(__VA_ARGS__)
#define TINYSFML_WARN(...) ::tinySFML::Logger::getLogger()->warn(__VA_ARGS__)
#define TINYSFML_INFO(...) ::tinySFML::Logger::getLogger()->info(__VA_ARGS__)
#define TINYSFML_TRACE(...) ::tinySFML::Logger::getLogger()->trace(__VA_ARGS__)

#endif



