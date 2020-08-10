#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m;
  cin>>n>>m;
  int s[n]={0},t[n]={0};
  for(int i=0;i<m;i++){
    int c,h,m;
    string cmd;
    cin>>c>>cmd>>h>>m;
    if(cmd=="START"){
      s[c-1]=h*60+m;
    } else {
      t[c-1]+=(h*60+m)-s[c-1];
    }
  }
  for(int i=0;i<n;i++)
	  cout<<t[i]/60<<" "<<t[i]%60<<"\n";
  return 0;
}