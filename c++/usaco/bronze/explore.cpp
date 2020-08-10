#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool comp(int a,int b){
  return abs(a)<abs(b);
}

int main() {
  int t,n;
  cin>>t>>n;
  int l[n];
  for(int i=0;i<n;i++)
    cin>>l[i];
  sort(l,l+n,comp);
  int d=0,i=0,total=0,a=0;
  while(d<t){
    d+=abs(a-l[i]);
    a=l[i];
    total++;
    i++;
  }
  cout<<total-1;
  return 0;
}