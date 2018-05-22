
#include <stdio.h>
#include <limits.h>

int saturating_add(int x, int y){
	int sum = x + y;
	int isPosFlow = !(x & INT_MIN) && !(y & INT_MIN) && (sum & INT_MIN);
	int isNegFlow = (x & INT_MIN) && (y & INT_MIN) && !(sum & INT_MIN);


	(!isPosFlow || (sum = INT_MAX)) && (!isNegFlow || (sum = INT_MIN));

	return sum;
}

int main(void){
	int result = saturating_add(3, INT_MAX);
	printf("%d \n", result);	
	return 0;
}
