#pragma once
#include <string>
#include <map>
#include <optional>
#include <system_error>
#include <string_view>
#include <functional>

namespace core
{
    class Config
    {
    public:
        void set(std::string_view name, std::string_view value);
        std::optional<std::string> get(std::string_view name) const;
        bool has(std::string_view name) const;
        bool load(const std::string& path, std::error_code& error);
        bool save(const std::string& path, std::error_code& error) const;

    private:
        std::map<std::string, std::string, std::less<>> configMap;
    };

    std::string trim(const std::string& text);
}