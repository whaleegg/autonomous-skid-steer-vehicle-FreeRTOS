################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../OS/FreeRTOS/portable/Tasking/TC3/port.c" 

COMPILED_SRCS += \
"OS/FreeRTOS/portable/Tasking/TC3/port.src" 

C_DEPS += \
"./OS/FreeRTOS/portable/Tasking/TC3/port.d" 

OBJS += \
"OS/FreeRTOS/portable/Tasking/TC3/port.o" 


# Each subdirectory must supply rules for building sources it contributes
"OS/FreeRTOS/portable/Tasking/TC3/port.src":"../OS/FreeRTOS/portable/Tasking/TC3/port.c" "OS/FreeRTOS/portable/Tasking/TC3/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/FreeRTOS/iLLD_TC375_ADS_FreeRTOS_Basic/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"OS/FreeRTOS/portable/Tasking/TC3/port.o":"OS/FreeRTOS/portable/Tasking/TC3/port.src" "OS/FreeRTOS/portable/Tasking/TC3/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-OS-2f-FreeRTOS-2f-portable-2f-Tasking-2f-TC3

clean-OS-2f-FreeRTOS-2f-portable-2f-Tasking-2f-TC3:
	-$(RM) ./OS/FreeRTOS/portable/Tasking/TC3/port.d ./OS/FreeRTOS/portable/Tasking/TC3/port.o ./OS/FreeRTOS/portable/Tasking/TC3/port.src

.PHONY: clean-OS-2f-FreeRTOS-2f-portable-2f-Tasking-2f-TC3

