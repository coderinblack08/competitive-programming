#include <bits/stdc++.h>
#define ll long long
using namespace std;

int comp(int a,int b){
  return a>b;
}

int main() {
  int n,b;
  cin>>n>>b;
  int h[n];
  for(int i=0;i<n;i++)
    cin>>h[i];
  sort(h,h+n,comp);
  int s=0,p=0,t=0;
  while(s<b){
    s+=h[p];
    t++;
    p++;
  }
  cout<<t;
  return 0;
}