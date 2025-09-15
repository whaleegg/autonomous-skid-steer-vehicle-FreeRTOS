################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../Drivers/src/Asclin.c" \
"../Drivers/src/Buzzer.c" \
"../Drivers/src/Encoder.c" \
"../Drivers/src/Gpt12.c" \
"../Drivers/src/Gtm_Atom_Pwm.c" \
"../Drivers/src/Led.c" \
"../Drivers/src/Stm.c" \
"../Drivers/src/Switch.c" \
"../Drivers/src/System_Init.c" \
"../Drivers/src/can_bsp.c" \
"../Drivers/src/motor_bsp.c" \
"../Drivers/src/ultrasonic_bsp.c" 

COMPILED_SRCS += \
"Drivers/src/Asclin.src" \
"Drivers/src/Buzzer.src" \
"Drivers/src/Encoder.src" \
"Drivers/src/Gpt12.src" \
"Drivers/src/Gtm_Atom_Pwm.src" \
"Drivers/src/Led.src" \
"Drivers/src/Stm.src" \
"Drivers/src/Switch.src" \
"Drivers/src/System_Init.src" \
"Drivers/src/can_bsp.src" \
"Drivers/src/motor_bsp.src" \
"Drivers/src/ultrasonic_bsp.src" 

C_DEPS += \
"./Drivers/src/Asclin.d" \
"./Drivers/src/Buzzer.d" \
"./Drivers/src/Encoder.d" \
"./Drivers/src/Gpt12.d" \
"./Drivers/src/Gtm_Atom_Pwm.d" \
"./Drivers/src/Led.d" \
"./Drivers/src/Stm.d" \
"./Drivers/src/Switch.d" \
"./Drivers/src/System_Init.d" \
"./Drivers/src/can_bsp.d" \
"./Drivers/src/motor_bsp.d" \
"./Drivers/src/ultrasonic_bsp.d" 

OBJS += \
"Drivers/src/Asclin.o" \
"Drivers/src/Buzzer.o" \
"Drivers/src/Encoder.o" \
"Drivers/src/Gpt12.o" \
"Drivers/src/Gtm_Atom_Pwm.o" \
"Drivers/src/Led.o" \
"Drivers/src/Stm.o" \
"Drivers/src/Switch.o" \
"Drivers/src/System_Init.o" \
"Drivers/src/can_bsp.o" \
"Drivers/src/motor_bsp.o" \
"Drivers/src/ultrasonic_bsp.o" 


# Each subdirectory must supply rules for building sources it contributes
"Drivers/src/Asclin.src":"../Drivers/src/Asclin.c" "Drivers/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/FreeRTOS/iLLD_TC375_ADS_FreeRTOS_Basic/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"Drivers/src/Asclin.o":"Drivers/src/Asclin.src" "Drivers/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"Drivers/src/Buzzer.src":"../Drivers/src/Buzzer.c" "Drivers/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/FreeRTOS/iLLD_TC375_ADS_FreeRTOS_Basic/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"Drivers/src/Buzzer.o":"Drivers/src/Buzzer.src" "Drivers/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"Drivers/src/Encoder.src":"../Drivers/src/Encoder.c" "Drivers/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/FreeRTOS/iLLD_TC375_ADS_FreeRTOS_Basic/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"Drivers/src/Encoder.o":"Drivers/src/Encoder.src" "Drivers/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"Drivers/src/Gpt12.src":"../Drivers/src/Gpt12.c" "Drivers/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/FreeRTOS/iLLD_TC375_ADS_FreeRTOS_Basic/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"Drivers/src/Gpt12.o":"Drivers/src/Gpt12.src" "Drivers/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"Drivers/src/Gtm_Atom_Pwm.src":"../Drivers/src/Gtm_Atom_Pwm.c" "Drivers/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/FreeRTOS/iLLD_TC375_ADS_FreeRTOS_Basic/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"Drivers/src/Gtm_Atom_Pwm.o":"Drivers/src/Gtm_Atom_Pwm.src" "Drivers/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"Drivers/src/Led.src":"../Drivers/src/Led.c" "Drivers/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/FreeRTOS/iLLD_TC375_ADS_FreeRTOS_Basic/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"Drivers/src/Led.o":"Drivers/src/Led.src" "Drivers/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"Drivers/src/Stm.src":"../Drivers/src/Stm.c" "Drivers/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/FreeRTOS/iLLD_TC375_ADS_FreeRTOS_Basic/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"Drivers/src/Stm.o":"Drivers/src/Stm.src" "Drivers/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"Drivers/src/Switch.src":"../Drivers/src/Switch.c" "Drivers/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/FreeRTOS/iLLD_TC375_ADS_FreeRTOS_Basic/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"Drivers/src/Switch.o":"Drivers/src/Switch.src" "Drivers/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"Drivers/src/System_Init.src":"../Drivers/src/System_Init.c" "Drivers/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/FreeRTOS/iLLD_TC375_ADS_FreeRTOS_Basic/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"Drivers/src/System_Init.o":"Drivers/src/System_Init.src" "Drivers/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"Drivers/src/can_bsp.src":"../Drivers/src/can_bsp.c" "Drivers/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/FreeRTOS/iLLD_TC375_ADS_FreeRTOS_Basic/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"Drivers/src/can_bsp.o":"Drivers/src/can_bsp.src" "Drivers/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"Drivers/src/motor_bsp.src":"../Drivers/src/motor_bsp.c" "Drivers/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/FreeRTOS/iLLD_TC375_ADS_FreeRTOS_Basic/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"Drivers/src/motor_bsp.o":"Drivers/src/motor_bsp.src" "Drivers/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"Drivers/src/ultrasonic_bsp.src":"../Drivers/src/ultrasonic_bsp.c" "Drivers/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/FreeRTOS/iLLD_TC375_ADS_FreeRTOS_Basic/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"Drivers/src/ultrasonic_bsp.o":"Drivers/src/ultrasonic_bsp.src" "Drivers/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-Drivers-2f-src

clean-Drivers-2f-src:
	-$(RM) ./Drivers/src/Asclin.d ./Drivers/src/Asclin.o ./Drivers/src/Asclin.src ./Drivers/src/Buzzer.d ./Drivers/src/Buzzer.o ./Drivers/src/Buzzer.src ./Drivers/src/Encoder.d ./Drivers/src/Encoder.o ./Drivers/src/Encoder.src ./Drivers/src/Gpt12.d ./Drivers/src/Gpt12.o ./Drivers/src/Gpt12.src ./Drivers/src/Gtm_Atom_Pwm.d ./Drivers/src/Gtm_Atom_Pwm.o ./Drivers/src/Gtm_Atom_Pwm.src ./Drivers/src/Led.d ./Drivers/src/Led.o ./Drivers/src/Led.src ./Drivers/src/Stm.d ./Drivers/src/Stm.o ./Drivers/src/Stm.src ./Drivers/src/Switch.d ./Drivers/src/Switch.o ./Drivers/src/Switch.src ./Drivers/src/System_Init.d ./Drivers/src/System_Init.o ./Drivers/src/System_Init.src ./Drivers/src/can_bsp.d ./Drivers/src/can_bsp.o ./Drivers/src/can_bsp.src ./Drivers/src/motor_bsp.d ./Drivers/src/motor_bsp.o ./Drivers/src/motor_bsp.src ./Drivers/src/ultrasonic_bsp.d ./Drivers/src/ultrasonic_bsp.o ./Drivers/src/ultrasonic_bsp.src

.PHONY: clean-Drivers-2f-src

