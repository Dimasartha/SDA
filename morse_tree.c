#include "morse_tree.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Struktur mapping karakter ke kode morse
typedef struct {
    char info;
    const char* morse;
} MorseMap;

// Daftar mapping sesuai permintaan
static MorseMap morseTable[] = {
    {'A', "."},    {'B', "-"},    {'C', ".."},   {'D', ".-"},   {'E', "-."},   {'F', "--"},
    {'G', "..."},  {'H', "..-"},  {'I', ".-."},  {'J', ".--"},  {'K', "-.."},  {'L', "-.-"},
    {'M', "--."},  {'N', "---"},  {'O', "...."}, {'P', "...-"}, {'Q', "..-."}, {'R', "..--"},
    {'S', ".-.."}, {'T', ".-.-"}, {'U', ".--."}, {'V', ".---"}, {'W', "-..."}, {'X', "-..."},
    {'Y', "-.-."}, {'Z', "-.--"},
    {'1', "--.."}, {'2', "--.-"}, {'3', "---."}, {'4', "----"}, {'5', "....."},
    {'6', "....-"}, {'7', "...-."}, {'8', "...--"}, {'9', "-...."}, {'0', "-...-"},
    {' ', "-..-."}
};
static int morseTableSize = sizeof(morseTable)/sizeof(MorseMap);

// Membuat node baru
static MorseNode* newNode(char info) {
    MorseNode* node = (MorseNode*)malloc(sizeof(MorseNode));
    node->info = info;
    node->left = node->right = NULL;
    return node;
}

// Membuat pohon morse sesuai mapping
MorseNode* createMorseTree() {
    MorseNode* root = newNode('#'); // root dummy
    for (int i = 0; i < morseTableSize; ++i) {
        MorseNode* curr = root;
        const char* code = morseTable[i].morse;
        for (int j = 0; code[j]; ++j) {
            if (code[j] == '.') {
                if (!curr->left) curr->left = newNode('#');
                curr = curr->left;
            } else if (code[j] == '-') {
                if (!curr->right) curr->right = newNode('#');
                curr = curr->right;
            }
        }
        curr->info = morseTable[i].info;
    }
    return root;
}

void freeMorseTree(MorseNode* root) {
    if (!root) return;
    freeMorseTree(root->left);
    freeMorseTree(root->right);
    free(root);
}

void inorderTraversal(MorseNode* root) {
    if (!root) return;
    inorderTraversal(root->left);
    if (root->info != '#') printf("%c ", root->info);
    inorderTraversal(root->right);
}

// Helper: cari morse dari karakter
static const char* charToMorse(char c) {
    c = toupper((unsigned char)c);
    for (int i = 0; i < morseTableSize; ++i) {
        if (morseTable[i].info == c) return morseTable[i].morse;
    }
    return NULL;
}

// Helper: cari karakter dari morse
static char morseToChar(MorseNode* root, const char* code) {
    MorseNode* curr = root;
    for (int i = 0; code[i]; ++i) {
        if (code[i] == '.') {
            if (!curr->left) return '?';
            curr = curr->left;
        } else if (code[i] == '-') {
            if (!curr->right) return '?';
            curr = curr->right;
        }
    }
    return curr->info;
}

// Konversi string ke morse
void stringToMorse(MorseNode* root, const char* str, char* out) {
    out[0] = '\0';
    for (int i = 0; str[i]; ++i) {
        const char* morse = charToMorse(str[i]);
        if (morse) {
            strcat(out, morse);
            strcat(out, " ");
        }
    }
}

// Konversi morse ke string
void morseToString(MorseNode* root, const char* morse, char* out) {
    int outIdx = 0;
    char code[MAX_MORSE_LEN];
    int codeIdx = 0;
    for (int i = 0; ; ++i) {
        char c = morse[i];
        if (c == '.' || c == '-') {
            code[codeIdx++] = c;
        } else if (c == ' ' || c == '\0') {
            if (codeIdx > 0) {
                code[codeIdx] = '\0';
                out[outIdx++] = morseToChar(root, code);
                codeIdx = 0;
            }
            if (c == '\0') break;
        }
    }
    out[outIdx] = '\0';
}

// File I/O: konversi isi file ke morse dan simpan ke file lain
void fileToMorse(MorseNode* root, const char* infile, const char* outfile) {
    FILE* fin = fopen(infile, "r");
    FILE* fout = fopen(outfile, "w");
    if (!fin || !fout) {
        printf("Gagal membuka file!\n");
        if (fin) fclose(fin);
        if (fout) fclose(fout);
        return;
    }
    char line[256], morse[1024];
    while (fgets(line, sizeof(line), fin)) {
        stringToMorse(root, line, morse);
        fprintf(fout, "%s\n", morse);
    }
    fclose(fin);
    fclose(fout);
} 
