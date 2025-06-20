#ifndef MORSE_CODE_H
#define MORSE_CODE_H

#include "morse_tree.h"

void encodeStringToMorse(MorseNode* root, const char* str, char* out);
void decodeMorseToString(MorseNode* root, const char* morse, char* out);

#endif
