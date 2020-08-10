#include <bits/stdc++.h>
using namespace std;

struct Cow {
  int t,l;
};

bool comp(Cow a,Cow b){
  return a.t<b.t;
}

int main() {
  int n;
  cin>>n;
  Cow c[n];
  for(int i=0;i<n;i++){
    cin>>c[i].t>>c[i].l;
  }
  sort(c,c+n,comp);
  int t=0;
  for(int i=0;i<n;i++){
    if(c[i].t>t)t+=(c[i].t-t)+c[i].l;
    else t+=c[i].l;
  }
  cout<<t;
  return 0;
}