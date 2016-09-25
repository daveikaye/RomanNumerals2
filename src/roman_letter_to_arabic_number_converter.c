const int INVALID_ARABIC_VALUE = -1;

int roman_letter_to_arabic_number(char roman_letter) {
    const int I_ARABIC_VALUE = 1;
    const int V_ARABIC_VALUE = 5;
    const int X_ARABIC_VALUE = 10;
    const int L_ARABIC_VALUE = 50;
    const int C_ARABIC_VALUE = 100;
    const int D_ARABIC_VALUE = 500;
    const int M_ARABIC_VALUE = 1000;

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