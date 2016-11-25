#############################################################
######    Begin of Makefile
#############################################################

SCADE=C:\Program Files (x86)\Esterel Technologies\SCADE R17\SCADE\.

SHELL=cmd.exe

C_FLAGS = -pedantic

all: test.exe test.dll 

win32/A661Cosim.o: ../../../../Program\ Files\ (x86)/Esterel\ Technologies/SCADE\ R17/SCADE/lib/A661Cosim.c
	gcc -I"." -I"$(SCADE)" -I"$(SCADE)\include" -I"$(SCADE)\include\C" -I"$(SCADE)\include\Ada" -I"$(SCADE)\lib\Ada" -I"..\Socket" -I"..\..\..\..\Program Files (x86)\Esterel Technologies\SCADE R17\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -DEXTENDED_SIM -DSIM -DWIN32 -D_CONSOLE -D_MBCS -c -ansi -std=c99 -m32 "..\..\..\..\Program Files (x86)\Esterel Technologies\SCADE R17\SCADE\lib\A661Cosim.c" -o "win32\A661Cosim.o"

win32/test_cosim.o: test_cosim.c
	gcc -I"." -I"$(SCADE)" -I"$(SCADE)\include" -I"$(SCADE)\include\C" -I"$(SCADE)\include\Ada" -I"$(SCADE)\lib\Ada" -I"..\Socket" -I"..\..\..\..\Program Files (x86)\Esterel Technologies\SCADE R17\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -DEXTENDED_SIM -DSIM -DWIN32 -D_CONSOLE -D_MBCS -c -ansi -std=c99 -m32 "test_cosim.c" -o "win32\test_cosim.o"

win32/test_UA_1.o: test_UA_1.c
	gcc -I"." -I"$(SCADE)" -I"$(SCADE)\include" -I"$(SCADE)\include\C" -I"$(SCADE)\include\Ada" -I"$(SCADE)\lib\Ada" -I"..\Socket" -I"..\..\..\..\Program Files (x86)\Esterel Technologies\SCADE R17\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -DEXTENDED_SIM -DSIM -DWIN32 -D_CONSOLE -D_MBCS -c -ansi -std=c99 -m32 "test_UA_1.c" -o "win32\test_UA_1.o"

win32/test_UA_1_private.o: test_UA_1_private.c
	gcc -I"." -I"$(SCADE)" -I"$(SCADE)\include" -I"$(SCADE)\include\C" -I"$(SCADE)\include\Ada" -I"$(SCADE)\lib\Ada" -I"..\Socket" -I"..\..\..\..\Program Files (x86)\Esterel Technologies\SCADE R17\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -DEXTENDED_SIM -DSIM -DWIN32 -D_CONSOLE -D_MBCS -c -ansi -std=c99 -m32 "test_UA_1_private.c" -o "win32\test_UA_1_private.o"

win32/test_UA_1_LAY_1.o: test_UA_1_LAY_1.c
	gcc -I"." -I"$(SCADE)" -I"$(SCADE)\include" -I"$(SCADE)\include\C" -I"$(SCADE)\include\Ada" -I"$(SCADE)\lib\Ada" -I"..\Socket" -I"..\..\..\..\Program Files (x86)\Esterel Technologies\SCADE R17\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -DEXTENDED_SIM -DSIM -DWIN32 -D_CONSOLE -D_MBCS -c -ansi -std=c99 -m32 "test_UA_1_LAY_1.c" -o "win32\test_UA_1_LAY_1.o"

win32/test.o: test.c
	gcc -I"." -I"$(SCADE)" -I"$(SCADE)\include" -I"$(SCADE)\include\C" -I"$(SCADE)\include\Ada" -I"$(SCADE)\lib\Ada" -I"..\Socket" -I"..\..\..\..\Program Files (x86)\Esterel Technologies\SCADE R17\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -DEXTENDED_SIM -DSIM -DWIN32 -D_CONSOLE -D_MBCS -c -ansi -std=c99 -m32 "test.c" -o "win32\test.o"

win32/kcg_types.o: kcg_types.c
	gcc -I"." -I"$(SCADE)" -I"$(SCADE)\include" -I"$(SCADE)\include\C" -I"$(SCADE)\include\Ada" -I"$(SCADE)\lib\Ada" -I"..\Socket" -I"..\..\..\..\Program Files (x86)\Esterel Technologies\SCADE R17\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -DEXTENDED_SIM -DSIM -DWIN32 -D_CONSOLE -D_MBCS -c -ansi -std=c99 -m32 "kcg_types.c" -o "win32\kcg_types.o"

win32/kcg_consts.o: kcg_consts.c
	gcc -I"." -I"$(SCADE)" -I"$(SCADE)\include" -I"$(SCADE)\include\C" -I"$(SCADE)\include\Ada" -I"$(SCADE)\lib\Ada" -I"..\Socket" -I"..\..\..\..\Program Files (x86)\Esterel Technologies\SCADE R17\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -DEXTENDED_SIM -DSIM -DWIN32 -D_CONSOLE -D_MBCS -c -ansi -std=c99 -m32 "kcg_consts.c" -o "win32\kcg_consts.o"

win32/socket_test_snapshot.o: socket_test_snapshot.c
	gcc -I"." -I"$(SCADE)" -I"$(SCADE)\include" -I"$(SCADE)\include\C" -I"$(SCADE)\include\Ada" -I"$(SCADE)\lib\Ada" -I"..\Socket" -I"..\..\..\..\Program Files (x86)\Esterel Technologies\SCADE R17\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -DEXTENDED_SIM -DSIM -DWIN32 -D_CONSOLE -D_MBCS -c -ansi -std=c99 -m32 "socket_test_snapshot.c" -o "win32\socket_test_snapshot.o"

win32/socket_test_type.o: socket_test_type.c
	gcc -I"." -I"$(SCADE)" -I"$(SCADE)\include" -I"$(SCADE)\include\C" -I"$(SCADE)\include\Ada" -I"$(SCADE)\lib\Ada" -I"..\Socket" -I"..\..\..\..\Program Files (x86)\Esterel Technologies\SCADE R17\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -DEXTENDED_SIM -DSIM -DWIN32 -D_CONSOLE -D_MBCS -c -ansi -std=c99 -m32 "socket_test_type.c" -o "win32\socket_test_type.o"

win32/SmuPredefConv.o: ../../../../Program\ Files\ (x86)/Esterel\ Technologies/SCADE\ R17/SCADE/lib/C/SmuPredefConv.c
	gcc -I"." -I"$(SCADE)" -I"$(SCADE)\include" -I"$(SCADE)\include\C" -I"$(SCADE)\include\Ada" -I"$(SCADE)\lib\Ada" -I"..\Socket" -I"..\..\..\..\Program Files (x86)\Esterel Technologies\SCADE R17\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -DEXTENDED_SIM -DSIM -DWIN32 -D_CONSOLE -D_MBCS -c -ansi -std=c99 -m32 "..\..\..\..\Program Files (x86)\Esterel Technologies\SCADE R17\SCADE\lib\C\SmuPredefConv.c" -o "win32\SmuPredefConv.o"

win32/SmuTypes.o: ../../../../Program\ Files\ (x86)/Esterel\ Technologies/SCADE\ R17/SCADE/lib/C/SmuTypes.c
	gcc -I"." -I"$(SCADE)" -I"$(SCADE)\include" -I"$(SCADE)\include\C" -I"$(SCADE)\include\Ada" -I"$(SCADE)\lib\Ada" -I"..\Socket" -I"..\..\..\..\Program Files (x86)\Esterel Technologies\SCADE R17\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -DEXTENDED_SIM -DSIM -DWIN32 -D_CONSOLE -D_MBCS -c -ansi -std=c99 -m32 "..\..\..\..\Program Files (x86)\Esterel Technologies\SCADE R17\SCADE\lib\C\SmuTypes.c" -o "win32\SmuTypes.o"

win32/SmuLib.o: ../../../../Program\ Files\ (x86)/Esterel\ Technologies/SCADE\ R17/SCADE/lib/C/SmuLib.c
	gcc -I"." -I"$(SCADE)" -I"$(SCADE)\include" -I"$(SCADE)\include\C" -I"$(SCADE)\include\Ada" -I"$(SCADE)\lib\Ada" -I"..\Socket" -I"..\..\..\..\Program Files (x86)\Esterel Technologies\SCADE R17\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -DEXTENDED_SIM -DSIM -DWIN32 -D_CONSOLE -D_MBCS -c -ansi -std=c99 -m32 "..\..\..\..\Program Files (x86)\Esterel Technologies\SCADE R17\SCADE\lib\C\SmuLib.c" -o "win32\SmuLib.o"

win32/SmuVTable.o: ../../../../Program\ Files\ (x86)/Esterel\ Technologies/SCADE\ R17/SCADE/lib/C/SmuVTable.c
	gcc -I"." -I"$(SCADE)" -I"$(SCADE)\include" -I"$(SCADE)\include\C" -I"$(SCADE)\include\Ada" -I"$(SCADE)\lib\Ada" -I"..\Socket" -I"..\..\..\..\Program Files (x86)\Esterel Technologies\SCADE R17\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -DEXTENDED_SIM -DSIM -DWIN32 -D_CONSOLE -D_MBCS -c -ansi -std=c99 -m32 "..\..\..\..\Program Files (x86)\Esterel Technologies\SCADE R17\SCADE\lib\C\SmuVTable.c" -o "win32\SmuVTable.o"

win32/socket_test_mapping.o: socket_test_mapping.c
	gcc -I"." -I"$(SCADE)" -I"$(SCADE)\include" -I"$(SCADE)\include\C" -I"$(SCADE)\include\Ada" -I"$(SCADE)\lib\Ada" -I"..\Socket" -I"..\..\..\..\Program Files (x86)\Esterel Technologies\SCADE R17\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -DEXTENDED_SIM -DSIM -DWIN32 -D_CONSOLE -D_MBCS -c -ansi -std=c99 -m32 "socket_test_mapping.c" -o "win32\socket_test_mapping.o"

win32/tcpserver.o: ../Socket/tcpserver.c
	gcc -I"." -I"$(SCADE)" -I"$(SCADE)\include" -I"$(SCADE)\include\C" -I"$(SCADE)\include\Ada" -I"$(SCADE)\lib\Ada" -I"..\Socket" -I"..\..\..\..\Program Files (x86)\Esterel Technologies\SCADE R17\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -DEXTENDED_SIM -DSIM -DWIN32 -D_CONSOLE -D_MBCS -c -ansi -std=c99 -m32 "..\Socket\tcpserver.c" -o "win32\tcpserver.o"

win32/socket_test_interface.o: socket_test_interface.c
	gcc -I"." -I"$(SCADE)" -I"$(SCADE)\include" -I"$(SCADE)\include\C" -I"$(SCADE)\include\Ada" -I"$(SCADE)\lib\Ada" -I"..\Socket" -I"..\..\..\..\Program Files (x86)\Esterel Technologies\SCADE R17\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -DEXTENDED_SIM -DSIM -DWIN32 -D_CONSOLE -D_MBCS -c -ansi -std=c99 -m32 "socket_test_interface.c" -o "win32\socket_test_interface.o"

win32/SmuProxy.o: C:/Program\ Files\ (x86)/Esterel\ Technologies/SCADE\ R17/SCADE/lib/C/SmuProxy.c
	gcc -I"." -I"$(SCADE)" -I"$(SCADE)\include" -I"$(SCADE)\include\C" -I"$(SCADE)\include\Ada" -I"$(SCADE)\lib\Ada" -I"..\Socket" -I"..\..\..\..\Program Files (x86)\Esterel Technologies\SCADE R17\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -DEXTENDED_SIM -DSIM -DWIN32 -D_CONSOLE -D_MBCS -c -ansi -std=c99 -m32 "C:\Program Files (x86)\Esterel Technologies\SCADE R17\SCADE\lib\C\SmuProxy.c" -o "win32\SmuProxy.o"

test.dll: win32/A661Cosim.o win32/test_cosim.o win32/test_UA_1.o win32/test_UA_1_private.o win32/test_UA_1_LAY_1.o win32/test.o win32/kcg_types.o win32/kcg_consts.o win32/socket_test_snapshot.o win32/socket_test_type.o win32/SmuPredefConv.o win32/SmuTypes.o win32/SmuLib.o win32/SmuVTable.o win32/socket_test_mapping.o win32/tcpserver.o win32/socket_test_interface.o win32/SmuProxy.o SmuExport.def 
	gcc -mwindows -mwin32 -shared -static-libgcc  "win32\A661Cosim.o" "win32\test_cosim.o" "win32\test_UA_1.o" "win32\test_UA_1_private.o" "win32\test_UA_1_LAY_1.o" "win32\test.o" "win32\kcg_types.o" "win32\kcg_consts.o" "win32\socket_test_snapshot.o" "win32\socket_test_type.o" "win32\SmuPredefConv.o" "win32\SmuTypes.o" "win32\SmuLib.o" "win32\SmuVTable.o" "win32\socket_test_mapping.o" "win32\tcpserver.o" "win32\socket_test_interface.o" "win32\SmuProxy.o" -Wl,--output-def,"SmuExport.def" -lm -lwsock32 -m32 -o "test.dll" 

SmuExport.def: C:/Program\ Files\ (x86)/Esterel\ Technologies/SCADE\ R17/SCADE/lib/C/SmuExport.def
	copy "C:\Program Files (x86)\Esterel Technologies\SCADE R17\SCADE\lib\C\SmuExport.def" "SmuExport.def"

win32/test_dll.o: test_dll.c
	gcc -I"." -I"$(SCADE)" -I"$(SCADE)\include" -I"$(SCADE)\include\C" -I"$(SCADE)\include\Ada" -I"$(SCADE)\lib\Ada" -I"..\Socket" -I"..\..\..\..\Program Files (x86)\Esterel Technologies\SCADE R17\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -DEXTENDED_SIM -DSIM -DWIN32 -D_CONSOLE -D_MBCS -c -ansi -std=c99 -m32 "test_dll.c" -o "win32\test_dll.o"

win32/SmuMainWindows.o: C:/Program\ Files\ (x86)/Esterel\ Technologies/SCADE\ R17/SCADE/lib/C/SmuMainWindows.c
	gcc -I"." -I"$(SCADE)" -I"$(SCADE)\include" -I"$(SCADE)\include\C" -I"$(SCADE)\include\Ada" -I"$(SCADE)\lib\Ada" -I"..\Socket" -I"..\..\..\..\Program Files (x86)\Esterel Technologies\SCADE R17\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -DEXTENDED_SIM -DSIM -DWIN32 -D_CONSOLE -D_MBCS -c -ansi -std=c99 -m32 "C:\Program Files (x86)\Esterel Technologies\SCADE R17\SCADE\lib\C\SmuMainWindows.c" -o "win32\SmuMainWindows.o"

test.exe: win32/test_dll.o win32/SmuMainWindows.o 
	gcc "win32\test_dll.o" "win32\SmuMainWindows.o" -lm -lwsock32 -m32 -o "test.exe" 

#############################################################
######    End of Makefile
#############################################################
