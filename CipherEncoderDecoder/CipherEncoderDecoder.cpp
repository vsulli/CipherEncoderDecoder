/* CipherEncoderDecoder.cpp
* vsulli
* 5 October 2024
* Program that allows the user to determine the type of cipher
* encode a message or decode a message based on that cipher type.
*/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <string>

#include <complex>
#include <iomanip>
#include <vector>

using namespace std;

// Atbash Encoder
void atbashEncoder(std::string message) {
    std::map<char, char> letter_map = {
        {'a', 'z'},{'b', 'y'},{'c', 'x'},{'d', 'w'},{'e', 'v'},
        {'f', 'u'},{'g', 't'},{'h', 's'},{'i', 'r'},{'j', 'q'},
        {'k', 'p'},{'l', 'o'},{'m', 'n'},{'n', 'm'},{'o', 'l'},
        {'p', 'k'},{'q', 'j'},{'r', 'i'},{'s', 'h'},{'t', 'g'},
        {'u', 'f'},{'v', 'e'},{'w', 'd'},{'x', 'c'},{'y', 'b'},
        {'z', 'a'},
    };
    message.erase(std::remove_if(message.begin(), message.end(), ispunct), message.end());
    // TODO create function to convert message to lowercase


    std::string encrypted_msg = "";
    // for every index of letter in message, retrieve new letter
    // make message all lower, strip punctuation?
    for (char& c : message) {
        if (isspace(c)) {
            encrypted_msg += " ";
        }
        else {
            char letter = letter_map.at(c);
            encrypted_msg.append(1, letter);
        }
    }

    std::cout << encrypted_msg << endl;
}

// Atbash Decoder
void atbashDecoder(std::string message) {
    std::map<char, char> letter_map = {
        {'z', 'a'},{'y', 'b'},{'x', 'c'},{'w', 'd'},{'v', 'e'},
        {'u', 'f'},{'t', 'g'},{'s', 'h'},{'r', 'i'},{'q', 'j'},
        {'p', 'k'},{'o', 'l'},{'n', 'm'},{'m', 'n'},{'l', 'o'},
        {'k', 'p'},{'j', 'q'},{'i', 'r'},{'h', 's'},{'g', 't'},
        {'f', 'u'},{'e', 'v'},{'d', 'w'},{'c', 'x'},{'b', 'y'},
        {'a', 'z'},
    };
    message.erase(std::remove_if(message.begin(), message.end(), ispunct), message.end());
    // TODO create function to convert message to lowercase


    std::string decrypted_msg = "";
    // for every index of letter in message, retrieve new letter
    // make message all lower, strip punctuation?
    for (char& c : message) {
        char letter = letter_map.at(c);
        decrypted_msg.append(1, letter);
    }

    std::cout << decrypted_msg << endl;
}


// Caesar Encoder
void caesarEncoder(std::string message) {
    // using the ASCII values
    int shift;
    std::cout << "How much is the shift?" << std::endl;
    std::cin >> shift;

    // in case shift extends past 26, mod division
    shift %= 26;


    // return original message 
    if (shift == 0) {
        cout << message << endl;
        return;
    }


    std::string encrypted_msg = "";
    for (char& c : message) {
        if (isspace(c)) {
            encrypted_msg += " ";
        }
        else {
            int ascii_num = int(c);
            ascii_num += shift;
            // add to beg if value now overruns ASCII char values
            if (ascii_num > 122){
                ascii_num = ascii_num % 122 + 97 - 1;
            }
            c = char(ascii_num);
            encrypted_msg.append(1, c);
        }
    }

    std::cout << encrypted_msg << endl;


}

// Caesar Decoder
void caesarDecoder(std::string message) {

}

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
                    atbashEncoder(message);
                }
                // decode
                else if (selection == 7) {
                    std::string message;
                    std::cout << "Input a message to decode." << std::endl;
                    std::cin >> message;
                    atbashDecoder(message);
                }
                break;

            case 2:
                // Caesar - encodes a message using a shift of x characters
                selection = subMenu();

                if (selection == 6) {
                    std::string message;
                    std::cout << "Input a message to encode." << std::endl;
                    std::cin >> message;
                    caesarEncoder(message);
                }
                // decode
                else if (selection == 7) {
                    std::string message;
                    std::cout << "Input a message to decode." << std::endl;
                    std::cin >> message;
                    caesarDecoder(message);
                }

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
