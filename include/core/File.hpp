#pragma once
#include <filesystem>

namespace core
{   
    bool exists(const std::filesystem::path& path);
    bool isFile(const std::filesystem::path& path);
    bool isDirectory(const std::filesystem::path& path);
    bool createFile(const std::filesystem::path& path);
    bool createDirectory(const std::filesystem::path& path);
    bool removeFile(const std::filesystem::path& path);
    bool removeDirectory(const std::filesystem::path& path);
}