################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Sort-Insertion\ Sort.cpp 

OBJS += \
./src/Sort-Insertion\ Sort.o 

CPP_DEPS += \
./src/Sort-Insertion\ Sort.d 


# Each subdirectory must supply rules for building sources it contributes
src/Sort-Insertion\ Sort.o: ../src/Sort-Insertion\ Sort.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Sort-Insertion Sort.d" -MT"src/Sort-Insertion\ Sort.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


