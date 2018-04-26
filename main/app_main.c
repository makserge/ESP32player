#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "app_main.h"
#include "display.h"
#include "encoder.h"

void app_main()
{
	xTaskHandle encoderTask;

    printf("Hello world!\n");
    display_init();

    display_test();

    xTaskCreate(task_encoder, "task_encoder", 2500, NULL, 5, &encoderTask);

    printf("Done11!\n");
}
