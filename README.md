# Tarefa 2: Semaforos

## 📌Introdução
Este projeto implementa um semáforo utilizando a função `add_repeating_timer_ms()` do Pico SDK, com temporização de 3 segundos para cada alteração de sinal.

## 🛠 Componentes Utilizados
A tarefa requer os seguintes componentes conectados à placa **BitDogLab**:

| Componente                  | Conexão à GPIO |
|-----------------------------|---------------|
| 1 LED RGB (vermelho, amarelo e verde)     | GPIOs 11, 12, 13 |
| 3 Resistores de 330 Ω                     | GPIO 5        |

## 💻 Simulação no Wokwi

A configuração sugerida para a simulação no Wokwi é apresentada abaixo:

https://wokwi.com/projects/421636014432418817

*Fonte: autor*

## 📌 Requisitos da Atividade

1. O acionamento dos LEDs (sinais do semáforo) inicia na cor vermelha, conforme o fluxograma, alterando para amarela e, em seguida, verde.
2. O temporizador é ajustado para um atraso de 3 segundos (3.000 ms).
3. A mudança de estado dos LEDs é implementada na função de callback do temporizador, similar à rotina `repeating_timer_callback()`.
4. A rotina principal, dentro da estrutura de repetição `while`, imprime uma mensagem a cada segundo (1.000 ms) via porta serial.
5. Utilizando a Ferramenta Educacional BitDogLab, foi realizado um experimento com o código deste exercício utilizando o LED RGB nos GPIOs 11, 12 e 13.

## 🚦 Instruções de Uso

1. Clone este repositório:
   ```sh
   git clone https://github.com/Sansaocarrasco/Embarcatech-Tarefa2-Semaforos.git
   
2. Abra o projeto no VS Code.

3. Conecte a placa Raspberry Pi Pico W ao computador no modo BOOTSEL (pressionando o botão BOOTSEL ao conectar via USB).

4. Compile e o arquivo "semaforos.c" e carregue o projeto para a placa.

## 🎥 Vídeo Demonstrativo

Um vídeo associado a esta prática pode ser acessado no link a seguir:

[Vídeo Demonstrativo](adicionar o video da simulação)

*Fonte: autor*

## 📜 Licença

Este projeto está licenciado sob a Licença MIT. Veja o arquivo [LICENSE](LICENSE) para mais detalhes.
