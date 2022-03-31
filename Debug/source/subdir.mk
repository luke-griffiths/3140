################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../source/3140.s 

C_SRCS += \
../source/3140_concur.c \
../source/lock.c \
../source/process.c \
../source/testl2.c \
../source/utils.c 

OBJS += \
./source/3140.o \
./source/3140_concur.o \
./source/lock.o \
./source/process.o \
./source/testl2.o \
./source/utils.o 

C_DEPS += \
./source/3140_concur.d \
./source/lock.d \
./source/process.d \
./source/testl2.d \
./source/utils.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.s source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU Assembler'
	arm-none-eabi-gcc -c -x assembler-with-cpp -D__REDLIB__ -I"/Users/tuckerstanley/Desktop/CS 3420/3140/board" -I"/Users/tuckerstanley/Desktop/CS 3420/3140/source" -I"/Users/tuckerstanley/Desktop/CS 3420/3140" -I"/Users/tuckerstanley/Desktop/CS 3420/3140/drivers" -I"/Users/tuckerstanley/Desktop/CS 3420/3140/utilities" -I"/Users/tuckerstanley/Desktop/CS 3420/3140/startup" -I"/Users/tuckerstanley/Desktop/CS 3420/3140/CMSIS" -g3 -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -specs=redlib.specs -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/%.o: ../source/%.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MKL46Z256VLL4_cm0plus -DCPU_MKL46Z256VLL4 -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"/Users/tuckerstanley/Desktop/CS 3420/3140/board" -I"/Users/tuckerstanley/Desktop/CS 3420/3140/source" -I"/Users/tuckerstanley/Desktop/CS 3420/3140" -I"/Users/tuckerstanley/Desktop/CS 3420/3140/drivers" -I"/Users/tuckerstanley/Desktop/CS 3420/3140/utilities" -I"/Users/tuckerstanley/Desktop/CS 3420/3140/startup" -I"/Users/tuckerstanley/Desktop/CS 3420/3140/CMSIS" -O0 -fno-common -g3 -Wall -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


