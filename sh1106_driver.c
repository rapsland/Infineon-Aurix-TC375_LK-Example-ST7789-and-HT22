#include "sh1106_driver.h"
#include "IfxPort.h"
#include "IfxI2c_I2c.h"
#include "IfxCpu.h"
#include "IfxStm.h"
#include "font5x7.h"
#include <stdio.h> // For snprintf
// I2C configuration
static IfxI2c_I2c i2c;
static IfxI2c_I2c_Device i2cDevice;

#define SH1106_I2C_ADDR 0x3C
#define SH1106_WIDTH 130
#define SH1106_HEIGHT 64
#define SH1106_BUFFERSIZE (SH1106_WIDTH * SH1106_HEIGHT / 8)

static uint8_t sh1106_buffer[SH1106_BUFFERSIZE];

// Utility function for delays
static void delay_ms(uint32_t ms) {
    uint32_t ticksFor1ms = IfxStm_getTicksFromMilliseconds(&MODULE_STM0, 1);
    uint32_t startTime = IfxStm_get(&MODULE_STM0);
    
    while ((uint32_t)(IfxStm_get(&MODULE_STM0) - startTime) < (ticksFor1ms * ms)) {
        // Wait
    }
}

// Initialize I2C for communication
static void SH1106_InitI2C(void) {
    IfxI2c_I2c_Config i2cConfig;
    IfxI2c_I2c_initConfig(&i2cConfig, &MODULE_I2C0);

    const IfxI2c_Pins pins = {
        .scl = &IfxI2c0_SCL_P13_1_INOUT,
        .sda = &IfxI2c0_SDA_P13_2_INOUT,
        .padDriver = IfxPort_PadDriver_cmosAutomotiveSpeed1
    };
    i2cConfig.pins = &pins;
    i2cConfig.baudrate = 400000; // 400kHz

    IfxI2c_I2c_initModule(&i2c, &i2cConfig);

    IfxI2c_I2c_deviceConfig i2cDeviceConfig;
    IfxI2c_I2c_initDeviceConfig(&i2cDeviceConfig, &i2c);
    i2cDeviceConfig.deviceAddress = SH1106_I2C_ADDR << 1;

    IfxI2c_I2c_initDevice(&i2cDevice, &i2cDeviceConfig);
}

// Send command to display
static void SH1106_WriteCommand(uint8_t cmd) {
    uint8_t buffer[2] = {0x00, cmd};
    IfxI2c_I2c_write(&i2cDevice, buffer, 2);
}

// Send data to display
static void SH1106_WriteData(uint8_t data) {
    uint8_t buffer[2] = {0x40, data};
    IfxI2c_I2c_write(&i2cDevice, buffer, 2);
}

// Initialize display
void SH1106_Init(void) {
    SH1106_InitI2C();

    // Initialization sequence
    SH1106_WriteCommand(0xAE); // Display off
    SH1106_WriteCommand(0xD5); // Set display clock divide ratio/oscillator frequency
    SH1106_WriteCommand(0x80); // Set divide ratio
    SH1106_WriteCommand(0xA8); // Set multiplex ratio
    SH1106_WriteCommand(0x3F); // 1/64 duty
    SH1106_WriteCommand(0xD3); // Set display offset
    SH1106_WriteCommand(0x00); // No offset
    SH1106_WriteCommand(0x40); // Set start line address
    SH1106_WriteCommand(0x8D); // Enable charge pump regulator
    SH1106_WriteCommand(0x14);
    SH1106_WriteCommand(0x20); // Set memory addressing mode
    SH1106_WriteCommand(0x00); // Horizontal addressing mode
    SH1106_WriteCommand(0xA1); // Set segment re-map
    SH1106_WriteCommand(0xC8); // Set COM output scan direction
    SH1106_WriteCommand(0xDA); // Set COM pins hardware configuration
    SH1106_WriteCommand(0x12);
    SH1106_WriteCommand(0x81); // Set contrast control
    SH1106_WriteCommand(0xCF);
    SH1106_WriteCommand(0xD9); // Set pre-charge period
    SH1106_WriteCommand(0xF1);
    SH1106_WriteCommand(0xDB); // Set VCOMH deselect level
    SH1106_WriteCommand(0x40);
    SH1106_WriteCommand(0xA4); // Entire display ON
    SH1106_WriteCommand(0xA6); // Set normal display
    SH1106_WriteCommand(0xAF); // Display ON

    // Clear buffer
    memset(sh1106_buffer, 0, SH1106_BUFFERSIZE);    
}

// Update display with buffer contents
void SH1106_UpdateDisplay(void) {
    for (uint8_t page = 0; page < 8; page++) {
        SH1106_WriteCommand(0xB0 + page); // Set page address
        SH1106_WriteCommand(0x00); // Set lower column address
        SH1106_WriteCommand(0x10); // Set higher column address

        for (uint8_t col = 0; col < 128; col++) {
            SH1106_WriteData(sh1106_buffer[page * 128 + col]);
        }
    }
}

// Clear display
void SH1106_Clear(void) {
    memset(sh1106_buffer, 0, SH1106_BUFFERSIZE);
    SH1106_UpdateDisplay();
}

// Draw pixel
void SH1106_DrawPixel2(uint8_t x, uint8_t y, uint8_t color) {
    if (x >= 128 || y >= 64) return;

    uint16_t index = x + (y / 8) * 128;
    if (color) {
        sh1106_buffer[index] |= (1 << (y % 8));
    } else {
        sh1106_buffer[index] &= ~(1 << (y % 8));
    }

    // SH1106_WriteCommand(0xB0 + (y / 8)); // Set page address
    // SH1106_WriteCommand(0x00 + (x & 0x0F)); // Set lower column address
    // SH1106_WriteCommand(0x10 + ((x >> 4) & 0x0F)); // Set higher column address
    // SH1106_WriteData(sh1106_buffer[index]);
}

void SH1106_DrawPixel(uint8_t x, uint8_t y, uint8_t color) {
    if (x >= 128 || y >= 64) return;

    uint16_t index = x + (y / 8) * 128;
    if (color == 1) {
        sh1106_buffer[index] |= (1 << (y % 8));
    } else if (color == 0) {
        sh1106_buffer[index] &= ~(1 << (y % 8));
    } else if (color == 2) { // Invert the pixel
        sh1106_buffer[index] ^= (1 << (y % 8));
    }
}

// Draw character
void SH1106_DrawChar(uint8_t x, uint8_t y, char c) {
    if (c < ' ' || c > '~') return; // Only printable characters

    for (uint8_t i = 0; i < 5; i++) {
        uint8_t line = font5x7[c - ' '][i];
        for (uint8_t j = 0; j < 8; j++) {
            SH1106_DrawPixel(x + i, y + j, (line & 0x01));
            line >>= 1;
        }
    }
}

// Draw string
void SH1106_DrawString(uint8_t x, uint8_t y, const char *str) {
    while (*str) {
        if (x + 5 >= 128) { // Check if the next character will be out of bounds
            x = 0; // Move to the next line
            y += 8;
            if (y >= 64) break; // Stop if out of display bounds
        }
        SH1106_DrawChar(x, y, *str++);
        x += 6; // Move to the next character position
    }
}

// Draw horizontal line
void SH1106_DrawHLine(uint8_t x, uint8_t y, uint8_t w, uint8_t color) {
    for (uint8_t i = 0; i < w; i++) {
        SH1106_DrawPixel(x + i, y, color);
    }
}

// Draw vertical line
void SH1106_DrawVLine2(uint8_t x, uint8_t y, uint8_t h) {
    if (x >= 128) return; // Check x boundary
    if (y >= 64) return; // Check y boundary
    if (y + h > 64) h = 64 - y; // Adjust height if it exceeds the display boundary

    for (uint8_t i = 0; i < h; i++) {
        SH1106_DrawPixel(x, y + i, 1);
    }
}

void SH1106_DrawVLine(uint8_t x, uint8_t y, uint8_t h, uint8_t color) {
    if (x >= 128) return; // Check x boundary
    if (y >= 64) return; // Check y boundary
    if (y + h > 64) h = 64 - y; // Adjust height if it exceeds the display boundary

    for (uint8_t i = 0; i < h; i++) {
        SH1106_DrawPixel(x, y + i, color);
    }
}

// Fill rectangle
void SH1106_FillRect(uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint8_t color) {
    for (uint8_t i = 0; i < w; i++) {
        for (uint8_t j = 0; j < h; j++) {
            SH1106_DrawPixel(x + i, y + j, color);
        }
    }
}

void SH1106_RunningPixel(void) {
    uint8_t x = 0;
    uint8_t y = 0;

    while (1) {
        // Clear display
        SH1106_Clear();

        // Draw pixel at current position
        SH1106_DrawPixel(x, y, 1);

        // Update display with buffer contents
        SH1106_UpdateDisplay();

        // Delay for 100ms
        delay_ms(100);

        // Move to the next position
        x++;
        if (x >= 128) {
            x = 0;
            y++;
            if (y >= 64) {
                y = 0;
            }
        }
    }
}

void SH1106_TestDisplay(void) {
    while (1) {
        // Fill the entire display with pixels
        for (uint8_t y = 0; y < SH1106_HEIGHT; y++) {
            for (uint8_t x = 0; x < SH1106_WIDTH; x++) {
                SH1106_DrawPixel(x, y, 1);
            }
        }
        SH1106_UpdateDisplay();
        delay_ms(1000); // Wait for 1 second

        // Clear the entire display
        SH1106_Clear();
        delay_ms(1000); // Wait for 1 second
    }
}

void SH1106_DisplayStatusAndProgress2(void) {
    int8_t percentage = 0;
    int8_t direction = 1; // 1 for counting up, -1 for counting down

    while (1) {
        // Clear the area where the text will be displayed
        SH1106_FillRect(0, 0, SH1106_WIDTH, 16, 0);

        // Display status text
        char statusText[20];
        snprintf(statusText, sizeof(statusText), " Status: Flash %3d%%", percentage);
        SH1106_DrawString(0, 0, statusText);

        // Draw progress bar
        uint8_t progressBarWidth = (percentage * SH1106_WIDTH) / 100;
        SH1106_FillRect(0, 16, SH1106_WIDTH, 8, 0); // Clear the entire progress bar area
        SH1106_FillRect(0, 16, progressBarWidth, 8, 1); // Draw the new progress bar
        
        // Update display with buffer contents
        SH1106_UpdateDisplay();

        // Delay for 25ms
        delay_ms(25);

        // Update percentage
        percentage += direction;
        if (percentage >= 100) {
            percentage = 100;
            direction = -1; // Reverse direction
        } else if (percentage <= 0) {
            percentage = 0;
            direction = 1; // Reverse direction
        }
    }
}

void SH1106_DisplayStatusAndProgress(void) {
    int8_t percentage = 0;
    int8_t direction = 1; // 1 for counting up, -1 for counting down
    int8_t verifyPercentage = 0;
    int8_t verifyDirection = 1; // 1 for counting up, -1 for counting down
    uint8_t flashDone = 0;

    while (1) {
        // Clear the area where the text will be displayed
        SH1106_FillRect(0, 0, SH1106_WIDTH, 32, 0);

        // Display status text
        char statusText[25];
        if (!flashDone) {
            snprintf(statusText, sizeof(statusText), " Status: Flash %3d%%", percentage);
        } else {
            snprintf(statusText, sizeof(statusText), " Status: Flash done!");
        }
        SH1106_DrawString(0, 0, statusText);
        
        // Draw box for flashing progress bar
        SH1106_DrawHLine(0, 14, SH1106_WIDTH, 1); // Top border
        SH1106_DrawHLine(0, 25, SH1106_WIDTH, 1); // Bottom border
        SH1106_DrawVLine(1, 14, 11, 1); // Left border
        SH1106_DrawVLine(SH1106_WIDTH - 2, 14, 11, 1); // Right border

        // Draw progress bar for flashing
        uint8_t progressBarWidth = (percentage * SH1106_WIDTH) / 100;
        SH1106_FillRect(1, 16, SH1106_WIDTH-1, 8, 0); // Clear the entire progress bar area
        SH1106_FillRect(1, 16, progressBarWidth, 8, 1); // Draw the new progress bar

        // Draw marks every 10%
        for (uint8_t i = 0; i <= 10; i++) {
            uint8_t markX = (i * SH1106_WIDTH) / 10;
            if (percentage >= i * 10) {
                SH1106_DrawVLine(markX, 16, 8, 2); // Invert the mark
            } else {
                SH1106_DrawVLine(markX, 15, 2, 1); // Turn on the mark
                SH1106_DrawVLine(markX, 23, 2, 1); // Turn on the mark
            }
        }

        if (flashDone) {
            // Display verify status text
            snprintf(statusText, sizeof(statusText), " Status: Verify %3d%%", verifyPercentage);
            SH1106_DrawString(0, 29, statusText);

            // Draw box for verifying progress bar
            SH1106_DrawHLine(0, 40, SH1106_WIDTH, 1); // Top border
            SH1106_DrawHLine(0, 51, SH1106_WIDTH, 1); // Bottom border
            SH1106_DrawVLine(1, 40, 11, 1); // Left border
            SH1106_DrawVLine(SH1106_WIDTH - 2, 40, 11, 1); // Right border            

            // Draw progress bar for verifying
            uint8_t verifyProgressBarWidth = (verifyPercentage * SH1106_WIDTH) / 100;
            SH1106_FillRect(0, 42, SH1106_WIDTH-1, 8, 0); // Clear the entire progress bar area
            SH1106_FillRect(0, 42, verifyProgressBarWidth, 8, 1); // Draw the new progress bar

                    // Draw marks every 10%
            // Draw marks every 10%
            for (uint8_t i = 0; i <= 10; i++) {
                uint8_t markX2 = (i * SH1106_WIDTH) / 10;
                if (verifyPercentage >= i * 10) {
                    SH1106_DrawVLine(markX2, 42, 8, 2); // Invert the mark
                } else {
                    SH1106_DrawVLine(markX2, 41, 2, 1); // Turn on the mark
                    SH1106_DrawVLine(markX2, 49, 2, 1); // Turn on the mark
                }
            }

            // Update verify percentage
            verifyPercentage += verifyDirection;
            if (verifyPercentage >= 100) {
                verifyPercentage = 100;
                verifyDirection = -1; // Reverse direction
            } else if (verifyPercentage <= 0) {
                verifyPercentage = 0;
                verifyDirection = 1; // Reverse direction
            }
        }

        // Update display with buffer contents
        SH1106_UpdateDisplay();

        // Delay for 25ms
        delay_ms(10);

        // Update percentage
        if (!flashDone) {
            percentage += direction;
            if (percentage >= 100) {
                percentage = 100;
                direction = -1; // Reverse direction
                flashDone = 1; // Flashing done
            } else if (percentage <= 0) {
                percentage = 0;
                direction = 1; // Reverse direction
            }
        }
    }
}

void SH1106_TestAllChars(void) {
    uint8_t x = 0;
    uint8_t y = 0;

    for (char c = ' '; c <= '~'; c++) {
        SH1106_DrawChar(x, y, c);
        x += 6; // Move to the next character position
        if (x + 5 >= SH1106_WIDTH) { // Check if the next character will be out of bounds
            x = 0; // Move to the next line
            y += 8;
            if (y + 7 >= SH1106_HEIGHT) break; // Stop if out of display bounds
        }
    }

    // Update display with buffer contents
    SH1106_UpdateDisplay();
}