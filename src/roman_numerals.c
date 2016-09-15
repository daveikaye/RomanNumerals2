#include <string.h>
#include <stdlib.h>
#include "to_roman_converter.h"

static int roman_letter_to_arabic_number(char roman_letter) {

    switch(roman_letter) {

        case 'I'  :
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return -1;
    }

}

static int roman_digit_to_arabic(char *roman, int* i_ptr, int roman_length) {
    int number = roman_letter_to_arabic_number(roman[*i_ptr]);
    (*i_ptr)++;

    if (*i_ptr < roman_length) {
        int nextNumber = roman_letter_to_arabic_number(roman[*i_ptr]);
        if (nextNumber > number) {
            number = nextNumber - number;
            (*i_ptr)++;
        }
    }

    return number;
}

int to_arabic(char *roman)
{
    if (roman == NULL) {

        return -1;
    }

    int i = 0;
    int arabic = 0;
    int roman_length = strlen(roman);
    while(i < roman_length) {
        arabic += roman_digit_to_arabic(roman, &i, roman_length);
    }

    return arabic <= 3999 && arabic > 0 ? arabic : -1;
}

static char* add_or_subtract(char* roman1, char* roman2, int should_add) {
    int arabic1 = to_arabic(roman1);
    int arabic2 = to_arabic(roman2);

    if (arabic1 > 0 && arabic2 > 0) {
        int arabic_result = should_add ? arabic1 + arabic2 : arabic1 - arabic2;

        return to_roman(arabic_result);
    }

    return NULL;
}

char* add(char* roman1, char* roman2) {
    const int should_add = 1;

    return add_or_subtract(roman1, roman2, should_add);
}

char* subtract(char* roman1, char* roman2) {
    const int should_add = 0;

    return add_or_subtract(roman1, roman2, should_add);
}