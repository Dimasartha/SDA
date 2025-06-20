#ifndef MORSE_TREE_H
#define MORSE_TREE_H

#include <stdio.h>
#include <stdbool.h>

#define MAX_MORSE_LEN 8
#define MAX_CHAR 40

// Struktur node pohon biner morse
typedef struct MorseNode {
    char info;
    struct MorseNode *left, *right;
} MorseNode;

// Fungsi ADT
MorseNode* createMorseTree();
void freeMorseTree(MorseNode* root);
void inorderTraversal(MorseNode* root);

// Konversi
void stringToMorse(MorseNode* root, const char* str, char* out);
void morseToString(MorseNode* root, const char* morse, char* out);

// File I/O
void fileToMorse(MorseNode* root, const char* infile, const char* outfile);

#endif // MORSE_TREE_H 
