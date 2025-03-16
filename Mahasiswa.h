#ifndef MAHASISWA_H
#define MAHASISWA_H

#include <stdio.h>
#include <stdlib.h>

#define nama(P) (P)->nama
#define nilaiUTS(P) (P)->nilaiUTS
#define next(P) (P)->next
#define Nil NULL
#define MAX_NAME_LENGTH 50

typedef struct tElmtList *address;
typedef struct tElmtList {
    char nama[MAX_NAME_LENGTH];
    int nilaiUTS;
    address next;
} ElmtList;

typedef struct {
    address first;
} List;

void CreateList(List *L);
void DeleteAll(List *L);
int isEmpty(List L);
void Insertascending(List *L, char nama[], int nilaiUTS);
void PrintList(List L);
void InsertDescendingnilai(List *L, char nama[], int nilaiUTS);
void PrintDescendingnilai(List L);
int CountList(List L);
void CopyL2(List L1, List *L2);
void DeleteDuplicate(List *L);

#endif
