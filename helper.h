#ifndef _H_HELPER
#define _H_HELPER

#include "macros.h"

// Section name
#define CB_SECTION ".tst"

// Section creation. Needed in MSVC...
#pragma section(STRINGIZE(PPCAT(CB_SECTION, "$a")), read, write)
#pragma section(STRINGIZE(PPCAT(CB_SECTION, "$m")), read, write)
#pragma section(STRINGIZE(PPCAT(CB_SECTION, "$z")), read, write)

// Section allocation attrs
#define CB_SECTION_ATTR __declspec(allocate(STRINGIZE(PPCAT(CB_SECTION, "$m"))))
// TODO GCC
// #define CB_SECTION_ATTR __attribute__((section(CB_SECTION)))

// Function callback
typedef void (*fcnptr_t)(void);

// Macro to register a callback function
#define AUTO_REG_FCN(name)                         \
    void name();                                  \
    CB_SECTION_ATTR fcnptr_t cbk_##name = &##name; \
    void name()

#endif
