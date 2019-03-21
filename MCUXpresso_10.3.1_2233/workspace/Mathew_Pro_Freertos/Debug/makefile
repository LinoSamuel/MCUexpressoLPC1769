################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include freertos/src/subdir.mk
-include example/src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: Mathew_Pro_Freertos.axf

# Tool invocations
Mathew_Pro_Freertos.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"/home/mathew/git/MCUexpressoLPC1769/MCUXpresso_10.3.1_2233/workspace/lpc_chip_175x_6x/Debug" -L"/home/mathew/git/MCUexpressoLPC1769/MCUXpresso_10.3.1_2233/workspace/lpc_board_nxp_lpcxpresso_1769/Debug" -Xlinker -Map="Mathew_Pro_Freertos.map" -Xlinker --gc-sections -mcpu=cortex-m3 -mthumb -T "Mathew_Pro_Freertos_Debug.ld" -o "Mathew_Pro_Freertos.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) Mathew_Pro_Freertos.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "Mathew_Pro_Freertos.axf"; # arm-none-eabi-objcopy -v -O binary "Mathew_Pro_Freertos.axf" "Mathew_Pro_Freertos.bin" ; # checksum -p LPC1769 -d "Mathew_Pro_Freertos.bin";
	-@echo ' '

.PHONY: all clean dependents post-build

-include ../makefile.targets
