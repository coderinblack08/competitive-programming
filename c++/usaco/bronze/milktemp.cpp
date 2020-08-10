#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll MAX_N = 2 * 1e4 + 1;

void setIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  setIO("milktemp");
  int N, X, Y, Z;
  int A[MAX_N+1], B[MAX_N+1];
  cin >> N  >> X >> Y >> Z;
  for (ll i = 0; i < N; ++i) {
    cin >> A[i] >> B[i];
  }
  sort(A, A + N);
  sort(B, B + N);
  A[N] = 1e9 + 1;
  B[N] = 1e9 + 1;
  int i = 0, j = 0;
  int current_milk = N * X;
  int answer = N * X;
  while (i < N || j < N) {
    if (A[i] <= B[j]) {
      current_milk += Y - X;
      i++;
    } else {
      current_milk += Z - Y;
      j++;
    }
    answer = max(answer, current_milk);
  }
  cout << answer;
  return 0;
}