#ifndef LINKED_H
#define LINKED_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define info(P) (P)->info
#define next(P) (P)->next
#define Nil NULL

typedef char infotype[50];  // Mengubah integer menjadi string
typedef struct tElmtList *address;
typedef struct tElmtList {
    infotype info;
    address next;
} ElmtList;

typedef struct {
    address first;
} List;

void CreateList(List *L);
void Insertfirst(List *L, char *X);
void Insertlast(List *L, char *X);
void Insertafter(List *L, char *X, char *after);
void Deletefirst(List *L);
void Deletelast(List *L);
void Delete(List *L, char *X);
void DeleteAll(List *L);
void PrintList(List L);

#endif
