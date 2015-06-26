#include <iostream>
using namespace std;

int main()
{   int n,i;
    //cout << "Hello World!" << endl;
   cin>>n;
   for(i=0;i<n;i++)
   cout<<"*";
   cout<<"\n";
   int k=1;
   for(i=0;i<=n-1;i++)
   {i++;
   	for(int j=1;j<=n;j++)
   	{	if(j==n-k)
   		cout<<"*";
   		else
   		cout<<" ";
   	}
   	cout<<"\n";
   	k++;
   }
   for(i=0;i<n;i++)
   cout<<"*";
   cout<<"\n";
    return 0;
}
