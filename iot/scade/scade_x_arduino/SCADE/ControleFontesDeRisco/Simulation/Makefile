#############################################################
######    Begin of Makefile
#############################################################

SCADE=C:\Program Files\Esterel Technologies\SCADE R17\SCADE\.

SHELL=cmd.exe

C_FLAGS = -pedantic

all: C:/Users/SHIGEMURA-PC/SCADE/ControleFontesDeRisco/Simulation/standalone 

win32/A661Cosim.o: ../../../../../Program\ Files/Esterel\ Technologies/SCADE\ R17/SCADE/lib/A661Cosim.c
	gcc -I"." -I"$(SCADE)" -I"$(SCADE)\include" -I"$(SCADE)\include\C" -I"$(SCADE)\include\Ada" -I"$(SCADE)\lib\Ada" -I"..\..\..\ControleFontesDeRisco" -I"..\..\..\..\..\Program Files\Esterel Technologies\SCADE R17\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -c -ansi -std=c99 -m32 "..\..\..\..\..\Program Files\Esterel Technologies\SCADE R17\SCADE\lib\A661Cosim.c" -o "win32\A661Cosim.o"

win32/Operator1_UA_1.o: Operator1_UA_1.c
	gcc -I"." -I"$(SCADE)" -I"$(SCADE)\include" -I"$(SCADE)\include\C" -I"$(SCADE)\include\Ada" -I"$(SCADE)\lib\Ada" -I"..\..\..\ControleFontesDeRisco" -I"..\..\..\..\..\Program Files\Esterel Technologies\SCADE R17\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -c -ansi -std=c99 -m32 "Operator1_UA_1.c" -o "win32\Operator1_UA_1.o"

win32/Operator1_UA_1_private.o: Operator1_UA_1_private.c
	gcc -I"." -I"$(SCADE)" -I"$(SCADE)\include" -I"$(SCADE)\include\C" -I"$(SCADE)\include\Ada" -I"$(SCADE)\lib\Ada" -I"..\..\..\ControleFontesDeRisco" -I"..\..\..\..\..\Program Files\Esterel Technologies\SCADE R17\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -c -ansi -std=c99 -m32 "Operator1_UA_1_private.c" -o "win32\Operator1_UA_1_private.o"

win32/Operator1_UA_1_LAY_1.o: Operator1_UA_1_LAY_1.c
	gcc -I"." -I"$(SCADE)" -I"$(SCADE)\include" -I"$(SCADE)\include\C" -I"$(SCADE)\include\Ada" -I"$(SCADE)\lib\Ada" -I"..\..\..\ControleFontesDeRisco" -I"..\..\..\..\..\Program Files\Esterel Technologies\SCADE R17\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -c -ansi -std=c99 -m32 "Operator1_UA_1_LAY_1.c" -o "win32\Operator1_UA_1_LAY_1.o"

win32/Operator1.o: Operator1.c
	gcc -I"." -I"$(SCADE)" -I"$(SCADE)\include" -I"$(SCADE)\include\C" -I"$(SCADE)\include\Ada" -I"$(SCADE)\lib\Ada" -I"..\..\..\ControleFontesDeRisco" -I"..\..\..\..\..\Program Files\Esterel Technologies\SCADE R17\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -c -ansi -std=c99 -m32 "Operator1.c" -o "win32\Operator1.o"

win32/kcg_types.o: kcg_types.c
	gcc -I"." -I"$(SCADE)" -I"$(SCADE)\include" -I"$(SCADE)\include\C" -I"$(SCADE)\include\Ada" -I"$(SCADE)\lib\Ada" -I"..\..\..\ControleFontesDeRisco" -I"..\..\..\..\..\Program Files\Esterel Technologies\SCADE R17\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -c -ansi -std=c99 -m32 "kcg_types.c" -o "win32\kcg_types.o"

win32/kcg_consts.o: kcg_consts.c
	gcc -I"." -I"$(SCADE)" -I"$(SCADE)\include" -I"$(SCADE)\include\C" -I"$(SCADE)\include\Ada" -I"$(SCADE)\lib\Ada" -I"..\..\..\ControleFontesDeRisco" -I"..\..\..\..\..\Program Files\Esterel Technologies\SCADE R17\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -c -ansi -std=c99 -m32 "kcg_consts.c" -o "win32\kcg_consts.o"

win32/WriteSerial.o: ../../../ControleFontesDeRisco/WriteSerial.c
	gcc -I"." -I"$(SCADE)" -I"$(SCADE)\include" -I"$(SCADE)\include\C" -I"$(SCADE)\include\Ada" -I"$(SCADE)\lib\Ada" -I"..\..\..\ControleFontesDeRisco" -I"..\..\..\..\..\Program Files\Esterel Technologies\SCADE R17\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -c -ansi -std=c99 -m32 "..\..\..\ControleFontesDeRisco\WriteSerial.c" -o "win32\WriteSerial.o"

win32/Operator1_standalone_exec.o: Operator1_standalone_exec.c
	gcc -I"." -I"$(SCADE)" -I"$(SCADE)\include" -I"$(SCADE)\include\C" -I"$(SCADE)\include\Ada" -I"$(SCADE)\lib\Ada" -I"..\..\..\ControleFontesDeRisco" -I"..\..\..\..\..\Program Files\Esterel Technologies\SCADE R17\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -c -ansi -std=c99 -m32 "Operator1_standalone_exec.c" -o "win32\Operator1_standalone_exec.o"

Operator1.exe: win32/A661Cosim.o win32/Operator1_UA_1.o win32/Operator1_UA_1_private.o win32/Operator1_UA_1_LAY_1.o win32/Operator1.o win32/kcg_types.o win32/kcg_consts.o win32/WriteSerial.o win32/Operator1_standalone_exec.o 
	gcc "win32\A661Cosim.o" "win32\Operator1_UA_1.o" "win32\Operator1_UA_1_private.o" "win32\Operator1_UA_1_LAY_1.o" "win32\Operator1.o" "win32\kcg_types.o" "win32\kcg_consts.o" "win32\WriteSerial.o" "win32\Operator1_standalone_exec.o" -lm -lwsock32 -m32 -o "Operator1.exe" 

Operator1_standalone_exec.c: Operator1_UA_1.h


C:/Users/SHIGEMURA-PC/SCADE/ControleFontesDeRisco/Simulation/standalone: Operator1.exe
	cmd.exe /c standalone.bat

#############################################################
######    End of Makefile
#############################################################
