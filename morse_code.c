#include "morse_code.h"
#include <string.h>
#include <ctype.h>

// Implementasi mirip stringToMorse dan morseToString, tapi lebih modular
void encodeStringToMorse(MorseNode* root, const char* str, char* out) {
    stringToMorse(root, str, out);
}
void decodeMorseToString(MorseNode* root, const char* morse, char* out) {
    morseToString(root, morse, out);
}
