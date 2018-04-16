#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "app_main.h"
#include "ucg_esp32_hal.h"

ucg_t ucg;

void display_init()
{
	printf("display_init\n");

	ucg_esp32_hal_t ucg_esp32_hal = UCG_ESP32_HAL_DEFAULT;
	ucg_esp32_hal.clk   = PIN_OLED_CLK;
	ucg_esp32_hal.mosi  = PIN_OLED_MOSI;
	ucg_esp32_hal.cs    = PIN_OLED_CS;
	ucg_esp32_hal.dc    = PIN_OLED_A0;
	ucg_esp32_hal.reset = PIN_OLED_RST;

	ucg_esp32_hal_init(ucg_esp32_hal);

	ucg_Init(&ucg, ucg_dev_ssd1331_18x96x64_univision, ucg_ext_ssd1331_18, ucg_com_hal);
}

void app_main()
{
    printf("Hello world!\n");
    display_init();

    ucg_SetFontMode(&ucg, UCG_FONT_MODE_TRANSPARENT);
    ucg_ClearScreen(&ucg);
    ucg_SetFontPosTop(&ucg);

    ucg_SetFont(&ucg, ucg_font_4x6_mf);
    const char *str = "Hello";
    ucg_DrawString(&ucg, 0, 0, 0, str);

    printf("Done5!\n");
}
