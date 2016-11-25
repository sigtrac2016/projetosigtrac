/* socket_test_mapping.c */

#include <stddef.h>

#include "SmuTypes.h"
#include "SmuMapping.h"
#include "socket_test_type.h"
#include "socket_test_mapping.h"

/* iterators */
extern const MappingIterator iter_array_16;
extern const MappingIterator iter_array_50;
extern const MappingIterator iter_array_150;
const MappingIterator iter_array_16 = { "array", 16, 16, NULL};
const MappingIterator iter_array_50 = { "array", 50, 50, NULL};
const MappingIterator iter_array_150 = { "array", 150, 150, NULL};

/* clock active helper functions */

/* forward declarations */
#define MAP_DECL(ident, nb) extern const MappingEntry ident##_entries[nb]; extern const MappingScope ident
MAP_DECL(scope_8, 1);
MAP_DECL(scope_7, 1);
MAP_DECL(scope_6, 1);
MAP_DECL(scope_1, 47);
MAP_DECL(scope_0, 1);

/* array_char_16 */
const MappingEntry scope_8_entries[1] = {
  /* 0 */ { MAP_ARRAY, "", &iter_array_16, sizeof(kcg_char), 0, &_Type_kcg_char_Utils, NULL, NULL, NULL, 1, 0}
};
const MappingScope scope_8 = {
  "array_char_16",
  scope_8_entries, 1,
};

/* array_char_50 */
const MappingEntry scope_7_entries[1] = {
  /* 0 */ { MAP_ARRAY, "", &iter_array_50, sizeof(kcg_char), 0, &_Type_kcg_char_Utils, NULL, NULL, NULL, 1, 0}
};
const MappingScope scope_7 = {
  "array_char_50",
  scope_7_entries, 1,
};

/* array_char_150 */
const MappingEntry scope_6_entries[1] = {
  /* 0 */ { MAP_ARRAY, "", &iter_array_150, sizeof(kcg_char), 0, &_Type_kcg_char_Utils, NULL, NULL, NULL, 1, 0}
};
const MappingScope scope_6 = {
  "array_char_150",
  scope_6_entries, 1,
};

/* test/ test */
const MappingEntry scope_1_entries[47] = {
  /* 0 */ { MAP_INPUT, "Description", NULL, sizeof(array_char_150), (size_t)&inputs_ctx.Description, &_Type_array_char_150_Utils, NULL, NULL, &scope_6, 1, 39},
  /* 1 */ { MAP_OUTPUT, "Emit", NULL, sizeof(kcg_bool), (size_t)&outputs_ctx.Emit, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 1, 34},
  /* 2 */ { MAP_OUTPUT, "EmitToOcurrenceType", NULL, sizeof(kcg_bool), (size_t)&outputs_ctx.EmitToOcurrenceType, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 1, 38},
  /* 3 */ { MAP_OUTPUT, "LEDReportDispatched", NULL, sizeof(kcg_int), (size_t)&outputs_ctx.LEDReportDispatched, &_Type_kcg_int_Utils, NULL, NULL, NULL, 1, 36},
  /* 4 */ { MAP_OUTPUT, "LEDReportRegisted", NULL, sizeof(kcg_int), (size_t)&outputs_ctx.LEDReportRegisted, &_Type_kcg_int_Utils, NULL, NULL, NULL, 1, 35},
  /* 5 */ { MAP_INPUT, "Latitude", NULL, sizeof(kcg_real), (size_t)&inputs_ctx.Latitude, &_Type_kcg_real_Utils, NULL, NULL, NULL, 1, 43},
  /* 6 */ { MAP_INPUT, "Longitude", NULL, sizeof(kcg_real), (size_t)&inputs_ctx.Longitude, &_Type_kcg_real_Utils, NULL, NULL, NULL, 1, 44},
  /* 7 */ { MAP_INPUT, "Notification", NULL, sizeof(kcg_bool), (size_t)&inputs_ctx.Notification, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 1, 40},
  /* 8 */ { MAP_INPUT, "NotifyFromOcurrenceType", NULL, sizeof(kcg_bool), (size_t)&inputs_ctx.NotifyFromOcurrenceType, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 1, 46},
  /* 9 */ { MAP_OUTPUT, "SelectedOcurrenceType", NULL, sizeof(kcg_int), (size_t)&outputs_ctx.SelectedOcurrenceType, &_Type_kcg_int_Utils, NULL, NULL, NULL, 1, 37},
  /* 10 */ { MAP_INPUT, "SignalFromButton", NULL, sizeof(kcg_bool), (size_t)&inputs_ctx.SignalFromButton, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 1, 41},
  /* 11 */ { MAP_INPUT, "Status", NULL, sizeof(kcg_int), (size_t)&inputs_ctx.Status, &_Type_kcg_int_Utils, NULL, NULL, NULL, 1, 45},
  /* 12 */ { MAP_INPUT, "Title", NULL, sizeof(kcg_int), (size_t)&inputs_ctx.Title, &_Type_kcg_int_Utils, NULL, NULL, NULL, 1, 42},
  /* 13 */ { MAP_LOCAL, "_L15", NULL, sizeof(kcg_int), (size_t)&outputs_ctx._L15, &_Type_kcg_int_Utils, NULL, NULL, NULL, 1, 3},
  /* 14 */ { MAP_LOCAL, "_L4", NULL, sizeof(kcg_bool), (size_t)&outputs_ctx._L4, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 1, 1},
  /* 15 */ { MAP_LOCAL, "_L44", NULL, sizeof(kcg_bool), (size_t)&outputs_ctx._L44, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 1, 7},
  /* 16 */ { MAP_LOCAL, "_L46", NULL, sizeof(kcg_bool), (size_t)&outputs_ctx._L46, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 1, 6},
  /* 17 */ { MAP_LOCAL, "_L47", NULL, sizeof(kcg_bool), (size_t)&outputs_ctx._L47, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 1, 5},
  /* 18 */ { MAP_LOCAL, "_L48", NULL, sizeof(kcg_bool), (size_t)&outputs_ctx._L48, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 1, 4},
  /* 19 */ { MAP_LOCAL, "_L50", NULL, sizeof(kcg_char), (size_t)&outputs_ctx._L50, &_Type_kcg_char_Utils, NULL, NULL, NULL, 1, 8},
  /* 20 */ { MAP_LOCAL, "_L52", NULL, sizeof(kcg_real), (size_t)&outputs_ctx._L52, &_Type_kcg_real_Utils, NULL, NULL, NULL, 1, 9},
  /* 21 */ { MAP_LOCAL, "_L53", NULL, sizeof(kcg_real), (size_t)&outputs_ctx._L53, &_Type_kcg_real_Utils, NULL, NULL, NULL, 1, 10},
  /* 22 */ { MAP_LOCAL, "_L55", NULL, sizeof(kcg_int), (size_t)&outputs_ctx._L55, &_Type_kcg_int_Utils, NULL, NULL, NULL, 1, 11},
  /* 23 */ { MAP_LOCAL, "_L56", NULL, sizeof(array_char_50), (size_t)&outputs_ctx._L56, &_Type_array_char_50_Utils, NULL, NULL, &scope_7, 1, 12},
  /* 24 */ { MAP_LOCAL, "_L57", NULL, sizeof(array_char_50), (size_t)&outputs_ctx._L57, &_Type_array_char_50_Utils, NULL, NULL, &scope_7, 1, 13},
  /* 25 */ { MAP_LOCAL, "_L58", NULL, sizeof(array_char_50), (size_t)&outputs_ctx._L58, &_Type_array_char_50_Utils, NULL, NULL, &scope_7, 1, 14},
  /* 26 */ { MAP_LOCAL, "_L59", NULL, sizeof(array_char_50), (size_t)&outputs_ctx._L59, &_Type_array_char_50_Utils, NULL, NULL, &scope_7, 1, 15},
  /* 27 */ { MAP_LOCAL, "_L62", NULL, sizeof(array_char_50), (size_t)&outputs_ctx._L62, &_Type_array_char_50_Utils, NULL, NULL, &scope_7, 1, 16},
  /* 28 */ { MAP_LOCAL, "_L63", NULL, sizeof(array_char_16), (size_t)&outputs_ctx._L63, &_Type_array_char_16_Utils, NULL, NULL, &scope_8, 1, 17},
  /* 29 */ { MAP_LOCAL, "_L64", NULL, sizeof(kcg_int), (size_t)&outputs_ctx._L64, &_Type_kcg_int_Utils, NULL, NULL, NULL, 1, 18},
  /* 30 */ { MAP_LOCAL, "_L65", NULL, sizeof(array_char_16), (size_t)&outputs_ctx._L65, &_Type_array_char_16_Utils, NULL, NULL, &scope_8, 1, 19},
  /* 31 */ { MAP_LOCAL, "_L66", NULL, sizeof(array_char_16), (size_t)&outputs_ctx._L66, &_Type_array_char_16_Utils, NULL, NULL, &scope_8, 1, 20},
  /* 32 */ { MAP_LOCAL, "_L67", NULL, sizeof(array_char_16), (size_t)&outputs_ctx._L67, &_Type_array_char_16_Utils, NULL, NULL, &scope_8, 1, 21},
  /* 33 */ { MAP_LOCAL, "_L68", NULL, sizeof(array_char_16), (size_t)&outputs_ctx._L68, &_Type_array_char_16_Utils, NULL, NULL, &scope_8, 1, 22},
  /* 34 */ { MAP_LOCAL, "_L69", NULL, sizeof(array_char_16), (size_t)&outputs_ctx._L69, &_Type_array_char_16_Utils, NULL, NULL, &scope_8, 1, 23},
  /* 35 */ { MAP_LOCAL, "_L71", NULL, sizeof(kcg_int), (size_t)&outputs_ctx._L71, &_Type_kcg_int_Utils, NULL, NULL, NULL, 1, 24},
  /* 36 */ { MAP_LOCAL, "_L72", NULL, sizeof(kcg_int), (size_t)&outputs_ctx._L72, &_Type_kcg_int_Utils, NULL, NULL, NULL, 1, 25},
  /* 37 */ { MAP_LOCAL, "_L73", NULL, sizeof(kcg_int), (size_t)&outputs_ctx._L73, &_Type_kcg_int_Utils, NULL, NULL, NULL, 1, 26},
  /* 38 */ { MAP_LOCAL, "_L74", NULL, sizeof(kcg_int), (size_t)&outputs_ctx._L74, &_Type_kcg_int_Utils, NULL, NULL, NULL, 1, 27},
  /* 39 */ { MAP_LOCAL, "_L76", NULL, sizeof(kcg_int), (size_t)&outputs_ctx._L76, &_Type_kcg_int_Utils, NULL, NULL, NULL, 1, 28},
  /* 40 */ { MAP_LOCAL, "_L77", NULL, sizeof(kcg_int), (size_t)&outputs_ctx._L77, &_Type_kcg_int_Utils, NULL, NULL, NULL, 1, 29},
  /* 41 */ { MAP_LOCAL, "_L78", NULL, sizeof(kcg_int), (size_t)&outputs_ctx._L78, &_Type_kcg_int_Utils, NULL, NULL, NULL, 1, 30},
  /* 42 */ { MAP_LOCAL, "_L80", NULL, sizeof(array_char_50), (size_t)&outputs_ctx._L80, &_Type_array_char_50_Utils, NULL, NULL, &scope_7, 1, 31},
  /* 43 */ { MAP_LOCAL, "_L81", NULL, sizeof(array_char_16), (size_t)&outputs_ctx._L81, &_Type_array_char_16_Utils, NULL, NULL, &scope_8, 1, 32},
  /* 44 */ { MAP_LOCAL, "_L82", NULL, sizeof(kcg_bool), (size_t)&outputs_ctx._L82, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 1, 33},
  /* 45 */ { MAP_LOCAL, "_L9", NULL, sizeof(array_char_150), (size_t)&outputs_ctx._L9, &_Type_array_char_150_Utils, NULL, NULL, &scope_6, 1, 2},
  /* 46 */ { MAP_LOCAL, "aqui", NULL, sizeof(array_char_50), (size_t)&outputs_ctx.aqui, &_Type_array_char_50_Utils, NULL, NULL, &scope_7, 1, 0}
};
const MappingScope scope_1 = {
  "test/ test",
  scope_1_entries, 47,
};

/*  */
const MappingEntry scope_0_entries[1] = {
  /* 0 */ { MAP_ROOT, "test", NULL, 0, 0, NULL, NULL, NULL, &scope_1, 1, 0}
};
const MappingScope scope_0 = {
  "",
  scope_0_entries, 1,
};

const MappingScope* pTop = &scope_0;

