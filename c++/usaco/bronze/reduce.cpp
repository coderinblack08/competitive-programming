#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n;
  cin>>n;
  int x[n],y[n];
  for(int i=0;i<n;i++)
    cin>>x[i]>>y[i];
  int tempx[n],tempy[n];
  for(int i=0;i<n;i++){
    tempx[i]=x[i];
    tempy[i]=y[i];
  }
  sort(tempx,tempx+n);
  sort(tempy,tempy+n);
  int x1=tempx[0],x2=tempx[1],x3=tempx[n-1],x4=tempx[n-2];
  int y1=tempy[0],y2=tempy[1],y3=tempy[n-1],y4=tempy[n-2];
  int area=(x1-x3)*(y1-y3);
  for(int i=0;i<n;i++){
    int lx=x1,hx=x3,ly=y1,hy=y3;
    if(x[i]==lx)lx=x2;
    if(x[i]==hx)hx=x4;
    if(y[i]==ly)ly=y2;
    if(y[i]==hy)hy=y4;
    area=min(area,(hx-lx)*(hy-ly));
  }
  cout<<area;
  return 0;
}
