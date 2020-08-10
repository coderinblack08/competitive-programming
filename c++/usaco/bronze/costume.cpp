#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[],int n,int t){
  int r=n-1,l=0,ans=0;
  while(l<r){
    if(arr[r]+arr[l]<=t){
      ans+=r-l;
      l++;
    }
    else if(arr[r]+arr[l]>t)
      r--;
  }
  return ans;
}

int main() {
  int n,s;
  cin>>n>>s;
  int arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
  sort(arr,arr+n);
  cout<<binarySearch(arr,n,s)<<"\n";
  return 0;
}