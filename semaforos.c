#include <stdio.h>
#include "pico/stdlib.h"

#define RED_LED_PIN 11
#define BLUE_LED_PIN 12
#define GREEN_LED_PIN 13

#define TIMER_DELAY_MS 3000 //Delay de 3 segundos

struct repeating_timer timer;
volatile int led_state = 0;  // Estado atual do LED

// Função de callback do temporizador
bool repeating_timer_callback(struct repeating_timer *t) {
    // Desliga todos os LEDs antes de mudar para o próximo
    gpio_put(RED_LED_PIN, false);
    gpio_put(GREEN_LED_PIN, false);
    gpio_put(BLUE_LED_PIN, false);

    // Alterna entre as cores
    if (led_state == 0) {
        // Vermelho
        gpio_put(BLUE_LED_PIN, false);
        gpio_put(GREEN_LED_PIN, true);
        gpio_put(RED_LED_PIN, false);
    } else if (led_state == 1) {
        // Amarelo = Vermelho + Verde
        gpio_put(RED_LED_PIN, true);
        gpio_put(GREEN_LED_PIN, true);
        gpio_put(BLUE_LED_PIN, false);  // Certifique-se de desligar o azul
        
    } else if (led_state == 2) {
        // Verde
        gpio_put(RED_LED_PIN, true);
        gpio_put(GREEN_LED_PIN, false);
        gpio_put(BLUE_LED_PIN, false);
    }

    // Atualiza o estado para o próximo LED
    led_state = (led_state + 1) % 3;
    
    return true;  // Mantém o timer rodando
}

int main() {
    stdio_init_all();

    // Inicializando os pinos dos LEDs RGB
    gpio_init(RED_LED_PIN);
    gpio_set_dir(RED_LED_PIN, GPIO_OUT);

    gpio_init(GREEN_LED_PIN);
    gpio_set_dir(GREEN_LED_PIN, GPIO_OUT);

    gpio_init(BLUE_LED_PIN);
    gpio_set_dir(BLUE_LED_PIN, GPIO_OUT);

    // Configurando o temporizador para chamar a função a cada 3 segundos
    add_repeating_timer_ms(TIMER_DELAY_MS, repeating_timer_callback, NULL, &timer);
  
    while (true) {
        printf("Executando... O LED atual eh: %d\n", led_state);
        sleep_ms(1000);  // Atraso de 1 segundo para exibir o estado
    }
}
