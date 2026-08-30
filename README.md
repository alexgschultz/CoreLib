**# CoreLib**



**\*\*Version 1.0\*\***



**Biblioteca C++ reutilizável desenvolvida como parte de um projeto de estudos e portfólio.**



**O objetivo do CoreLib é fornecer funcionalidades básicas e reutilizáveis para outros projetos em C++, mantendo uma arquitetura simples e evitando complexidade desnecessária.**



**## Funcionalidades**



**### Logger**



**Sistema simples de logging com diferentes níveis:**



**\* `Debug`**

**\* `Info`**

**\* `Warning`**

**\* `Error`**



**Permite definir um nível mínimo de log e inclui timestamp nas mensagens.**



**### File**



**Funcionalidades para trabalhar com arquivos e diretórios utilizando `std::filesystem`.**



**\* Verificar se um caminho existe**

**\* Verificar se é um arquivo**

**\* Verificar se é um diretório**

**\* Criar arquivos**

**\* Criar diretórios**

**\* Remover arquivos**

**\* Remover diretórios**



**### Config**



**Sistema simples de configuração baseado em arquivos no formato:**



**```text**

**key=value**

**```**



**Recursos:**



**\* Definir valores**

**\* Consultar valores**

**\* Verificar existência de chaves**

**\* Carregar configurações de arquivos**

**\* Salvar configurações em arquivos**

**\* Ignorar linhas vazias**

**\* Suporte a comentários iniciados por `#`**

**\* Remoção de espaços desnecessários**



**Exemplo:**



**```text**

**name=CoreLib**

**author=Alex**

**version=1.0**

**```**



**## Tecnologias**



**\* C++20/23**

**\* CMake**

**\* STL**

**\* `std::filesystem`**

**\* `std::map`**

**\* `std::optional`**

**\* `std::string\_view`**

**\* `std::error\_code`**

**\* Git**



**## Estrutura**



**```text**

**CoreLib/**

**├── CMakeLists.txt**

**├── include/**

**│   └── core/**

**│       ├── Config.hpp**

**│       ├── File.hpp**

**│       └── Logger.hpp**

**├── src/**

**│   ├── Config.cpp**

**│   ├── File.cpp**

**│   └── Logger.cpp**

**├── tests/**

**│   └── CoreLibTest.cpp**

**├── config.txt**

**└── .gitignore**

**```**



**## Compilação**



**O projeto utiliza CMake.**



**Na raiz do projeto:**



**```bash**

**cmake -B build**

**cmake --build build**

**```**



**No Windows, o executável de testes pode ser encontrado em:**



**```text**

**build/Debug/CoreLibTest.exe**

**```**



**Execute:**



**```powershell**

**.\\build\\Debug\\CoreLibTest.exe**

**```**



**## Testes**



**O projeto possui um programa de testes próprio para verificar as funcionalidades da biblioteca.**



**Os testes utilizam uma função auxiliar para comparar o resultado obtido com o resultado esperado:**



**```cpp**

**check(resultado, esperado, "Nome do teste");**

**```**



**Exemplo:**



**```cpp**

**check(config.has("missing"), false, "Config::has (chave inexistente)");**

**```**



**Uma execução bem-sucedida apresenta resultados como:**



**```text**

**--- File ---**

**\[PASS] File::exists**

**\[PASS] File::isFile**

**\[PASS] File::isDirectory**

**...**



**--- Config ---**

**\[PASS] Config::set**

**\[PASS] Config::get**

**\[PASS] Config::load**

**\[PASS] Config::save**

**```**



**## Objetivo do projeto**



**O CoreLib foi desenvolvido para praticar e consolidar conhecimentos de desenvolvimento em C++, incluindo:**



**\* organização de bibliotecas**

**\* separação entre `.hpp` e `.cpp`**

**\* CMake**

**\* STL**

**\* manipulação de arquivos**

**\* tratamento de erros**

**\* testes**

**\* organização de código**

**\* reutilização de componentes**



**A biblioteca continuará evoluindo conforme necessidades reais surgirem em projetos futuros.**



