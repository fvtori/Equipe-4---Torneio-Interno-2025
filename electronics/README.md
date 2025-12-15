# Diretório de Eletrônica

Este diretório contém todos os arquivos relacionados ao projeto eletrônico do robô *(categoria do robô)*, incluindo:

- Esquemáticos eletrônicos  
- Diagramas de conexão  
- Lista de componentes (BOM)  
- Datasheets dos componentes  
- Registros de testes  
- Configurações de hardware  

---

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

O sistema eletrônico do robô **Jack**, desenvolvido pela **Equipe 4** para o **Torneio Interno de Robôs 2025** do projeto **G.E.A.R.**, é responsável pelo **controle, alimentação e acionamento dos motores** durante as partidas.

A eletrônica tem como objetivo principal permitir o **controle remoto via Bluetooth**, por meio de um **controle 8BitDo**, utilizando a biblioteca **Bluepad32** conectada à **ESP32 DevKit**.

Na versão atual do projeto, foi adotada novamente a **placa de expansão roxa da ESP32**, pois ela facilitou a organização das conexões e permitiu uma montagem elétrica **mais compacta**, adequada ao espaço reduzido do chassi do robô.

O sistema é alimentado por uma **bateria de lítio 2S (~7,4 – 7,8 V)**, responsável por fornecer energia tanto para os motores quanto para a parte lógica.

A **ponte H utilizada é a L298N**, responsável exclusivamente pelo **acionamento e controle dos motores DC**.

A **alimentação da ESP32 não é feita pela saída de 5V da L298N, como estava sendo feita antes**.  
A ESP32 é alimentada diretamente pela bateria através da **placa de expansão**, que possui **regulador onboard**, responsável por adequar a tensão de entrada aos níveis corretos de operação do microcontrolador.

Além disso, foi incluído no circuito um **módulo carregador de bateria de lítio**, permitindo a recarga da bateria sem a necessidade de desmontar o robô.

O sistema conta ainda com:
- um **interruptor (switch)** geral;
- um **fusível único** de proteção;
- um **buzzer** para sinalização sonora.

Os motores utilizados são **motores DC N20 com caixa de redução**, escolhidos por serem mais leves e compatíveis com o limite de peso da competição.

Essa versão representa a **arquitetura final da eletrônica do robô**, utilizada na fase de competição.

---

## ⚙️ Componentes Principais do Sistema Eletrônico

| Componente | Quantidade | Função no Circuito | Observações |
|-----------|------------|--------------------|-------------|
| **ESP32 DevKit** | 1 | Comunicação Bluetooth e controle do robô | Biblioteca Bluepad32 |
| **Placa de expansão roxa (ESP32 Expansion Board)** | 1 | Organização das conexões e regulação de tensão | Regulador onboard |
| **Ponte H L298N** | 1 | Controle dos motores DC | Dois canais independentes |
| **Motores DC N20 com redução** | 2 | Tração do robô | Leves e eficientes |
| **Bateria de lítio 2S (7,4 – 7,8V)** | 1 | Fonte de energia principal | Alimenta todo o sistema |
| **Módulo carregador de bateria** | 1 | Recarga da bateria | Integrado ao circuito |
| **Interruptor (switch)** | 1 | Liga/desliga geral | Corte total da alimentação |
| **Fusível** | 1 | Proteção elétrica | Protege a linha principal |
| **Buzzer** | 1 | Sinalização sonora | Controlado por GPIO |
| **Cabos e fios** | — | Interligações elétricas | Curtos e organizados |

---

## 🔌 Alimentação e Ligações de Energia

O robô **Jack** é alimentado por uma **bateria de lítio 2S (7,4 – 7,8V)**.  
A distribuição de energia é feita de forma direta e compacta utilizando a **placa de expansão da ESP32**.

### 🔋 Caminho da alimentação

1. **Bateria 2S (7,4 – 7,8V)**  
2. **Interruptor (switch)**  
3. **Placa de expansão da ESP32**  
4. Distribuição da energia para:
   - ESP32 (via regulador onboard)
   - Ponte H L298N
   - Demais periféricos

Todos os módulos compartilham **GND comum**, condição essencial para o correto funcionamento dos sinais de controle.

---

## 🔒 Fusível (Proteção)

O circuito utiliza **um único fusível**, instalado após o switch, responsável por proteger a alimentação principal e a ponte H contra curto-circuito e sobrecorrente.

---

## 🧠 Resumo da Alimentação

| Elemento | Alimentação |
|--------|-------------|
| ESP32 | 7,4 – 7,8V (via placa de expansão) |
| Ponte H L298N | 7,4 – 7,8V |
| Motores N20 | 7,4 – 7,8V |
| Buzzer | Linha lógica |
| Módulo carregador | Conectado à bateria |

---

## 🧩 Pinagem e Conexões Lógicas — ESP32 + L298N

As conexões lógicas entre a **ESP32** e a **ponte H L298N** seguem o mapeamento abaixo.

---

### 🔵 Canal A — Motor Esquerdo

| Ponte H | GPIO ESP32 | Função |
|-------|-----------|--------|
| ENA | GPIO 23 | PWM (velocidade) |
| IN1 | GPIO 19 | Direção |
| IN2 | GPIO 18 | Direção |

---

### 🔴 Canal B — Motor Direito

| Ponte H | GPIO ESP32 | Função |
|-------|-----------|--------|
| ENB | GPIO 22 | PWM (velocidade) |
| IN3 | GPIO 5 | Direção |
| IN4 | GPIO 21 | Direção |

---

### 🔔 Buzzer

| Componente | GPIO ESP32 | Função |
|----------|------------|--------|
| Buzzer | GPIO 32 | Sinalização sonora |

---

## ⚡ Observações Importantes

- ENA e ENB utilizam **PWM** para controle de velocidade.
- IN1 a IN4 definem o sentido de rotação dos motores.
- O buzzer é utilizado para sinalizar quando o controle conecta na esp32
- O compartilhamento de **GND comum** é essencial para o funcionamento correto do sistema.

---

## 📌 Resumo Rápido da Pinagem

| Componente | GPIO |
|----------|------|
| ENA | 23 |
| IN1 | 19 |
| IN2 | 18 |
| ENB | 22 |
| IN3 | 5 |
| IN4 | 21 |
| Buzzer | 32 |
