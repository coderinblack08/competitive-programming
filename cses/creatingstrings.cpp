#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  vector<string> L;
  sort(s.begin(), s.end());

  do {
    L.push_back(s);
  } while (next_permutation(s.begin(), s.end()));

  cout << L.size() << "\n";
  for(auto a: L) {
    cout << a << "\n";
  }
  return 0;
}