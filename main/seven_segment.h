#pragma once
#include <stdint.h>

extern int current_time;

// GPIO pin configuration
#define SEG_A_GPIO 13 // 11
#define SEG_B_GPIO 14 // 7
#define SEG_C_GPIO 18 // 4
#define SEG_D_GPIO 19 // 2
#define SEG_E_GPIO 21 // 1
#define SEG_F_GPIO 22 // 10
#define SEG_G_GPIO 23 //5
#define SEG_DP_GPIO 25 //3
#define DIG_0_GPIO 26 // 6
#define DIG_1_GPIO 27 // 8
#define DIG_2_GPIO 32 // 9
#define DIG_3_GPIO 33 // 12

#define NUM_DIGITS 4

#define LEDS ((1ULL << SEG_A_GPIO) |\
(1ULL << SEG_B_GPIO) |\
(1ULL << SEG_C_GPIO) |\
(1ULL << SEG_D_GPIO) |\
(1ULL << SEG_E_GPIO) |\
(1ULL << SEG_F_GPIO) |\
(1ULL << SEG_G_GPIO) |\
(1ULL << SEG_DP_GPIO) |\
(1ULL << DIG_0_GPIO) |\
(1ULL << DIG_1_GPIO) |\
(1ULL << DIG_2_GPIO) |\
(1ULL << DIG_3_GPIO))

void ss_init();

// Displays a single digit
//  int index: location of 7 segment display to write to (0-3)
//  int digit: digit to write (0-9)
void write_digit(int index, int digit);

// Displays 4 least significant digits of num
//   int num: number to display
void write_number(int num);
