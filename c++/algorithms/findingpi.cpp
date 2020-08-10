#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll p;
    double t=0;
    cin>>p;
    for(int i=0;i<p;i++){
        double d=1/(double)((i*2)+1);
        t+=(i%2==0)?d:-1*d;
    }
    cout<<t*4;
    return 0;
}

