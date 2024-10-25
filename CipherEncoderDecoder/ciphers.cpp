// ciphers file

#include "ciphers.h"
#include "globals.h"

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>


using namespace std;


string getMessage(string func) {
    cout << "Input a message to " << func << ":";
    string message;
    // flush input buffer
    cin.ignore();
    getline(cin, message);
    
    // strip all numbers
    message.erase(std::remove_if(message.begin(), message.end(), ::isdigit), message.end());

    return message;
}

string formatMessage(string message) {
    // gets rid of punctuation at beginning or end of word
    message.erase(remove_if(message.begin(), message.end(), ispunct), message.end());
    
    // converts all letters to lowercase
    std::transform(message.begin(), message.end(), message.begin(),
        [](unsigned char c) { return std::tolower(c); });
    return message;
}

// Atbash Encoder
void atbashEncoder(string message) {

    message = formatMessage(message);

    string encrypted_msg = "";
    // for every index of letter in message, retrieve new letter
    for (char& c : message) {
        if (isspace(c)) {
            encrypted_msg = encrypted_msg + " ";
        }
        else {
            char letter = letter_map.at(c);
            encrypted_msg.append(1, letter);
        }
    }

    cout << encrypted_msg << endl;
}

// Atbash Decoder
void atbashDecoder(string message) {

    message = formatMessage(message);

    string decrypted_msg = "";
    for (char& c : message) {
        if (isspace(c)) {
            decrypted_msg = decrypted_msg + " ";
        }
        else {
            char letter = letter_map.at(c);
            decrypted_msg.append(1, letter);
        }
    }

    cout << decrypted_msg << endl;
}

// Caesar Encoder
void caesarEncoder(string message) {

    message = formatMessage(message);

    int shift;
    cout << "How much is the shift?" << endl;
    cin >> shift;

    // in case shift extends past 26, mod division
    shift %= 26;

    // return original message 
    if (shift == 0) {
        cout << message << endl;
        return;
    }

    string encrypted_msg = "";
    for (char& c : message) {
        if (isspace(c)) {
            encrypted_msg += " ";
        }
        else {
            // using the ASCII values
            int ascii_num = int(c);
            ascii_num += shift;
            // add to beg if value now overruns ASCII char values
            if (ascii_num > 122) {
                ascii_num = ascii_num % 122 + 97 - 1;
            }
            c = char(ascii_num);
            encrypted_msg.append(1, c);
        }
    }
    cout << encrypted_msg << endl;
}

// Caesar Decoder
void caesarDecoder(string message) {

    message = formatMessage(message);

    int shift;
    cout << "How much is the shift?" << endl;
    cin >> shift;
    shift %= 26;

    if (shift == 0) {
        cout << message << endl;
        return;
    }

    string decrypted_msg = "";

    for (char& c : message) {
        if (isspace(c)) {
            decrypted_msg += " ";
        }
        else {
            int ascii_num = int(c);
            ascii_num -= shift;

            if (ascii_num < 97) {
                ascii_num = 122 - 97 % ascii_num + 1;
            }

            c = char(ascii_num);
            decrypted_msg.append(1, c);
        }
    }
    cout << decrypted_msg << endl;
}

// Affine Encoder
void affineEncoder(string message) {

    message = formatMessage(message);

    // E(x)=(ax+b) mod m
    // using a = 17, b = 7, m = 26
    int a = 17;
    int b = 7;
    int m = 26;

    string encrypted_msg = "";
    for (char& c : message) {
        if (isspace(c)) {
            encrypted_msg += " ";
        }
        else {
            int num = letter_map2.at(c);
            num = (a * num + b) % m;
            c = num_map.at(num);
            encrypted_msg.append(1, c);
        }
    }
    cout << encrypted_msg << endl;

}

// Modular Multiplicative Inverse
int modInverse(int a, int mod) {

    for (int x = 1; x < mod; x++) {
        if (((a % mod) * (x % mod)) % mod == 1) {
            return x;
        }
    }
}

// Affine Decoder
void affineDecoder(string message) {

    message = formatMessage(message);

    double a = 17.0;
    int result;
    double exponent = -1.0;
    int b = 7;
    int m = 26;

    string decrypted_msg = "";
    for (char& c : message) {
        if (isspace(c)) {
            decrypted_msg += " ";
        }
        else {
            // convert c -> num
            int num = letter_map2.at(c);
            result = modInverse(a, m) * (num - b) % m;
            // if neg res, make pos
            result = (result + m) % m;
            c = num_map.at(result);
            decrypted_msg.append(1, c);
        }
    }
    cout << decrypted_msg << endl;
}

// Vigenere Encoder
void viginereEncoder(string message) {

    message = formatMessage(message);

    string key;
    cout << "Input a key for the message." << endl;
    cin >> key;

    string encrypted_msg = "";
    int num;
    int k_ptr = 0;
    int m = 26;

    for (char& c : message) {
        if (isspace(c)) {
            encrypted_msg += " ";
        }
        else {
            num = letter_map2.at(c);
            // E(x) = (x + k) mod 26
            num = (letter_map2.at(c) + letter_map2.at(key.at(k_ptr))) % m;
            c = num_map.at(num);
            encrypted_msg.append(1, c);
            // increment key pointer
            k_ptr++;
            // if key pointer > indices of key, reset
            if (k_ptr > key.length() - 1) {
                k_ptr = 0;
            }
        }
    }
    cout << encrypted_msg << endl;
}

// Viginere Decoder
void viginereDecoder(string message) {

    message = formatMessage(message);

    string key;
    cout << "Input the key for the message." << endl;
    cin >> key;

    string decrypted_msg = "";
    int num;
    int k_ptr = 0;
    int m = 26;

    for (char& c : message) {
        if (isspace(c)) {
            decrypted_msg += " ";
        }
        else {
            num = letter_map2.at(c);
            // D(x) = (x - k) mod 26
            num = (letter_map2.at(c) - letter_map2.at(key.at(k_ptr))) % m;
            num = (num + m) % m;
            c = num_map.at(num);
            decrypted_msg.append(1, c);
            k_ptr++;
         
            if (k_ptr > key.length() - 1) {
                k_ptr = 0;
            }
        }
    }
    cout << decrypted_msg << endl;
}

int subMenu() {
    int selection2 = 0;

    cout << "Would you like to encode or decode a message?" << endl
        << "1) Encode" << endl
        << "2) Decode" << endl
        << "3) Quit" << endl;

    cin >> selection2;

    while (selection2 != -2) {

        switch (selection2) {

        case 1:
            return selection2 = 6;

        case 2:
            return selection2 = 7;

        case 3:
            selection2 = -2;
            break;

        default:
            cout << "Invalid Selection. Select a valid menu option" << endl;
            cout << "Would you like to encode or decode a message?" << endl
                << "1) Encode" << endl
                << "2) Decode" << endl
                << "3) Quit" << endl;
            cin >> selection2;
        }
    }
    return selection2;
}

void menu()
{
    int selection = 0;

    cout << "Select from one of the ciphers below:" << endl
        << "1) Atbash Cipher" << endl
        << "2) Caesar Cipher" << endl
        << "3) Affine Cipher" << endl
        << "4) Vigenere Cipher" << endl
        << "5) Exit" << endl;
    
    cin >> selection;
    // error handling if selection isn't a digit

    while (selection != -1) {

        switch (selection) {

        case 1:
            // Atbash - encodes message with the reverse of the alphabet
            selection = subMenu();
            
            // encode
            if (selection == 6) {
                atbashEncoder(getMessage("encode"));
            }

            // decode
            else if (selection == 7) {
                atbashDecoder(getMessage("decode"));
            }
            break;

        case 2:
            // Caesar - encodes a message using a shift of x characters
            selection = subMenu();

            
            if (selection == 6) {
                caesarEncoder(getMessage("encode"));
            }
            
            else if (selection == 7) {
                caesarDecoder(getMessage("decode"));
            }
            break;

        case 3:
            // Affine - encodes a message using a mathematical equation
            selection = subMenu();

            
            if (selection == 6) {
                affineEncoder(getMessage("encode"));
            }

            
            else if (selection == 7) {
                affineDecoder(getMessage("decode"));
            }
            break;

        case 4:
            // Viginere Cipher - encodes a message using a different caesar on each letter
            selection = subMenu();

            
            if (selection == 6) {
                viginereEncoder(getMessage("encode"));
            }
            
            else if (selection == 7) {
                viginereDecoder(getMessage("decode"));
            }
            break;

        case 5:
            selection = -1;
            break;

        default:
            cout << "Please select from the options below." << endl
                << "1) Atbash Cipher" << endl
                << "2) Caesar Cipher" << endl
                << "3) Affine Cipher" << endl
                << "4) Vigenere Cipher" << endl
                << "5) Exit" << endl;
           
            cin >> selection;
            
        }
    }
    return;
}