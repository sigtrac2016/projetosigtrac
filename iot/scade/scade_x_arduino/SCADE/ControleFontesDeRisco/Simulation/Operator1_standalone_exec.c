
/* Code generated for Standalone Executable */

#include "Operator1_UA_1.h"

/* Contexts for SCADE Suite KCG Code */

/* includes */
#include "Operator1.h"

#include "A661Cosim.h"

/* Declare scade context */
typedef struct {
    inC_Operator1 inputs_ctx;
    outC_Operator1 outputs_ctx;
} WU_Operator1;
#define WU_CTX_TYPE_Operator1 WU_Operator1
#define WU_CTX_TYPE_Operator1_SIZE sizeof(WU_Operator1)


static WU_Operator1 CTX_Operator1;


/* Declare sensors */




#include <windows.h>
#include <time.h>
#define PERIOD (clock_t)20.0
int main(int argc, char **argv){

	/* Local declarations */
	clock_t __start, __finish;
	long __duration;

	/* Reset SCADE Suite KCG output context */
	    #ifndef KCG_USER_DEFINED_INIT
        Operator1_init(&CTX_Operator1.outputs_ctx);
    #else
        #ifndef KCG_NO_EXTERN_CALL_TO_RESET
            Operator1_reset(&CTX_Operator1.outputs_ctx);
        #endif
    #endif

	/* Initialize Graphical Panels drawings */
	A661SetServerPath("C:/Program Files/Esterel Technologies/SCADE R17/SCADE/bin/../../SCADE A661/bin/A661Server.exe");
	#ifdef A661_LOGFILE
	A661SetLogFile(A661_LOGFILE);
	#endif
	if (0/*OK*/ != A661ConnectServer("127.0.0.1", 1231, " \"C:/Users/SHIGEMURA-PC/SCADE/ControleFontesDeRisco/Simulation/Operator1_UA_1.bin\"", "C:/Users/SHIGEMURA-PC/SCADE/ControleFontesDeRisco/Simulation/Operator1_UA_1_conf.xml" )) {
	}

	/* Loop forever */
	while(1) {

		/* Record starting time */
		__start = clock();

		/* Exit point*/

		/* Connect Graphical Panels => SCADE Suite */
	{
	buffer_el msg[Operator1_UA_1_MAX_SIZE_INPUT_BUFFER];
	/* reveive from server */
	Operator1_UA_1_receive_clear(&(CTX_Operator1.inputs_ctx), NULL);
	if (A661Receive(msg, sizeof msg) == 0)
		Operator1_UA_1_receive(msg, sizeof msg, &(CTX_Operator1.inputs_ctx), NULL);
	}

		/* Perform SCADE Suite cycle computation */
		    Operator1( 
        &CTX_Operator1.inputs_ctx /* input context */,
        &CTX_Operator1.outputs_ctx /* output/memories context */
    );


		/* Connect SCADE Suite => Graphical Panels */

		/* Perform Graphical Panels drawings */
	{
	buffer_el msg[Operator1_UA_1_MAX_SIZE_OUTPUT_BUFFER];
	int len;
	len = Operator1_UA_1_send(msg, &(CTX_Operator1.outputs_ctx), NULL);
	/* Send to server */
	A661Send(msg, len);
	}

		/* Sleep remaining time to PERIOD */
		__finish = clock();
		__duration = (long) ((double)(__finish - __start) / CLOCKS_PER_SEC * 1000.0);
		if (__duration < PERIOD) {
			Sleep(PERIOD - __duration);
		}

	}

}

