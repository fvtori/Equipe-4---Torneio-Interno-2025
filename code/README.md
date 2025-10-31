# code

Este é um template de projeto padrão para desenvolvimento com [PlatformIO](https://platformio.org/). Ele fornece uma estrutura de pastas limpa e organizada, ideal para iniciar seus projetos de sistemas embarcados.

O objetivo deste template é promover as melhores práticas de organização de código, separando a lógica da aplicação, configurações, bibliotecas e testes.

## Estrutura de Diretórios

O projeto está organizado da seguinte forma:

```
code/
├── .pio/               # Arquivos de compilação e firmware (gerado automaticamente, não está no git)
├── .vscode/            # Configurações do editor Visual Studio Code (gerado automaticamente, não está no git)
├── include/            # Arquivos de cabeçalho (.h) globais do projeto
├── lib/                # Bibliotecas privadas (específicas do projeto) e externas
├── src/                # Arquivos de código-fonte (.c, .cpp) da aplicação
├── test/               # Testes unitários para validação do código
├── platformio.ini      # Arquivo de configuração principal do PlatformIO
└── README.md           # Este arquivo de documentação
```

### Descrição

  * `├── .pio/`

      * Este diretório é gerenciado pelo PlatformIO e contém os arquivos de compilação, dependências baixadas e o firmware final (`.bin` ou `.hex`). **Ele deve ser ignorado pelo sistema de controle de versão (ex: .gitignore).**

  * `├── .vscode/`

      * Contém as configurações específicas para o editor Visual Studio Code, como definições do IntelliSense. Também é gerenciado automaticamente.

  * `├── include/`

      * Use este diretório para arquivos de cabeçalho (`.h`, `.hpp`) que precisam ser compartilhados entre diferentes partes do seu código-fonte em `src/`. Um exemplo clássico é um arquivo `config.h` com definições de pinos e constantes globais.

  * `├── lib/`

      * Local ideal para bibliotecas. Cada biblioteca deve estar em sua própria subpasta (ex: `lib/MySensorLib/`). O PlatformIO automaticamente compila e vincula essas bibliotecas ao projeto. É perfeito para encapsular e reutilizar código.

  * `├── src/`

      * O coração da sua aplicação. O código-fonte principal (`.c`, `.cpp`) reside aqui. O arquivo `main.cpp` (ou `main.c`), que contém as funções `setup()` e `loop()`, é o ponto de entrada do programa.

  * `├── test/`

      * Destinado aos testes unitários. O [PlatformIO Test Runner](https://docs.platformio.org/en/latest/advanced/unit-testing/index.html) procura e executa os testes localizados aqui, ajudando a garantir a qualidade e a confiabilidade do código.

  * `└── platformio.ini`
      * Este é o arquivo de configuração mais importante do projeto. Nele você define a placa-alvo (`board`), o framework (`framework`), as bibliotecas de que o projeto depende (`lib_deps`), as opções de compilação (`build_flags`) e as configurações de upload e monitoramento.

## Como Começar

1.  Clone este repositório para sua máquina local.
2.  Abra a pasta do projeto com o Visual Studio Code (com a extensão PlatformIO instalada).
3.  Modifique o arquivo `platformio.ini` para configurar a sua placa e as bibliotecas necessárias.
4.  Comece a desenvolver o código principal no diretório `src/`.
