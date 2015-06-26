#include<stdio.h>
#include<stdlib.h>
struct stack{
	int top;
	int capacity;
	int *array;
};
stack *st1=(stack *)malloc(sizeof(stack));
int main()
{   int k;
	printf("enter the stack size\n");
	scanf("%d",&k);
	st1->array=(int *)malloc(sizeof(int)*k);
	return 0;
}
