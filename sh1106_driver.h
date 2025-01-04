#ifndef SH1106_DRIVER_H
#define SH1106_DRIVER_H

#include <stdint.h>

void SH1106_Init(void);
void SH1106_Clear(void);
void SH1106_DrawPixel(uint8_t x, uint8_t y, uint8_t color);

#endif // SH1106_DRIVER_H