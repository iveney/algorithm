#include<bits/stdc++.h>
using namespace std;
int binary(int arr[],int x,int l,int r)
{int mid;
if(r>=l){
mid=l+(r-l)/2;
if(arr[mid]==x)
return mid;
else if(arr[mid]>=x)
return binary(arr,x,l,mid-1);
return binary(arr,x,mid+1,r);
}
return -1;}
int main ()
{
int i,x,mid,arr[10];
cin>>x;
for(i=0;i<10;i++)
cin>>arr[i];
mid=binary(arr,x,0,9);
cout<<"index at"<<mid+1;
return 0;
}
