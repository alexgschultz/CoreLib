#include <core/Config.hpp>
#include <fstream>
#include <cctype>

namespace core
{   
    std::string trim(const std::string& text)
    {
        std::size_t start = 0;

        while (start < text.size() &&
            std::isspace(static_cast<unsigned char>(text[start])))
        {
            ++start;
        }

        std::size_t end = text.size();

        while (end > start &&
            std::isspace(static_cast<unsigned char>(text[end - 1])))
        {
            --end;
        }

        return text.substr(start, end - start);
    }

    void Config::set(std::string_view name, std::string_view value)
    {
        configMap[std::string(name)] = value;
    }

    std::optional<std::string> Config::get(std::string_view name) const
    {
        auto it = configMap.find(name);

        if (it != configMap.end())
        {
            return it->second;
        }

        return std::nullopt;
    }

    bool Config::has(std::string_view name) const
    {
        return configMap.find(name) != configMap.end();
    }

    bool Config::load(const std::string& path, std::error_code& error)
    {
        error.clear();

        std::ifstream file(path);

        if (!file)
        {
            error = std::make_error_code(std::errc::no_such_file_or_directory);

            return false;
        }

        std::string line;

        while (std::getline(file, line))
        {
            line = trim(line);

            if (line.empty() || line[0] == '#')
            {
                continue;
            }

            auto position = line.find('=');

            if (position != std::string::npos)
            {
                std::string key = line.substr(0, position);
                std::string value = line.substr(position + 1);

                key = trim(key);
                value = trim(value);

                set(key, value);
            }
        }

        return true;
    }

    bool Config::save(const std::string& path, std::error_code& error) const
    {
        error.clear();

        std::ofstream file(path);

        if (!file)
        {
            error = std::make_error_code(
                std::errc::io_error
            );

            return false;
        }

        for (const auto& [key, value] : configMap)
        {
            file << key << '=' << value << '\n';
        }

        if (!file)
        {
            error = std::make_error_code(std::errc::io_error);
            return false;
        }

        return true;
    }
}