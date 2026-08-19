#include <iostream>
#include <system_error>

#include <core/Config.hpp>
#include <core/File.hpp>
#include <core/Logger.hpp>

void testFile();
void testConfig();
void testLogger();

int main()
{
    testFile();
    testConfig();
    testLogger();

    return 0;
}

void testFile()
{
    if (core::exists("test.txt"))
    {
        std::cout << "O arquivo existe." << std::endl;
    }
    else
    {
        std::cout << "O arquivo não existe." << std::endl;
    }

    if (core::isFile("test.txt"))
    {
        std::cout << "O arquivo é um arquivo regular." << std::endl;
    }
    else
    {
        std::cout << "O arquivo não é um arquivo regular." << std::endl;
    }

    if (core::isDirectory("test_directory"))
    {
        std::cout << "O arquivo é um diretório." << std::endl;
    }
    else
    {
        std::cout << "O arquivo não é um diretório." << std::endl;
    }

    if (core::createFile("test.txt"))
    {
        std::cout << "Arquivo criado com sucesso." << std::endl;
    }
    else
    {
        std::cout << "Falha ao criar o arquivo." << std::endl;
    }

    if (core::createDirectory("test_directory"))
    {
        std::cout << "Diretorio criado com sucesso." << std::endl;
    }
    else
    {
        std::cout << "Falha ao criar o diretorio." << std::endl;
    }

    if (core::createFile("test_directory/arquivo.txt"))
    {
        std::cout << "Arquivo criado com sucesso dentro do diretorio." << std::endl;
    }
    else
    {
        std::cout << "Falha ao criar o arquivo dentro do diretorio." << std::endl;
    }

    if (core::removeFile("test_directory/arquivo.txt"))
    {
        std::cout << "Arquivo removido com sucesso." << std::endl;
    }
    else
    {
        std::cout << "Falha ao remover o arquivo." << std::endl;
    }

    if (core::removeDirectory("test_directory"))
    {
        std::cout << "Diretorio removido com sucesso." << std::endl;
    }
    else
    {
        std::cout << "Falha ao remover o diretorio." << std::endl;
    }
}

void testConfig()
{
    core::Config config;

    std::cout << "\n--- Config ---" << std::endl;

    config.set("name", "CoreLib");

    if (config.has("name"))
    {
        std::cout << "Chave 'name' encontrada." << std::endl;
    }
    else
    {
        std::cout << "Chave 'name' não encontrada." << std::endl;
    }

    auto name = config.get("name");

    if (name)
    {
        std::cout << "name: " << *name << std::endl;
    }
    else
    {
        std::cout << "Chave 'name' não encontrada." << std::endl;
    }

    auto missing = config.get("missing");

    if (!missing)
    {
        std::cout << "Chave 'missing' não encontrada." << std::endl;
    }

    std::error_code error;

    if (config.load("config.txt", error))
    {
        std::cout << "Configuração carregada com sucesso." << std::endl;
    }
    else
    {
        std::cout << "Falha ao carregar configuração: "
            << error.message() << std::endl;
    }

    auto author = config.get("author");

    if (author)
    {
        std::cout << "author: " << *author << std::endl;
    }

    auto version = config.get("version");

    if (version)
    {
        std::cout << "version: " << *version << std::endl;
    }

    error.clear();

    if (config.save("config_saved.txt", error))
    {
        std::cout << "Configuração salva com sucesso." << std::endl;
    }
    else
    {
        std::cout << "Falha ao salvar configuração: "
            << error.message() << std::endl;
    }

    error.clear();

    if (!config.load("arquivo_inexistente.txt", error))
    {
        std::cout << "Erro esperado: "
            << error.message() << std::endl;
    }
}

void testLogger()
{
    core::Logger::setLevel(core::LogLevel::Error);

    core::Logger::debug("Mensagem de depuracao");
    core::Logger::info("CoreLib iniciada");
    core::Logger::warning("Isso e um aviso");
    core::Logger::error("Isso e um erro");
}