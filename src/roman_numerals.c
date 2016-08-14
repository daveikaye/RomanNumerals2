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
    }

}

int to_arabic(char *roman)
{

    return roman_letter_to_arabic_number(roman[0]);
}