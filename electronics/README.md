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

## 🔌 Alimentação e Ligações de Energia

O sistema eletrônico do robô **Jack** é alimentado por uma **bateria de lítio 2S (≈ 7,4 a 7,8V)**, responsável por fornecer energia tanto para os motores de tração quanto para a parte lógica (ESP32).

Nesta versão do projeto, **não é utilizado regulador de tensão externo**, pois a própria **ponte H L298N** fornece uma saída regulada de **5V**, que é utilizada para alimentar a **ESP32**.

### 🔋 Caminho da alimentação no circuito

O percurso da energia no robô segue a seguinte lógica:

1. **Bateria 2S (7,4 – 7,8V)**  
   → fornece energia principal do sistema.

2. O **fio positivo da bateria** passa por:  
   - um **interruptor (switch)**, responsável por ligar e desligar todo o robô;  
   - e um **fusível**, instalado em série para proteção contra curto-circuito.

3. Após o fusível, o positivo é distribuído para:
   - o pino **VCC (12V)** da ponte H **L298N**;
   - a entrada do sistema de alimentação geral do robô.

4. A partir da **saída de 5V da L298N**, é feita a alimentação da **ESP32** pelo pino **5V/VIN**.

5. Todos os componentes compartilham o **mesmo GND**, ou seja:
   - GND da bateria  
   - GND da ponte H  
   - GND da ESP32  
   estão conectados em comum.

---

### ⚠️ Observações importantes sobre a alimentação:

- A **tensão de 7,4V** é aplicada diretamente na ponte H, pois ela é projetada para trabalhar com esse nível de tensão nos motores.
- A **ESP32 não recebe 7,4V diretamente**, ela recebe apenas **5V regulados** vindos da ponte H (através da saída 5V da L298N).
- O GND comum é fundamental para o correto funcionamento do controle dos motores.
- O interruptor está ligado no **fio positivo**.

---

### 🧠 Resumo da alimentação:

| Elemento | Alimentação |
|---------|--------------|
| ESP32 | 5V (fornecido pela L298N) |
| Ponte H L298N | 7,4 – 7,8V (direto da bateria) |
| Motores N20 | 7,4 – 7,8V (via L298N) |
| Buzzer | 5V (fornecido pela saída da L298N) |

## 🧩 Pinagem e Conexões Lógicas — ESP32 + L298N

Nesta versão do projeto do robô **Jack**, os motores são controlados utilizando uma **ponte H L298N**, ligada diretamente à **ESP32 DevKit V1 (38 pinos)**, sem expansor de pinos.

Abaixo estão listadas as conexões entre a **ESP32** e a **ponte H** conforme o circuito atual do robô.

---

### 🔵 Canal A – Motor Esquerdo

| Ponte H (L298N) | Pino ESP32 | Função |
|-----------------|-----------|--------|
| **ENA** | GPIO **23** | Controle de velocidade via PWM |
| **IN1** | GPIO **19** | Controle de direção |
| **IN2** | GPIO **18** | Controle de direção |

---

### 🔴 Canal B – Motor Direito

| Ponte H (L298N) | Pino ESP32 | Função |
|-----------------|-----------|--------|
| **ENB** | GPIO **22** | Controle de velocidade via PWM |
| **IN3** | GPIO **17** | Controle de direção |
| **IN4** | GPIO **16** | Controle de direção |

---

### 🔔 Buzzer

| Componente | Pino ESP32 | Função |
|-----------|-----------|--------|
| **Buzzer** | GPIO **21** | Emite sinal sonoro de inicialização e diagnóstico |

---

## ⚡ Observações Importantes

- Os pinos **ENA** e **ENB** recebem sinais **PWM**, permitindo o controle da velocidade dos motores.
- Os pinos **IN1, IN2, IN3 e IN4** controlam a **direção de rotação** dos motores.
- O **buzzer no GPIO21** é utilizado para:
  - sinalizar que o robô foi ligado,
  - provocar o robô adversário emitindo sons,
  - ou tocar músicas durante a batalha.
    
---

### 📌 Resumo rápido da pinagem

| Componente | Pino ESP32 |
|-----------|-----------|
| ENA | GPIO 23 |
| IN1 | GPIO 19 |
| IN2 | GPIO 18 |
| ENB | GPIO 22 |
| IN3 | GPIO 17 |
| IN4 | GPIO 16 |
| Buzzer | GPIO 21 |
