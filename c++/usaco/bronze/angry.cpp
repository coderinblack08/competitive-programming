#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int n;
  cin>>n;
  int nl[n];
  for(int i=0;i<n;i++){
    cin>>nl[i];
  }
  sort(nl,nl+n);
  int m=0;
  for(int i=0;i<n;i++){
    int r=1,t=i,c=1;
    while(t<n&&nl[t+1]<=nl[t]+r){
      int j=1,b=1;
      while(nl[t+1+b]<=nl[t]+r)
        j++;
      c+=j;
      r++;
      t++;
    }
    t=i;
    r=1;
    while(t>0&&nl[t+1]>=nl[t]+r){
      int j=1,b=1;
      while(nl[t+1+b]>=nl[t]+r)
        j++;
      c+=j;
      t--;
      r++;
    }
    m=max(m,c);
  }
  cout<<m;
  return 0;
}