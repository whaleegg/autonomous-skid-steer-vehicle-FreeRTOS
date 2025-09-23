################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../Flash_Programming.c" \
"../Sys_Init.c" \
"../calc.c" \
"../main.c" \
"../print.c" 

COMPILED_SRCS += \
"Flash_Programming.src" \
"Sys_Init.src" \
"calc.src" \
"main.src" \
"print.src" 

C_DEPS += \
"./Flash_Programming.d" \
"./Sys_Init.d" \
"./calc.d" \
"./main.d" \
"./print.d" 

OBJS += \
"Flash_Programming.o" \
"Sys_Init.o" \
"calc.o" \
"main.o" \
"print.o" 


# Each subdirectory must supply rules for building sources it contributes
"Flash_Programming.src":"../Flash_Programming.c" "subdir.mk"
	cctc -cs --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/USER/Desktop/AURIX_WS/TC375LK_NGV/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -Wc-g3 -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"Flash_Programming.o":"Flash_Programming.src" "subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"Sys_Init.src":"../Sys_Init.c" "subdir.mk"
	cctc -cs --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/USER/Desktop/AURIX_WS/TC375LK_NGV/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -Wc-g3 -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"Sys_Init.o":"Sys_Init.src" "subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"calc.src":"../calc.c" "subdir.mk"
	cctc -cs --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/USER/Desktop/AURIX_WS/TC375LK_NGV/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -Wc-g3 -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"calc.o":"calc.src" "subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"main.src":"../main.c" "subdir.mk"
	cctc -cs --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/USER/Desktop/AURIX_WS/TC375LK_NGV/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -Wc-g3 -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"main.o":"main.src" "subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"print.src":"../print.c" "subdir.mk"
	cctc -cs --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/USER/Desktop/AURIX_WS/TC375LK_NGV/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -Wc-g3 -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
"print.o":"print.src" "subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean--2e-

clean--2e-:
	-$(RM) ./Flash_Programming.d ./Flash_Programming.o ./Flash_Programming.src ./Sys_Init.d ./Sys_Init.o ./Sys_Init.src ./calc.d ./calc.o ./calc.src ./main.d ./main.o ./main.src ./print.d ./print.o ./print.src

.PHONY: clean--2e-

