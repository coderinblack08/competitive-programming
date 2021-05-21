#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;

void setIO(string s = "") {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  if ((int)s.size()) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
  }
}

int n, arr[100000];

int main() {
  setIO("herding");
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  int max_ans = max(arr[n - 2] - arr[0], arr[n - 1] - arr[1]) - (n - 2);
  int min_ans = 0;
  if (arr[n - 2] - arr[0] == n - 2 && arr[n - 1] - arr[n - 2] > 2)
    min_ans = 2;
  else if (arr[n - 1] - arr[1] == n - 2 && arr[1] - arr[0] > 2)
    return 2;
  else {
    int p1 = 0, p2 = 0;
    int max_range = 0;
    for (; p1 < n; p1++) {
      while (p2 < n - 1 && arr[p2 + 1] - arr[p1] <= n - 1) p2++;
      max_range = max(max_range, p2 - p1 + 1);
    }
    min_ans = n - max_range;
  }
  cout << min_ans << endl
       << max_ans << endl;
  return 0;
}