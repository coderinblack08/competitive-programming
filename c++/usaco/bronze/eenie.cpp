#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  int n,l,a;
  cin>>n>>l;
  int r[n]={0};
  bool rm[n]={0};
  for(int i=0;i<l;i++)
    cin>>r[i];
  int c=n,pos=-1,cur=0;
  while(c>1) {
    int rn=r[cur];
    while(rn>0){
      pos+=1;
      pos=pos%n;
      if(!rm[pos])rn--;
    }
    rm[pos]=1;
    c--;
    cur++;
    cur=cur%l;
  }
  for(int i=0;i<n;i++){
    if(!rm[i]){
      cout<<i+1<<"\n";
      break;
    }
  }
  return 0;
}