#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h" 
#include "numeros/numeros.h"

#include "Interrupcoes.pio.h" 

#define WS2812_PIN 7
#define LED_PIN_RED 13
#define BUTTON_A_PIN 5
#define BUTTON_B_PIN 6
#define DEBOUNCE_DELAY_MS 500

double* numeros[10] = {numero0, numero1, numero2, numero3, numero4, numero5, numero6, numero7, numero8, numero9};

volatile static uint32_t last_button_press = 0;
volatile static uint current_numero = 0;


void iniciar(){
    gpio_init(LED_PIN_RED);
    gpio_set_dir(LED_PIN_RED, GPIO_OUT);

    gpio_init(BUTTON_A_PIN);
    gpio_set_dir(BUTTON_A_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_A_PIN);

    gpio_init(BUTTON_B_PIN);
    gpio_set_dir(BUTTON_B_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_B_PIN);
}

//Funções para exibir os números na matriz de leds
uint32_t matrix_rgb(double r, double g, double b) {
    unsigned char R = r * 255, G = g * 255, B = b * 255;
    return (G << 24) | (R << 16) | (B << 8);
}

void desenho_pio(double *desenho, uint32_t valor_led, PIO pio, uint sm, double r, double g, double b) {
    for (int i = 0; i < NUM_PIXELS; i++) {
        uint32_t valor_led = matrix_rgb(desenho[24 - i] * r, desenho[24 - i] * g, desenho[24 - i] * b);
        pio_sm_put_blocking(pio, sm, valor_led);
    }
}

//Função de interrupção
void gpio_irq_handler(uint gpio, uint32_t events) {

    uint32_t now = to_ms_since_boot(get_absolute_time());

    if ((now - last_button_press) < DEBOUNCE_DELAY_MS) {
        return; // Ignora pulsos muito próximos
    }
    
    last_button_press = now; // Atualiza o timestamp


    if (gpio == BUTTON_A_PIN && (events & GPIO_IRQ_EDGE_FALL)) {
        if (current_numero < 9) {
            current_numero++;
        }
    }
    else if (gpio == BUTTON_B_PIN && (events & GPIO_IRQ_EDGE_FALL)) {
        if (current_numero > 0) {
            current_numero--;
        }
    }
    
}

int main() {
    stdio_init_all();
    PIO pio = pio0;
    uint offset = pio_add_program(pio, &pio_matrix_program);
    uint sm = pio_claim_unused_sm(pio, true);
    pio_matrix_program_init(pio, sm, offset, WS2812_PIN);
    pio_sm_put_blocking(pio, sm, 0.0);

    //Acionando as funções de interrupção
    gpio_set_irq_enabled_with_callback(BUTTON_A_PIN, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler); 
    gpio_set_irq_enabled_with_callback(BUTTON_B_PIN, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
    
    iniciar();

    uint last_numero = -1;

    while (true) {
        gpio_put(LED_PIN_RED, 1);
        sleep_ms(200);
        gpio_put(LED_PIN_RED, 0);
        sleep_ms(200);
        if (current_numero != last_numero) {
            desenho_pio(numeros[current_numero], 0, pio, sm, 1.0, 0.0, 0.0);
            last_numero = current_numero;
        }
        tight_loop_contents();
        sleep_ms(50);
    }
    return 0;
}