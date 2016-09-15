#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "to_roman_converter.h"
#include "to_arabic_converter.h"

static char* add_or_subtract(char* roman1, char* roman2, bool should_add) {
    int arabic1 = to_arabic(roman1);
    int arabic2 = to_arabic(roman2);

    if (arabic1 > 0 && arabic2 > 0) {
        int arabic_result = should_add ? arabic1 + arabic2 : arabic1 - arabic2;

        return to_roman(arabic_result);
    }

    return NULL;
}

char* add(char* roman1, char* roman2) {
    const bool should_add = true;

    return add_or_subtract(roman1, roman2, should_add);
}

char* subtract(char* roman1, char* roman2) {
    const bool should_add = false;

    return add_or_subtract(roman1, roman2, should_add);
}