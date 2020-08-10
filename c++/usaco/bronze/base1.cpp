#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m;
  cin>>n>>m;
  int d=0,i=0;
  while(n>0){
    d+=pow(m,i)*(n%10);
    n/=10;
    i++;
  }
  cout<<d;
  return 0;
}