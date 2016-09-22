#include <string.h>
#include <stdlib.h>

static int roman_letter_to_arabic_number(char roman_letter) {
    const int I_ARABIC_VALUE = 1;
    const int V_ARABIC_VALUE = 5;
    const int X_ARABIC_VALUE = 10;
    const int L_ARABIC_VALUE = 50;
    const int C_ARABIC_VALUE = 100;
    const int D_ARABIC_VALUE = 500;
    const int M_ARABIC_VALUE = 1000;
    const int INVALID_ARABIC_VALUE = -1;

    switch(roman_letter) {

        case 'I'  :
            return I_ARABIC_VALUE;
        case 'V':
            return V_ARABIC_VALUE;
        case 'X':
            return X_ARABIC_VALUE;
        case 'L':
            return L_ARABIC_VALUE;
        case 'C':
            return C_ARABIC_VALUE;
        case 'D':
            return D_ARABIC_VALUE;
        case 'M':
            return M_ARABIC_VALUE;
        default:
            return INVALID_ARABIC_VALUE;
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
    int roman_length = (int) strlen(roman);
    while(i < roman_length) {
        arabic += roman_digit_to_arabic(roman, &i, roman_length);
    }

    return arabic <= 3999 && arabic > 0 ? arabic : -1;
}