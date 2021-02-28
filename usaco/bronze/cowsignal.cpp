#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int m,n,k;
  string output="";
  cin>>m>>n>>k;
  while(m--){
    string newstring="";
    for(int i=0;i<n;i++){
      char c;
      cin>>c;
      newstring+=string(k,c);
    }
    for(int j=0;j<k;j++)
      cout<<newstring<<"\n";
  }
  return 0;
}