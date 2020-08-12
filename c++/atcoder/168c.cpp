#include <bits/stdc++.h>
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s+".in").c_str(),"r",stdin);
  freopen((s+".out").c_str(),"w",stdout);
}

double degrees_radian(double degrees){ 
  return degrees * M_PI / 180;
} 

int main() {
  ll a, b, h, m;
  cin >> a >> b >> h >> m;
  ll angle_1 = h * 30 + m / 2, angle_2 = m * 6;
  if (angle_2 - angle_1 > 180) {
    cout << setprecision(20) << sqrt(a * a + b * b + 2 * a * b * cos(abs(degrees_radian(360 - angle_2 - angle_1))));
  } else {
    cout << setprecision(20) << sqrt(a * a + b * b + 2 * a * b * cos(abs(degrees_radian(angle_2 - angle_1))));
  }
  return 0;
}