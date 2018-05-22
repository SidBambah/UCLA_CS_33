

//Sidharth Bambah UID:904787435

static float u2f(unsigned u){
union converter{
	unsigned i;
	float f;
};
union converter s1;
s1.i = u;
return s1.f;
}

float fpwr4(int x){
/* Result exponent and fraction */
unsigned exp, frac;
unsigned u;
if (x < -75){
	/* Too small. Return 0.0 */
	exp = 0;
	frac = 0;
} else if (x < -63){
	/* Denormalized result */
	exp = 0;
	frac = 1 << (2 * x);
} else if (x < 64){
	/* Normalized result. */
	exp = 2 * x + 127;
	frac = 0;
} else{
	/* Too big. Return +infinity */
	exp = 0xFF;
	frac = 0;
}

/* Pack exp and frac into 32 bits */
u = exp << 23 | frac;
/* Return as float */
return u2f(u);
}