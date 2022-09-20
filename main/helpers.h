#pragma once
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define DELAY(n) (vTaskDelay(n / portTICK_PERIOD_MS))
#define PRIO_LOW (tskIDLE_PRIORITY + 1)
#define PRIO_MID (tskIDLE_PRIORITY + 2)
#define PRIO_HIGH (tskIDLE_PRIORITY + 3)