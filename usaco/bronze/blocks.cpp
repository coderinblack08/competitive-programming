#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, alphabet[26]={0};
  cin>>n;
  for(int j=0;j<n;j++){
    string b,c;
    int used[26]={0},rest[26]={0};
    cin>>b>>c;
    for(int i=0;i<b.length();i++)
      used[b[i]-'a']++;
    for(int i=0;i<c.length();i++)
      rest[c[i]-'a']++;
    for(int i=0;i<26;i++){
      if(used[i]>=rest[i])alphabet[i]+=used[i];
      else alphabet[i]+=rest[i];
    }
  }
  for(int i=0;i<26;i++)
    cout<<alphabet[i]<<endl;
  return 0;
}
