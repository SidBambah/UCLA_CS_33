
// Sidharth Bambah UID:904787435

long switch_prob(long x, long n) {
	long result = x;
	switch(n){
	
		case 60:
		case 62:
			result = 8 * x;
			return result;
		case 63:
			result = x;
			result = result >> 3;
			return result;
		case 64:
			result = x;
			result = result << 4;
			result -= x;
			x = result;
		case 65:		
			x *= x;
		default:
			result = x + 75;
	}
	return result;
}