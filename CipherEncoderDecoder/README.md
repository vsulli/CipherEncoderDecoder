# CipherEncoderDecoder

This is a program that implements 4 common ciphers to encode and decode text using those ciphers.

[Ciphers Explanations](https://www.tutorialspoint.com/cryptography/traditional_ciphers.htm)

## Atbash Cipher

Encodes a message by reversing the alphabet. 

## Caesar Cipher / Shift Cipher

Encodes a message by replacing each letter with a different letter x units down.
- using ASCII table can add x to its value
lowercase letters are in the range (a: 97 - z: 122)
if value extends past 122: value - 122 + 97 - 1
ex) x shift of 1
z -> a (122 -> 123)
first convert letter to ascii, then do shift
end up with value of 97
convert back to letter

if shift is > 26, mod by 26


## Affine Cipher

Encodes a message by mapping a letter to its numerica equivalent, applying a mathematical function, and then converting
it back to a letter.


## Vigenere Cipher

Encodes a message by using a different Caesar cipher on each letter, where a key determines how much it increments.


TODO
- make a function to make words lowercase before feeding into encoder
- adapt Caesar cipher to work for shifts > 26