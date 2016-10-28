@cd "C:/Users/SHIGEMURA-PC/SCADE/ControleFontesDeRisco/Simulation"
@set OCAMLRUNPARAM=b
"C:/Program Files/Esterel Technologies/SCADE R17/SCADE/bin/uaadaptor.exe" -sdy "C:\Users\SHIGEMURA-PC\SCADE\ControleFontesDeRisco\ControleFontesDeRisco.sdy" -n "C:\Program Files\Esterel Technologies\SCADE R17\SCADE Display\config\a661_description\a661.xml" -outdir "C:/Users/SHIGEMURA-PC/SCADE/ControleFontesDeRisco/Simulation" -k "C:/Users/SHIGEMURA-PC/SCADE/ControleFontesDeRisco/Simulation/kcg_trace.xml" -o "Operator1_UA_1" -i "ControleFontesDeRisco_interface.h"  -encoding "ASCII"  "C:\Users\SHIGEMURA-PC\ControleFontesDeRisco\ControleFontesDeRisco.sgfx"
@IF ERRORLEVEL 1 GOTO failed
@move "Operator1_UA_1.log" "Operator1_UA_1_uaadaptor.log"
"C:\Program Files\Esterel Technologies\SCADE R17\SCADE Display\bin\ScadeDisplayConsole.exe" batch generate "C:\Users\SHIGEMURA-PC\ControleFontesDeRisco\ControleFontesDeRisco.etp" -conf "DF Generation" -source "ControleFontesDeRisco.sgfx" -outdir "C:/Users/SHIGEMURA-PC/SCADE/ControleFontesDeRisco/Simulation" -prefix "Operator1_UA_1"
@IF ERRORLEVEL 1 GOTO failed
@move "Operator1_UA_1.log" "Operator1_UA_1_dfgen.log"
"C:\Program Files\Esterel Technologies\SCADE R17\SCADE Display\bin\ScadeDisplayConsole.exe" batch  generateServerConf "C:\Users\SHIGEMURA-PC\ControleFontesDeRisco\ControleFontesDeRisco.etp" -spec "ControleFontesDeRisco.sgfx" -out "C:/Users/SHIGEMURA-PC/SCADE/ControleFontesDeRisco/Simulation/Operator1_UA_1_conf.xml"
@exit 0
:failed
@exit 1
