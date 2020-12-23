// #include <bits/stdc++.h>
// #define all(x) (x).begin(), (x).end()
// #define ll long long
// using namespace std;

// void setIO(string s) {
//   ios_base::sync_with_stdio(0);
//   cin.tie(0);
//   freopen((s + ".in").c_str(), "r", stdin);
//   freopen((s + ".out").c_str(), "w", stdout);
// }

// ll cowIndex(string cow) {
//   vector<string> cows = {"Bessie", "Elsie", "Mildred"};
//   for (ll i = 0; i < cows.size(); i++) {
//     if (cows[i] == cow) {
//       return i;
//     }
//   }
//   return -1;
// }

// bool comp(array<string, 3> a, array<string, 3> b) {
//   return stoi(a[0]) < stoi(b[0]);
// }

// int main() {
//   // setIO("measurement");
//   ll n;
//   cin >> n;
//   vector<ll> lb(3, 7);
//   vector<array<string, 3>> entries(n);
//   for (ll i = 0; i < n; i++) {
//     cin >> entries[i][0] >> entries[i][1] >> entries[i][2];
//   }
//   sort(all(entries), comp);
//   ll best = -1, bestCow = -1, count = 0;
//   for (ll i = 0; i < entries.size(); i++) {
//     auto entry = entries[i];
//     ll day = stoi(entry[0]);
//     string cow = entry[1];
//     ll arg = stoi(entry[2]);

//     lb[cowIndex(cow)] += arg;
//     if (lb[cowIndex(cow)] >= best) {
//       best = lb[cowIndex(cow)];
//       bestCow = cowIndex(cow);
//       count++;
//     } else if (bestCow == cowIndex(cow)) {
//       ll temp = 0;
//       for (ll i = 0; i < 3; i++) {
//         if (cowIndex(cow) == i) {
//           continue;
//         }
//         if (lb[cowIndex(cow)] >= lb[i]) {
//           temp++;
//         }
//       }
//       if (temp == 2) {
//         best = lb[cowIndex(cow)];
//         bestCow = cowIndex(cow);
//         count++;
//       }
//     }
//   }
//   cout << count << endl;
//   return 0;
// }

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define ll long long
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

struct Cow {
  string name;
  ll day, gain;
};

bool comp(Cow a, Cow b) {
  return a.day < b.day;
}

int main() {
  setIO("measurement");
  ll n, ans = 0;
  cin >> n;
  vector<Cow> A(n);
  for (ll i = 0; i < n; i++) {
    cin >> A[i].day >> A[i].name >> A[i].gain;
  }
  sort(all(A), comp);
  string leaderboard = "BEM";
  vector<ll> prod(3, 7);
  vector<string> cows = {"Bessie", "Elsie", "Mildred"};
  for (ll i = 0; i < n; i++) {
    ll index = -1;
    for (ll j = 0; j < 3; j++) {
      if (cows[j] == A[i].name) {
        index = j;
        break;
      }
    }
    prod[index] += A[i].gain;
    string new_leaderboard = "";
    ll winner = max(max(prod[0], prod[1]), prod[2]);
    for (ll j = 0; j < 3; j++) {
      if (winner == prod[j]) {
        new_leaderboard += cows[j][0];
      }
    }
    if (leaderboard != new_leaderboard) {
      leaderboard = new_leaderboard;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}