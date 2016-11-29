@cd "C:/Users/SHIGEMURA-PC/TS08-Drone/TS08-Drone/Simulation"
@set OCAMLRUNPARAM=b
"C:/Program Files/Esterel Technologies/SCADE R17/SCADE/bin/uaadaptor.exe" -sdy "C:\Users\SHIGEMURA-PC\TS08-Drone\TS08-Drone\TS08-Drone.sdy" -n "C:\Program Files\Esterel Technologies\SCADE R17\SCADE Display\config\a661_description\a661.xml" -outdir "C:/Users/SHIGEMURA-PC/TS08-Drone/TS08-Drone/Simulation" -k "C:/Users/SHIGEMURA-PC/TS08-Drone/TS08-Drone/Simulation/kcg_trace.xml" -o "StatusControl_UA_1" -i "TS08-Drone_interface.h"  -encoding "ASCII"  "C:\Users\SHIGEMURA-PC\TS08-Drone\UADF.sgfx"
@IF ERRORLEVEL 1 GOTO failed
@move "StatusControl_UA_1.log" "StatusControl_UA_1_uaadaptor.log"
"C:\Program Files\Esterel Technologies\SCADE R17\SCADE Display\bin\ScadeDisplayConsole.exe" batch generate "C:\Users\SHIGEMURA-PC\TS08-Drone\TS08-Drone.etp" -conf "DF Generation" -source "UADF.sgfx" -outdir "C:/Users/SHIGEMURA-PC/TS08-Drone/TS08-Drone/Simulation" -prefix "StatusControl_UA_1"
@IF ERRORLEVEL 1 GOTO failed
@move "StatusControl_UA_1.log" "StatusControl_UA_1_dfgen.log"
"C:\Program Files\Esterel Technologies\SCADE R17\SCADE Display\bin\ScadeDisplayConsole.exe" batch  generateServerConf "C:\Users\SHIGEMURA-PC\TS08-Drone\TS08-Drone.etp" -spec "UADF.sgfx" -out "C:/Users/SHIGEMURA-PC/TS08-Drone/TS08-Drone/Simulation/StatusControl_UA_1_conf.xml"
@exit 0
:failed
@exit 1
