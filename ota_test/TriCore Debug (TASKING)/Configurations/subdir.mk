################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../Configurations/Ifx_Cfg_Ssw.c" 

COMPILED_SRCS += \
"Configurations/Ifx_Cfg_Ssw.src" 

C_DEPS += \
"./Configurations/Ifx_Cfg_Ssw.d" 

OBJS += \
"Configurations/Ifx_Cfg_Ssw.o" 


# Each subdirectory must supply rules for building sources it contributes
"Configurations/Ifx_Cfg_Ssw.src":"../Configurations/Ifx_Cfg_Ssw.c" "Configurations/subdir.mk"
	cctc -cs --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/USER/Desktop/AURIX_WS/TC375LK_NGV/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -Wc-g3 -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"Configurations/Ifx_Cfg_Ssw.o":"Configurations/Ifx_Cfg_Ssw.src" "Configurations/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-Configurations

clean-Configurations:
	-$(RM) ./Configurations/Ifx_Cfg_Ssw.d ./Configurations/Ifx_Cfg_Ssw.o ./Configurations/Ifx_Cfg_Ssw.src

.PHONY: clean-Configurations

