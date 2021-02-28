#include <bits/stdc++.h>
using namespace std;

int main() {
  string a,b;
  cin>>a>>b;
  int l=0;
  for(int i=0;i<min(a.length(),b.length());i++){
    if(a.substr(a.length()-i,a.length())==b.substr(0,i))
      l=max(l,i);
    if(b.substr(b.length()-i,b.length())==a.substr(0,i))
      l=max(l,i);
  }
  cout<<l;
  return 0;
}