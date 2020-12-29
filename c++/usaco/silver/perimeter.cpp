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

// remember, global variables default to 0! (r)
int n, r;
char grid[1002][1002];
int region[1002][1002], area[1000000], perimeter[1000000];

// we can solve the problem by approaching it with a flood fill algorithm approach
// in this solution, we use an iterative approach

void visit(int i, int j) {
  stack<pair<int, int>> to_visit;
  // has (x, y) coords to see where to visit next
  to_visit.push({i, j});
  // start with the og point
  // while we still have to check more points
  while (!to_visit.empty()) {
    // get the current value
    pair<ll, ll> current = to_visit.top();
    // remove that after we proccess
    to_visit.pop();
    // set the i and j to our current pair
    i = current.first;
    j = current.second;
    // if it is categorized already or actually is ice cream
    if (region[i][j] != 0 || grid[i][j] == '.') {
      continue;
    }
    // if that did not pass, it means we are '#' and not categorized
    // set the region to our current number
    region[i][j] = r;
    // increase the area
    area[r]++;
    // now floodfill and try all surrounding points
    to_visit.push({i - 1, j});
    to_visit.push({i + 1, j});
    to_visit.push({i, j - 1});
    to_visit.push({i, j + 1});
  }
}

void find_perimeters() {
  // based on the region info, we can get the perimeter easily by checking if the
  // surrounding region is not ice cream!
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int reg = region[i][j];
      if (reg == 0) {
        continue;
      }
      if (region[i - 1][j] == 0) {
        perimeter[reg]++;
      }
      if (region[i + 1][j] == 0) {
        perimeter[reg]++;
      }
      if (region[i][j - 1] == 0) {
        perimeter[reg]++;
      }
      if (region[i][j + 1] == 0) {
        perimeter[reg]++;
      }
    }
  }
}

int main() {
  setIO("perimeter");
  cin >> n;
  for (int i = 0; i < n + 2; i++) {
    grid[0][i] = grid[n + 1][i] = '.';
    // set border (left and right) to be . (basically pad the borders for the floodfill)
    // we need to do this so we can calculate the perimeter later
  }
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    grid[i][0] = grid[i][n + 1] = '.';
    // same as above and pad the top and bottom
    for (ll j = 1; j <= n; j++) {
      grid[i][j] = s[j - 1];
      // set the grid to be input, we start at grid[i][1] because the sides are padded, remember?
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      // if it has no assigned region yet, and it is ice cream, then visit it and try to find all
      // other # that are part of the component of the graph
      if (grid[i][j] == '#' && region[i][j] == 0) {
        // increase the region number since we found a new region
        r++;
        // visit it (sets area and region)
        visit(i, j);
      }
    }
  }

  find_perimeters();

  int best_area = 0, best_perimeter = 0;
  // best_area = maximum possible area, best_perimeter = that best_area's component (we want to minimize this so if we have
  // an equal to the best_area but it has smaller perimeter, we can set the perimeter to the new, smaller one)
  for (int i = 1; i <= r; i++) {
    if (area[i] > best_area || (area[i] == best_area && perimeter[i] < best_perimeter)) {
      best_area = area[i];
      best_perimeter = perimeter[i];
    }
  }

  cout << best_area << " " << best_perimeter << endl;
  return 0;
}