################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../Bsp/STM/Stm.c" 

COMPILED_SRCS += \
"Bsp/STM/Stm.src" 

C_DEPS += \
"./Bsp/STM/Stm.d" 

OBJS += \
"Bsp/STM/Stm.o" 


# Each subdirectory must supply rules for building sources it contributes
"Bsp/STM/Stm.src":"../Bsp/STM/Stm.c" "Bsp/STM/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/FreeRTOS/iLLD_TC375_ADS_FreeRTOS_Basic/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"Bsp/STM/Stm.o":"Bsp/STM/Stm.src" "Bsp/STM/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-Bsp-2f-STM

clean-Bsp-2f-STM:
	-$(RM) ./Bsp/STM/Stm.d ./Bsp/STM/Stm.o ./Bsp/STM/Stm.src

.PHONY: clean-Bsp-2f-STM

