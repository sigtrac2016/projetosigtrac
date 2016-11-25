
/* Code generated for Graphical Panels Co-simulation */

#include "test_UA_1.h"
#include "socket_test_interface.h"
#include "A661Cosim.h"



void AfterSimInit(void){
	A661SetServerPath("C:/Program Files (x86)/Esterel Technologies/SCADE R17/SCADE/bin/../../SCADE A661/bin/A661Server.exe");
	#ifdef A661_LOGFILE
	A661SetLogFile(A661_LOGFILE);
	#endif
	if (0/*OK*/ != A661ConnectServer("127.0.0.1", 1231, " \"C:/Dev/ces-65/Tmp/socket_test/socket_test/Simulation/test_UA_1.bin\"", "C:/Dev/ces-65/Tmp/socket_test/socket_test/Simulation/test_UA_1_conf.xml" )) {
		const char *pszError;
		A661GetLastError(&pszError);
		SsmOutputMessage(SIM_WARNING, pszError);
	}
}


void BeforeSimStep(void){
	buffer_el msg[test_UA_1_MAX_SIZE_INPUT_BUFFER];
	/* reveive from server */
	test_UA_1_receive_clear(&inputs_ctx, NULL);
	if (A661Receive(msg, sizeof msg) == 0)
		test_UA_1_receive(msg, sizeof msg, &inputs_ctx, NULL);
}


void AfterSimStep(void){
	static buffer_el msg[test_UA_1_MAX_SIZE_OUTPUT_BUFFER];
	int len;
	len = test_UA_1_send(msg, &outputs_ctx, NULL);
	/* Send to server */
	A661Send(msg, len);
}


void RefreshSimValues(void){
	 if (GraphicalInputsConnected) {
		BeforeSimStep();
		UpdateSimulatorValues();
	}
}


void BeforeSimInit(void){
}


void ExtendedSimStop(void){
	A661KillServer();
}


int ExtendedGetDumpSize(){
	return 0;
}


void ExtendedGatherDumpData(char * pData){
}


void ExtendedRestoreDumpData(const char * pData){
	AfterSimStep();
}


void UpdateValues(void){
}

