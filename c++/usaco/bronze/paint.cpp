#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  bool f[101]={false};
  for(int i=a;i<b;i++){
    f[i]=true;
  }
  for(int i=c;i<d;i++){
    f[i]=true;
  }
  int r=0;
  for(int i=0;i<101;i++)
    if(f[i])r++;
  cout<<r;
  return 0;
}