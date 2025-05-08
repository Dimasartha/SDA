#ifndef LINKED_H
#define LINKED_H

#include <stdio.h>
#include <stdlib.h>

#define info(P) (P)->info
#define next(P) (P)->next
#define Nil NULL

typedef int infotype;
typedef struct tElmtList *address;
typedef struct tElmtList {
    infotype info;
    address next;
} ElmtList;

typedef struct {
    address first;
} List;

void CreateList(List *L);
void Insertfirst(List *L, infotype X);
void Insertlast(List *L, infotype X);
void Insertafter(List *L, infotype X, infotype after);
void Deletefirst(List *L);
void Deletelast(List *L);
void Delete(List *L, infotype X);
void DeleteAll(List *L);
void PrintList(List L);

#endif
