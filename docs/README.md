# **docs**
Este diretório tem como objetivo documentar o projeto do código do robô do seu grupo. É o relatório de todo o projeto.

O código implementado pode ser visto em: [`code`](../code).
## **Introdução**

O projeto se trata de um robô *(categoria do robô)* de alto desempenho utilizado para a competição *(nome da competição)*.

<!-- *Imagem/ do robô* -->
<!-- ![Nome do robô](img/nome_do_arquivo_de_imagem.png)  -->

*Figura 1: *(categoria do robô)**

## **1. Bill of Materials (BOM)** 

**(*Apenas um exemplo, adicionar coisas como motor, microcontrolador, pneu, etc*)**

Na tabela a seguir será possível observar a lista com todos os componentes físicos utilizados para a construção do robô *(categoria do robô)*:

|                                      	|                       **Bill of Materials - BOM**                       	|            	|
|:------------------------------------:	|:-----------------------------------------------------------------------:	|:----------:	|
|                 Nome                 	|                                Explicação                               	| Quantidade 	|
|                                      	|                **Baterias e componentes relacionados**                    |            	|
|               Bateria X            	|                             Bateria do robô                             	|      qtd     	|
|                                      	|                       **Componentes eletrônicos**                       	|            	|
|              Sensor X             	|                           Sensor para X coisa                          	|      qtd     	|
|             Componente Y             	|                          Componente para Y coisa                          |      qtd     	|

## **2. Modelagem 3D**

*Inserir imagens e explicações da [modelagem 3D](../mechanics)*.

## **3. Esquemático eletrônico**

*Inserir imagens e explicações do [circuito eletrônico](../electronics)*.

## **4. Arquitetura geral do diretório raiz**

- **[/code](../code)** — Código-fonte do robô: firmware, bibliotecas, scripts de build e exemplos de execução.
- **[/docs](../docs)** — Documentação do projeto: relatórios, manuais, diagramas e este README.
- **[/eletronics](../eletronics)** — Esquemáticos, listas de componentes (BOM), layouts de PCB e notas de montagem.
- **[/mechanics](../mechanics)** — Modelos 3D, desenhos CAD, arquivos de impressão/usinagem e instruções de montagem mecânica.
- **[/misc](../misc)** — Arquivos diversos: qualquer arquivo que não se enquadram nas demais pastas. (editais, planilhas, etc)
- **[/simu](../simu)** — (OPCIONAL) Cenários de simulação, scripts de execução e automação, ferramentas de visualização.

Cada pasta contém um README interno com instruções específicas de uso, dependências e explicações específicas.

## **5. Organização do Fluxo do Robô (Exemplo)**

1. **Setup:**
    - Inicializar sensores, motores, PID, e conexão remota.

2. **Loop Principal: (Exemplo)**
    - Ler sensores.
    - Calcular o erro da linha.
    - Ajustar a velocidade com o PID.
    - Detectar faixas indicativas e curvas.
    - Analisa eventos para mapeamento.
    - Enviar dados para telemetria.
    
3. **Comunicação Bluetooth:**
    - Escutar comandos remotos para ajuste do PID.
    - Enviar dados em tempo real.
