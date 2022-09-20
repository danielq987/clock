#include "seven_segment.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h" // gpio

// "A" segment is rightmost bit, "B" segment is second rightmost bit, so on.
static uint32_t segments[10] = {
  0b0111111, //0
  0b0000110, //1
  0b1011011, //2
  0b1001111, //3
  0b1100110, //4 
  0b1101101, //5 
  0b1111101, //6
  0b0000111, //7
  0b1111111, //8 
  0b1101111, //9 
};

// Order of segments
static int segment_order[8] = {
  SEG_A_GPIO,
  SEG_B_GPIO,
  SEG_C_GPIO,
  SEG_D_GPIO,
  SEG_E_GPIO,
  SEG_F_GPIO,
  SEG_G_GPIO,
  SEG_DP_GPIO,
};

// Order of digits
static int digit_order[NUM_DIGITS] = {
  DIG_0_GPIO,
  DIG_1_GPIO,
  DIG_2_GPIO,
  DIG_3_GPIO,
};

void ss_init() {
	const gpio_config_t gpio_init = {
			.pin_bit_mask = LEDS,
			.mode = GPIO_MODE_OUTPUT
	};

	gpio_config(&gpio_init);

	// Reset the selector pins to 1 (they are active-low)
  for (int i = 0; i < NUM_DIGITS; i++) {
    gpio_set_level(digit_order[i], 1);
  }
}

void write_digit(int index, int digit) {
	if (digit < 0 || digit > 9) return;

	gpio_set_level(digit_order[index], 0);

	int segment_mask = segments[digit];

	for (int i = 0; i < 7; i++) {
		gpio_set_level(segment_order[i], (segment_mask >> i) & 1U ? 1 : 0);
	}

	vTaskDelay(5 / portTICK_PERIOD_MS);
	
	for (int i = 0; i < 7; i++) {
		gpio_set_level(segment_order[i], 0);
	}

	gpio_set_level(digit_order[index], 1);
}

void write_number(int num) {
	for (int i = 0; i < NUM_DIGITS; i++, num /= 10) {
		write_digit(i, num % 10);
	}
}
