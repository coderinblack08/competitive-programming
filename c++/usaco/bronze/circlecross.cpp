#include <bits/stdc++.h>
using namespace std;

int main() {
  int s[26]={0},e[26]={0};
  for(int i=0;i<52;i++){
    char a;
    cin>>a;
    if(s[a-'A']==0)s[a-'A']=i+1;
    else e[a-'A']=i+1;
  }
  int c=0;
  for(int i=0;i<26;i++)
    for(int j=0;j<26;j++)
      if(s[i]<s[j]&&e[i]<e[j]&&e[i]>s[j])
        c++;
  cout<<c;
  return 0;
}