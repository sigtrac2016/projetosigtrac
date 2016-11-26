#############################################################
######    Begin of Makefile
#############################################################

SCADE=C:\Program Files (x86)\Esterel Technologies\SCADE R17\SCADE\.

SHELL=cmd.exe

C_FLAGS = -pedantic

all: C:/Users/Bruna/Desktop/sp3/almost/SCADE/tutorial-arduino-display/KCG/standalone 

win32/DisplayOp.o: DisplayOp.c
	gcc -I"." -I"$(SCADE)" -I"$(SCADE)\include" -I"$(SCADE)\include\C" -I"$(SCADE)\include\Ada" -I"$(SCADE)\lib\Ada" -I".." -I"..\..\..\..\..\..\..\..\Program Files (x86)\Esterel Technologies\SCADE R17\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -c -ansi -std=c99 -m32 "DisplayOp.c" -o "win32\DisplayOp.o"

win32/kcg_types.o: kcg_types.c
	gcc -I"." -I"$(SCADE)" -I"$(SCADE)\include" -I"$(SCADE)\include\C" -I"$(SCADE)\include\Ada" -I"$(SCADE)\lib\Ada" -I".." -I"..\..\..\..\..\..\..\..\Program Files (x86)\Esterel Technologies\SCADE R17\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -c -ansi -std=c99 -m32 "kcg_types.c" -o "win32\kcg_types.o"

win32/kcg_consts.o: kcg_consts.c
	gcc -I"." -I"$(SCADE)" -I"$(SCADE)\include" -I"$(SCADE)\include\C" -I"$(SCADE)\include\Ada" -I"$(SCADE)\lib\Ada" -I".." -I"..\..\..\..\..\..\..\..\Program Files (x86)\Esterel Technologies\SCADE R17\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -c -ansi -std=c99 -m32 "kcg_consts.c" -o "win32\kcg_consts.o"

win32/temperature.o: ../temperature.c
	gcc -I"." -I"$(SCADE)" -I"$(SCADE)\include" -I"$(SCADE)\include\C" -I"$(SCADE)\include\Ada" -I"$(SCADE)\lib\Ada" -I".." -I"..\..\..\..\..\..\..\..\Program Files (x86)\Esterel Technologies\SCADE R17\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -c -ansi -std=c99 -m32 "..\temperature.c" -o "win32\temperature.o"

win32/respiratory_rate.o: ../respiratory_rate.c
	gcc -I"." -I"$(SCADE)" -I"$(SCADE)\include" -I"$(SCADE)\include\C" -I"$(SCADE)\include\Ada" -I"$(SCADE)\lib\Ada" -I".." -I"..\..\..\..\..\..\..\..\Program Files (x86)\Esterel Technologies\SCADE R17\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -c -ansi -std=c99 -m32 "..\respiratory_rate.c" -o "win32\respiratory_rate.o"

win32/oxygen_saturation.o: ../oxygen_saturation.c
	gcc -I"." -I"$(SCADE)" -I"$(SCADE)\include" -I"$(SCADE)\include\C" -I"$(SCADE)\include\Ada" -I"$(SCADE)\lib\Ada" -I".." -I"..\..\..\..\..\..\..\..\Program Files (x86)\Esterel Technologies\SCADE R17\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -c -ansi -std=c99 -m32 "..\oxygen_saturation.c" -o "win32\oxygen_saturation.o"

win32/heart_rate.o: ../heart_rate.c
	gcc -I"." -I"$(SCADE)" -I"$(SCADE)\include" -I"$(SCADE)\include\C" -I"$(SCADE)\include\Ada" -I"$(SCADE)\lib\Ada" -I".." -I"..\..\..\..\..\..\..\..\Program Files (x86)\Esterel Technologies\SCADE R17\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -c -ansi -std=c99 -m32 "..\heart_rate.c" -o "win32\heart_rate.o"

win32/DisplayOp_standalone_exec.o: DisplayOp_standalone_exec.c
	gcc -I"." -I"$(SCADE)" -I"$(SCADE)\include" -I"$(SCADE)\include\C" -I"$(SCADE)\include\Ada" -I"$(SCADE)\lib\Ada" -I".." -I"..\..\..\..\..\..\..\..\Program Files (x86)\Esterel Technologies\SCADE R17\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -c -ansi -std=c99 -m32 "DisplayOp_standalone_exec.c" -o "win32\DisplayOp_standalone_exec.o"

DisplayOp.exe: win32/DisplayOp.o win32/kcg_types.o win32/kcg_consts.o win32/temperature.o win32/respiratory_rate.o win32/oxygen_saturation.o win32/heart_rate.o win32/DisplayOp_standalone_exec.o SDY1_specification.a 
	gcc "win32\DisplayOp.o" "win32\kcg_types.o" "win32\kcg_consts.o" "win32\temperature.o" "win32\respiratory_rate.o" "win32\oxygen_saturation.o" "win32\heart_rate.o" "win32\DisplayOp_standalone_exec.o" "SDY1_specification.a" -lm -lwsock32 -m32 -o "DisplayOp.exe" 

SDY1_specification.a: SDY1_specification.h


DisplayOp_standalone_exec.c: SDY1_specification.h


C:/Users/Bruna/Desktop/sp3/almost/SCADE/tutorial-arduino-display/KCG/standalone: DisplayOp.exe
	cmd.exe /c standalone.bat

#############################################################
######    End of Makefile
#############################################################
