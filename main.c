#include "helper.h"

#include <stdio.h>

// Section limits. In MSVC a variable is created in adjacent sections to calcullate start and end addr...
__declspec(allocate(STRINGIZE(PPCAT(CB_SECTION, "$a")))) const void *__section_pre_var = (void *)NULL;
__declspec(allocate(STRINGIZE(PPCAT(CB_SECTION, "$z")))) const void *__section_post_var = (void *)NULL;
fcnptr_t *__start_section = (fcnptr_t *)(&__section_pre_var + 1);
fcnptr_t *__stop_section = (fcnptr_t *)&__section_post_var;
// TODO GCC
// #define CB_SECTION_START &__start_callbacks
// #define CB_SECTION_END &__stop_callbacks

int main(int argc, char **argv)
{
    // Iterate all pointers in the section and call them...
    for (fcnptr_t *ptr = __start_section; ptr != __stop_section; ptr++)
        (*ptr)();

    return 0;
}
