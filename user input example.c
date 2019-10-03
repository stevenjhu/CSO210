#include <stdio.h>	//must have for printf
#include <string.h> //for string operations

int main()
{
	//int c;
	// int *a = &c;
	// c = 1;
	// *a = 1;

	char in[100];
	
	printf("The first input > " );
	//scanf(" %s\n",a);
	fgets(in,100,stdin);
	in[strcspn(in,"\n")]='\0'; //input remove line example
	printf("%s\n",in);
	
	
	printf("The second input > " );
	//scanf("%s\n",a);
	fgets(in,100,stdin);
	printf("%s\n",in);
}