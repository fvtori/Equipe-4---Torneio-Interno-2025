# Diretório de Simulação (OPCIONAL)

A simulação é preferencialmente feita utilizando o software [Webots](https://cyberbotics.com/), mas é livre de sua escolha.

A simulação do robô é opcional, mas caso queira utilizar, neste diretório deve conter todos os arquivos relacionados à simulação do robô seguidor de linha, incluindo:

- Modelos de simulação
- Arquivos de mundo/ambiente
- Controladores para simulação
- Configurações de simulação
- Resultados e logs de simulação
- Scripts de teste automatizado

## Ambiente de Simulação

Este template é preparado para usar simuladores como:
- Webots
- Gazebo
- CoppeliaSim (V-REP)

## Estrutura Sugerida

- `worlds/`: Ambientes de simulação
- `controllers/`: Códigos dos controladores
- `models/`: Modelos 3D para simulação
- `configs/`: Arquivos de configuração
- `results/`: Resultados e logs de simulação

## Boas Práticas

1. Mantenha os ambientes de simulação compatíveis com o robô real
2. Documente as configurações de simulação neste README
3. Mantenha scripts de teste automatizados
4. Compare resultados com o robô real
5. Documente limitações conhecidas da simulação
