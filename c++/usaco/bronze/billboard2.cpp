#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool pointIn(int x,int y,int x1,int y1,int x2,int y2){
  return x>=x1&&x<=x2&&y>=y1&&y<=y2;
}

int main(){
  int x1,x2,y1,y2,x3,x4,y3,y4;
  cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
  int points=0;
  if(pointIn(x1,y1,x3,y3,x4,y4))points++;
  if(pointIn(x1,y2,x3,y3,x4,y4))points++;
  if(pointIn(x2,y2,x3,y3,x4,y4))points++;
  if(pointIn(x2,y1,x3,y3,x4,y4))points++;
  if(points<2)
    cout<<(x2-x1)*(y2-y1);
  else if(points==4)
    cout<<0;
  else
    cout<<(x2-x1)*(y2-y1)-(min(x2,x4)-max(x1,x3))*(min(y2,y4)-max(y1,y3));
  return 0;
}

