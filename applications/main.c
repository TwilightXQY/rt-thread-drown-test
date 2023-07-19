/*
 * Copyright (c) 2006-2020, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2020-09-02     RT-Thread    first version
 */

#include <rtthread.h>
#include <rtdevice.h>
#include "drv_common.h"
#include "drv_spi_ili9488.h"
#include <lcd_spi_port.h>
#define LED_PIN GET_PIN(I, 8)

struct rt_event ov2640_event;
extern int rt_gc0328c_init(void);
extern void DCMI_Start(void);
extern rt_uint8_t *img_Gray_p;
extern rt_uint8_t img_Gray[240][320];
extern int if_Drown(rt_uint8_t array_in_320X240[][320]);

int main(void)
{
    rt_pin_mode(LED_PIN, PIN_MODE_OUTPUT);
    /* init spi data notify event */
    rt_event_init(&ov2640_event, "ov2640", RT_IPC_FLAG_FIFO);
    struct drv_lcd_device *lcd;
    lcd = (struct drv_lcd_device *)rt_device_find("lcd");
    struct rt_device_rect_info rect_info = {0, 0, LCD_WIDTH, 240};
    rt_gc0328c_init();
    DCMI_Start();


    while(1)
    {
        rt_event_recv(&ov2640_event,
                            1,
                            RT_EVENT_FLAG_AND | RT_EVENT_FLAG_CLEAR,
                            RT_WAITING_FOREVER,
                            RT_NULL);
        lcd->parent.control(&lcd->parent, RTGRAPHIC_CTRL_RECT_UPDATE, &rect_info);
        if_Drown(img_Gray);
    }
    return RT_EOK;
}

#include "stm32h7xx.h"
static int vtor_config(void)
{
   /* Vector Table Relocation in Internal QSPI_FLASH */
   SCB->VTOR = QSPI_BASE;
   return 0;
}
INIT_BOARD_EXPORT(vtor_config);


