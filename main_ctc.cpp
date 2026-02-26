// Simaal Belgaumi, Jesus Novoa Vasquez
// 2/26/26
// Cracking the Code

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

const int SIZE_PW = 6; // password length (not numeric range anymore)

// Function to generate random password with numbers + upper + lower letters
string generatePasscode() {
    string pw = "";

    for (int i = 0; i < SIZE_PW; i++) {
        int type = rand() % 3;
        char c;

        if (type == 0) {
            // numbers 0-9 (ASCII 48-57)
            c = char(48 + rand() % 10);
        }
        else if (type == 1) {
            // uppercase A-Z (ASCII 65-90)
            c = char(65 + rand() % 26);
        }
        else {
            // lowercase a-z (ASCII 97-122)
            c = char(97 + rand() % 26);
        }

        pw += c;
    }

    return pw;
}

int main() {
    srand(time(0)); 
    string passcode = generatePasscode();

    cout << "A password has been generated. Try to crack it!" << endl;
    cout << passcode << endl; // remove this if you want it hidden

    // Start Timer
    auto start = high_resolution_clock::now();

    /*    Original Number Only Algorithm Below

    int guess = 0;

    for (int i = 0; i < SIZE_PW; i++) {
        if (i == passcode) {
            guess = i;
            break; // stop once we find it
        }
    }

    cout << "Passcode cracked: " << guess << endl;

    */

    // New ASCII brute-force (random guessing)
    string guess = "";

    while (guess != passcode) {
        guess = "";

        for (int i = 0; i < SIZE_PW; i++) {
            int type = rand() % 3;
            char c;

            if (type == 0) {
                c = char(48 + rand() % 10);
            }
            else if (type == 1) {
                c = char(65 + rand() % 26);
            }
            else {
                c = char(97 + rand() % 26);
            }

            guess += c;
        }
    }

    cout << "Passcode cracked: " << guess << endl;

    // Stop Timer
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << "Passcode cracked in: " << duration.count() << " nanoseconds!" << endl;

    return 0;
}
