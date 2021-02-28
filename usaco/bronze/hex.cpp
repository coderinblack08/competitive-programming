#include <bits/stdc++.h>
using namespace std;

int main() {
  string n;
  cin>>n;
  if(n=="0"){
    cout<<0;
    return 0;
  }
  string b2="";
  for(int i=0;i<n.length();i++){
    int b16=0;
    if(n[i]-'A'>=0){
      b16=n[i]-'A'+10;
    } else {
      b16=n[i]-'0';
    }
    string b2n="";
    int j=0;
    while(b16>0){
      b2n=to_string(b16%2)+b2n;
      b16/=2;
      j++;
    }
    string b22n="";
    for(int i=0;i<4-b2n.length();i++){
      b22n+='0';
    }
    b22n+=b2n;
    b2+=b22n;
  }
  string b8="";
  int remainder=b2.length()%3;
  if(remainder!=0){
    string num=b2.substr(0,remainder);
    int b8n=0;
    for(int i=remainder-1;i>=0;i--){
      b8n+=pow(2,i)*(num[remainder-1-i]-'0');
    }
    b8+=to_string(b8n);
  }
  for(int i=0;i<b2.length()/3;i++){
    string num=b2.substr(i*3+remainder,i*3+3+remainder);
    int b8n=0;
    for(int j=2;j>=0;j--){
      b8n+=pow(2,j)*(num[2-j]-'0');
    }
    b8+=to_string(b8n);
  }
  int i=0;
  while(b8[i]=='0')i++;
  cout<<b8.substr(i,b8.length());
  return 0;
}