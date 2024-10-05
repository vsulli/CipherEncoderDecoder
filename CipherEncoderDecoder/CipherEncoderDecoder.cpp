/* CipherEncoderDecoder.cpp
* vsulli
* 5 October 2024
* Program that allows the user to determine the type of cipher
* encode a message or decode a message based on that cipher type.
*/

#include <iostream>

void menu()
{
    std::cout << "Select from one of the ciphers below:" << std::endl
        << "1) Atbash Cipher" << std::endl
        << "2) Caesar Cipher" << std::endl
        << "3) Affine Cipher" << std::endl
        << "4) Vigenere Cipher" << std:: endl; 

}

int main()
{
    menu();
    return 0;


}
