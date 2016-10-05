#include <string.h>


static char* concat_strings(char* maxMemoryBuffer, char* target, const char* source) {
    if (target == NULL) {
        target = maxMemoryBuffer;
        strcpy(target, source);
    } else{
        strcat(target, source);
    }

    return target;
}

char *to_roman(char* maxMemoryBuffer, int arabic) {
    if (arabic > 3999) {

        return NULL;
    }

    const int numbers[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
    const char* letters[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

    char *roman = NULL;

    int i=0;
    for (i = 0; i < sizeof(numbers)/sizeof(int); i++) {
        while (arabic >= numbers[i]) {
            roman = concat_strings(maxMemoryBuffer, roman, letters[i]);
            arabic -= numbers[i];
        }
    }

    return roman;
}