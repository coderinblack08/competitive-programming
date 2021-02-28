#include <bits/stdc++.h>
using namespace std;

int lowerBound(int arr[],int t,int n) {
  int r=n-1,l=0,ans=-1;
  while(l<=r){
    int mid=l+(r-l)/2;
    if(arr[mid]==t){
      ans=mid;
      r=mid-1;
    }
    else if(arr[mid]>t)
      r=mid-1;
    else
      l=mid+1;
  }
  return ans;
}

int main() {
  int n,q;
  cin>>n>>q;
  int arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
  for(int i=0;i<q;i++){
    int t;
    cin>>t;
    cout<<lowerBound(arr,t,n)<<"\n";
  }
  return 0;
}