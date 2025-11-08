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
