#include <iostream>

int compute_expression(int a, int b, int c, int d) {
    int part1 = (b << 11) + b; // 2049 * b
    int part2 = ((d << 4) - d + 12 * a) >> 11; // (d * 15 + 12 * a) / 2048
    int part3 = (c << 6) + (c << 5) + (c << 2); // c * 100
    int part4 = (d << 7) - (d << 5) + (d << 3); // d * 104

    return part1 + part2 - part3 + part4;
}

int main() {
    int a = 1, b = 2, c = 3, d = 4;
    int result = compute_expression(a, b, c, d);

    std::cout << "Result: " << result << std::endl;
    return 0;
}
#include <iostream>
#include <string>

void Crypt(std::string text[16], unsigned short rez[16][4]) {
    short i, j, l;

    for (int i = 0; i < 16; i++) {
        std::cout << "enter line " << i + 1 << ": ";
        std::getline(std::cin, text[i]);
    }
    std::cout << "You entered:\n";
    for (i = 0; i < 16; i++) {
        while (text[i].length() < 16) {
            text[i] += ' ';
        }
    }

    for (i = 0; i < 16; i++) {
        std::cout << text[i] << std::endl;
    }
    std::cout << "\nCrypted info:\n";
    for (i = 0; i < 16; i++) {
        for (j = 0; j < 4; j++) {
            unsigned short r = 0;
            unsigned char c = text[i][j];

            r |= i;

            int asciiValue = static_cast<int>(c);
            int higherPart = asciiValue >> 4;
            int lowerPart = asciiValue & 0xF;
            r |= (higherPart << 4);

            unsigned short t = 1;
            unsigned short b = 0;
            for (l = 0; l < 7; l++) {
                if (r & t) {
                    if (b == 0) b = 1; else b = 0;
                }
                t <<= 1;
            }

            r |= b << 8;


            r |= (j << 9);
            r |= (lowerPart << 10);
            t = 1;
            b = 0;
            for (l = 6; l < 16; l++) {
                if (r & t) {
                    if (b == 0) b = 1; else b = 0;
                }
                t <<= 1;
            }
            r |= b << 15;

            rez[i][j] = r;
            std::cout << std::hex << rez[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
void Decrypt(unsigned short rez[16][4]) {
    std::cout << "\nDecrypted info:\n";
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 4; ++j) {
            unsigned short r = rez[i][j];
            unsigned char higherPart = (r >> 4) & 0xF;
            unsigned char lowerPart = (r >> 10) & 0xF;
            char decryptedChar = (higherPart << 4) | lowerPart;
            std::cout << decryptedChar;
        }
        std::cout << std::endl;
    }
}
int main() {
    std::string text[16];
    unsigned short rez[16][4];
    Crypt(text, rez);
    Decrypt(rez);
    return 0;
}


