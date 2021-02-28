#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m;
  cin>>n>>m;
  int d=0,i=0;
  while(n>0){
    d+=pow(10,i)*(n%m);
    n/=m;
    i++;
  }
  cout<<d;
  return 0;
}