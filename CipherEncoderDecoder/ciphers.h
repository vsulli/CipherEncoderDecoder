// ciphers header
#include <string>
using namespace std;

string getMessage(string func);

// Atbash Encoder
void atbashEncoder(string message);

// Atbash Decoder
void atbashDecoder(string message);

// Caesar Encoder
void caesarEncoder(string message);

// Caesar Decoder
void caesarDecoder(string message);

// Affine Encoder
void affineEncoder(string message);

// Modular Multiplicative Inverse
int modInverse(int a, int mod);

// Affine Decoder
void affineDecoder(string message);

// Vigenere Encoder
void viginereEncoder(string message);

// Viginere Decoder
void viginereDecoder(string message);

int subMenu();

void menu();