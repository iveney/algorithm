/* Binary Search Algorithm*/
#include<bits/stdc++.h>
using namespace std;
int main ()
{
long long int n,i,x,ub=9,lb=0,a[201201],mid;
cin>>x;
for(i=0;i<10;i++)
cin>>a[i];
while(1)
{
mid=(lb+ub)/2;
if(x==mid){
cout<<mid;return 0;}
else if(a[mid]>x)
lb=mid+1;
else
ub=mid-1;}
return 0;
}
