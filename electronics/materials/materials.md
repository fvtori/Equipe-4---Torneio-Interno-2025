# 🧾 Lista de Materiais — Robô Jack (Mini Sumô)

Este documento apresenta todos os componentes utilizados no desenvolvimento da parte **eletrônica** do robô **Jack**, da **Equipe 4 — Torneio Interno G.E.A.R. 2025**.  
Os itens listados abrangem desde a alimentação até os módulos de controle e sinalização.

---

## 🔋 Alimentação e Proteção

| Item | Quantidade | Especificação | Função / Observações |
|------|-------------|---------------|----------------------|
| Case para 3 pilhas AA | 1 | Saída ~4,5 V | Fonte principal de energia do robô |
| Pilhas AA | 3 | Alcalinas ou recarregáveis | Alimentação principal do sistema |
| Interruptor simples | 1 | 3 A / 12 V | Liga/desliga geral da alimentação |
| Fusível de vidro | 1 | 1 A / 250 V | Proteção contra sobrecorrente nos motores |
| Polyfuse (PTC) | 1 | 500 mA resetável | Proteção contra curtos no circuito lógico |

---

## ⚙️ Controle e Processamento

| Item | Quantidade | Especificação | Função / Observações |
|------|-------------|---------------|----------------------|
| ESP32 DevKit (38 pinos) | 1 | Microcontrolador Wi-Fi/Bluetooth | Unidade central de controle do robô |
| Expansor de ESP32 | 1 | Compatível com 38 pinos, entrada até 16 V | Facilita conexões e integra regulador interno |
| Placas de servo modificadas | 2 | Circuito interno de servo reutilizado | Funcionam como drivers dos motores DC |
| Controle Xbox One | 1 | Conexão Bluetooth | Envia comandos ao robô via Bluepad32 |

---

## 🔄 Atuadores

| Item | Quantidade | Especificação | Função / Observações |
|------|-------------|---------------|----------------------|
| Motor DC JGA25-370 | 2 | 6 V / eixo metálico | Responsáveis pela tração e movimento do robô |

---

## 🔔 Sinalização

| Item | Quantidade | Especificação | Função / Observações |
|------|-------------|---------------|----------------------|
| Buzzer ativo | 1 | 5 V | Emite alertas sonoros de inicialização e status |

---

## 🔌 Cabos, Conexões e Acessórios

| Item | Quantidade | Especificação | Função / Observações |
|------|-------------|---------------|----------------------|
| Fios jumper / soldáveis | Diversos | AWG 22–24 | Conexões entre módulos e alimentação |
| Estanho e solda | — | — | Fixação permanente de conexões |
| Suporte de montagem | — | Acrílico ou PLA | Fixação dos módulos no corpo do robô |

---

## 🧠 Observações Gerais

- O projeto priorizou o **baixo peso e a simplicidade** nas conexões.  
- A **ponte H (L298N)** e os reguladores externos (7805 / LM2596) foram eliminados nas versões finais.  
- Os **drivers foram obtidos a partir da modificação de servos**, reduzindo custo e volume.  
- O **expansor da ESP32** possui regulador onboard, dispensando componentes externos de tensão.  
- Todos os **módulos compartilham o mesmo GND**, garantindo estabilidade elétrica.

---

📎 **Versão do documento:** 1.0 — Atualizado em novembro de 2025  
📘 **Autor:** Luan — Responsável pela parte de eletrônica da Equipe 4

