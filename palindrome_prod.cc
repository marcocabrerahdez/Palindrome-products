// Autor Marco Antonio Cabrera Hernández
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

bool IsPalindrome(int, int);

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Usage: " << argv[0] << " Natural number" << "Name of output file(must be in the same directory)" << endl;
    }

    int kDigits = atoi(argv[1]);

    ofstream fout;
    fout.open(argv[2]);

    int low_number = 1 * pow(10, kDigits - 1); // menor numero posible segun los digitos
    int high_number = pow(10, kDigits) - 1; // mayor numero posible segun los digitos

    for (int i = low_number; i <= high_number; i++) {
        for (int j = i; j <= high_number; j++) {
            if (IsPalindrome(i, j)) {
                fout << i << " x " << j << " = " << i * j << endl;
            }
        }
    }

    return 0;
}



bool IsPalindrome(int i, int j) {
    int kPalindrome = i * j, modulusNumber, InverseNumber = 0;
    bool CheckPalindrome;

    int NormalNumber = kPalindrome;
    
    while (kPalindrome != 0) {
        modulusNumber = kPalindrome % 10;
        InverseNumber = InverseNumber * 10 + modulusNumber;
        kPalindrome = kPalindrome / 10;  
    }

    CheckPalindrome = InverseNumber == NormalNumber;

    return CheckPalindrome;
}