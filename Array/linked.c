#include<stdio.h>
#include "linked.h"

void CreateList(List *L) {
    L->first = Nil;
}

void Insertfirst(List *L, infotype X) {
    address P = (address)malloc(sizeof(ElmtList));
    if (P != Nil) {
        info(P) = X;
        next(P) = L->first;
        L->first = P;
    }
}

void Insertlast(List *L, infotype X) {
    address P = (address)malloc(sizeof(ElmtList));
    if (P != Nil) {
        info(P) = X;
        next(P) = Nil;
        if (L->first == Nil) {
            L->first = P;
        } else {
            address Q = L->first;
            while (next(Q) != Nil) {
                Q = next(Q);
            }
            next(Q) = P;
        }
    }
}

void Insertafter(List *L, infotype X, infotype after) {
    address P = (address)malloc(sizeof(ElmtList));
    if (P != Nil) {
        info(P) = X;
        address Q = L->first;
        while (Q != Nil && info(Q) != after) {
            Q = next(Q);
        }
        if (Q != Nil) {
            next(P) = next(Q);
            next(Q) = P;
        }
    }
}

void Deletefirst(List *L) {
    if (L->first != Nil) {
        address P = L->first;
        L->first = next(P);
        free(P);
    }
}

void Deletelast(List *L) {
    if (L->first != Nil) {
        address P = L->first;
        address prev = Nil;
        while (next(P) != Nil) {
            prev = P;
            P = next(P);
        }
        if (prev == Nil) { 
            L->first = Nil;
        } else {
            next(prev) = Nil;
        }
        free(P);
    }
}

void Delete(List *L, infotype X) {
    if (L->first != Nil) {
        address P = L->first;
        address prev = Nil;
        while (P != Nil && info(P) != X) {
            prev = P;
            P = next(P);
        }
        if (P != Nil) {
            if (prev == Nil) {
                L->first = next(P);
            } else {
                next(prev) = next(P);
            }
            free(P);
        }
    }
}

void DeleteAll(List *L) {
    address P;
    while (L->first != Nil) {
        P = L->first;
        L->first = next(P);
        free(P);
    }
}

void PrintList(List L) {
    address P = L.first;
    printf("elemen List = {");
    while (P != Nil) {
        printf("%d", info(P));
        if (next(P) != Nil) {
            printf(", ");
        }
        P = next(P);
    }
    printf("}\n");
}
