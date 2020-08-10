#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  int mid[n];
  for(int i=0;i<n;i++){
    int arr[n];
    for(int j=0;j<n;j++){
      cin>>arr[j];
    }
    sort(arr,arr+n);
    mid[i]=arr[n/2];
  }
  sort(mid,mid+n);
  cout<<mid[n/2];
  return 0;
}