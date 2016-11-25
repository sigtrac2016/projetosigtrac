@cd "C:/Dev/ces-65/Tmp/socket_test/socket_test/Simulation"
@set OCAMLRUNPARAM=b
"C:/Program Files (x86)/Esterel Technologies/SCADE R17/SCADE/bin/uaadaptor.exe" -sdy "C:\Dev\ces-65\Tmp\socket_test\socket_test\socket_test.sdy" -n "C:\Program Files (x86)\Esterel Technologies\SCADE R17\SCADE Display\config\a661_description\a661.xml" -outdir "C:/Dev/ces-65/Tmp/socket_test/socket_test/Simulation" -k "C:/Dev/ces-65/Tmp/socket_test/socket_test/Simulation/kcg_trace.xml" -o "test_UA_1" -i "socket_test_interface.h"  -encoding "ASCII"  "C:\Dev\ces-65\Tmp\socket_test\socket_test\DisplaySCADE(nova versao)\DisplayTS04.sgfx"
@IF ERRORLEVEL 1 GOTO failed
@move "test_UA_1.log" "test_UA_1_uaadaptor.log"
"C:\Program Files (x86)\Esterel Technologies\SCADE R17\SCADE Display\bin\ScadeDisplayConsole.exe" batch generate "C:\Dev\ces-65\Tmp\socket_test\socket_test\DisplaySCADE(nova versao)\Display_SCADE.etp" -conf "DF Generation" -source "DisplayTS04.sgfx" -outdir "C:/Dev/ces-65/Tmp/socket_test/socket_test/Simulation" -prefix "test_UA_1"
@IF ERRORLEVEL 1 GOTO failed
@move "test_UA_1.log" "test_UA_1_dfgen.log"
"C:\Program Files (x86)\Esterel Technologies\SCADE R17\SCADE Display\bin\ScadeDisplayConsole.exe" batch  generateServerConf "C:\Dev\ces-65\Tmp\socket_test\socket_test\DisplaySCADE(nova versao)\Display_SCADE.etp" -spec "DisplayTS04.sgfx" -out "C:/Dev/ces-65/Tmp/socket_test/socket_test/Simulation/test_UA_1_conf.xml"
@exit 0
:failed
@exit 1
