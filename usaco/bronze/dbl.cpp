#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  string nm[7]={"Bessie","Elsie","Daisy","Gertie","Annabelle","Maggie","Henrietta"};
  int n,s[7]={0};
  cin>>n;
  for(int j=0;j<n;j++){
    string c;
    int m;
    cin>>c>>m;
    for(int i=0;i<7;i++){
      if(nm[i]==c){
        s[i]+=m;
        break;
      }
    }
  }
  int temp[7],minLastIndex=0;
  for(int i=0;i<7;i++)
    temp[i]=s[i];
  sort(temp,temp+7);
  while(minLastIndex<7&&temp[0]==temp[minLastIndex]&&temp[minLastIndex]!=0)
    minLastIndex++;
  minLastIndex--;
  int m1=temp[minLastIndex],m2=temp[minLastIndex+1],m1i,m2i,size=0;
  string input;
  for(int i=0;i<7;i++){
    if(s[i]==m1) m1i=i;
    if(s[i]==m2) m2i=i;
    if(s[i]!=0) {
      size++;
      input=nm[i];
    }
  }
  if(size==1)
    cout<<input;
  else if(minLastIndex==6||m2==temp[minLastIndex+2])
    cout<<"Tie";
  else
    cout<<nm[m2i];
  return 0;
}