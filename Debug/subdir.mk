################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Cpu0_Main.c \
../Cpu1_Main.c \
../Cpu2_Main.c \
../DHT11.c \
../Flash_Programming.c \
../STM_System_Time.c \
../fonts.c \
../sh1106_driver.c \
../st7789_driver.c 

COMPILED_SRCS += \
Cpu0_Main.src \
Cpu1_Main.src \
Cpu2_Main.src \
DHT11.src \
Flash_Programming.src \
STM_System_Time.src \
fonts.src \
sh1106_driver.src \
st7789_driver.src 

C_DEPS += \
Cpu0_Main.d \
Cpu1_Main.d \
Cpu2_Main.d \
DHT11.d \
Flash_Programming.d \
STM_System_Time.d \
fonts.d \
sh1106_driver.d \
st7789_driver.d 

OBJS += \
Cpu0_Main.o \
Cpu1_Main.o \
Cpu2_Main.o \
DHT11.o \
Flash_Programming.o \
STM_System_Time.o \
fonts.o \
sh1106_driver.o \
st7789_driver.o 


# Each subdirectory must supply rules for building sources it contributes
Cpu0_Main.src: ../Cpu0_Main.c subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/rapsland/AURIX-v1.10.2-workspace/SPI_ST7789TFT_KIT_TC375_LK_v3/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
Cpu0_Main.o: Cpu0_Main.src subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
Cpu1_Main.src: ../Cpu1_Main.c subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/rapsland/AURIX-v1.10.2-workspace/SPI_ST7789TFT_KIT_TC375_LK_v3/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
Cpu1_Main.o: Cpu1_Main.src subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
Cpu2_Main.src: ../Cpu2_Main.c subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/rapsland/AURIX-v1.10.2-workspace/SPI_ST7789TFT_KIT_TC375_LK_v3/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
Cpu2_Main.o: Cpu2_Main.src subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
DHT11.src: ../DHT11.c subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/rapsland/AURIX-v1.10.2-workspace/SPI_ST7789TFT_KIT_TC375_LK_v3/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
DHT11.o: DHT11.src subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
Flash_Programming.src: ../Flash_Programming.c subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/rapsland/AURIX-v1.10.2-workspace/SPI_ST7789TFT_KIT_TC375_LK_v3/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
Flash_Programming.o: Flash_Programming.src subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
STM_System_Time.src: ../STM_System_Time.c subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/rapsland/AURIX-v1.10.2-workspace/SPI_ST7789TFT_KIT_TC375_LK_v3/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
STM_System_Time.o: STM_System_Time.src subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
fonts.src: ../fonts.c subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/rapsland/AURIX-v1.10.2-workspace/SPI_ST7789TFT_KIT_TC375_LK_v3/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
fonts.o: fonts.src subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
sh1106_driver.src: ../sh1106_driver.c subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/rapsland/AURIX-v1.10.2-workspace/SPI_ST7789TFT_KIT_TC375_LK_v3/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
sh1106_driver.o: sh1106_driver.src subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
st7789_driver.src: ../st7789_driver.c subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/rapsland/AURIX-v1.10.2-workspace/SPI_ST7789TFT_KIT_TC375_LK_v3/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
st7789_driver.o: st7789_driver.src subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean--2e-

clean--2e-:
	-$(RM) Cpu0_Main.d Cpu0_Main.o Cpu0_Main.src Cpu1_Main.d Cpu1_Main.o Cpu1_Main.src Cpu2_Main.d Cpu2_Main.o Cpu2_Main.src DHT11.d DHT11.o DHT11.src Flash_Programming.d Flash_Programming.o Flash_Programming.src STM_System_Time.d STM_System_Time.o STM_System_Time.src fonts.d fonts.o fonts.src sh1106_driver.d sh1106_driver.o sh1106_driver.src st7789_driver.d st7789_driver.o st7789_driver.src

.PHONY: clean--2e-

