This is an implementation of the Roman Numeral Calculator Kata.
For the description of the kata, refer to: https://github.com/daveikaye/RomanNumerals2/blob/master/Roman_Numeral_Calculator.pdf

The public API is roman_numerals.h.
It consists of:
 +char* add(char* roman1, char* roman2)
   - adds two roman numerals
   - returns sum as a roman numeral or NULL if the sum or its component is invalid (per kata's definition).

 +char* subtract(char* roman1, char* roman2)
   - subtracts roman numeral roman2 from roman numeral roman1.
   - returns the difference as a roman numeral or NULL if the difference or its component is invalid (per kata's definition).

This kata was solved using TDD.
The solution consists of three components:
   1.  Conversion to Arabic from Roman numerals.
   2.  Performance of addition/subtraction on the Arabic numerals.
   3.  Conversion of the result to Roman numeral.


To build and run tests:
  make -f romannumerals.makefile clean test