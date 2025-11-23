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

# Documentação da Parte Eletrônica — Mini Sumô (Equipe 4)

O sistema eletrônico do robô **Jack**, desenvolvido pela **Equipe 4** para o *Torneio Interno de Robôs 2025* do projeto **G.E.A.R.**, é responsável pelo **controle, alimentação, acionamento dos motores e proteção elétrica** do robô durante as partidas.

O objetivo principal da eletrônica é permitir o **controle remoto via Bluetooth**, utilizando um **controle Xbox One** com a biblioteca **Bluepad32** em uma **ESP32 DevKit (ESP32-WROOM - 38 pinos)**.

Devido às limitações de peso e ajustes do projeto, a arquitetura foi reformulada para uma solução mais leve e eficiente, baseada em ponte H e bateria de lítio.

---

## ⚙️ Componentes Principais do Sistema Eletrônico

| Componente | Quantidade | Função no Circuito | Observações |
|------------|------------|--------------------|-------------|
| **ESP32 DevKit (38 pinos)** | 1 | Microcontrolador principal responsável pelo controle Bluetooth e lógica do robô. | Comunicação via Bluepad32 com controle Xbox One |
| **Ponte H L298N** | 1 | Driver de potência responsável por controlar os dois motores DC | Canal A = motor esquerdo / Canal B = motor direito |
| **Motores DC N20 (com redução)** | 2 | Responsáveis pela tração do robô | Utilizados por serem mais leves que os modelos anteriores |
| **Bateria Li-ion / LiPo ~7,4–7,8 V (2S)** | 1 | Fonte principal de energia do sistema | Substitui o antigo case de 3 pilhas AA |
| **Regulador DC-DC LM2596** | 1 | Converte a tensão da bateria em 5V para alimentar a ESP32 | Ajustado manualmente para 5,0 V |
| **Interruptor (Switch)** | 1 | Permite ligar/desligar todo o sistema | Instalado no positivo da bateria |
| **Fusível (ou Polyfuse)** | 1 | Proteção contra curto e sobrecorrente | Instalado após o switch |
| **Buzzer** | 1 | Sinalização sonora do sistema | Opcional, controlado por GPIO |
| **Cabos e fios** | — | Conexões elétricas do sistema | Cabos mais curtos para reduzir peso |

---

## 🔋 Alimentação e Distribuição de Energia

### Fonte principal  
A alimentação do robô agora é feita por uma:

> 🔋 **Bateria de lítio 2S (7,4 – 7,8 V)**

Essa bateria alimenta **tanto os motores quanto a parte lógica** do sistema.

---

### 🔌 Arquitetura elétrica

```text
BATERIA +  ── CHAVE ── FUSÍVEL ──┬──▶ VCC da L298N (~7,8 V)
                                  └──▶ ENTRADA do LM2596

BATERIA −  ───────────────────────┬──▶ GND da L298N
                                  ├──▶ GND do LM2596
                                  └──▶ GND da ESP32

LM2596 (saída regulada em 5V) ─▶ Pino VIN da ESP32
