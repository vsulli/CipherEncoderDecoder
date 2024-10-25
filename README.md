# CipherEncoderDecoder

This is a program that implements 4 common ciphers (Atbash, Caesar, Affine, & Viginere) to encode and decode text. 

[Ciphers Explanations](https://www.tutorialspoint.com/cryptography/traditional_ciphers.htm)

## Atbash Cipher

Encodes a message by reversing the alphabet. 

- a simple map was used for quick lookups for each character

## Caesar Cipher / Shift Cipher

Encodes a message by replacing each letter with a different letter x units away.

- using the ASCII table you can add x to the current character's value
 
lowercase letters are in the range (a: 97 - z: 122)

if a value goes below 97 or extends past 122 you have to calculate the new value of the char

asciiNum = 122 - 97 % asciiNum + 1;

asciiNum = asciiNum % 122 + 97 - 1;


## Affine Cipher

[Affine Cipher Description](https://math.asu.edu/sites/default/files/affine.pdf)

Encodes a message by mapping a letter to its numerical equivalent, applying a mathematical function, and then converting
it back to a letter.

**Encryption Function** 

E(x) = (ax+b) mod m

'key' consists of two values (a & b)
- a - must be prime to m (not have any factors in common with m)
- a - 1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25
- m = 26 (the letters of the English alphabet)

My values chosen:
a = 17
b = 7

**Decryption function**

D(x)= a^-1 *(x-b) mod m

a^-1 is the modular multiplicative inverse

[Modular multiplicative inverse](https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/#)

if neg res, make pos

   - result = (result + m) % m;

## Vigenere Cipher

Encodes a message by using a different Caesar cipher on each letter, where a key determines how much it increments.

- choose a key
- that key is repeated until it is as long as the message to encrypt

**Encryption Function**

E(x) = (x + k) mod 26
- x = num of letter of message to encode from map
- k = num of letter of key 

**Decryption Function**

D(x) = (x - k) mod 26
- x = num of letter of message in cipher to decode from map

## FUTURE CHANGES

- Affine: allow user to select a (among possible choices) and b


## RESEARCH NOTES

[Casting between types in c++](https://stackoverflow.com/questions/37497016/best-practice-in-c-for-casting-between-number-types)

[Power function](https://www.programiz.com/cpp-programming/library-function/cmath/pow)

[Algorithms library](https://en.cppreference.com/w/cpp/algorithm)

- have to include # <algorithm> in order to use std::transform 

[Transform function](https://en.cppreference.com/w/cpp/algorithm/transform)

- in c++ you have to use getline(cin, variable_name) to get full string with spaces

- getline won't function correctly unless input buffer is cleared before calling getline
	
	- cin.clear();
    - cin.sync();
	
	or
 
	- cin.ignore(); 

cin.ignore(256, '\n');

- ignores up to 256 characters before newline delimiter

