#include"myheader.h"

void Fatal(char *ErrorMessage)
{
	char Message[100];
	strcpy(Message,"[!!]Fatal Error: ");
	strncat(Message,ErrorMessage,strlen(ErrorMessage));

	perror(Message);

	return;
}

BOOL CheckAddresses(unsigned long long int ValueChecked)
{
	if(ValueChecked == 0)	//For 64-bits --> 8 bytes
	{
		Fatal("There is an invalid address value!");
		exit(-1);
	}

	return TRUE;
}

void *ECMalloc(unsigned int size)
{
	void *Pointer;
	Pointer=malloc(size);
	
	if(Pointer == NULL)
	{
		Fatal("Failed to allocate memory!\n");
		exit(-1);
	}

	return Pointer;
}
