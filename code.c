#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int price, int money, int count);

int main(){
	long long result = solution(3, 20, 4);
	printf("%lld\n", result);
	return 0;
}

long long solution(int price, int money, int count){
	int n = 1;
	int total = 0;

	while (count--){
		total += price * n++;
		printf("%d %d total %d\n", count, price, total);
	}
	
	printf("%d %d \n", total, money);
	if (total > money){
		return total - money;
	}
	return 0;
}


