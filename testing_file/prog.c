/* Preprocessor command to load in a file called stdio.h from a library
*/

#include <stdio.h>

int fac(int x)
{
	int prod =1;
	for(int i = 1; i<= x; i++)
		prod = prod * i;
	return prod;
}



//Every program must have a main() function.
//main() can take parameters, but doesn't have to

int main()
{
	printf("Hello World\n");
	printf("%d factorial = %d\n", 5, fac(5));

}
//compile using gcc + file name with .format
//compile to a more sensible name gcc -o + file name with .format
//run using command ./a.out (on macs)
//					./a 	(on Windows)

