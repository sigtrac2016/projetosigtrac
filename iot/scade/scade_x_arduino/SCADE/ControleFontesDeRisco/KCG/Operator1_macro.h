#ifndef _OPERATOR1_MACRO_H_
#define _OPERATOR1_MACRO_H_


/*$************** SCADE Macro wrapper *********************
** Begin of file Operator1_macro.h
***********************************************************$*/


/*$**********************************************************
*                        INCLUDES
***********************************************************$*/

/* includes */
#include "Operator1.h"

/*$**********************************************************
*                           CONTEXT
***********************************************************$*/

typedef struct {
    inC_Operator1 inputs_ctx;
    outC_Operator1 outputs_ctx;
} WU_Operator1;
#define WU_CTX_TYPE_Operator1 WU_Operator1
#define WU_CTX_TYPE_Operator1_SIZE sizeof(WU_Operator1)

/*$**********************************************************
*                           SENSORS
***********************************************************$*/

#define DECLARE_SENSORS_Operator1() 

#define DECLARE_EXT_SENSORS_Operator1(MODE) 

/*$**********************************************************
*                           INPUTS
***********************************************************$*/

#define VARC_Operator1_SignalFromButton(context) context.inputs_ctx.SignalFromButton  /* Operator1/SignalFromButton */
#define VAR_Operator1_SignalFromButton VARC_Operator1_SignalFromButton(CTX_Operator1)


/*$**********************************************************
*                           OUTPUTS
***********************************************************$*/

#define VARC_Operator1_ReqLayerVisible(context) context.outputs_ctx.ReqLayerVisible  /* Operator1/ReqLayerVisible */
#define VAR_Operator1_ReqLayerVisible VARC_Operator1_ReqLayerVisible(CTX_Operator1)

#define VARC_Operator1_ReqLayerActive(context) context.outputs_ctx.ReqLayerActive  /* Operator1/ReqLayerActive */
#define VAR_Operator1_ReqLayerActive VARC_Operator1_ReqLayerActive(CTX_Operator1)

#define VARC_Operator1_SignalToLed(context) context.outputs_ctx.SignalToLed  /* Operator1/SignalToLed */
#define VAR_Operator1_SignalToLed VARC_Operator1_SignalToLed(CTX_Operator1)

#define VARC_Operator1_EmitToCDS(context) context.outputs_ctx.EmitToCDS  /* Operator1/EmitToCDS */
#define VAR_Operator1_EmitToCDS VARC_Operator1_EmitToCDS(CTX_Operator1)


/*$**********************************************************
*                           ELEMENT ACCESS
***********************************************************$*/

#define GET_ELEMENT_AT(VARIABLE, INDEX)  (VARIABLE)[INDEX]
#define GET_STRUCTURE_FIELD(VARIABLE, FIELD) (VARIABLE).FIELD

/*$**********************************************************
*                        VARIABLES TYPES
***********************************************************$*/

#define T_SignalFromButton kcg_bool
#define CPY_SignalFromButton(DST, SRC) DST = SRC
#define T_ReqLayerVisible kcg_bool
#define CPY_ReqLayerVisible(DST, SRC) DST = SRC
#define T_ReqLayerActive kcg_bool
#define CPY_ReqLayerActive(DST, SRC) DST = SRC
#define T_SignalToLed kcg_int
#define CPY_SignalToLed(DST, SRC) DST = SRC
#define T_EmitToCDS kcg_bool
#define CPY_EmitToCDS(DST, SRC) DST = SRC


/*$**********************************************************
*                      CREATION, INIT AND PERFORM
***********************************************************$*/

#define DECLAREC_CTXT_Operator1(context)  WU_Operator1 context;

#define DECLARE_CTXT_Operator1() DECLAREC_CTXT_Operator1(CTX_Operator1)

#define DECLAREC_EXT_CTXT_Operator1(MODE , context) MODE WU_Operator1 context;

#define DECLARE_EXT_CTXT_Operator1(MODE) DECLAREC_EXT_CTXT_Operator1(MODE , CTX_Operator1)

#define INITC_Operator1(context)     #ifndef KCG_USER_DEFINED_INIT\
        Operator1_init(&context.outputs_ctx);\
    #else\
        #ifndef KCG_NO_EXTERN_CALL_TO_RESET\
            Operator1_reset(&context.outputs_ctx);\
        #endif\
    #endif
#define INIT_Operator1() INITC_Operator1(CTX_Operator1)

#define PERFORMC_Operator1(context)     Operator1( \
        &context.inputs_ctx /* input context */,\
        &context.outputs_ctx /* output/memories context */\
    )

#define PERFORM_Operator1() PERFORMC_Operator1(CTX_Operator1)

/*$************** SCADE Macro wrapper *********************
** End of file Operator1_macro.h
***********************************************************$*/

#endif /* _OPERATOR1_MACRO_H_ */
