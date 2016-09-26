#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

static bool basic_roman_numeral_validation_passed(char* roman) {
    if (roman == NULL) {

        return false;
    }

    return true;
}

bool is_roman_numeral_valid(char *roman) {
    if (!basic_roman_numeral_validation_passed(roman)) {

        return false;
    }

    int roman_length = (int) strlen(roman);
    if (roman_length == 0) {

        return false;
    }

    int i = 0;
    int iCounter = 0;
    while(i < roman_length) {
        if (roman[i] == 'I') {
            iCounter++;
            if(iCounter == 4) {
                return false;
            }
        } else {
            iCounter = 0;
        }

        i++;
    }

    return true;
}