#include "buzzers.h"
#include "pico/stdlib.h"

#define BUZZER_PIN 21

void tocar_buzzer(int frequencia, int duracao)
{
    gpio_init(BUZZER_PIN);
    gpio_set_dir(BUZZER_PIN, GPIO_OUT);

    int periodo_us = 1000000 / frequencia;

    for (int i = 0; i < duracao * 1000; i += periodo_us) {
        gpio_put(BUZZER_PIN, 1);
        sleep_us(periodo_us / 2); 

        gpio_put(BUZZER_PIN, 0);
        sleep_us(periodo_us / 2); 
    }
}


void buzz_numero0(){
    tocar_buzzer(1000, 300);  
    sleep_ms(100);
    tocar_buzzer(1000, 300);   
    sleep_ms(100);       
    tocar_buzzer(1000, 300);  
    sleep_ms(100);  
    tocar_buzzer(1000, 300);  
    sleep_ms(100);     
    tocar_buzzer(1000, 300); 
}

void buzz_numero1(){
    tocar_buzzer(1000, 100);  
    sleep_ms(100);            
    tocar_buzzer(1000, 300);   
    sleep_ms(100);            
    tocar_buzzer(1000, 300);  
    sleep_ms(100);          
    tocar_buzzer(1000, 300);  
    sleep_ms(100);            
    tocar_buzzer(1000, 300);  
}

void buzz_numero2(){
    tocar_buzzer(1000, 100);  
    sleep_ms(100);            
    tocar_buzzer(1000, 100);   
    sleep_ms(100);            
    tocar_buzzer(1000, 300);  
    sleep_ms(100);          
    tocar_buzzer(1000, 300);  
    sleep_ms(100);            
    tocar_buzzer(1000, 300);    
}
void buzz_numero3(){
    tocar_buzzer(1000, 100);  
    sleep_ms(100);            
    tocar_buzzer(1000, 100);   
    sleep_ms(100);            
    tocar_buzzer(1000, 100);  
    sleep_ms(100);          
    tocar_buzzer(1000, 300);  
    sleep_ms(100);            
    tocar_buzzer(1000, 300);  
}

void buzz_numero4(){
    tocar_buzzer(1000, 100);  
    sleep_ms(100);            
    tocar_buzzer(1000, 100);   
    sleep_ms(100);            
    tocar_buzzer(1000, 100);  
    sleep_ms(100);          
    tocar_buzzer(1000, 100);  
    sleep_ms(100);            
    tocar_buzzer(1000, 300);  
}

void buzz_numero5(){
    tocar_buzzer(1000, 100);  
    sleep_ms(100);            
    tocar_buzzer(1000, 100);   
    sleep_ms(100);            
    tocar_buzzer(1000, 100);  
    sleep_ms(100);          
    tocar_buzzer(1000, 100);  
    sleep_ms(100);            
    tocar_buzzer(1000, 100);  
}

void buzz_numero6(){
    tocar_buzzer(1000, 300);  
    sleep_ms(100);            
    tocar_buzzer(1000, 100);   
    sleep_ms(100);            
    tocar_buzzer(1000, 100);  
    sleep_ms(100);          
    tocar_buzzer(1000, 100);  
    sleep_ms(100);            
    tocar_buzzer(1000, 100);  
}

void buzz_numero7(){
    tocar_buzzer(1000, 300);  
    sleep_ms(100);            
    tocar_buzzer(1000, 300);   
    sleep_ms(100);            
    tocar_buzzer(1000, 100);  
    sleep_ms(100);          
    tocar_buzzer(1000, 100);  
    sleep_ms(100);            
    tocar_buzzer(1000, 100);  
}

void buzz_numero8(){
    tocar_buzzer(1000, 300);  
    sleep_ms(100);            
    tocar_buzzer(1000, 300);   
    sleep_ms(100);            
    tocar_buzzer(1000, 300);  
    sleep_ms(100);          
    tocar_buzzer(1000, 100);  
    sleep_ms(100);            
    tocar_buzzer(1000, 100);  
}

void buzz_numero9(){
    tocar_buzzer(1000, 300);  
    sleep_ms(100);            
    tocar_buzzer(1000, 300);   
    sleep_ms(100);            
    tocar_buzzer(1000, 300);  
    sleep_ms(100);          
    tocar_buzzer(1000, 300);  
    sleep_ms(100);            
    tocar_buzzer(1000, 100);  
}