# Documentação da Parte Eletrônica — Mini Sumô (Equipe 4)


O sistema eletrônico do nosso robô **Jack**, desenvolvido pela **Equipe 4** para o *Torneio Interno de Robôs 2025* do projeto **G.E.A.R.**, é responsável pelo **controle, alimentação e proteção elétrica** do robô durante as partidas da competição interna do GEAR.

A eletrônica tem como objetivo principal permitir o **controle remoto via Bluetooth**, por meio de um **controle Xbox One**, utilizando a biblioteca **Bluepad32** conectada à **ESP32 WROOM (38 pinos)**.  
Essa ESP32 está acoplada a um **expansor de pinos**, facilitando as conexões dos periféricos e drivers de motor.

O sistema é alimentado por **três pilhas AA**, conectadas em um *case* com **interruptor (switch)** embutido, fornecendo energia para toda a parte de controle e tração.  
Para proteção, o circuito conta com um **fusível** em série com a alimentação e um **buzzer**, utilizado para sinalização sonora (por exemplo, quando o robô liga ele emite um som).

Os dois motores de tração do robô **(JGA25-370)** são controlados por **duas placas de servo modificadas** que atuam como **pontes H**, permitindo o controle independente de velocidade e direção de cada roda.

O sistema eletrônico do **Jack** foi planejado para garantir:
- **Segurança** (proteção com fusível);
- **Organização** (uso de expansor de pinos);
- **Facilidade de controle** (via Bluetooth);
- **Modularidade** (componentes facilmente substituíveis);
- **Eficiência** (baixo consumo com três pilhas AA).

---

## ⚙️ Componentes Principais do Sistema Eletrônico

A seguir estão listados os principais componentes utilizados na montagem eletrônica do robô **Jack**, com suas respectivas funções dentro do sistema:


| Componente | Quantidade | Função no Circuito | Observações |
|-------------|-------------|--------------------|--------------|
| **ESP32 (38 pinos)** | 1 | Microcontrolador principal responsável pela comunicação Bluetooth, leitura de comandos e controle dos motores. | Utiliza biblioteca Bluepad32 para integração com controle Xbox One. |
| **Expansor de Pinos (ESP32)** | 1 | Facilita o acesso aos pinos da ESP32 e melhora a organização das ligações. | Conectado diretamente na ESP32. |
| **Placas de Servo Modificadas (Ponte H)** | 2 | Controlam os dois motores DC (esquerdo e direito), permitindo reversão e controle de velocidade. | Cada placa controla um motor. |
| **Motores DC JGA25-370** | 2 | Responsáveis pela tração do robô. | Alimentados pelas pontes H. |
| **Buzzer** | 1 | Emite sinal sonoro para indicar inicialização ou eventos do sistema. | Ligado a um pino digital da ESP32. |
| **Fusível (PTC ou de vidro)** | 1 | Protege o circuito contra sobrecorrente ou curto-circuito. | Instalado em série com a alimentação principal. |
| **Interruptor (Switch)** | 1 | Liga e desliga toda a alimentação do circuito. | Integrado ao case das pilhas. |
| **Case de Pilhas (3x AA)** | 1 | Fornece energia elétrica ao sistema. | Alimenta ESP32 e pontes H. |
| **Cabos Jumper e Fios** | — | Fazem as interligações entre os módulos. | Usados conforme necessidade do protótipo. |

---

## 🔌 Alimentação e Ligações de Energia

**Fonte:** case com **3 pilhas AA**  
**Caminho da energia (feito no protótipo):**
1) Case de pilhas **(+/–)** → **chave liga/desliga (switch)**  
2) **Switch → fusível (PTC ou vidro)** em série  
3) **Fusível → pads do conector DC** (parte inferior do expansor da ESP32)  
4) O **regulador onboard do expansor** converte a entrada para as tensões usadas pela **ESP32** (5 V/3,3 V, conforme a placa)

> **Por que assim?** O expansor suporta entrada **até 16 V** e **já regula** para a ESP32. Portanto **não é necessário regulador externo** só para a placa de controle.

### Motores e drivers
- **V+ dos drivers (placas de servo modificadas):** ligar no **mesmo positivo da bateria (antes do regulador)** para não sobrecarregar o regulador do expansor.  
- **GND comum:** **obrigatório** unir o GND da bateria, do expansor/ESP32 e dos dois drivers.  
- **EN/PWM e IN1/IN2**: saem da ESP32 (nível lógico), **somente sinais**.
  
- Para o detalhamento completo das conexões (fio a fio, diagramas e fotos da montagem), acesse o diretório [`/electronics/esqm_circ`](./esqm_circ/).

  ---
  
## 🧩 Pinagem e Conexões Lógicas da ESP32

A tabela abaixo mostra a distribuição dos pinos da **ESP32 (38 pinos)** utilizada no robô **Jack**, indicando as funções de controle, sensores e periféricos:

| Função / Componente | Pino da ESP32 | Tipo de Sinal | Descrição / Observações |
|---------------------|----------------|----------------|--------------------------|
| **Motor Esquerdo — IN1** | GPIO22 | Saída Digital | Sentido de rotação (1) |
| **Motor Esquerdo — IN2** | GPIO23 | Saída Digital | Sentido de rotação (2) |
| **Motor Esquerdo — EN/PWM** | GPIO21 | Saída PWM | Controle de velocidade |
| **Motor Direito — IN1** | GPIO18 | Saída Digital | Sentido de rotação (1) |
| **Motor Direito — IN2** | GPIO19 | Saída Digital | Sentido de rotação (2) |
| **Motor Direito — EN/PWM** | GPIO5 | Saída PWM | Controle de velocidade |
| **Buzzer** | GPIO2 | Saída Digital | Ativação sonora de status |
| **LED de Status (opcional)** | GPIO4 | Saída Digital | Pode indicar energização ou modo ativo |
| **Bluetooth (Bluepad32)** | Integrado na ESP32 | Comunicação sem fio | Recebe comandos do controle Xbox One |
| **Alimentação** | VIN / GND | Energia | 3x pilhas AA conectadas ao pad do conector DC do expansor (com fusível e chave) |
| **GND Comum** | — | — | GND interligado entre ESP32, drivers e motores |

> **Nota:** As portas podem variar conforme testes futuros. A pinagem será atualizada conforme as revisões do firmware forem feitas.

