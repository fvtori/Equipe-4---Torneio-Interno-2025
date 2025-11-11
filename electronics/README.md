# Diretório de Eletrônica

Este diretório deve conter todos os arquivos relacionados ao projeto eletrônico do robô *(categoria do robô)*, incluindo:

- Esquemáticos eletrônicos
- Layout de PCB
- Lista de componentes (BOM)
- Datasheets dos componentes
- Diagramas de conexão
- Configurações de hardware

## Estrutura

- `img/`: Pasta contendo imagens do projeto eletrônico
  - Fotos das placas
  - Esquemas de conexão
  - Diagramas de pinout

## Documentação

Neste README deve conter as instruções de uso, pinos utilizados e explicação do circuito.

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

As conexões do sistema eletrônico do robô **Jack** seguem o diagrama mostrado na pasta `/esqm_circ/`.  
Abaixo está o resumo das ligações **reais**, conforme o circuito montado.

| Função / Componente | Pino da ESP32 | Tipo de Sinal | Descrição / Observações |
|---------------------|----------------|----------------|--------------------------|
| **Motor Esquerdo (Driver 1)** | GPIO22 | Saída Digital | Sinal de controle direto do driver do motor esquerdo |
| **Motor Direito (Driver 2)** | GPIO23 | Saída Digital | Sinal de controle direto do driver do motor direito |
| **Buzzer** | GPIO2 | Saída Digital | Emite sinal sonoro de status (ex.: inicialização) |
| **Alimentação Principal** | VIN / GND | Energia | Alimentação proveniente do case de 3 pilhas AA via switch e fusível |
| **Bluetooth (Bluepad32)** | Integrado | Comunicação sem fio | Responsável pelo recebimento dos comandos do controle Xbox One |
| **GND Comum** | — | — | Todos os módulos (ESP32, drivers e motores) compartilham o mesmo GND |

> 🔎 **Observação:**  
> As placas de servo **não estão operando como pontes H**, mas sim como **drivers simples**, onde o sinal da ESP32 ativa diretamente o motor em um único sentido de rotação.  
> Cada motor é controlado por um único pino digital, e o controle de velocidade ou inversão de sentido **não está implementado nesta versão**.

---

📎 Para visualizar o esquema detalhado e as ligações físicas, consulte o diretório [`/electronics/esqm_circ`](./esqm_circ/), onde estão os diagramas e imagens do circuito completo.
