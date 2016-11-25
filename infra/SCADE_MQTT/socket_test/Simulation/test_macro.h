#ifndef _TEST_MACRO_H_
#define _TEST_MACRO_H_


/*$************** SCADE Macro wrapper *********************
** Begin of file test_macro.h
***********************************************************$*/


/*$**********************************************************
*                        INCLUDES
***********************************************************$*/

/* includes */
#include "test.h"

/*$**********************************************************
*                           CONTEXT
***********************************************************$*/

typedef struct {
    inC_test inputs_ctx;
    outC_test outputs_ctx;
} WU_test;
#define WU_CTX_TYPE_test WU_test
#define WU_CTX_TYPE_test_SIZE sizeof(WU_test)

/*$**********************************************************
*                           SENSORS
***********************************************************$*/

#define DECLARE_SENSORS_test() 

#define DECLARE_EXT_SENSORS_test(MODE) 

/*$**********************************************************
*                           INPUTS
***********************************************************$*/

#define VARC_test_Description(context) context.inputs_ctx.Description  /* test/Description */
#define VAR_test_Description VARC_test_Description(CTX_test)

#define VARC_test_Notification(context) context.inputs_ctx.Notification  /* test/Notification */
#define VAR_test_Notification VARC_test_Notification(CTX_test)

#define VARC_test_SignalFromButton(context) context.inputs_ctx.SignalFromButton  /* test/SignalFromButton */
#define VAR_test_SignalFromButton VARC_test_SignalFromButton(CTX_test)

#define VARC_test_Title(context) context.inputs_ctx.Title  /* test/Title */
#define VAR_test_Title VARC_test_Title(CTX_test)

#define VARC_test_Latitude(context) context.inputs_ctx.Latitude  /* test/Latitude */
#define VAR_test_Latitude VARC_test_Latitude(CTX_test)

#define VARC_test_Longitude(context) context.inputs_ctx.Longitude  /* test/Longitude */
#define VAR_test_Longitude VARC_test_Longitude(CTX_test)

#define VARC_test_Status(context) context.inputs_ctx.Status  /* test/Status */
#define VAR_test_Status VARC_test_Status(CTX_test)

#define VARC_test_NotifyFromOcurrenceType(context) context.inputs_ctx.NotifyFromOcurrenceType  /* test/NotifyFromOcurrenceType */
#define VAR_test_NotifyFromOcurrenceType VARC_test_NotifyFromOcurrenceType(CTX_test)


/*$**********************************************************
*                           OUTPUTS
***********************************************************$*/

#define VARC_test_Emit(context) context.outputs_ctx.Emit  /* test/Emit */
#define VAR_test_Emit VARC_test_Emit(CTX_test)

#define VARC_test_LEDReportRegisted(context) context.outputs_ctx.LEDReportRegisted  /* test/LEDReportRegisted */
#define VAR_test_LEDReportRegisted VARC_test_LEDReportRegisted(CTX_test)

#define VARC_test_LEDReportDispatched(context) context.outputs_ctx.LEDReportDispatched  /* test/LEDReportDispatched */
#define VAR_test_LEDReportDispatched VARC_test_LEDReportDispatched(CTX_test)

#define VARC_test_SelectedOcurrenceType(context) context.outputs_ctx.SelectedOcurrenceType  /* test/SelectedOcurrenceType */
#define VAR_test_SelectedOcurrenceType VARC_test_SelectedOcurrenceType(CTX_test)

#define VARC_test_EmitToOcurrenceType(context) context.outputs_ctx.EmitToOcurrenceType  /* test/EmitToOcurrenceType */
#define VAR_test_EmitToOcurrenceType VARC_test_EmitToOcurrenceType(CTX_test)


/*$**********************************************************
*                           ELEMENT ACCESS
***********************************************************$*/

#define GET_ELEMENT_AT(VARIABLE, INDEX)  (VARIABLE)[INDEX]
#define GET_STRUCTURE_FIELD(VARIABLE, FIELD) (VARIABLE).FIELD

/*$**********************************************************
*                        VARIABLES TYPES
***********************************************************$*/

#define T_Description array_char_150
#define CPY_Description(DST, SRC) kcg_copy_array_char_150(DST, SRC)
#define T_Notification kcg_bool
#define CPY_Notification(DST, SRC) DST = SRC
#define T_SignalFromButton kcg_bool
#define CPY_SignalFromButton(DST, SRC) DST = SRC
#define T_Title kcg_int
#define CPY_Title(DST, SRC) DST = SRC
#define T_Latitude kcg_real
#define CPY_Latitude(DST, SRC) DST = SRC
#define T_Longitude kcg_real
#define CPY_Longitude(DST, SRC) DST = SRC
#define T_Status kcg_int
#define CPY_Status(DST, SRC) DST = SRC
#define T_NotifyFromOcurrenceType kcg_bool
#define CPY_NotifyFromOcurrenceType(DST, SRC) DST = SRC
#define T_Emit kcg_bool
#define CPY_Emit(DST, SRC) DST = SRC
#define T_LEDReportRegisted kcg_int
#define CPY_LEDReportRegisted(DST, SRC) DST = SRC
#define T_LEDReportDispatched kcg_int
#define CPY_LEDReportDispatched(DST, SRC) DST = SRC
#define T_SelectedOcurrenceType kcg_int
#define CPY_SelectedOcurrenceType(DST, SRC) DST = SRC
#define T_EmitToOcurrenceType kcg_bool
#define CPY_EmitToOcurrenceType(DST, SRC) DST = SRC


/*$**********************************************************
*                      CREATION, INIT AND PERFORM
***********************************************************$*/

#define DECLAREC_CTXT_test(context)  WU_test context;

#define DECLARE_CTXT_test() DECLAREC_CTXT_test(CTX_test)

#define DECLAREC_EXT_CTXT_test(MODE , context) MODE WU_test context;

#define DECLARE_EXT_CTXT_test(MODE) DECLAREC_EXT_CTXT_test(MODE , CTX_test)

#define INITC_test(context)     #ifndef KCG_USER_DEFINED_INIT\
        test_init(&context.outputs_ctx);\
    #else\
        #ifndef KCG_NO_EXTERN_CALL_TO_RESET\
            test_reset(&context.outputs_ctx);\
        #endif\
    #endif
#define INIT_test() INITC_test(CTX_test)

#define PERFORMC_test(context)     test( \
        &context.inputs_ctx /* input context */,\
        &context.outputs_ctx /* output/memories context */\
    )

#define PERFORM_test() PERFORMC_test(CTX_test)

/*$************** SCADE Macro wrapper *********************
** End of file test_macro.h
***********************************************************$*/

#endif /* _TEST_MACRO_H_ */
