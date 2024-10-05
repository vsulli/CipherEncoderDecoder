/* CipherEncoderDecoder.cpp
* vsulli
* 5 October 2024
* Program that allows the user to determine the type of cipher
* encode a message or decode a message based on that cipher type.
*/

#include <iostream>
#include <map>
#include <string>

// Atbash Encoder
std::string atbashEncoder(std::string message) {
    std::map<char, char> letter_map = {
        {'a', 'z'},{'b', 'y'},{'c', 'x'},{'d', 'w'},{'e', 'v'},
        {'f', 'u'},{'g', 't'},{'h', 's'},{'i', 'r'},{'j', 'q'},
        {'k', 'p'},{'l', 'o'},{'m', 'n'},{'n', 'm'},{'o', 'l'},
        {'p', 'k'},{'q', 'j'},{'r', 'i'},{'s', 'h'},{'t', 'g'},
        {'u', 'f'},{'v', 'e'},{'w', 'd'},{'x', 'c'},{'y', 'b'},
        {'z', 'a'},
    };
    std::string encrypted_msg = "";
    // for every index of letter in message, retrieve new letter
    // make message all lower, strip punctuation?

}

// Atbash Decoder

int subMenu() {
    int selection2 = 0;

    std::cout << "Would you like to encode or decode a message?" << std::endl
        << "1) Encode" << std::endl
        << "2) Decode" << std::endl
        << "3) Quit" << std:: endl;

    std::cin >> selection2;

    while (selection2 != -2){
        switch (selection2) {
            case 1:
               return selection2 = 6;

            case 2:
                return selection2 = 7;

            case 3:
                selection2 = -2;
                break;

            default:
                std::cout << "Invalid Selection. Select a valid menu option" << std::endl;
                std::cout << "Would you like to encode or decode a message?" << std::endl
                    << "1) Encode" << std::endl
                    << "2) Decode" << std::endl
                    << "3) Quit" << std::endl;
                std::cin >> selection2;
            }
    }
    return selection2; 
}

void menu()
{
    int selection = 0;

    std::cout << "Select from one of the ciphers below:" << std::endl
        << "1) Atbash Cipher" << std::endl
        << "2) Caesar Cipher" << std::endl
        << "3) Affine Cipher" << std::endl
        << "4) Vigenere Cipher" << std::endl
        << "5) Exit" << std::endl;
    std::cin >> selection;

    while (selection != -1) {
        switch (selection) {

            case 1:
                // Atbash - encodes message with the reverse of the alphabet
                selection = subMenu();
                // encode
                if (selection == 6) {
                    std::string message;
                    std::cout << "Input a message to encode." << std::endl;
                    std::cin >> message;

                }
                // decode
                else if (selection == 7) {

                }
                break;

            case 2:
                break;

            case 3:
                break;

            case 4:
                break;

            case 5:
                selection = -1;
                break;

            default:
                std::cout << "Please select from the options below." << std::endl
                    << "1) Atbash Cipher" << std::endl
                    << "2) Caesar Cipher" << std::endl
                    << "3) Affine Cipher" << std::endl
                    << "4) Vigenere Cipher" << std::endl
                    << "5) Exit" << std::endl;
                std::cin >> selection;
            }
    }
    return;
}

int main()
{
    menu();
    return 0;


}
