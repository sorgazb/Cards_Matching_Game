################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Main.cpp \
../src/TAD\ Baraja.cpp \
../src/TAD\ Carta.cpp \
../src/TAD\ Juego.cpp \
../src/TAD\ Tablero.cpp \
../src/entorno.cpp \
../src/pr_TAD\ Tablero.cpp \
../src/pr_TADBaraja.cpp \
../src/pr_TADCarta.cpp 

OBJS += \
./src/Main.o \
./src/TAD\ Baraja.o \
./src/TAD\ Carta.o \
./src/TAD\ Juego.o \
./src/TAD\ Tablero.o \
./src/entorno.o \
./src/pr_TAD\ Tablero.o \
./src/pr_TADBaraja.o \
./src/pr_TADCarta.o 

CPP_DEPS += \
./src/Main.d \
./src/TAD\ Baraja.d \
./src/TAD\ Carta.d \
./src/TAD\ Juego.d \
./src/TAD\ Tablero.d \
./src/entorno.d \
./src/pr_TAD\ Tablero.d \
./src/pr_TADBaraja.d \
./src/pr_TADCarta.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/TAD\ Baraja.o: ../src/TAD\ Baraja.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/TAD Baraja.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/TAD\ Carta.o: ../src/TAD\ Carta.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/TAD Carta.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/TAD\ Juego.o: ../src/TAD\ Juego.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/TAD Juego.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/TAD\ Tablero.o: ../src/TAD\ Tablero.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/TAD Tablero.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/pr_TAD\ Tablero.o: ../src/pr_TAD\ Tablero.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/pr_TAD Tablero.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


