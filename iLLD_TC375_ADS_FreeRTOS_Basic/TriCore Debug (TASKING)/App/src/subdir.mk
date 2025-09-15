################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../App/src/App_Led1.c" \
"../App/src/App_Led2.c" \
"../App/src/can_task.c" \
"../App/src/encoder_task.c" \
"../App/src/parking_task.c" \
"../App/src/switch_motor_task.c" 

COMPILED_SRCS += \
"App/src/App_Led1.src" \
"App/src/App_Led2.src" \
"App/src/can_task.src" \
"App/src/encoder_task.src" \
"App/src/parking_task.src" \
"App/src/switch_motor_task.src" 

C_DEPS += \
"./App/src/App_Led1.d" \
"./App/src/App_Led2.d" \
"./App/src/can_task.d" \
"./App/src/encoder_task.d" \
"./App/src/parking_task.d" \
"./App/src/switch_motor_task.d" 

OBJS += \
"App/src/App_Led1.o" \
"App/src/App_Led2.o" \
"App/src/can_task.o" \
"App/src/encoder_task.o" \
"App/src/parking_task.o" \
"App/src/switch_motor_task.o" 


# Each subdirectory must supply rules for building sources it contributes
"App/src/App_Led1.src":"../App/src/App_Led1.c" "App/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/FreeRTOS/iLLD_TC375_ADS_FreeRTOS_Basic/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"App/src/App_Led1.o":"App/src/App_Led1.src" "App/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"App/src/App_Led2.src":"../App/src/App_Led2.c" "App/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/FreeRTOS/iLLD_TC375_ADS_FreeRTOS_Basic/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"App/src/App_Led2.o":"App/src/App_Led2.src" "App/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"App/src/can_task.src":"../App/src/can_task.c" "App/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/FreeRTOS/iLLD_TC375_ADS_FreeRTOS_Basic/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"App/src/can_task.o":"App/src/can_task.src" "App/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"App/src/encoder_task.src":"../App/src/encoder_task.c" "App/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/FreeRTOS/iLLD_TC375_ADS_FreeRTOS_Basic/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"App/src/encoder_task.o":"App/src/encoder_task.src" "App/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"App/src/parking_task.src":"../App/src/parking_task.c" "App/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/FreeRTOS/iLLD_TC375_ADS_FreeRTOS_Basic/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"App/src/parking_task.o":"App/src/parking_task.src" "App/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"App/src/switch_motor_task.src":"../App/src/switch_motor_task.c" "App/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/FreeRTOS/iLLD_TC375_ADS_FreeRTOS_Basic/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"App/src/switch_motor_task.o":"App/src/switch_motor_task.src" "App/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-App-2f-src

clean-App-2f-src:
	-$(RM) ./App/src/App_Led1.d ./App/src/App_Led1.o ./App/src/App_Led1.src ./App/src/App_Led2.d ./App/src/App_Led2.o ./App/src/App_Led2.src ./App/src/can_task.d ./App/src/can_task.o ./App/src/can_task.src ./App/src/encoder_task.d ./App/src/encoder_task.o ./App/src/encoder_task.src ./App/src/parking_task.d ./App/src/parking_task.o ./App/src/parking_task.src ./App/src/switch_motor_task.d ./App/src/switch_motor_task.o ./App/src/switch_motor_task.src

.PHONY: clean-App-2f-src

