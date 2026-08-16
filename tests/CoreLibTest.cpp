#include <iostream>
#include <core/Logger.hpp>
#include <core/File.hpp>

void testFile();
void testLogger();

int main()
{   
	testFile();

	testLogger();

    return 0;
}

void testFile() {
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

void testLogger() {
	core::Logger::setLevel(core::LogLevel::Error);

	core::Logger::debug("Mensagem de depuracao");
	core::Logger::info("CoreLib iniciada");
	core::Logger::warning("Isso e um aviso");
	core::Logger::error("Isso e um erro");
}