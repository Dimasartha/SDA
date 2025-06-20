#include <stdio.h>
#include <string.h>
#include "morse_tree.h"
#include "morse_code.h"
#include "file_utils.h"
#include "menu.h"

int main() {
    MorseNode* root = createMorseTree();
    int running = 1;
    char input[256], output[1024];

    while (running) {
        showMenu();
        printf("Inorder traversal pohon Morse:\n");
    	inorderTraversal(root);
    	printf("\n\n");
        int choice = getMenuChoice();
        getchar(); // flush newline

        switch (choice) {
        case 1:
            printf("Masukkan string: ");
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = 0;
            encodeStringToMorse(root, input, output);
            printf("Kode morse: %s\n", output);
            break;
        case 2:
            printf("Masukkan kode morse (pisahkan tiap huruf dengan spasi): ");
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = 0;
            decodeMorseToString(root, input, output);
            printf("Hasil decode: %s\n", output);
            break;
        case 3:
            printf("Konversi file input.txt ke out.txt ...\n");
            convertFileToMorse(root, "input.txt", "out.txt");
            printf("Selesai. Lihat out.txt\n");
            break;
        case 4:
            running = 0;
            break;
        default:
            printf("Pilihan tidak valid!\n");
        }
        printf("\n");
    }
    freeMorseTree(root);
    return 0;
}
