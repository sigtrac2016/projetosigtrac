
/* Code generated for Standalone Executable */

#include "SDY1_specification.h"

/* Contexts for SCADE Suite KCG Code */

/* includes */
#include "DisplayOp.h"


/* Declare scade context */
typedef struct {
    outC_DisplayOp outputs_ctx;
} WU_DisplayOp;
#define WU_CTX_TYPE_DisplayOp WU_DisplayOp
#define WU_CTX_TYPE_DisplayOp_SIZE sizeof(WU_DisplayOp)


static WU_DisplayOp CTX_DisplayOp;


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
        DisplayOp_init(&CTX_DisplayOp.outputs_ctx);
    #else
        #ifndef KCG_NO_EXTERN_CALL_TO_RESET
            DisplayOp_reset(&CTX_DisplayOp.outputs_ctx);
        #endif
    #endif

	/* Initialize Graphical Panels drawings */
	SDY1_specification__init();
	SDY1_specification__draw();

	/* Loop forever */
	while(1) {

		/* Record starting time */
		__start = clock();

		/* Exit point*/
		if (SDY1_specification__cancelled()) break;

		/* Connect Graphical Panels => SCADE Suite */
		SDY1_specification__lockio();
		SDY1_specification__unlockio();
	{
	}

		/* Perform SCADE Suite cycle computation */
		    DisplayOp( 
        &CTX_DisplayOp.outputs_ctx /* output/memories context */
    );


		/* Connect SCADE Suite => Graphical Panels */
		SDY1_specification__lockio();
		/* temperature => temperature */
		SDY1_specification_symbology_layer_S_temperature(SDY1_specification_L_symbology_layer(), CTX_DisplayOp.outputs_ctx.temperature);
		/* respiratory_rate => respiratory_rate */
		SDY1_specification_symbology_layer_S_respiratory_rate(SDY1_specification_L_symbology_layer(), CTX_DisplayOp.outputs_ctx.respiratory_rate);
		/* oxygen_saturation => oxygen_saturation */
		SDY1_specification_symbology_layer_S_oxygen_saturation(SDY1_specification_L_symbology_layer(), CTX_DisplayOp.outputs_ctx.oxygen_saturation);
		/* heart_rate => heart_rate */
		SDY1_specification_symbology_layer_S_heart_rate(SDY1_specification_L_symbology_layer(), CTX_DisplayOp.outputs_ctx.heart_rate);

		/* Perform Graphical Panels drawings */
		SDY1_specification__draw();
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

