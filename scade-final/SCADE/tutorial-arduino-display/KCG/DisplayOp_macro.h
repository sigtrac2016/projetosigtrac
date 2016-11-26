#ifndef _DISPLAYOP_MACRO_H_
#define _DISPLAYOP_MACRO_H_


/*$************** SCADE Macro wrapper *********************
** Begin of file DisplayOp_macro.h
***********************************************************$*/


/*$**********************************************************
*                        INCLUDES
***********************************************************$*/

/* includes */
#include "DisplayOp.h"

/*$**********************************************************
*                           CONTEXT
***********************************************************$*/

typedef struct {
    outC_DisplayOp outputs_ctx;
} WU_DisplayOp;
#define WU_CTX_TYPE_DisplayOp WU_DisplayOp
#define WU_CTX_TYPE_DisplayOp_SIZE sizeof(WU_DisplayOp)

/*$**********************************************************
*                           SENSORS
***********************************************************$*/

#define DECLARE_SENSORS_DisplayOp() 

#define DECLARE_EXT_SENSORS_DisplayOp(MODE) 

/*$**********************************************************
*                           INPUTS
***********************************************************$*/


/*$**********************************************************
*                           OUTPUTS
***********************************************************$*/

#define VARC_DisplayOp_temperature(context) context.outputs_ctx.temperature  /* DisplayOp/temperature */
#define VAR_DisplayOp_temperature VARC_DisplayOp_temperature(CTX_DisplayOp)

#define VARC_DisplayOp_respiratory_rate(context) context.outputs_ctx.respiratory_rate  /* DisplayOp/respiratory_rate */
#define VAR_DisplayOp_respiratory_rate VARC_DisplayOp_respiratory_rate(CTX_DisplayOp)

#define VARC_DisplayOp_oxygen_saturation(context) context.outputs_ctx.oxygen_saturation  /* DisplayOp/oxygen_saturation */
#define VAR_DisplayOp_oxygen_saturation VARC_DisplayOp_oxygen_saturation(CTX_DisplayOp)

#define VARC_DisplayOp_heart_rate(context) context.outputs_ctx.heart_rate  /* DisplayOp/heart_rate */
#define VAR_DisplayOp_heart_rate VARC_DisplayOp_heart_rate(CTX_DisplayOp)


/*$**********************************************************
*                           ELEMENT ACCESS
***********************************************************$*/

#define GET_ELEMENT_AT(VARIABLE, INDEX)  (VARIABLE)[INDEX]
#define GET_STRUCTURE_FIELD(VARIABLE, FIELD) (VARIABLE).FIELD

/*$**********************************************************
*                        VARIABLES TYPES
***********************************************************$*/

#define T_temperature kcg_real
#define CPY_temperature(DST, SRC) DST = SRC
#define T_respiratory_rate kcg_real
#define CPY_respiratory_rate(DST, SRC) DST = SRC
#define T_oxygen_saturation kcg_real
#define CPY_oxygen_saturation(DST, SRC) DST = SRC
#define T_heart_rate kcg_real
#define CPY_heart_rate(DST, SRC) DST = SRC


/*$**********************************************************
*                      CREATION, INIT AND PERFORM
***********************************************************$*/

#define DECLAREC_CTXT_DisplayOp(context)  WU_DisplayOp context;

#define DECLARE_CTXT_DisplayOp() DECLAREC_CTXT_DisplayOp(CTX_DisplayOp)

#define DECLAREC_EXT_CTXT_DisplayOp(MODE , context) MODE WU_DisplayOp context;

#define DECLARE_EXT_CTXT_DisplayOp(MODE) DECLAREC_EXT_CTXT_DisplayOp(MODE , CTX_DisplayOp)

#define INITC_DisplayOp(context)     #ifndef KCG_USER_DEFINED_INIT\
        DisplayOp_init(&context.outputs_ctx);\
    #else\
        #ifndef KCG_NO_EXTERN_CALL_TO_RESET\
            DisplayOp_reset(&context.outputs_ctx);\
        #endif\
    #endif
#define INIT_DisplayOp() INITC_DisplayOp(CTX_DisplayOp)

#define PERFORMC_DisplayOp(context)     DisplayOp( \
        &context.outputs_ctx /* output/memories context */\
    )

#define PERFORM_DisplayOp() PERFORMC_DisplayOp(CTX_DisplayOp)

/*$************** SCADE Macro wrapper *********************
** End of file DisplayOp_macro.h
***********************************************************$*/

#endif /* _DISPLAYOP_MACRO_H_ */
