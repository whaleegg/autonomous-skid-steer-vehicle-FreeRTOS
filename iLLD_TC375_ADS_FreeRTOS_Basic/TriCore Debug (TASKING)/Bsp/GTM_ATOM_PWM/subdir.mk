################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../Bsp/GTM_ATOM_PWM/Gtm_Atom_Pwm.c" 

COMPILED_SRCS += \
"Bsp/GTM_ATOM_PWM/Gtm_Atom_Pwm.src" 

C_DEPS += \
"./Bsp/GTM_ATOM_PWM/Gtm_Atom_Pwm.d" 

OBJS += \
"Bsp/GTM_ATOM_PWM/Gtm_Atom_Pwm.o" 


# Each subdirectory must supply rules for building sources it contributes
"Bsp/GTM_ATOM_PWM/Gtm_Atom_Pwm.src":"../Bsp/GTM_ATOM_PWM/Gtm_Atom_Pwm.c" "Bsp/GTM_ATOM_PWM/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/FreeRTOS/iLLD_TC375_ADS_FreeRTOS_Basic/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"Bsp/GTM_ATOM_PWM/Gtm_Atom_Pwm.o":"Bsp/GTM_ATOM_PWM/Gtm_Atom_Pwm.src" "Bsp/GTM_ATOM_PWM/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-Bsp-2f-GTM_ATOM_PWM

clean-Bsp-2f-GTM_ATOM_PWM:
	-$(RM) ./Bsp/GTM_ATOM_PWM/Gtm_Atom_Pwm.d ./Bsp/GTM_ATOM_PWM/Gtm_Atom_Pwm.o ./Bsp/GTM_ATOM_PWM/Gtm_Atom_Pwm.src

.PHONY: clean-Bsp-2f-GTM_ATOM_PWM

