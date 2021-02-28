#include <bits/stdc++.h>
#define ll long long
using namespace std;

int reverseNum(int a){
  int reverse=0;
  while(a>0){
    reverse=reverse*10+(a%10);
    a/=10;
  }
  return reverse;
}

bool isPalindrome(int a){
  return reverseNum(a)==a;
}

int main() {
  int n,s=0;
  cin>>n;
  while(true){
    if(isPalindrome(n))
      break;
    else {
      n+=reverseNum(n);
      s++;
    }
  }
  cout<<s<<" "<<n;
  return 0;
}