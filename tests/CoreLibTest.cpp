#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif
#include <string>
#include <filesystem>
#include <system_error>

#include <core/Config.hpp>
#include <core/File.hpp>
#include <core/Logger.hpp>

void check(bool result, bool expected, const std::string& testName);

void testFile();
void testConfig();
void testLogger();

void testFileExists();
void testFileIsFile();
void testFileIsDirectory();
void testFileCreate();
void testFileCreateDirectory();
void testFileRemove();

void testConfigSet();
void testConfigGet();
void testConfigHas();
void testConfigLoad();
void testConfigSave();

int failedTests = 0;

int main()
{   
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    testFile();
    testConfig();
    testLogger();

    return (failedTests == 0) ? 0 : 1;
}

void check(bool result, bool expected, const std::string& testName)
{
    if (result == expected)
    {
        std::cout << "[PASS] " << testName << std::endl;
    }
    else
    {   
        ++failedTests;
        std::cout << "[FAIL] " << testName << std::endl;
    }
}

void testFile()
{
    std::cout << "\n--- File ---" << std::endl;

    std::error_code error;
    std::filesystem::remove("test.txt", error);
    std::filesystem::remove_all("test_directory", error);

    testFileCreate();
    testFileExists();
    testFileIsFile();
    testFileIsDirectory();
    testFileCreateDirectory();
    testFileRemove();
}

void testFileExists()
{
    check(
        core::exists("test.txt"), true, "File::exists");
}

void testFileIsFile()
{
    check(
        core::isFile("test.txt"), true, "File::isFile");
}

void testFileIsDirectory()
{
    check(
        core::isDirectory("test.txt"), false, "File::isDirectory");
}

void testFileCreate()
{
    check(core::createFile("test.txt"), true, "File::createFile");
    check(core::createFile("test.txt"), false, "File::createFile (arquivo existente)");
}

void testFileCreateDirectory()
{
    check(core::createDirectory("test_directory"), true, "File::createDirectory");
    check(core::createFile("test_directory/arquivo.txt"), true, "File::createFile (dentro do diretório)");
}

void testFileRemove()
{
    check(core::removeFile("test_directory/arquivo.txt"), true, "File::removeFile");
    check(core::removeDirectory("test_directory"), true, "File::removeDirectory");
    check(core::removeFile("test.txt"), true, "File::removeFile (arquivo principal)");
}

void testConfig()
{
    std::cout << "\n--- Config ---" << std::endl;

    testConfigSet();
    testConfigGet();
    testConfigHas();
    testConfigLoad();
    testConfigSave();
}

void testConfigSet()
{
    core::Config config;

    config.set("name", "CoreLib");

    auto name = config.get("name");

    check(name && *name == "CoreLib", true, "Config::set");
}

void testConfigGet()
{
    core::Config config;

    config.set("name", "CoreLib");

    auto name = config.get("name");

    check(name && *name == "CoreLib", true, "Config::get");

    auto missing = config.get("missing");

    check(!missing, true, "Config::get (chave inexistente)");
}

void testConfigHas()
{
    core::Config config;

    config.set("name", "CoreLib");

    check(config.has("name"), true, "Config::has");
    check(config.has("missing"), false, "Config::has (chave inexistente)");
}

void testConfigLoad()
{
    core::Config config;
    std::error_code error;

    bool loaded = config.load("config.txt", error);

    check(loaded, true, "Config::load");

    auto name = config.get("name");
    auto author = config.get("author");
    auto version = config.get("version");

    check(name && *name == "CoreLib", true, "Config::load (name)");
    check(author && *author == "Alex", true, "Config::load (author)");
    check(version && *version == "1.0", true, "Config::load (version)");

    error.clear();

    bool missingFile = config.load("arquivo_inexistente.txt", error);

    check(missingFile, false, "Config::load (arquivo inexistente)");
}

void testConfigSave()
{
    core::Config config;
    std::error_code error;

    config.set("name", "CoreLib");
    config.set("author", "Alex");
    config.set("version", "1.0");

    bool saved = config.save("config_saved.txt", error);

    check(saved, true, "Config::save");
}

void testLogger()
{
    std::cout << "\n--- Logger ---" << std::endl;

    core::Logger::setLevel(core::LogLevel::Error);

    core::Logger::debug("Mensagem de depuração");
    core::Logger::info("CoreLib iniciada");
    core::Logger::warning("Isso é um aviso");
    core::Logger::error("Isso é um erro");
}