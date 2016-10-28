
/* Code generated for Standalone Executable */


/* Contexts for SCADE Suite KCG Code */

/* includes */
#include "Operator1.h"


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

	/* Loop forever */
	while(1) {

		/* Record starting time */
		__start = clock();

		/* Exit point*/

		/* Connect Graphical Panels => SCADE Suite */
	{
	}

		/* Perform SCADE Suite cycle computation */
		    Operator1( 
        &CTX_Operator1.inputs_ctx /* input context */,
        &CTX_Operator1.outputs_ctx /* output/memories context */
    );


		/* Connect SCADE Suite => Graphical Panels */

		/* Perform Graphical Panels drawings */
	{
	}

		/* Sleep remaining time to PERIOD */
		__finish = clock();
		__duration = (long) ((double)(__finish - __start) / CLOCKS_PER_SEC * 1000.0);
		if (__duration < PERIOD) {
			Sleep(PERIOD - __duration);
		}

	}

}

