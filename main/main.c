/* Blink Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>

// freertos
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_log.h" // logging
#include "esp_sntp.h" // ntp server
#include "esp_system.h" // error handling
#include "esp_wifi.h" // wifi

#include "seven_segment.h" // 7-segment display functions
#include "helpers.h"

static const char *TAG = "clock";

int current_time = 3456;

// Display the current time!
static void display_time(void *arg) {
  while (1) {
    write_number(current_time);
  }
}

// Update the current time!
static void update_time(void *arg) {
  while (1) {
    current_time++;
    DELAY(1000);
  }
}

void app_main(void) {

  ss_init();

  /* Configure the peripheral according to the LED type */
  ESP_LOGI(TAG, "Turning the LED %llu!", LEDS);

  TaskHandle_t display_handle = NULL;
  TaskHandle_t update_handle = NULL;

  xTaskCreate(display_time, "display_time", 1024, NULL, PRIO_LOW, &display_handle);
  xTaskCreate(update_time, "update_time", 1024, NULL, PRIO_MID, &update_handle);

  while (1) {
  }
}
