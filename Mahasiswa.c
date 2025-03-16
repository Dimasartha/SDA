#include <stdio.h>
#include <string.h>
#include "Mahasiswa.h"

// Creator/Constructor
void CreateList(List *L) {
    L->first = Nil;
}

// Destructor
void DeleteAll(List *L) {
    address P;
    while (L->first != Nil) {
        P = L->first;
        L->first = next(P);
        free(P);
    }
}

// Validator
int isEmpty(List L) {
    return (L.first == Nil);
}

// Get/Set
void Insertascending(List *L, char nama[], int nilaiUTS) {
    address P = (address)malloc(sizeof(ElmtList));
    if (P != Nil) {
        strcpy(nama(P), nama);
        nilaiUTS(P) = nilaiUTS;
        next(P) = Nil;
        
        if (isEmpty(*L) || strcmp(nama, L->first->nama) < 0) {
            next(P) = L->first;
            L->first = P;
        } else {
            address Q = L->first;
            while (next(Q) != Nil && strcmp(next(Q)->nama, nama) < 0) {
                Q = next(Q);
			}
            next(P) = next(Q);
            next(Q) = P;
		}
	}
}

// PrintObject
void PrintList(List L) {
    address P = L.first;
    while (P != Nil) {
        printf("%s - %d\n", nama(P), nilaiUTS(P));
        P = next(P);
    }
}

void InsertDescendingnilai(List *L, char nama[], int nilaiUTS) {
    address P = (address)malloc(sizeof(ElmtList));
    if (P != Nil) {
        strcpy(nama(P), nama);
        nilaiUTS(P) = nilaiUTS;
        next(P) = Nil;

        if (isEmpty(*L) || nilaiUTS > L->first->nilaiUTS) {
            next(P) = L->first;
            L->first = P;
        } else {
            address Q = L->first;
            while (next(Q) != Nil && next(Q)->nilaiUTS > nilaiUTS) {
                Q = next(Q);
            }
            next(P) = next(Q);
            next(Q) = P;
        }
    }
}

// Print Nilai secara Descending
void PrintDescendingnilai(List L) {
    if (isEmpty(L)) {
        printf("List Kosong\n");
        return;
    }

    List tempList;
    CreateList(&tempList);

    address P = L.first;
    while (P != Nil) {
        InsertDescendingnilai(&tempList, nama(P), nilaiUTS(P));
        P = next(P);
    }

    P = tempList.first;
    while (P != Nil) {
        printf("%s - %d\n", nama(P), nilaiUTS(P));
        P = next(P);
    }

    DeleteAll(&tempList);
}

/* Menghitung jumlah elemen dalam list */
int CountList(List L) {
    int count = 0;
    address P = L.first;
    while (P != Nil) {
        count++;
        P = next(P);
    }
    return count;
}

/* Menyalin mahasiswa dengan nilai UTS > 70 ke L2 */
void CopyL2(List L1, List *L2) {
    CreateList(L2);
    address P = L1.first;
    while (P != Nil) {
        if (nilaiUTS(P) > 70) {
            Insertascending(L2, nama(P), nilaiUTS(P));
        }
        P = next(P);
    }
}

/* Menghapus nama yang duplikat dari list */
void DeleteDuplicate(List *L) {
    address P = L->first;
    
    while (P != Nil && next(P) != Nil) {
        address Q = P;
        
        while (next(Q) != Nil) {
            if (strcmp(next(Q)->nama, nama(P)) == 0) {
                address temp = next(Q);
                next(Q) = next(Q)->next;
                free(temp);
            } else {
                Q = next(Q);
            }
        }
        
        P = next(P);
    }
}
