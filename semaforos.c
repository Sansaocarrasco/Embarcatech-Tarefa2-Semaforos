#include <stdio.h>
#include "pico/stdlib.h"

#define RED_LED_PIN 11
#define YELLOW_LED_PIN 12
#define GREEN_LED_PIN 13

#define TIMER_DELAY_MS 3000 //Delay de 3 segundos

struct repeating_timer timer;
volatile int led_state = 0;  // Estado atual do LED

// Função de callback do temporizador
bool repeating_timer_callback(struct repeating_timer *t) {
    // Desliga todos os LEDs antes de mudar para o próximo
    gpio_put(RED_LED_PIN, false);
    gpio_put(YELLOW_LED_PIN, false);
    gpio_put(GREEN_LED_PIN, false);

    // Alterna entre os LEDs
    if (led_state == 0) {
        gpio_put(RED_LED_PIN, true);
    } else if (led_state == 1) {
        gpio_put(YELLOW_LED_PIN, true);
    } else if (led_state == 2) {
        gpio_put(GREEN_LED_PIN, true);
    }

    // Atualiza o estado para o próximo LED
    led_state = (led_state + 1) % 3;
    
    return true;  // Mantém o timer rodando
}

int main() {
  stdio_init_all();

  // Inicializando os LEDs
  gpio_init(RED_LED_PIN);
  gpio_set_dir(RED_LED_PIN, GPIO_OUT);

  gpio_init(YELLOW_LED_PIN);
  gpio_set_dir(YELLOW_LED_PIN, GPIO_OUT);

  gpio_init(GREEN_LED_PIN);
  gpio_set_dir(GREEN_LED_PIN, GPIO_OUT);

  // Configurando o temporizador para chamar a função a cada 3 segundos
  add_repeating_timer_ms(TIMER_DELAY_MS, repeating_timer_callback, NULL, &timer);
  
  while (true) {
        printf("Executando... LED atual: %d\n", led_state);
        sleep_ms(1000);
    }
}