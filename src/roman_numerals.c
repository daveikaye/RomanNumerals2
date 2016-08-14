#include <string.h>
#include <stdlib.h>

int roman_letter_to_arabic_number(char roman_letter) {

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

int to_arabic(char *roman)
{
    int i = 0;
    int arabic = 0;
    int roman_length = strlen(roman);

    while(i < roman_length) {
        arabic += roman_letter_to_arabic_number(roman[i]);
        i++;
    }

    return arabic;
}