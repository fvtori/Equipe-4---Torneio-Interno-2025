Este diretório destina-se a bibliotecas específicas (privadas) do projeto.
O **PlatformIO** as compilará em bibliotecas estáticas e as vinculará ao arquivo executável.

O código-fonte de cada biblioteca deve ser colocado em um diretório separado
(`lib/nome_da_sua_biblioteca/[Código]`).

Por exemplo, veja a estrutura das seguintes bibliotecas de exemplo `Foo` e `Bar`:

```
|--lib
|  |
|  |--Bar
|  |  |--docs
|  |  |--examples
|  |  |--src
|  |     |- Bar.c
|  |     |- Bar.h
|  |  |- library.json (opcional. para opções de compilação personalizadas, etc) https://docs.platformio.org/page/librarymanager/config.html
|  |
|  |--Foo
|  |  |- Foo.c
|  |  |- Foo.h
|  |
|  |- README --> ESTE ARQUIVO
|
|- platformio.ini
|--src
   |- main.c
```

Exemplo de conteúdo de `src/main.c` usando Foo e Bar:

```c
#include <Foo.h>
#include <Bar.h>

int main (void)
{
  ...
}
```

O Localizador de Dependências de Biblioteca (LDF) do **PlatformIO** encontrará automaticamente as bibliotecas dependentes, analisando os arquivos de código-fonte do projeto.

Mais informações sobre o Localizador de Dependências de Biblioteca do **PlatformIO**:

  - [https://docs.platformio.org/page/librarymanager/ldf.html](https://docs.platformio.org/page/librarymanager/ldf.html)
