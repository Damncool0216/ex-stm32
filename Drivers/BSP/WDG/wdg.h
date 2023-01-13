#ifndef __WDG_H
#define __WDG_H

#include "./SYSTEM/sys/sys.h"
#include "./BSP/LED/led.h"

extern IWDG_HandleTypeDef g_iwdg_handle;
extern WWDG_HandleTypeDef g_wwdg_handle;

void iwdg_init(uint8_t prer, uint16_t rld);
void iwdg_feed();


void wwdg_init(uint8_t ctr, uint8_t wd, uint32_t prer, uint32_t mode);

#endif