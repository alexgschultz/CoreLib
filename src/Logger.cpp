#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string_view>
#include <core/Logger.hpp>

namespace core
{   
    LogLevel Logger::minimumLevel = LogLevel::Info;

    void Logger::setLevel(LogLevel level)
    {
        minimumLevel = level;
    }

    void Logger::log(LogLevel level, std::string_view message)
    {   
        if (level < minimumLevel)
        {
            return;
        }
        
        const auto now = std::chrono::system_clock::now();
        const std::time_t time = std::chrono::system_clock::to_time_t(now);
        std::tm localTime{};
#ifdef _WIN32
        localtime_s(&localTime, &time);
#else
        localtime_r(&time, &localTime);
#endif

        std::cout << '[' << std::put_time(&localTime, "%Y-%m-%d %H:%M:%S") << "] ";

        switch (level)
        {
        case LogLevel::Debug:
            std::cout << "[DEBUG] ";
            break;
        case LogLevel::Info:
            std::cout << "[INFO] ";
            break;
        case LogLevel::Warning:
            std::cout << "[WARNING] ";
            break;
        case LogLevel::Error:
            std::cout << "[ERROR] ";
            break;

        default:
            break;

        }

        std::cout << message << '\n';
    }

    void Logger::debug(std::string_view message)
    {
        log(LogLevel::Debug, message);
    }

    void Logger::info(std::string_view message)
    {
        log(LogLevel::Info, message);
    }

    void Logger::warning(std::string_view message)
    {
        log(LogLevel::Warning, message);
    }

    void Logger::error(std::string_view message)
    {
        log(LogLevel::Error, message);
    }
}