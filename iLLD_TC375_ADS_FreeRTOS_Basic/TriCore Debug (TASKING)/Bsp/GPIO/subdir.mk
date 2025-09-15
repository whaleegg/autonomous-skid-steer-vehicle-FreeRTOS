################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../Bsp/GPIO/Buzzer.c" \
"../Bsp/GPIO/Led.c" \
"../Bsp/GPIO/Switch.c" 

COMPILED_SRCS += \
"Bsp/GPIO/Buzzer.src" \
"Bsp/GPIO/Led.src" \
"Bsp/GPIO/Switch.src" 

C_DEPS += \
"./Bsp/GPIO/Buzzer.d" \
"./Bsp/GPIO/Led.d" \
"./Bsp/GPIO/Switch.d" 

OBJS += \
"Bsp/GPIO/Buzzer.o" \
"Bsp/GPIO/Led.o" \
"Bsp/GPIO/Switch.o" 


# Each subdirectory must supply rules for building sources it contributes
"Bsp/GPIO/Buzzer.src":"../Bsp/GPIO/Buzzer.c" "Bsp/GPIO/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/FreeRTOS/iLLD_TC375_ADS_FreeRTOS_Basic/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"Bsp/GPIO/Buzzer.o":"Bsp/GPIO/Buzzer.src" "Bsp/GPIO/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"Bsp/GPIO/Led.src":"../Bsp/GPIO/Led.c" "Bsp/GPIO/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/FreeRTOS/iLLD_TC375_ADS_FreeRTOS_Basic/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"Bsp/GPIO/Led.o":"Bsp/GPIO/Led.src" "Bsp/GPIO/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"Bsp/GPIO/Switch.src":"../Bsp/GPIO/Switch.c" "Bsp/GPIO/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/FreeRTOS/iLLD_TC375_ADS_FreeRTOS_Basic/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"Bsp/GPIO/Switch.o":"Bsp/GPIO/Switch.src" "Bsp/GPIO/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-Bsp-2f-GPIO

clean-Bsp-2f-GPIO:
	-$(RM) ./Bsp/GPIO/Buzzer.d ./Bsp/GPIO/Buzzer.o ./Bsp/GPIO/Buzzer.src ./Bsp/GPIO/Led.d ./Bsp/GPIO/Led.o ./Bsp/GPIO/Led.src ./Bsp/GPIO/Switch.d ./Bsp/GPIO/Switch.o ./Bsp/GPIO/Switch.src

.PHONY: clean-Bsp-2f-GPIO

