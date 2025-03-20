#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int main() {
	int n;
	
	printf("Masukkan bilangan desimal: ");
	scanf("%d", &n);
	
	ConvertToBinary(n);
	
	return 0;
}

