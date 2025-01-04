################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Libraries/iLLD/TC37A/Tricore/_PinMap/subdir.mk
-include Libraries/iLLD/TC37A/Tricore/_Impl/subdir.mk
-include Libraries/iLLD/TC37A/Tricore/Stm/Std/subdir.mk
-include Libraries/iLLD/TC37A/Tricore/Src/Std/subdir.mk
-include Libraries/iLLD/TC37A/Tricore/Scu/Std/subdir.mk
-include Libraries/iLLD/TC37A/Tricore/Qspi/Std/subdir.mk
-include Libraries/iLLD/TC37A/Tricore/Qspi/SpiSlave/subdir.mk
-include Libraries/iLLD/TC37A/Tricore/Qspi/SpiMaster/subdir.mk
-include Libraries/iLLD/TC37A/Tricore/Port/Std/subdir.mk
-include Libraries/iLLD/TC37A/Tricore/Pms/Std/subdir.mk
-include Libraries/iLLD/TC37A/Tricore/Mtu/Std/subdir.mk
-include Libraries/iLLD/TC37A/Tricore/I2c/Std/subdir.mk
-include Libraries/iLLD/TC37A/Tricore/I2c/I2c/subdir.mk
-include Libraries/iLLD/TC37A/Tricore/Gtm/Std/subdir.mk
-include Libraries/iLLD/TC37A/Tricore/Flash/Std/subdir.mk
-include Libraries/iLLD/TC37A/Tricore/Dma/Std/subdir.mk
-include Libraries/iLLD/TC37A/Tricore/Dma/Dma/subdir.mk
-include Libraries/iLLD/TC37A/Tricore/Cpu/Trap/subdir.mk
-include Libraries/iLLD/TC37A/Tricore/Cpu/Std/subdir.mk
-include Libraries/iLLD/TC37A/Tricore/Cpu/Irq/subdir.mk
-include Libraries/Service/CpuGeneric/SysSe/Bsp/subdir.mk
-include Libraries/Service/CpuGeneric/If/subdir.mk
-include Libraries/Infra/Ssw/TC37A/Tricore/subdir.mk
-include Libraries/Infra/Platform/Tricore/Compilers/subdir.mk
-include Configurations/Debug/subdir.mk
-include Configurations/subdir.mk
-include subdir.mk
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := SPI_ST7789TFT_KIT_TC375_LK_v3
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_SIZE += \
SPI_ST7789TFT_KIT_TC375_LK_v3.siz \


# All Target
all: main-build

# Main-build Target
main-build: SPI_ST7789TFT_KIT_TC375_LK_v3.elf secondary-outputs

# Tool invocations
SPI_ST7789TFT_KIT_TC375_LK_v3.elf: $(OBJS) makefile $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: TASKING Linker'
	cctc --lsl-file="../Lcf_Tasking_Tricore_Tc.lsl" -Wl-Oc -Wl-OL -Wl-Ot -Wl-Ox -Wl-Oy -Wl--map-file="SPI_ST7789TFT_KIT_TC375_LK_v3.map" -Wl-mc -Wl-mf -Wl-mi -Wl-mk -Wl-ml -Wl-mm -Wl-md -Wl-mr -Wl-mu --no-warnings= -Wl--error-limit=42 --fp-model=3 -lrt --lsl-core=vtc --exceptions --strict --anachronisms --force-c++ -Ctc37x -o"SPI_ST7789TFT_KIT_TC375_LK_v3.elf" -Wl-o"SPI_ST7789TFT_KIT_TC375_LK_v3.hex:IHEX" $(OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

SPI_ST7789TFT_KIT_TC375_LK_v3.siz: SPI_ST7789TFT_KIT_TC375_LK_v3.elf makefile $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: Print Size'
	elfsize  "SPI_ST7789TFT_KIT_TC375_LK_v3.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) SPI_ST7789TFT_KIT_TC375_LK_v3.siz SPI_ST7789TFT_KIT_TC375_LK_v3.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_SIZE)

.PHONY: all clean dependents main-build

-include ../makefile.targets
