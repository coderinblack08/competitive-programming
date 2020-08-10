#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int x,y;
  cin>>x>>y;
  int s=1,d=0,o=1;
  while(true) {
    if((o==1 && x<=y && y<=x+s)||(o==-1 && x-s<=y && y<=x)){
      d+=abs(y-x);cout<<d;break;
     }else {
       d+=s*2;s*=2;o*=-1;
     }
  }
  return 0;
}