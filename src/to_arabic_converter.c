#include <string.h>
#include "roman_numeral_validator.h"
#include "roman_letter_to_arabic_number_converter.h"
#include "to_roman_converter.h"

const int MAX_ARABIC_VALUE = 3999;

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

int to_arabic(char* maxMemoryBuffer, char *roman)
{
    if (!is_roman_numeral_valid(roman)) {

        return INVALID_ARABIC_VALUE;
    }

    int roman_length = (int) strlen(roman);
    int arabic = 0;
    int i = 0;
    while(i < roman_length) {
        arabic += roman_digit_to_arabic(roman, &i, roman_length);
    }

    if (arabic > MAX_ARABIC_VALUE || arabic < 1) {
        return INVALID_ARABIC_VALUE;
    }
    if (strcmp(to_roman(maxMemoryBuffer, arabic),roman) != 0) {

        return INVALID_ARABIC_VALUE;
    }

    return arabic;
}