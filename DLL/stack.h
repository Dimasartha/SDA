#ifndef STACK_H
#define STACK_H
#include "linked.h"

#include<stdio.h>
#include<stdlib.h>

typedef List Stack;

void CreateStack(Stack *S);
void Push(Stack *S, infotype X);
int Pop(Stack *S);
int IsEmpty(Stack S);
void PrintStack(Stack S);
void ClearStack(Stack *S);
void ConvertToBinary(int N);

#endif
