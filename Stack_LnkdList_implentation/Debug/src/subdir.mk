################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Expression_Conversion.cpp \
../src/LL.cpp \
../src/Stack_LnkdList_implentation.cpp \
../src/stack.cpp 

OBJS += \
./src/Expression_Conversion.o \
./src/LL.o \
./src/Stack_LnkdList_implentation.o \
./src/stack.o 

CPP_DEPS += \
./src/Expression_Conversion.d \
./src/LL.d \
./src/Stack_LnkdList_implentation.d \
./src/stack.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


