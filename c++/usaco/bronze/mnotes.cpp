#include <bits/stdc++.h>
#define ll long long
using namespace std;

int binarySearch(int arr[],int n, int t){
  int r=n-1,l=0;
  while(l<=r){
    int mid=l+(r-l)/2;
    if(arr[mid]<=t&&arr[mid+1]>t&&mid!=n-1)
      return mid;
    else if(mid==n-1&&arr[mid]<=t)
      return mid;
    else if(arr[mid]<t)
      l=mid+1;
    else
      r=mid-1;
  }
  return -1;
}

int main() {
  int n,q;
  cin>>n>>q;
  int s[n],l[n];
  for(int i=0;i<n;i++){
    cin>>l[i];
    if(i==0)
      s[i]=0;
    else s[i]=s[i-1]+l[i-1];
  }
  for(int i=0;i<q;i++){
    int index,question;
    cin>>question;
    cout<<binarySearch(s,n,question)+1<<"\n";
  }
  return 0;
}