#include "menu.h"
#include <stdio.h>

void showMenu() {
    printf("==== PROGRAM MORSE ====\n");
    printf("1. Encode string ke morse\n");
    printf("2. Decode morse ke string\n");
    printf("3. Konversi file ke morse\n");
    printf("4. Exit\n");
    printf("=======================\n");
}

int getMenuChoice() {
    int ch;
    printf("Pilih menu: ");
    scanf("%d", &ch);
    return ch;
}
