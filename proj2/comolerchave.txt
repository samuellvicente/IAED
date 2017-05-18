#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

typedef uint32_t Key;

int main(){
	Key a;
	scanf("%" PRIx32, &a);
	printf("%" PRIx32 " %" PRIu32 "\n", a, a);
	return 0;
}
