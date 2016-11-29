#ifndef _STATUSCONTROL_MACRO_H_
#define _STATUSCONTROL_MACRO_H_


/*$************** SCADE Macro wrapper *********************
** Begin of file StatusControl_macro.h
***********************************************************$*/


/*$**********************************************************
*                        INCLUDES
***********************************************************$*/

/* includes */
#include "StatusControl.h"

/*$**********************************************************
*                           CONTEXT
***********************************************************$*/

typedef struct {
    inC_StatusControl inputs_ctx;
    outC_StatusControl outputs_ctx;
} WU_StatusControl;
#define WU_CTX_TYPE_StatusControl WU_StatusControl
#define WU_CTX_TYPE_StatusControl_SIZE sizeof(WU_StatusControl)

/*$**********************************************************
*                           SENSORS
***********************************************************$*/

#define DECLARE_SENSORS_StatusControl() 

#define DECLARE_EXT_SENSORS_StatusControl(MODE) 

/*$**********************************************************
*                           INPUTS
***********************************************************$*/

#define VARC_StatusControl_OnButton(context) context.inputs_ctx.OnButton  /* StatusControl/OnButton */
#define VAR_StatusControl_OnButton VARC_StatusControl_OnButton(CTX_StatusControl)


/*$**********************************************************
*                           OUTPUTS
***********************************************************$*/

#define VARC_StatusControl_StatusButtonText(context) context.outputs_ctx.StatusButtonText  /* StatusControl/StatusButtonText */
#define VAR_StatusControl_StatusButtonText VARC_StatusControl_StatusButtonText(CTX_StatusControl)

#define VARC_StatusControl_StatusButtonColor(context) context.outputs_ctx.StatusButtonColor  /* StatusControl/StatusButtonColor */
#define VAR_StatusControl_StatusButtonColor VARC_StatusControl_StatusButtonColor(CTX_StatusControl)

#define VARC_StatusControl_ButtonText(context) context.outputs_ctx.ButtonText  /* StatusControl/ButtonText */
#define VAR_StatusControl_ButtonText VARC_StatusControl_ButtonText(CTX_StatusControl)


/*$**********************************************************
*                           ELEMENT ACCESS
***********************************************************$*/

#define GET_ELEMENT_AT(VARIABLE, INDEX)  (VARIABLE)[INDEX]
#define GET_STRUCTURE_FIELD(VARIABLE, FIELD) (VARIABLE).FIELD

/*$**********************************************************
*                        VARIABLES TYPES
***********************************************************$*/

#define T_OnButton kcg_bool
#define CPY_OnButton(DST, SRC) DST = SRC
#define T_StatusButtonText T_String
#define CPY_StatusButtonText(DST, SRC) kcg_copy_T_String(DST, SRC)
#define T_StatusButtonColor kcg_int
#define CPY_StatusButtonColor(DST, SRC) DST = SRC
#define T_ButtonText T_String
#define CPY_ButtonText(DST, SRC) kcg_copy_T_String(DST, SRC)


/*$**********************************************************
*                      CREATION, INIT AND PERFORM
***********************************************************$*/

#define DECLAREC_CTXT_StatusControl(context)  WU_StatusControl context;

#define DECLARE_CTXT_StatusControl() DECLAREC_CTXT_StatusControl(CTX_StatusControl)

#define DECLAREC_EXT_CTXT_StatusControl(MODE , context) MODE WU_StatusControl context;

#define DECLARE_EXT_CTXT_StatusControl(MODE) DECLAREC_EXT_CTXT_StatusControl(MODE , CTX_StatusControl)

#define INITC_StatusControl(context)     #ifndef KCG_USER_DEFINED_INIT\
        StatusControl_init(&context.outputs_ctx);\
    #else\
        #ifndef KCG_NO_EXTERN_CALL_TO_RESET\
            StatusControl_reset(&context.outputs_ctx);\
        #endif\
    #endif
#define INIT_StatusControl() INITC_StatusControl(CTX_StatusControl)

#define PERFORMC_StatusControl(context)     StatusControl( \
        &context.inputs_ctx /* input context */,\
        &context.outputs_ctx /* output/memories context */\
    )

#define PERFORM_StatusControl() PERFORMC_StatusControl(CTX_StatusControl)

/*$************** SCADE Macro wrapper *********************
** End of file StatusControl_macro.h
***********************************************************$*/

#endif /* _STATUSCONTROL_MACRO_H_ */
