/*
 Author: Dafu Ai 766586
*/
#include "hash.h"
#include "hashtable.h"
#include <stdlib.h>
#include <string.h>

#define MAXSTRLEN 256

/* Used as the second hashing function on double hash */
unsigned int linear_probe(void *e, unsigned int size) {
	/* In order to hash e into closet following empty cell */
    return 1;
}

/* Very simple hash */
unsigned int worst_hash(void *e, unsigned int size) {
    (void) e;
    (void) size;
    return 0;
}

/* Basic numeric hash function */
unsigned int num_hash(long n, unsigned int size) {
    return n % size;
}

/* Bad hash function */
unsigned int bad_hash(char *key, unsigned int size) {
	static unsigned int a;
	static int flag = 1;
	if (flag == 1){
	/* To be consistent only assgn to a once */
		/* Assume strand() has been called */
		a = rand()%size;
		flag ++;
	}
	return (a*key[0])%size;
}

/* Universal hash function as described in Dasgupta et al 1.5.2 */
unsigned int universal_hash(unsigned char *key, unsigned int size) {
    int n, i, sum = 0;
	static int r[MAXSTRLEN];
	static int flag = 1;
	if (flag == 1){
	/* To be consistent only assgn to r once */
		for (i=0; i<MAXSTRLEN; i++) {
			/* Assume strand() has been called */
			r[i] = rand()%size;
		}
		flag ++;
	}
    /* Determine n of the summation*/
    /* Assume maximum string length MAXSTRLEN*/
    n = strlen((char*)key);

    for (i=0; i<n; i++){
    	sum = sum + r[i]*key[i];
    }
    
	return sum%size;
}
