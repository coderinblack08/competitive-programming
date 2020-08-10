#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  int ar[n];
  for(int i=0;i<n;i++)
    cin>>ar[i];
  int s[n];
  for(int i=0;i<n;i++)
    s[i]=ar[i];
  sort(s,s+n);
  int c=0;
  for(int i=0;i<n;i++){
    if(s[i]!=ar[i])c++;
  }
  cout<<c-1;
  return 0;
}