################################################################################
# MRS Version: 1.9.1
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/app.c \
../User/ch32v00x_it.c \
../User/led.c \
../User/main.c \
../User/system_ch32v00x.c 

OBJS += \
./User/app.o \
./User/ch32v00x_it.o \
./User/led.o \
./User/main.o \
./User/system_ch32v00x.o 

C_DEPS += \
./User/app.d \
./User/ch32v00x_it.d \
./User/led.d \
./User/main.d \
./User/system_ch32v00x.d 


# Each subdirectory must supply rules for building sources it contributes
User/%.o: ../User/%.c
	@	@	riscv-none-embed-gcc -march=rv32ecxw -mabi=ilp32e -msmall-data-limit=0 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Andre\PROJECTS\FRANZININHO\Projeto-Natal-2023\Projeto-Andre-Arvore-3D\SOFTWARE\Arvore-3D\Debug" -I"C:\Andre\PROJECTS\FRANZININHO\Projeto-Natal-2023\Projeto-Andre-Arvore-3D\SOFTWARE\Arvore-3D\Core" -I"C:\Andre\PROJECTS\FRANZININHO\Projeto-Natal-2023\Projeto-Andre-Arvore-3D\SOFTWARE\Arvore-3D\User" -I"C:\Andre\PROJECTS\FRANZININHO\Projeto-Natal-2023\Projeto-Andre-Arvore-3D\SOFTWARE\Arvore-3D\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

