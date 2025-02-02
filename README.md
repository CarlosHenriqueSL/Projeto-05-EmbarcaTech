# Projeto 05: **Uso de interrupções na RP2040**
**EMBARCATECH - UNIDADE 04**

## Aluno: 
- **Carlos Henrique Silva Lopes**

## **Link do vídeo de Ensaio**


## **Descrição do Projeto**
Este projeto implementa o controle de uma matriz de LEDs utilizando um Raspberry Pi Pico. O objetivo é exibir números de 0 a 9 na matriz, com a possibilidade de incrementar ou decrementar o número exibido por meio de dois botões (A e B). Além disso, o projeto também faz o acionamento um LED RGB vermelho 5 vezes por segundo. O código utiliza interrupções para detectar os pressionamentos dos botões e faz o debounce por software para evitar leituras incorretas.

## **Funcionalidades**

1. **Exibição de números na matriz de LEDs**:
   - Exibe números de 0 a 9 na matriz de LEDs.

2. **Controle por botões**:
   - Botão A: Incrementa o número exibido (0 → 1 → 2 → ... → 9).
   - Botão B: Decrementa o número exibido (9 → 8 → 7 → ... → 0).

3. **Debounce por Software**:
  - Evita leituras múltiplas ou incorretas dos botões, garantindo que apenas um pressionamento válido seja registrado, o debounce do projeto foi feito usando um intervalo de 500 ms.

4. **Interrupções GPIO**:
   - Utiliza interrupções para detectar os pressionamentos dos botões, garantindo uma resposta rápida e eficiente.
  
5. **LED de Status**:
   - Um LED vermelho pisca periodicamente (5 vezes por segundo).


## Requisitos

### Hardware
- **Raspberry Pi Pico W**
- Matriz 5x5 de LEDs (endereçáveis) WS2812
- LED RGB
- Resistor de 1kΩ para o LED RGB
- Dois botões

### Software
- **VS Code** (Visual Studio Code)
- **Pico SDK** configurado no ambiente de desenvolvimento
- Simulador **Wokwi**


## Configuração do Projeto

1. Clone este repositório para sua máquina:

   ```
   https://github.com/CarlosHenriqueSL/Projeto-05-EmbarcaTech.git
   
   ```

2. Certifique-se de que o **Pico SDK** está configurado no VS Code.

3. Abra o projeto no **VS Code** e configure os arquivos `CMakeLists.txt` adequados para compilar o código.

4. Execute o projeto no simulador **Wokwi** ou faça o upload para o hardware físico do Raspberry Pi Pico W.


## Estrutura do Código

### Principais Arquivos
- **`Interrupcoes.c:`** Contém a lógica principal para fazer o desenho dos números na matriz de LED's, interromper o código quando um botão for pressionado, fazer o debounce por software e acionar o LED RGB vermelho.
- **`diagram.json:`** Configuração física do projeto no simulador Wokwi.
- **`numeros:`** Pasta onde ficam os números à serem desenhados na matriz.
- **`README.md:`** Documentação detalhada do projeto.

### Funções Principais

#### `void iniciar()`
- Configura os pinos GPIO associados aos botões e ao LED RGB.

#### `uint32_t matrix_rgb()`
- Retorna a cor que deve aparecer nos desenhos da matriz.

#### `void desenho_pio()`
- Função que desenha os números na matriz.

#### `void gpio_irq_handler`
- Função de interrupção associada aos botões A e B.



## Testes e Validação

1. Pressione os botões e observe aa matriz de LEDs:
   - **Botão A (Botão verde)**: Deve incrementar o número que aparece na matriz de LED's.
   - **Botão B (Botão vermelho)**: Deve decrementar o número que aparece na matriz de LED's.
  
2. O LED RGB deve piscar em vermelho 5x por segundo.

2. Certifique-se de que o comportamento está de acordo com o esperado tanto no simulador quanto no hardware real.