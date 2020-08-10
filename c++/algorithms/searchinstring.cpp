#include <bits/stdc++.h>
using namespace std;

int main() {
  string p,n,c;
  cin>>n>>p;
  int t=0;
  vector<string>l;
  int a[26]={0};
  for(int i=0;i<n.length();i++){
    if(n[i]>=65&&n[i]<97)a[n[i]-'A']++;
    else a[n[i]-'a']++;
  }
  for(int i=0;i<p.length();i++){
    if(p[i]!=' ')c+=p[i];
    else c="";
    if(p[i]!=' '&&p[i+1]==' '&&i!=p.length()-1)
      l.push_back(c);
  }
  cout<<l.at(0);
  for(int i=0;i<l.size();i++)
    cout<<l.at(i)<<"\n";  
  for(int i=0;i<l.size();i++){
    int b[26]={0};
    for(int j=0;j<l.at(i).length();j++){
      if(l.at(i)[j]>=65&&l.at(i)[j]<97)a[l.at(i)[j]-'A']++;
      else a[l.at(i)[j]-'a']++;
    } 
    bool same=true;
    for(int j=0;j<26;j++)
      if(a[j]!=b[j])same=false;
    if(same)t++;
  }
  cout<<t;
}