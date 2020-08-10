#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int n;
  cin>>n;
  int ar[n];
  for(int i=0;i<n;i++)
    cin>>ar[i];
  int a=n-1;
  for(int i=n-2;i>=0;i--){
    if(ar[i]<ar[i+1])
      a=i;
    else break;
  }
  cout<<a;
  return 0;
}