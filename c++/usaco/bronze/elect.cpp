#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Cow {
  int first,second,index;
};

bool comp1(Cow a,Cow b){
  return a.first>b.first;
}

bool comp2(Cow a,Cow b){
  return a.second>b.second;
}

int main() {
  int n,k;
  cin>>n>>k;
  Cow c[n];
  for(int i=0;i<n;i++){
    cin>>c[i].first>>c[i].second;
    c[i].index=i+1;
  }
  sort(c,c+n,comp1);
  sort(c,c+k,comp2);
  cout<<c[0].index;
  return 0;
}