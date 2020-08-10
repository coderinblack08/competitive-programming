#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  freopen("square.in","r",stdin);
  freopen("square.out","w",stdout);
  int x,y;
  int lx=0,sx=10,ly=0,sy=10;
  for(int i=0;i<4;i++){
    cin>>x>>y;
    lx=max(lx,x);
    ly=max(ly,y);
    sx=min(sx,x);
    sy=min(sy,y);
  }
  int rx=lx-sx,ry=ly-sy,a;
  if(rx>ry)
    a=rx*rx;
  else
    a=ry*ry;
  cout<<a;
  return 0;
}