################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../source/3140.s 

C_SRCS += \
../source/3140_concur.c \
../source/lab4_l0.c \
../source/lab4_l1.c \
../source/lab4_x0.c \
../source/lab4_x1.c \
../source/process.c \
../source/utils.c 

OBJS += \
./source/3140.o \
./source/3140_concur.o \
./source/lab4_l0.o \
./source/lab4_l1.o \
./source/lab4_x0.o \
./source/lab4_x1.o \
./source/process.o \
./source/utils.o 

C_DEPS += \
./source/3140_concur.d \
./source/lab4_l0.d \
./source/lab4_l1.d \
./source/lab4_x0.d \
./source/lab4_x1.d \
./source/process.d \
./source/utils.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.s source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU Assembler'
	arm-none-eabi-gcc -c -x assembler-with-cpp -D__REDLIB__ -I"/Users/lukegriffiths/Documents/MCUXpressoIDE_11.5.0_7232/workspace/lab4/board" -I"/Users/lukegriffiths/Documents/MCUXpressoIDE_11.5.0_7232/workspace/lab4/source" -I"/Users/lukegriffiths/Documents/MCUXpressoIDE_11.5.0_7232/workspace/lab4" -I"/Users/lukegriffiths/Documents/MCUXpressoIDE_11.5.0_7232/workspace/lab4/drivers" -I"/Users/lukegriffiths/Documents/MCUXpressoIDE_11.5.0_7232/workspace/lab4/utilities" -I"/Users/lukegriffiths/Documents/MCUXpressoIDE_11.5.0_7232/workspace/lab4/startup" -I"/Users/lukegriffiths/Documents/MCUXpressoIDE_11.5.0_7232/workspace/lab4/CMSIS" -g3 -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -specs=redlib.specs -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/%.o: ../source/%.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MKL46Z256VLL4_cm0plus -DCPU_MKL46Z256VLL4 -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"/Users/lukegriffiths/Documents/MCUXpressoIDE_11.5.0_7232/workspace/lab4/board" -I"/Users/lukegriffiths/Documents/MCUXpressoIDE_11.5.0_7232/workspace/lab4/source" -I"/Users/lukegriffiths/Documents/MCUXpressoIDE_11.5.0_7232/workspace/lab4" -I"/Users/lukegriffiths/Documents/MCUXpressoIDE_11.5.0_7232/workspace/lab4/drivers" -I"/Users/lukegriffiths/Documents/MCUXpressoIDE_11.5.0_7232/workspace/lab4/utilities" -I"/Users/lukegriffiths/Documents/MCUXpressoIDE_11.5.0_7232/workspace/lab4/startup" -I"/Users/lukegriffiths/Documents/MCUXpressoIDE_11.5.0_7232/workspace/lab4/CMSIS" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

