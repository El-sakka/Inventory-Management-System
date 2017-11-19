################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Inventory\ Management\ System.cpp 

OBJS += \
./Inventory\ Management\ System.o 

CPP_DEPS += \
./Inventory\ Management\ System.d 


# Each subdirectory must supply rules for building sources it contributes
Inventory\ Management\ System.o: ../Inventory\ Management\ System.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"Inventory Management System.d" -MT"Inventory\ Management\ System.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


