################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../Bsp/ENCODER/Encoder.c" 

COMPILED_SRCS += \
"Bsp/ENCODER/Encoder.src" 

C_DEPS += \
"./Bsp/ENCODER/Encoder.d" 

OBJS += \
"Bsp/ENCODER/Encoder.o" 


# Each subdirectory must supply rules for building sources it contributes
"Bsp/ENCODER/Encoder.src":"../Bsp/ENCODER/Encoder.c" "Bsp/ENCODER/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/FreeRTOS/iLLD_TC375_ADS_FreeRTOS_Basic/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"Bsp/ENCODER/Encoder.o":"Bsp/ENCODER/Encoder.src" "Bsp/ENCODER/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-Bsp-2f-ENCODER

clean-Bsp-2f-ENCODER:
	-$(RM) ./Bsp/ENCODER/Encoder.d ./Bsp/ENCODER/Encoder.o ./Bsp/ENCODER/Encoder.src

.PHONY: clean-Bsp-2f-ENCODER

