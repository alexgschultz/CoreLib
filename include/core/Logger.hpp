#pragma once
#include <string_view>

namespace core
{   
    enum class LogLevel
    {   
        Debug,
        Info,
        Warning,
        Error
    };

    class Logger
    {
    public:
        static void debug(std::string_view message);
        static void info(std::string_view message);
        static void warning(std::string_view message);
        static void error(std::string_view message);

        static void setLevel(LogLevel level);

    private:
        static LogLevel minimumLevel;
        static void log(LogLevel level, std::string_view message);
    };
}