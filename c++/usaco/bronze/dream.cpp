#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m,digits[10]={0};
  cin>>n>>m;
  for(int i=n;i<=m;i++){
    int num=i;
    while(num>0){
      digits[num%10]++;
	    num/=10;
    }
  }
  for(int i=0;i<10;i++)
	  cout<<digits[i]<<" ";
  return 0;
}