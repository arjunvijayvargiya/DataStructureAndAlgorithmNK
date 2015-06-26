#include<stdio.h>
#include<stdlib.h>
 
int isSameBST(int a[], int b[], int n)
{
   int aleft[n], aright[n], bleft[n], bright[n];
   int i, k=0, l=0, m=0, o=0;
 
   if(n==0) return 1;
   if(a[0]!=b[0]) return 0;
   if(n==1) return 1;
 
   	for(i=1; i<n; i++)
		{
			if(a[i]<a[0])
 				aleft[k++]=a[i]; 
			else aright[l++]=a[i];
 
			if(b[i]<a[0])
 				bleft[m++]=b[i]; 
			else bright[o++]=b[i];
		}
 
   if(k!=m || l!=o) 
	   return 0;
 
   return isSameBST(aleft, bleft, k) && isSameBST(aright, bright, l);
}
 
// Driver program to test above functions
int main()
{
   int a[] = {8, 3, 6, 1, 4, 7, 10, 14, 13};
   int b[] = {8, 10, 14, 3, 6, 4, 1, 7, 13};
   int n=sizeof(a)/sizeof(a[0]);
   printf("%s\n", isSameBST(a, b, n)?"BSTs are same":"BSTs not same");
   return 0;
}
