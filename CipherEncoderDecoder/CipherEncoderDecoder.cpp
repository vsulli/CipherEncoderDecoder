/* CipherEncoderDecoder.cpp
* vsulli
* 5 October 2024
* Program that allows the user to determine the type of cipher
* encode a message or decode a message based on that cipher type.
*/

#include <iostream>

int submenu() {
    int selection2 = 0;

    std::cout << "Would you like to encode or decode a message?" << std::endl
        << "1) Encode" << std::endl
        << "2) Decode" << std::endl
        << "3) Quit" << std:: endl;

    std::cin >> selection2;

    while (selection2 != -2){
        switch (selection2) {
            case 1:
                break;

            case 2:
                break;

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
                selection = submenu();
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
