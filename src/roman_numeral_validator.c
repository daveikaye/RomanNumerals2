#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_roman_numeral_valid(char *roman) {
    int roman_length = (int) strlen(roman);
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