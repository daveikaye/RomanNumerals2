#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "roman_letter_to_arabic_number_converter.h"

static bool basic_roman_numeral_validation_passed(char* roman) {
    if (roman == NULL) {

        return false;
    }

    return true;
}

static bool is_valid_roman_letter(char roman_letter) {
    int arabic = roman_letter_to_arabic_number(roman_letter);
    if (arabic == -1) {

        return false;
    }

    return true;
}

static bool is_contains_all_valid_roman_letters(char *roman) {
    int i = 0;
    int roman_length = (int) strlen(roman);
    while(i < roman_length) {
        if (!is_valid_roman_letter(roman[i])) {

            return false;
        }

        i++;
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

    if (!is_contains_all_valid_roman_letters(roman)){
        return false;
    }

    return true;
}