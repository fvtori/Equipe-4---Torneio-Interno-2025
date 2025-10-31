Este diretório é destinado aos arquivos de cabeçalho do projeto (*header files*).

Um arquivo de cabeçalho é um arquivo que contém declarações C e definições de macro a serem compartilhadas entre vários arquivos de código-fonte do projeto. Você solicita o uso de um arquivo de cabeçalho em seu arquivo de código-fonte do projeto (C, C++, etc) localizado na pasta `src`, incluindo-o com a diretiva de pré-processamento C `#include`.

```c
// src/main.c

#include "header.h"

int main (void)
{
  ...
}
```

Incluir um arquivo de cabeçalho produz os mesmos resultados que copiar o arquivo de cabeçalho em cada arquivo de código-fonte que precisa dele. Essa cópia seria demorada e propensa a erros. Com um arquivo de cabeçalho, as declarações relacionadas aparecem em um só lugar. Se precisarem ser alteradas, podem ser alteradas em um único local, e os programas que incluem o arquivo de cabeçalho usarão automaticamente a nova versão na próxima vez que forem recompilados. O arquivo de cabeçalho elimina o trabalho de encontrar e alterar todas as cópias, bem como o risco de uma falha em encontrar uma cópia resultar em inconsistências dentro de um programa.

Em C, a convenção é dar aos arquivos de cabeçalho nomes que terminam com `.h`.

Leia mais sobre o uso de arquivos de cabeçalho na documentação oficial do GCC:

  * Sintaxe de Inclusão
  * Operação de Inclusão
  * Cabeçalhos de Inclusão Única
  * Inclusões Computadas

[https://gcc.gnu.org/onlinedocs/cpp/Header-Files.html](https://gcc.gnu.org/onlinedocs/cpp/Header-Files.html)
