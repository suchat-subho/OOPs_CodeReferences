/* Array static initialization example:
In this case 'a' was initialized to all zeros and, 'b' being uninitialized having garbade values.

Also check the return value by using the following command just after the execution 
echo $? (in linux)
   
*/

#include<stdio.h>
int main(int argc, char const *argv[])
{
	int a[10] = {};
	int b[10];
	for(int i=0; i<10;i++){
		printf("a[%d],= %d\n",i,a[i]);
		printf("b[%d],= %d\n",i,b[i]);
	}
	return 5;
}

