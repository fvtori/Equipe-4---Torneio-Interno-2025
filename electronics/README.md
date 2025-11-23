# Diretório de Eletrônica

Este diretório contém todos os arquivos relacionados ao projeto eletrônico do robô *(categoria do robô)*, incluindo:

- Esquemáticos eletrônicos
- Diagramas de conexão
- Lista de componentes (BOM)
- Datasheets dos componentes
- Registros de testes
- Configurações de hardware

## Estrutura

- `img/`: Pasta contendo imagens do projeto eletrônico  
  - Fotos das placas  
  - Diagramas de ligação  
  - Esquemáticos em protoboard/PCB  

---

## Documentação

Este README contém as instruções de uso, pinagem utilizada e explicação do circuito da versão atual do robô.

---

# Documentação da Parte Eletrônica — Mini Sumô (Jack)

O sistema eletrônico do nosso robô **Jack**, desenvolvido pela **Equipe 4** para o *Torneio Interno de Robôs 2025* do projeto **G.E.A.R.**, é responsável pelo **controle, alimentação e acionamento dos motores** durante as partidas.

A eletrônica tem como objetivo principal permitir o **controle remoto via Bluetooth**, por meio de um **controle Xbox One**, utilizando a biblioteca **Bluepad32** conectada à **ESP32 DevKit (ESP32-DEVKIT, 30 pinos)**.

Diferente das versões iniciais do projeto, **não utilizamos mais o expansor de pinos**, visando a redução de peso do robô e maior simplicidade nas conexões elétricas.

O sistema agora é alimentado por uma **bateria de lítio 2S (~7,4 – 7,8 V)**, que fornece energia para os motores e para a lógica do sistema.

A **ponte H utilizada é a L298N**, que além de controlar os motores, também fornece uma saída regulada de **5V**, utilizada para alimentar diretamente a **ESP32**.

Por questões de simplicidade e peso, **não está sendo utilizado regulador de tensão externo** (como LM2596).  
A ESP32 é alimentada através do pino **5V/VIN**, conectado à saída de **5V da L298N**.

O sistema conta ainda com:
- Um **interruptor (switch)** geral para ligar e desligar o robô;
- Um **fusível / polyfuse** para proteção contra curto-circuito;
- Um **buzzer** para sinalização sonora (por exemplo, quando o robô é ligado).

Os motores utilizados atualmente são dois **motores DC N20 com caixa de redução**, mais leves que os modelos anteriores e mais adequados ao limite de peso da competição.  

Essa versão representa a **arquitetura atual da eletrônica do robô**, utilizada na fase final do projeto para a competição.

## ⚙️ Componentes Principais do Sistema Eletrônico

A seguir estão listados os principais componentes utilizados na montagem eletrônica atual do robô **Jack**, com suas respectivas funções dentro do sistema:

| Componente | Quantidade | Função no Circuito | Observações |
|-------------|-------------|--------------------|--------------|
| **ESP32 DevKit (38 pinos)** | 1 | Microcontrolador principal responsável pela comunicação Bluetooth, leitura dos comandos e controle dos motores. | Utiliza biblioteca Bluepad32 para integração com controle Xbox One. |
| **Ponte H L298N** | 1 | Driver de potência responsável por controlar os dois motores DC (esquerdo e direito). | Canal A → motor esquerdo / Canal B → motor direito. Possui saída de 5V usada para alimentar a ESP32. |
| **Motores DC N20 com redução** | 2 | Responsáveis pela tração do robô. | Escolhidos por serem mais leves que os modelos anteriores (JGA25-370). |
| **Bateria de lítio 2S (~7,4 – 7,8V)** | 1 | Fonte principal de energia do sistema. | Substitui o antigo case de 3 pilhas AA. |
| **Interruptor (Switch)** | 1 | Liga e desliga toda a alimentação do robô. | Instalado em série no fio positivo da bateria. |
| **Fusível** | 1 | Proteção contra curto-circuito e sobrecorrente. | Instalado após o switch na alimentação principal. |
| **Buzzer** | 1 | Emite sinal sonoro para indicar o estado do sistema. | Controlado por um pino digital da ESP32. |
| **Cabos e fios de ligação** | — | Realizam a interligação entre bateria, ESP32, ponte H e motores. | Utilizados fios mais curtos e leves para reduzir peso. |
