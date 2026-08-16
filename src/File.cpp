#include <fstream>
#include <system_error>
#include <core/File.hpp>

namespace core
{   
    bool exists(const std::filesystem::path& path)
    {
        return std::filesystem::exists(path);
    }

    bool isFile(const std::filesystem::path& path)
    {
        return std::filesystem::is_regular_file(path);
    }

    bool isDirectory(const std::filesystem::path& path)
    {
        return std::filesystem::is_directory(path);
    }

    bool createFile(const std::filesystem::path& path)
    {
        if (core::exists(path)) return false;
        std::ofstream file(path);
        if (!file) return false;
        return true;
    }

    bool createDirectory(const std::filesystem::path& path)
    {
        if (core::exists(path)) return false;
        return std::filesystem::create_directory(path);
    }

    bool removeFile(const std::filesystem::path& path)
    {
        if (!core::exists(path) || !core::isFile(path)) return false;
        return std::filesystem::remove(path);
    }

    bool removeDirectory(const std::filesystem::path& path)
    {
        if (!core::exists(path) || !core::isDirectory(path)) return false;
        std::error_code error;
        return std::filesystem::remove(path, error);
    }
}