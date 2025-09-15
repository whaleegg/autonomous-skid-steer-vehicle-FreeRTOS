################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../Bsp/GPT12/Gpt12.c" 

COMPILED_SRCS += \
"Bsp/GPT12/Gpt12.src" 

C_DEPS += \
"./Bsp/GPT12/Gpt12.d" 

OBJS += \
"Bsp/GPT12/Gpt12.o" 


# Each subdirectory must supply rules for building sources it contributes
"Bsp/GPT12/Gpt12.src":"../Bsp/GPT12/Gpt12.c" "Bsp/GPT12/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/FreeRTOS/iLLD_TC375_ADS_FreeRTOS_Basic/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"Bsp/GPT12/Gpt12.o":"Bsp/GPT12/Gpt12.src" "Bsp/GPT12/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-Bsp-2f-GPT12

clean-Bsp-2f-GPT12:
	-$(RM) ./Bsp/GPT12/Gpt12.d ./Bsp/GPT12/Gpt12.o ./Bsp/GPT12/Gpt12.src

.PHONY: clean-Bsp-2f-GPT12

