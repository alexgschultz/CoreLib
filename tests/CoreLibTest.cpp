#include <core/Logger.hpp>

int main()
{
    core::Logger::setLevel(core::LogLevel::Error);

    core::Logger::debug("Mensagem de depuracao");
    core::Logger::info("CoreLib iniciada");
    core::Logger::warning("Isso e um aviso");
    core::Logger::error("Isso e um erro");

    return 0;
}