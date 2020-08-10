#include <bits/stdc++.h>
using namespace std;

struct Bale {
  int pos,size;
};

bool comp(Bale a, Bale b){
  return a.pos<b.pos;
}

int main(){
  int n,c=0;
  cin>>n;
  Bale g[n];
  for(int i=0;i<n;i++)
    cin>>g[i].size>>g[i].pos;
  sort(g,g+n,comp);
  for(int i=0;i<n-1;i++){
    int left=i,right=i+1;
    int area=g[i+1].pos-g[i].pos;
    while(left>=0&&right<n){
      bool broken=false;
      int curArea=g[right].pos-g[left].pos;
      if(curArea>g[left].size){
        left--;
        broken=true;
      }
      if(curArea>g[right].size){
        right++;
        broken=true;
      }
      if(!broken)
        break;
    }
    if(left>=0&&right<n)
      c+=area;
  }
  cout<<c;
  return 0;
}
