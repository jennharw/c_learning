#include <stdio.h>

int main(){
	int a;
	int * pa;

	int arry[1];

	pa = &a;
	*pa = 0x77;

	arry[0] = 0x55;

	return 1;
}
