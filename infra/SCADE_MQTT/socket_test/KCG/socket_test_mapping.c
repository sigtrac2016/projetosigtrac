/* socket_test_mapping.c */

#include <stddef.h>

#include "SmuTypes.h"
#include "SmuMapping.h"
#include "socket_test_type.h"
#include "socket_test_mapping.h"

/* iterators */

/* clock active helper functions */

/* forward declarations */
#define MAP_DECL(ident, nb) extern const MappingEntry ident##_entries[nb]; extern const MappingScope ident
MAP_DECL(scope_2, 2);
MAP_DECL(scope_1, 4);
MAP_DECL(scope_0, 1);

/* LutIndex_lut */
const MappingEntry scope_2_entries[2] = {
  /* 0 */ { MAP_FIELD, ".f", NULL, sizeof(kcg_real), offsetof(LutIndex_lut, f), &_Type_kcg_real_Utils, NULL, NULL, NULL, 1, 1},
  /* 1 */ { MAP_FIELD, ".k", NULL, sizeof(kcg_int), offsetof(LutIndex_lut, k), &_Type_kcg_int_Utils, NULL, NULL, NULL, 1, 0}
};
const MappingScope scope_2 = {
  "LutIndex_lut",
  scope_2_entries, 2,
};

/* test/ test */
const MappingEntry scope_1_entries[4] = {
  /* 0 */ { MAP_OUTPUT, "Emit", NULL, sizeof(kcg_bool), (size_t)&outputs_ctx.Emit, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 1, 3},
  /* 1 */ { MAP_OUTPUT, "Output1", NULL, sizeof(kcg_int), (size_t)&outputs_ctx.Output1, &_Type_kcg_int_Utils, NULL, NULL, NULL, 1, 2},
  /* 2 */ { MAP_LOCAL, "_L2", NULL, sizeof(kcg_int), (size_t)&outputs_ctx._L2, &_Type_kcg_int_Utils, NULL, NULL, NULL, 1, 0},
  /* 3 */ { MAP_LOCAL, "_L4", NULL, sizeof(kcg_bool), (size_t)&outputs_ctx._L4, &_Type_kcg_bool_Utils, NULL, NULL, NULL, 1, 1}
};
const MappingScope scope_1 = {
  "test/ test",
  scope_1_entries, 4,
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

