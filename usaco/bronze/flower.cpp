#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int f,k;
  cin>>f>>k;
  bool p[f]={false};
  for(int i=0;i<k;i++){
    int l,ii;
    cin>>l>>ii;
    for(int j=l-1;j<f;j+=ii){
      p[j]=true;
    }   
  }
  int c=0;
  for(int i=0;i<f;i++)
    if(!p[i])c++;
  cout<<c;
  return 0;
}