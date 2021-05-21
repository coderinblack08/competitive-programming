#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;

void setio(string s = "") {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if ((int)s.size()) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
  }
}

int main() {
  setio();
  int n, k;
  cin >> n >> k;
  int psum[n + 1] = {0};
  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    psum[a - 1]++;
    psum[b]--;
  }
  vector<int> nums;
  int count = 0;
  for (int i = 0; i < n; i++) {
    count += psum[i];
    nums.push_back(count);
  }
  sort(all(nums));
  cout << nums[n / 2] << endl;
  return 0;
}