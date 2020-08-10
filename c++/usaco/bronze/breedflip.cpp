#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("breedflip.in","r",stdin);
  freopen("breedflip.out","w",stdout);
  int n,ans=0;
  string a,b;
  cin>>n>>a>>b;
  bool mismatched=false;
  for(int i=0;i<n;i++){
    if(a[i]!=b[i]){
      if(!mismatched){
        ans++;
        mismatched=true;
      }
    } else {
      mismatched=false;
    }
  }
  cout<<ans;
  return 0;
}