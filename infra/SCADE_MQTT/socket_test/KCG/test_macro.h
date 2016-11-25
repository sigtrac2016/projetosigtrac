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


/*$**********************************************************
*                           OUTPUTS
***********************************************************$*/

#define VARC_test_Output1(context) context.outputs_ctx.Output1  /* test/Output1 */
#define VAR_test_Output1 VARC_test_Output1(CTX_test)

#define VARC_test_Emit(context) context.outputs_ctx.Emit  /* test/Emit */
#define VAR_test_Emit VARC_test_Emit(CTX_test)


/*$**********************************************************
*                           ELEMENT ACCESS
***********************************************************$*/

#define GET_ELEMENT_AT(VARIABLE, INDEX)  (VARIABLE)[INDEX]
#define GET_STRUCTURE_FIELD(VARIABLE, FIELD) (VARIABLE).FIELD

/*$**********************************************************
*                        VARIABLES TYPES
***********************************************************$*/

#define T_Output1 kcg_int
#define CPY_Output1(DST, SRC) DST = SRC
#define T_Emit kcg_bool
#define CPY_Emit(DST, SRC) DST = SRC


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
        &context.outputs_ctx /* output/memories context */\
    )

#define PERFORM_test() PERFORMC_test(CTX_test)

/*$************** SCADE Macro wrapper *********************
** End of file test_macro.h
***********************************************************$*/

#endif /* _TEST_MACRO_H_ */
