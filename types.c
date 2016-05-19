/*
 * COMP20007 Design of Algorithms
 * Semester 1 2016
 *
 * Clement Poh (cpoh@unimelb.edu.au)
 *
 * This module provides fundamental functionality used to
 * interpret generic pointers into typed data.
 *
*/
/* Dafu Ai 766586 */
#include "types.h"

#include <string.h>
#include <stdlib.h>
#include <assert.h>

/* Returns whether n1 is equal to n2 */
bool int_eq(long e1, long e2) {
    return e1 == e2;
}

/* Prints n to file */
void int_print(FILE *file, long e) {
    fprintf(file, " %ld", e);
}

/* Returns whether str1 is equal to str2 */
bool str_eq(char *str1, char *str2) {
	if(strcmp(str1, str2) == 0){
		return true;
	}else{
		return false;
	}
}
/* Returns a copy of src */
char *str_copy(char *src) {
	char *copy;
	copy = (char*)malloc(sizeof(char)*(strlen(src)+1));
	assert(copy);
	strcpy(copy, src); 
	/* Replace \n with \0 */
	copy[strlen(copy)-1] = '\0';
    return copy;
}

/* Prints str to file */
void str_print(FILE *file, char *str) {
	if (file != NULL && str != NULL){
		fprintf(file, str);
	}
}

