# 🧾 BOM — Bill of Materials  
## Robô Mini Sumô Jack (Circuito Eletrônico Oficial)

Este documento apresenta a **lista oficial de materiais (BOM)** utilizados no **circuito eletrônico final** do robô **Jack**, desenvolvido pela **Equipe 4** para o **Torneio Interno de Robôs 2025 — G.E.A.R.**

O BOM tem como objetivo **documentar tecnicamente** todos os componentes empregados na versão final do circuito, servindo como referência para:
- manutenção;
- replicação do projeto;
- controle de componentes;
- consulta técnica futura.

> 📌 **Observação:**  
> Os componentes listados referem-se **exclusivamente ao circuito final**, não incluindo versões de teste descartadas ao longo do desenvolvimento.

---

## 🔋 Alimentação e Proteção

| Item | Quantidade | Componente | Especificação / Modelo | Observações |
|----|----|----|----|----|
| 1 | 1 | Bateria de lítio 2S | 7,4 – 7,8 V | Fonte principal de energia do robô |
| 2 | 1 | Módulo carregador de bateria de lítio | Tipo TP4056 ou equivalente | Permite recarga sem desmontar o robô |
| 3 | 1 | Interruptor (switch) | ON/OFF | Corte geral da alimentação |
| 4 | 1 | Fusível | Vidro ou automotivo (corrente compatível) | Proteção da linha principal e da ponte H |

---

## 🧠 Controle e Processamento

| Item | Quantidade | Componente | Especificação / Modelo | Observações |
|----|----|----|----|----|
| 5 | 1 | ESP32 DevKit | ESP32-WROOM | Microcontrolador principal |
| 6 | 1 | Placa de expansão ESP32 (roxa) | Expansion Board | Distribuição de VCC, GND e sinais |
| 7 | 1 | Controle Bluetooth | 8BitDo | Comunicação via Bluepad32 |

---

## ⚙️ Atuadores e Drivers

| Item | Quantidade | Componente | Especificação / Modelo | Observações |
|----|----|----|----|----|
| 8 | 1 | Ponte H | L298N | Controle de dois motores DC |
| 9 | 2 | Motor DC com redução | N20 | Motores de tração do robô |

---

## 🔔 Sinalização

| Item | Quantidade | Componente | Especificação / Modelo | Observações |
|----|----|----|----|----|
| 10 | 1 | Buzzer ativo | 5 V | Sinalização sonora do sistema |

---

## 🔌 Conexões e Montagem

| Item | Quantidade | Componente | Especificação / Modelo | Observações |
|----|----|----|----|----|
| 11 | — | Fios elétricos | AWG 22–26 | Alimentação e sinais |
| 12 | — | Estanho para solda | — | Fixação permanente das conexões |
| 13 | — | Terminais / jumpers | — | Conexões internas do circuito |

---

## 📌 Observações Gerais

- Todos os componentes listados pertencem à **versão final do circuito** utilizada na competição.
- A **ESP32 é alimentada pela bateria através da placa de expansão**, que possui **regulador onboard**, não sendo alimentada pela saída de 5V da ponte H.
- O **GND é comum** a todos os módulos (ESP32, ponte H, motores, buzzer e carregador).
