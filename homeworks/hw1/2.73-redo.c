
#include <limits.h>

int saturating_add(int x, int y){
	int sum = x + y;
	int temp;
	int isPosFlow = !(x & INT_MIN) && !(y & INT_MIN) && __builtin_add_overflow(x, y, &temp);
	int isNegFlow = (x & INT_MIN) && (y & INT_MIN) && __builtin_add_overflow(x, y, &temp);


	(!isPosFlow || (sum = INT_MAX)) && (!isNegFlow || (sum = INT_MIN));

	return sum;
}
