#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
string s;

int largestGap(){
  int l=0,s=-1;
  for(int i=0;i<n;i++){
    bool isOne=s[i]=='1';
    if(isOne){
      if(s!=-1&&i-s>l){
        l=i-s;
      }
      else if(s==-1)s=i;
    }
  }
  return l;
}

int main() {
  freopen("test.in","r",stdin);
  freopen("test.out","w",stdout);
  cin>>n>>s;
}