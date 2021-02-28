#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {string a,b;
ll as=1,bs=1;
cin>>a>>b;
for(int i=0;i<a.length();i++)as*=a[i]-'A'+1;
for(int i=0;i<b.length();i++)bs*=b[i]-'A'+1;
if(as%47==bs%47)cout<<"GO"<<"\n";
else cout<<"STAY"<<"\n";}