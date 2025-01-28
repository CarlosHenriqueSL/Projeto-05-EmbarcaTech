// matrix_keypad_led.c
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h" // For clock_get_hz and clk_sys
#include "desenhos/desenhos.h"

#include "pio_matrix.pio.h" // Include the autogenerated file

#define ROWS 4
#define COLS 4
#define LED_PIN 14
#define BUZZER_PIN 21

const uint8_t row_pins[ROWS] = {9, 8, 7, 6};
const uint8_t col_pins[COLS] = {5, 4, 3, 2};

double global_r = 1.0, global_g = 0.0, global_b = 0.0;
double global_intensidade = 1.0;

const char keys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};


// Função para inicializar o teclado matricial
void iniciar_teclado()
{
    for (int i = 0; i < ROWS; i++)
    {
        gpio_init(row_pins[i]);
        gpio_set_dir(row_pins[i], GPIO_OUT);
        gpio_put(row_pins[i], 1);
    }
    for (int j = 0; j < COLS; j++)
    {
        gpio_init(col_pins[j]);
        gpio_set_dir(col_pins[j], GPIO_IN);
        gpio_pull_up(col_pins[j]);
    }
}

// Função para verificar a tecla pressionada
char get_tecla()
{
    for (int i = 0; i < ROWS; i++)
    {
        gpio_put(row_pins[i], 0);
        for (int j = 0; j < COLS; j++)
        {
            if (gpio_get(col_pins[j]) == 0)
            {
                while (gpio_get(col_pins[j]) == 0)
                    ; // Aguarda a tecla ser solta
                gpio_put(row_pins[i], 1);
                return keys[i][j];
            }
        }
        gpio_put(row_pins[i], 1);
    }
    return '\0'; // Nenhuma tecla pressionada
}

uint32_t matrix_rgb(double r, double g, double b)
{
    unsigned char R = 0, G = 0, B = 0;

    R = r * 255;
    G = g * 255;
    B = b * 255;

    return (G << 24) | (R << 16) | (B << 8);
}

void desenho_pio(double *desenho, uint32_t valor_led, PIO pio, uint sm, double r, double g, double b)
{
    for (int i = 0; i < NUM_PIXELS; i++)
    {
        uint32_t valor_led = matrix_rgb(desenho[24 - i] * r, desenho[24 - i] * g, desenho[24 - i] * b);
        pio_sm_put_blocking(pio, sm, valor_led);
    }
}

// Função principal
int main()
{   
    bool condition = true;
    double intensidade;
    double r = 0.0, b = 0.0, g = 0.0;
    uint32_t valor_led;
    stdio_init_all();
    PIO pio = pio0;
    uint offset = pio_add_program(pio, &pio_matrix_program);
    uint sm = pio_claim_unused_sm(pio, true);
    pio_matrix_program_init(pio, sm, offset, LED_PIN);
    pio_sm_put_blocking(pio, sm, 0.0);

    iniciar_teclado();

    while (condition)
    {
        char tecla = get_tecla();
        switch (tecla)
        {
        case '0':
            setIntensidade(desenhomiddle1, global_intensidade);
            setIntensidade(desenhomiddle2, global_intensidade);
            setIntensidade(desenhomiddle3, global_intensidade);
            setIntensidade(desenhomiddle4, global_intensidade);
            setIntensidade(desenhomiddle5, global_intensidade);
            desenho_pio(desenhomiddle1, valor_led, pio, sm, global_r, global_g, global_b);
            sleep_ms(600);
            desenho_pio(desenhomiddle2, valor_led, pio, sm, global_r, global_g, global_b);
            sleep_ms(600);
            desenho_pio(desenhomiddle3, valor_led, pio, sm, global_r, global_g, global_b);
            sleep_ms(600);
            desenho_pio(desenhomiddle4, valor_led, pio, sm, global_r, global_g, global_b);
            sleep_ms(600);
            desenho_pio(desenhomiddle5, valor_led, pio, sm, global_r, global_g, global_b);
            sleep_ms(600);
            desenho_pio(ledsDesligados, valor_led, pio, sm, 0.0, 0.0, 0.0);
            break;
        case '1':
            setIntensidade(circulo, global_intensidade);
            setIntensidade(coracao, global_intensidade);
            setIntensidade(setaBaixo, global_intensidade);
            setIntensidade(setaCima, global_intensidade);
            setIntensidade(quadrado, global_intensidade);
            desenho_pio(circulo, valor_led, pio, sm, global_r, global_g, global_b);
            sleep_ms(600);
            desenho_pio(coracao, valor_led, pio, sm, global_r, global_g, global_b);
            sleep_ms(600);
            desenho_pio(setaBaixo, valor_led, pio, sm, global_r, global_g, global_b);
            sleep_ms(600);
            desenho_pio(setaCima, valor_led, pio, sm, global_r, global_g, global_b);
            sleep_ms(600);
            desenho_pio(quadrado, valor_led, pio, sm, global_r, global_g, global_b);
            sleep_ms(600);
            desenho_pio(ledsDesligados, valor_led, pio, sm, 0.0, 0.0, 0.0);
            break;
        case '2':
            setIntensidade(estrela, global_intensidade);
            setIntensidade(coroa, global_intensidade);
            setIntensidade(setaEsquerda, global_intensidade);
            setIntensidade(setaDireita, global_intensidade);
            setIntensidade(rosto, global_intensidade);
            desenho_pio(estrela, valor_led, pio, sm, global_r, global_g, global_b);
            sleep_ms(600);
            desenho_pio(coroa, valor_led, pio, sm, global_r, global_g, global_b);
            sleep_ms(600);
            desenho_pio(setaEsquerda, valor_led, pio, sm, global_r, global_g, global_b);
            sleep_ms(600);
            desenho_pio(setaDireita, valor_led, pio, sm, global_r, global_g, global_b);
            sleep_ms(600);
            desenho_pio(rosto, valor_led, pio, sm, global_r, global_g, global_b);
            sleep_ms(600);
            desenho_pio(ledsDesligados, valor_led, pio, sm, 0.0, 0.0, 0.0);
            break;
        case '3':
            setIntensidade(letraT, global_intensidade);
            setIntensidade(letraE, global_intensidade);
            setIntensidade(letraC, global_intensidade);
            setIntensidade(letraH, global_intensidade);
            setIntensidade(exclamacao, global_intensidade);
            desenho_pio(letraT, valor_led, pio, sm, global_r, global_g, global_b);
            sleep_ms(600);
            desenho_pio(letraE, valor_led, pio, sm, global_r, global_g, global_b);
            sleep_ms(600);
            desenho_pio(letraC, valor_led, pio, sm, global_r, global_g, global_b);
            sleep_ms(600);
            desenho_pio(letraH, valor_led, pio, sm, global_r, global_g, global_b);
            sleep_ms(600);
            desenho_pio(exclamacao, valor_led, pio, sm, global_r, global_g, global_b);
            sleep_ms(600);
            desenho_pio(ledsDesligados, valor_led, pio, sm, 0.0, 0.0, 0.0);
            break;
        case '4':
            setIntensidade(numero1, global_intensidade);
            setIntensidade(numero2, global_intensidade);
            setIntensidade(numero3, global_intensidade);
            setIntensidade(numero4, global_intensidade);
            setIntensidade(numero5, global_intensidade);
            desenho_pio(numero1, valor_led, pio, sm, global_r, global_g, global_b);
            sleep_ms(600);
            desenho_pio(numero2, valor_led, pio, sm, global_r, global_g, global_b);
            sleep_ms(600);
            desenho_pio(numero3, valor_led, pio, sm, global_r, global_g, global_b);
            sleep_ms(600);
            desenho_pio(numero4, valor_led, pio, sm, global_r, global_g, global_b);
            sleep_ms(600);
            desenho_pio(numero5, valor_led, pio, sm, global_r, global_g, global_b);
            sleep_ms(600);
            desenho_pio(ledsDesligados, valor_led, pio, sm, 0.0, 0.0, 0.0);
            break;
        case '5':
            setIntensidade(animacao_5_frame1, global_intensidade);
            setIntensidade(animacao_5_frame2, global_intensidade);
            setIntensidade(animacao_5_frame3, global_intensidade);
            setIntensidade(animacao_5_frame4, global_intensidade);
            setIntensidade(animacao_5_frame5, global_intensidade);
            desenho_pio(animacao_5_frame1, valor_led, pio, sm, global_r, global_g, global_b);
            sleep_ms(600);
            desenho_pio(animacao_5_frame2, valor_led, pio, sm, global_r, global_g, global_b);
            sleep_ms(600);
            desenho_pio(animacao_5_frame3, valor_led, pio, sm, global_r, global_g, global_b);
            sleep_ms(600);
            desenho_pio(animacao_5_frame4, valor_led, pio, sm, global_r, global_g, global_b);
            sleep_ms(600);
            desenho_pio(animacao_5_frame5, valor_led, pio, sm, global_r, global_g, global_b);
            sleep_ms(600);
            desenho_pio(ledsDesligados, valor_led, pio, sm, 0.0, 0.0, 0.0);
            break;
        case '6':
            setIntensidade(animacao_6_frame1, global_intensidade);
            setIntensidade(animacao_6_frame2, global_intensidade);
            setIntensidade(animacao_6_frame3, global_intensidade);
            setIntensidade(animacao_6_frame4, global_intensidade);
            setIntensidade(animacao_6_frame5, global_intensidade);
            desenho_pio(animacao_6_frame1, valor_led, pio, sm, global_r, global_g, global_b);
            sleep_ms(600);
            desenho_pio(animacao_6_frame2, valor_led, pio, sm, global_r, global_g, global_b);
            sleep_ms(600);
            desenho_pio(animacao_6_frame3, valor_led, pio, sm, global_r, global_g, global_b);
            sleep_ms(600);
            desenho_pio(animacao_6_frame4, valor_led, pio, sm, global_r, global_g, global_b);
            sleep_ms(600);
            desenho_pio(animacao_6_frame5, valor_led, pio, sm, global_r, global_g, global_b);
            sleep_ms(600);
            desenho_pio(ledsDesligados, valor_led, pio, sm, 0.0, 0.0, 0.0);
            break;
        case '7':
            setIntensidade(desenho_numero7a, 1.0);
            setIntensidade(desenho_numero7b, 1.0);
            setIntensidade(desenho_numero7c, 1.0);
            setIntensidade(desenho_numero7d, 1.0);
            desenho_pio(desenho_numero7a, valor_led, pio, sm, 1.0, 0.0, 0.0);
            sleep_ms(600);
            desenho_pio(desenho_numero7b, valor_led, pio, sm, 1.0, 0.0, 0.0);
            sleep_ms(600);
            desenho_pio(desenho_numero7c, valor_led, pio, sm, 1.0, 0.0, 0.0);
            sleep_ms(600);
            desenho_pio(desenho_numero7b, valor_led, pio, sm, 1.0, 0.0, 0.0);
            sleep_ms(600);
            desenho_pio(desenho_numero7d, valor_led, pio, sm, 1.0, 0.0, 0.0);
            sleep_ms(600);
            desenho_pio(ledsDesligados, valor_led, pio, sm, 0.0, 0.0, 0.0);
            break;
        case '8':
            setIntensidade(desenho_numero8a, 1.0);
            setIntensidade(desenho_numero8b, 1.0);
            setIntensidade(desenho_numero8c, 1.0);
            setIntensidade(desenho_numero8d, 1.0);
            setIntensidade(desenho_numero8e, 1.0);
            setIntensidade(desenho_numero8f, 1.0);
            desenho_pio(desenho_numero8a, valor_led, pio, sm, 0.0, 0.0, 1.0);
            sleep_ms(600);
            desenho_pio(desenho_numero8b, valor_led, pio, sm, 0.0, 0.0, 1.0);
            sleep_ms(600);
            desenho_pio(desenho_numero8c, valor_led, pio, sm, 0.0, 0.0, 1.0);
            sleep_ms(600);
            desenho_pio(desenho_numero8d, valor_led, pio, sm, 0.0, 0.0, 1.0);
            sleep_ms(600);
            desenho_pio(desenho_numero8e, valor_led, pio, sm, 0.0, 0.0, 1.0);
            sleep_ms(600);
            desenho_pio(desenho_numero8f, valor_led, pio, sm, 0.0, 0.0, 1.0);
            sleep_ms(600);
            desenho_pio(ledsDesligados, valor_led, pio, sm, 0.0, 0.0, 0.0);
            break;
        case '9':
            setIntensidade(desenhocorner1, global_intensidade);
            setIntensidade(desenhocorner2, global_intensidade);
            setIntensidade(desenhocorner3, global_intensidade);
            setIntensidade(desenhocorner4, global_intensidade);
            setIntensidade(desenhocorner5, global_intensidade);
            desenho_pio(desenhocorner1, valor_led, pio, sm, global_r, global_g, global_b);
            sleep_ms(600);
            desenho_pio(desenhocorner2, valor_led, pio, sm, global_r, global_g, global_b);
            sleep_ms(600);
            desenho_pio(desenhocorner3, valor_led, pio, sm, global_r, global_g, global_b);
            sleep_ms(600);
            desenho_pio(desenhocorner4, valor_led, pio, sm, global_r, global_g, global_b);
            sleep_ms(600);
            desenho_pio(desenhocorner5, valor_led, pio, sm, global_r, global_g, global_b);
            sleep_ms(600);
            desenho_pio(ledsDesligados, valor_led, pio, sm, 0.0, 0.0, 0.0);
            break;
        case 'A':
            desenho_pio(ledsDesligados, valor_led, pio, sm, 0.0, 0.0, 0.0);
            break;
        case 'B':
            desenho_pio(ledsLigados, valor_led, pio, sm, 0.0, 0.0, 1.0);
            while (1) {
                char tecla = get_tecla();
                if (tecla != 'B') {
                    desenho_pio(ledsDesligados, valor_led, pio, sm, 0.0, 0.0, 0.0);
                    break;
                }
            }
            break;
        case 'C':
            setIntensidade(ledsLigados, 0.8);
            desenho_pio(ledsLigados, valor_led, pio, sm, 1.0, 0.0, 0.0);
            while (1) {
                char tecla = get_tecla();
                if (tecla != 'C') {
                    desenho_pio(ledsDesligados, valor_led, pio, sm, 0.0, 0.0, 0.0);
                    break;
                }
            }
            break;
        case 'D':   
            setIntensidade(ledsLigados, 0.5);
            desenho_pio(ledsLigados, valor_led, pio, sm, 0.0, 1.0, 0.0);
            while (1) {
                char tecla = get_tecla();
                if (tecla != 'D') {
                    desenho_pio(ledsDesligados, valor_led, pio, sm, 0.0, 0.0, 0.0);
                    break;
                }
            }
            break;
        case '#':
            setIntensidade(ledsLigados, 0.2);
            desenho_pio(ledsLigados, valor_led, pio, sm, 1.0, 1.0, 1.0);
            while (1) {
                char tecla = get_tecla();
                if (tecla != '#') {
                    desenho_pio(ledsDesligados, valor_led, pio, sm, 0.0, 0.0, 0.0);
                    break;
                }
            }
            break;
        default:
            break;
        }
        sleep_ms(50);
    }
    return 0;
}