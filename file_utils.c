#include "file_utils.h"
#include <stdio.h>
#include <string.h>

int readTextFile(const char* filename, char* buffer, int maxlen) {
    FILE* f = fopen(filename, "r");
    if (!f) return 0;
    int len = fread(buffer, 1, maxlen-1, f);
    buffer[len] = 0;
    fclose(f);
    return len;
}

int writeTextFile(const char* filename, const char* buffer) {
    FILE* f = fopen(filename, "w");
    if (!f) return 0;
    int len = fprintf(f, "%s", buffer);
    fclose(f);
    return len;
}

void convertFileToMorse(MorseNode* root, const char* infile, const char* outfile) {
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
