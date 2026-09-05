# CoreLib

**Versão 1.0**

[English](README.md)

CoreLib é uma biblioteca C++ reutilizável desenvolvida como projeto de estudos e portfólio.

Seu objetivo é fornecer funcionalidades simples e reutilizáveis para outros projetos em C++, mantendo uma arquitetura pequena e evitando complexidade desnecessária.

## Funcionalidades

### Logger

Sistema simples de logging com diferentes níveis:

- `Debug`
- `Info`
- `Warning`
- `Error`

Permite definir um nível mínimo de log e inclui timestamp nas mensagens.

### File

Funcionalidades para arquivos e diretórios utilizando `std::filesystem`.

- Verificar se um caminho existe
- Verificar se é um arquivo
- Verificar se é um diretório
- Criar arquivos
- Criar diretórios
- Remover arquivos
- Remover diretórios

### Config

Sistema simples de configuração utilizando arquivos no formato:

```text
key=value
```

Recursos:

- Definir valores
- Consultar valores
- Verificar existência de chaves
- Carregar arquivos de configuração
- Salvar arquivos de configuração
- Ignorar linhas vazias
- Suporte a comentários iniciados por `#`
- Remoção de espaços desnecessários

Exemplo:

```text
name=CoreLib
author=Alex
version=1.0
```

## Tecnologias

- C++20
- CMake
- CTest
- STL
- `std::filesystem`
- `std::map`
- `std::optional`
- `std::string_view`
- `std::error_code`
- Git

## Estrutura do Projeto

```text
CoreLib/
├── CMake/
├── include/
│   └── core/
│       ├── Config.hpp
│       ├── File.hpp
│       ├── Logger.hpp
│       └── core.hpp
├── src/
│   ├── Config.cpp
│   ├── File.cpp
│   ├── Logger.cpp
│   └── core.cpp
├── tests/
│   └── CoreLibTest.cpp
├── config.txt
├── CMakeLists.txt
└── .gitignore
```

## Compilação

O projeto utiliza CMake.

Configure o projeto:

```bash
cmake -S . -B build
```

Compile a configuração Debug:

```bash
cmake --build build --config Debug
```

## Testes

O CoreLib utiliza CTest para executar seu programa de testes.

Execute:

```bash
ctest --test-dir build -C Debug --output-on-failure
```

Uma execução bem-sucedida deve apresentar:

```text
100% tests passed out of 1
```

O executável de testes também utiliza uma função auxiliar para comparar o resultado obtido com o esperado.

Exemplo:

```cpp
check(config.has("missing"), false, "Config::has (chave inexistente)");
```

## Objetivo do Projeto

O CoreLib foi desenvolvido para praticar e consolidar conhecimentos de desenvolvimento em C++, incluindo:

- Organização de bibliotecas
- Separação entre arquivos de cabeçalho e implementação
- CMake
- CTest
- STL
- Manipulação de arquivos
- Tratamento de erros
- Testes
- Organização de código
- Reutilização de componentes

A biblioteca poderá evoluir quando necessidades reais e reutilizáveis surgirem em projetos futuros.
