#include <bits/stdc++.h>
using namespace std;

 bool hn(int n){
    int s=0,n2=n;
    while(n2>0){
        s+=n2%10;
        n2/=10;
    }
    if((double)n/s==floor((double)n/s))return true;
    return false;
}

int main(){
    int n;
    cin>>n;
    if(hn(n))cout<<"true";
    else cout<<"false";
    return 0;
}