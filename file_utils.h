#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include "morse_tree.h"

int readTextFile(const char* filename, char* buffer, int maxlen);
int writeTextFile(const char* filename, const char* buffer);
void convertFileToMorse(MorseNode* root, const char* infile, const char* outfile);

#endif
