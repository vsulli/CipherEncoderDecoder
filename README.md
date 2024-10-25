# CipherEncoderDecoder

This is a program that implements 4 common ciphers to encode and decode text using those ciphers.

[Ciphers Explanations](https://www.tutorialspoint.com/cryptography/traditional_ciphers.htm)

## Atbash Cipher

Encodes a message by reversing the alphabet. 

## Caesar Cipher / Shift Cipher

Encodes a message by replacing each letter with a different letter x units down.
- using ASCII table can add x to its value
lowercase letters are in the range (a: 97 - z: 122)
if value extends past 122 have to calculate new value of char
// ascii_num = ascii_num - 122 + 97 - 1;
// ascii_num = ascii_num % 122 + 97 - 1;
- 
ex) x shift of 1
z -> a (122 -> 123)
first convert letter to ascii, then do shift
end up with value of 97
convert back to letter

- if shift is > 26, mod by 26


## Affine Cipher
https://math.asu.edu/sites/default/files/affine.pdf

Encodes a message by mapping a letter to its numerical equivalent, applying a mathematical function, and then converting
it back to a letter.

Encryption function for a single letter: E(x) = (ax+b) mod m

'key' consists of two values (a & b)
a - must be prime to m (not have any factors in common with m)
a - 1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25
m = 26 (the letters of the alphabet)

My values chosen:
a - 17
b - 7

Decryption function: D(x)= a^-1 *(x-b) mod m
a^-1 modular multiplicative inverse
https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/#
// if neg res, make pos
   result = (result + m) % m;

## Vigenere Cipher

Encodes a message by using a different Caesar cipher on each letter, where a key determines how much it increments.

- choose a key
- that key is repeated until it is as long as the message to encrypt
E(x) = (x + k) mod 26
x = num of letter of message to encode
k = num of letter of key 

D(x) = (x - k) mod 26
x = num of letter of message in cipher

FUTURE CHANGES
- Affine: allow user to select a (among possible choices) and b


OTHER NOTES

- casting between types in c++
https://stackoverflow.com/questions/37497016/best-practice-in-c-for-casting-between-number-types

- power of a number in c++
 https://www.programiz.com/cpp-programming/library-function/cmath/pow

- have to include # <algorithm> in order to use std::transform 
https://en.cppreference.com/w/cpp/algorithm/transform

- in c++ have to use getline(cin, variable_name) to get full string with spaces
- getline won't function correctly unless input buffer is cleared before calling getline
	- cin.ignore(); 
	or
		- cin.clear();
        - cin.sync();

cin.ignore(256, '\n');
- ignores up to 256 characters before newline delimiter

TODO
- reformat README
