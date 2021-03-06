#ifndef _MY_HEADER
#define _MY_HEADER

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define BOOL int
#define FALSE 0
#define TRUE  1

//This function is used to print a fatal error message
void Fatal(char *ErrorMessage);

//This function is used to check the validation of several addresses,
//you can typecase several addresses to 'unsigned long long int'
//type(for 64-bits --> 8 bytes) or 'unsigned int' type(for 32-bits 4 bytes)
//then do bitwise operator '|' to the addresses,and then give the result  
//to this function as its argument.
BOOL CheckAddresses(unsigned long long int ValueChecked);

//This function is an error-checked version 'malloc' function
void *ECMalloc(unsigned int size);

#endif	
