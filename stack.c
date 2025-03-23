#include "Stack.h"
#include<stdio.h>
#include<stdlib.h>

// Inisialisasi Stack
void CreateStack(Stack *S) {
    CreateList(S);
}

// Cek apakah Stack kosong
int IsEmpty(Stack S) {
    return (S.first == Nil);
}

// Push
void Push(Stack *S, infotype X) {
    Insertfirst(S, X);
}

// Pop
int Pop(Stack *S) {
    if (IsEmpty(*S)) {
        printf("Stack kosong!\n");
        return -1;
    }
    
    int value = S->first->info;
    Deletefirst(S);
    
    return value;
}

// Menampilkan isi Stack
void PrintStack(Stack S) {
    PrintList(S);
}

// Menghapus semua elemen Stack
void ClearStack(Stack *S) {
    DeleteAll(S);
}
