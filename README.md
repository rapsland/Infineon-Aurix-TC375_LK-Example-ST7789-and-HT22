This example has been created using the "https://github.com/Infineon/AURIX_code_examples/blob/master/code_examples/SPI_CPU_1_KIT_TC375_LK/.project" SPI example.
This example shows a simple implementation of ST7789 2.8" display with DHT sensor informations.
I have experimented on flashing the min max values in to PFLASH. But it has some bugs regarding format. I won't be able fix it due to other activities (christmas vacation is over).
I hope it helps them who plans to use TC3xx in his projects.

//----- Pin Definitionen für TC375_LK Board --------------------------
 TFT_BLK     &MODULE_P10,4   // GPIO für Backlight
 TFT_RST     &MODULE_P10,6   // GPIO für Reset (use arduino mikrobus)
 VCC         (7)             // arduino mikrobus 3.3v
 GND         (8)             // arduino mikrobus
 TFT_CS      &MODULE_P10,5   // SLSO (CS) für QSPI1 - Chip Select
 TFT_DC      &MODULE_P15,4   // GPIO für Data/Command
 TFT_MOSI    &MODULE_P10,3   // MTSR (MOSI) - Master Out Slave In
 TFT_MISO    &MODULE_P10,1   // MRST (MISO) - Master In Slave Out
 TFT_SCK     &MODULE_P10,2   // SCLK - Serial Clock

[Infineon-SPI_CPU_1_KIT_TC375_LK-Training-v01_01-EN.pdf](https://github.com/user-attachments/files/18309844/Infineon-SPI_CPU_1_KIT_TC375_LK-Training-v01_01-EN.pdf)

[Infineon-AURIX_TC375_lite_Kit-UserManual-v02_20-EN.pdf](https://github.com/user-attachments/files/18309845/Infineon-AURIX_TC375_lite_Kit-UserManual-v02_20-EN.pdf)

