#include <string.h>
#include "to_roman_converter.h"
#include "to_arabic_converter.h"

const int POSITIVE_MULTIPLIER = 1;
const int NEGATIVE_MULTIPLIER = -1;

static char* do_addition(char* maxMemoryBuffer, char* roman1, char* roman2, int signMultiplier) {
    int arabic1 = to_arabic(maxMemoryBuffer, roman1);
    int arabic2 = to_arabic(maxMemoryBuffer, roman2);

    if (arabic1 > 0 && arabic2 > 0) {
        int arabic_result = arabic1 + (arabic2 * signMultiplier);

        return to_roman(maxMemoryBuffer, arabic_result);
    }

    return NULL;
}

char* add(char* maxMemoryBuffer, char* roman1, char* roman2) {

    return do_addition(maxMemoryBuffer, roman1, roman2, POSITIVE_MULTIPLIER);
}

char* subtract(char* maxMemoryBuffer, char* roman1, char* roman2) {

    return do_addition(maxMemoryBuffer, roman1, roman2, NEGATIVE_MULTIPLIER);
}