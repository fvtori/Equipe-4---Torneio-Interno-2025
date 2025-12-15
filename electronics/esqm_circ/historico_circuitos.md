# Histórico de Desenvolvimento do Circuito — Robô Jack

Este documento mostra a evolução do circuito eletrônico do robô **Jack**, desde as primeiras versões de teste até o modelo final utilizado na competição.

---

### 🧪 Circuito Teste 1

![Circuito introdutório - versão inicial](../img/Circuito_teste1.jpg)

O primeiro circuito desenvolvido para o robô **Jack** teve como principal finalidade **representar conceitualmente o sistema eletrônico** do projeto.  
Nesta etapa, ainda não foram realizados testes práticos, com o objetivo sendo apenas **visualizar e planejar** como seria feita a distribuição de energia e o controle básico dos motores.

A proposta dessa montagem foi criar uma **referência visual** que ajudasse a equipe a entender o caminho da alimentação e a função de cada componente, antes de partir para a execução real do protótipo.

#### 🧩 Estrutura e componentes representados
- **Case de 4 pilhas AAA**: escolhido inicialmente para fornecer aproximadamente **9 V**, simulando uma fonte simples e acessível.  
- **Chave liga/desliga (switch)**: adicionada para representar o controle manual de energia.  
- **Regulador de tensão 7805**: responsável por reduzir a tensão de 9 V para 5 V, garantindo segurança à ESP32.  
- **Protoboard**: utilizada como base para a montagem ilustrativa, permitindo visualizar o trajeto dos fios e conexões.  
- **Ponte H (L298N)**: incluída para simular o controle bidirecional dos dois motores DC.  
- **Buzzer**: adicionado como indicação sonora de funcionamento.  
- **ESP32**: microcontrolador principal, representando o núcleo lógico do sistema.

#### 🎯 Objetivo da versão
O propósito desta primeira versão foi **explorar visualmente a arquitetura elétrica** do robô, definindo:
- Como a energia fluiria desde o case de pilhas até a ESP32;  
- Onde seriam posicionados os componentes principais;  
- E como os motores e o buzzer seriam integrados ao controle lógico.

---

### ⚙️ Circuito Teste 2 — Planejamento para Transição à PCB

![Circuito Teste 2](../img/Circuito_teste2.jpg)

Nesta segunda etapa, a equipe buscou **aperfeiçoar o planejamento elétrico** do robô **Jack**, avançando do modelo conceitual inicial para uma proposta **mais estruturada e realista**.  
A principal mudança foi a **intenção de substituir o uso da protoboard por uma placa PCB personalizada**, onde os componentes seriam soldados, garantindo maior confiabilidade durante a competição.

O esquema apresentado representa esse novo conceito de organização e distribuição de energia. Embora o circuito não tenha sido montado fisicamente, ele serviu como **base de estudo para o design da futura placa**.

#### 🔧 Estrutura e componentes representados
- **Bateria 18650 (2 unidades em série)**: substituiu o antigo case de pilhas AAA, fornecendo uma **tensão nominal de 7,4 V** e maior autonomia.  
- **Chave liga/desliga (switch)**: manteve-se como controle principal de alimentação.  
- **Regulador de tensão 7805**: responsável por fornecer **5 V estáveis** para o circuito lógico.  
- **Barramentos VCC e GND**: representados pelos terminais azuis, planejados para fazer parte da futura **PCB**, permitindo a distribuição de energia de forma organizada e segura.  
- **Ponte H (L298N)**: utilizada para controle dos dois motores DC.  
- **Buzzer**: mantido como dispositivo sonoro auxiliar.  
- **ESP32**: microcontrolador principal, responsável pela lógica e controle dos motores.  

#### 🎯 Objetivo da versão
O objetivo desta fase foi **planejar a implementação física definitiva do circuito**, simulando:
- A disposição dos componentes sobre a placa;  
- A criação de **barramentos integrados de 5 V e GND**;  
- A eliminação de fios soltos e conexões instáveis típicas de protoboards.  

A ideia era que a futura PCB concentrasse **toda a parte elétrica principal**, incluindo a ESP32, o regulador, os conectores dos motores e o buzzer.

#### ⚙️ Desafios e decisões
Apesar de o conceito ser promissor, a equipe identificou algumas dificuldades práticas:
- O **tamanho da placa** seria considerável, aumentando o peso e a complexidade do robô;  
- O **processo de soldagem** exigiria tempo e precisão elevados;  
- O número de fios e trilhas seria grande, o que aumentava a chance de erro e dificultava a manutenção.

Esses fatores levaram à decisão de **não prosseguir com o uso da PCB** neste estágio, concentrando esforços em buscar uma solução mais compacta e funcional para a alimentação e distribuição de energia.

---

### ⚙️ Circuito Teste 3 — Implementação de Proteções e Uso do Expansor da ESP32

![Circuito Teste 3](../img/Circuito_teste3.jpg)

O **Circuito Teste 3** marcou uma das maiores evoluções no projeto eletrônico do robô **Jack**.  
Nesta versão, a equipe focou em **otimizar o espaço físico, melhorar a segurança elétrica e reduzir a quantidade de fios**, aproximando o design do formato que seria utilizado no protótipo final.

Diferente das versões anteriores, este circuito já apresenta uma **configuração mais realista e organizada**, com elementos de proteção e componentes atualizados conforme a disponibilidade no laboratório G.E.A.R.

#### 🔧 Principais mudanças e melhorias
- **Regulador de tensão LM2596:** substituiu o antigo **7805**, já que este não estava disponível no laboratório. O LM2596, além de ser **ajustável e mais eficiente**, dissipa menos calor e garante maior estabilidade.  
- **Interruptor compacto:** adotado no lugar da chave *switch* tradicional, oferecendo **menor consumo de espaço** e melhor integração ao corpo do robô.  
- **Duas medidas de proteção:**  
  - **Fusível** entre a bateria e a **ponte H**, evitando sobrecorrente nos motores;  
  - **Polyfuse (PTC resetável)** em série com o circuito lógico, protegendo a **ESP32 e o regulador** contra curtos e aquecimentos.  
- **Expansor da ESP32:** substituiu a placa simples, funcionando como **protoboard integrada**, o que **reduziu a quantidade de fios** e **facilitou as conexões** de sensores e drivers.  
- **Buzzer** mantido como componente auxiliar de sinalização, agora ligado diretamente ao expansor.

#### 🔋 Organização da alimentação
O novo arranjo manteve o uso de **duas baterias 18650 (7,4 V totais)** como fonte principal, agora com melhor distribuição:
1. A energia passa primeiro pelo **interruptor principal**;
2. Em seguida, é direcionada ao **fusível dos motores** e ao **polyfuse do circuito lógico**;
3. O **regulador LM2596** reduz a tensão para o valor ideal da ESP32 e demais módulos.

Essa configuração tornou o sistema mais seguro, evitando riscos de sobrecarga e incêndio — um passo importante para garantir confiabilidade durante o torneio.

#### ⚙️ Considerações do design
Além das melhorias elétricas, esta versão trouxe uma grande vantagem mecânica: a **eliminação da protoboard**.  
Com o expansor da ESP32, todas as conexões ficaram mais firmes, reduzindo o risco de mau contato e simplificando o layout geral do robô.  

A equipe também pôde visualizar de forma mais clara a **separação das linhas de potência e lógica**, o que facilita futuras manutenções e diagnósticos.

---

### ⚙️ Circuito Teste 4 — Integração Completa com L298N e Placa de Expansão

![Circuito Teste 4](../img/Circuito_teste4.jpg)

O **Circuito Teste 4** marcou a fase de **integração completa dos principais módulos eletrônicos** do robô **Jack**, aproximando o projeto de uma configuração funcional real.  
Nesta etapa, o foco foi **validar a comunicação entre a ESP32, a ponte H L298N e os motores**, além de testar uma nova forma de organização da alimentação utilizando a **placa de expansão roxa da ESP32**.

Diferente dos testes anteriores, este circuito já foi **montado fisicamente** e utilizado para testes práticos de acionamento dos motores e distribuição de energia.

A proposta desta versão foi **avaliar desempenho, estabilidade elétrica e viabilidade física** do conjunto dentro do chassi do robô.

#### 🧩 Estrutura e componentes utilizados
- **Bateria de lítio 2S (7,4 – 7,8 V)**: utilizada como fonte principal de energia, substituindo definitivamente os cases de pilhas.  
- **Interruptor (switch)**: responsável por ligar e desligar todo o sistema eletrônico.  
- **Fusível único**: adicionado em série para proteção contra curto-circuito e sobrecorrente.  
- **Placa de expansão roxa da ESP32**: utilizada para distribuir alimentação (VCC e GND) e facilitar as conexões dos sinais, reduzindo a quantidade de fios.  
- **Ponte H L298N**: responsável pelo controle bidirecional dos dois motores DC.  
- **Motores DC N20 com redução**: empregados nos testes por serem mais leves e adequados ao limite de peso.  
- **Buzzer**: conectado à ESP32 para sinalização sonora durante os testes.  
- **Módulo carregador de bateria de lítio**: integrado ao circuito para facilitar a recarga da bateria.

#### 🎯 Objetivo da versão
O objetivo do Circuito Teste 4 foi:
- Validar o **funcionamento da L298N** com a ESP32 via placa de expansão;  
- Testar a **distribuição de energia pelos pads da placa de expansão**;  
- Avaliar o **comportamento dos motores N20** sob carga real;  
- Analisar a **organização física da elétrica** dentro do robô.

Apesar de apresentar bons resultados, esta versão ainda foi considerada **experimental**, servindo como base para ajustes finais de organização, simplificação e documentação.

---

### 🏁 Circuito Teste 5 — Circuito Oficial do Robô Jack

![Circuito Oficial — Versão Final](../img/Circuito_Final.png)

O **Circuito Teste 5** representa a **versão final e oficial** do sistema eletrônico do robô **Jack**, adotada para a competição.  
Esta configuração é resultado direto dos aprendizados obtidos nos testes anteriores, especialmente no Circuito Teste 4, com refinamentos voltados para **confiabilidade, compactação e facilidade de manutenção**.

Nesta versão, o circuito foi **totalmente validado em bancada**, com testes contínuos de acionamento dos motores, alimentação estável da ESP32 e funcionamento correto dos periféricos.

#### 🧩 Estrutura e componentes atualizados
- **Bateria de lítio 2S (7,4 – 7,8 V)**: fonte principal de energia do robô.  
- **Interruptor (switch)**: controle geral de alimentação.  
- **Fusível único**: protege a ponte H e a alimentação principal contra falhas elétricas.  
- **Placa de expansão roxa da ESP32**: utilizada como base central da elétrica, com soldagem direta da alimentação nos pads positivo e negativo.  
- **ESP32 DevKit**: microcontrolador responsável pela lógica, comunicação Bluetooth e controle dos motores.  
- **Ponte H L298N**: driver de potência para os motores, alimentado diretamente pela bateria.  
- **Motores DC N20 com caixa de redução**: responsáveis pela tração do robô.  
- **Módulo carregador de bateria de lítio**: permite recarga da bateria sem desmontagem do robô.  
- **Buzzer ativo**: utilizado para sinalização sonora e feedback do sistema.

#### 🔋 Organização da alimentação
Nesta versão oficial, a alimentação foi organizada da seguinte forma:
- O **positivo da bateria**, após o switch, é conectado diretamente ao **pad positivo da placa de expansão**;  
- O **GND da bateria** é conectado ao **pad negativo da placa de expansão**;  
- A **placa de expansão realiza a regulação interna**, fornecendo as tensões adequadas para a ESP32;  
- A **ponte H L298N** recebe a tensão da bateria para acionamento dos motores;  
- Todos os módulos compartilham **GND comum**, garantindo referência elétrica correta.

#### 🎯 Objetivo da versão
O Circuito Teste 5 teve como objetivo final:
- Consolidar a **arquitetura elétrica definitiva** do robô;  
- Reduzir ao máximo o número de fios e pontos de falha;  
- Garantir **estabilidade elétrica durante combates**;  
- Facilitar futuras manutenções e ajustes rápidos;  
- Atender aos **requisitos de peso, espaço e confiabilidade** da competição.

Esta versão foi adotada como o **circuito oficial do robô Jack**, sendo utilizada na fase final do projeto e durante o **Torneio Interno G.E.A.R. 2025**.
