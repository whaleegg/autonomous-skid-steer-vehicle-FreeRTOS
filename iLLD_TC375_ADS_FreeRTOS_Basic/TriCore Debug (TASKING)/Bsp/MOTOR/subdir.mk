################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../Bsp/MOTOR/motor_bsp.c" 

COMPILED_SRCS += \
"Bsp/MOTOR/motor_bsp.src" 

C_DEPS += \
"./Bsp/MOTOR/motor_bsp.d" 

OBJS += \
"Bsp/MOTOR/motor_bsp.o" 


# Each subdirectory must supply rules for building sources it contributes
"Bsp/MOTOR/motor_bsp.src":"../Bsp/MOTOR/motor_bsp.c" "Bsp/MOTOR/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/FreeRTOS/iLLD_TC375_ADS_FreeRTOS_Basic/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"Bsp/MOTOR/motor_bsp.o":"Bsp/MOTOR/motor_bsp.src" "Bsp/MOTOR/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-Bsp-2f-MOTOR

clean-Bsp-2f-MOTOR:
	-$(RM) ./Bsp/MOTOR/motor_bsp.d ./Bsp/MOTOR/motor_bsp.o ./Bsp/MOTOR/motor_bsp.src

.PHONY: clean-Bsp-2f-MOTOR

