################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Asteroid.cpp \
../Background.cpp \
../Bullet.cpp \
../Explosion.cpp \
../File.cpp \
../Game.cpp \
../GameObject.cpp \
../MenuState.cpp \
../PauseState.cpp \
../PlayState.cpp \
../Player.cpp \
../Sprite.cpp \
../main.cpp 

OBJS += \
./Asteroid.o \
./Background.o \
./Bullet.o \
./Explosion.o \
./File.o \
./Game.o \
./GameObject.o \
./MenuState.o \
./PauseState.o \
./PlayState.o \
./Player.o \
./Sprite.o \
./main.o 

CPP_DEPS += \
./Asteroid.d \
./Background.d \
./Bullet.d \
./Explosion.d \
./File.d \
./Game.d \
./GameObject.d \
./MenuState.d \
./PauseState.d \
./PlayState.d \
./Player.d \
./Sprite.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


