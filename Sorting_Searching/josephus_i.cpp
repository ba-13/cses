#define LOCAL
#include <bits/stdc++.h>
#ifdef LOCAL
#include "../_header.hpp"
#endif

std::vector<int> josephus(int n) {
  std::vector<int> result(n, 1);
  std::vector<int> order(n);
  int idx = 0;
  bool remove = false;
  int visited = 0;
  while (visited < n) {
    if (order[idx] < 0) {
      // this cell has been visited before
      // check its value to know how much to jump
      idx = (idx - order[idx]) % n;
    } else {
      if (remove) {
        remove = false;
        result[visited] = idx + 1;
        visited += 1;
        // remove this cell, borrow the next valid cell's location
        // from the next cell
        if (order[(idx + 1) % n] < 0)
          order[idx] = order[(idx + 1) % n] - 1;
        else
          order[idx] = -1;
        idx = (idx - order[idx]) % n;
      } else {
        remove = true;
        // don't do anything to this cell
        // just move ahead, the next cell would tell you where to land
        idx = (idx + 1) % n;
      }
    }
  }
  return result;
}

std::vector<int> josephus_queue(int n) {
  std::vector<int> result(n);
  std::queue<int> order;
  for (int i = 0; i < n; i++)
    order.push(i + 1);
  bool remove = false;
  int visited = 0;
  while (!order.empty()) {
    if (remove) {
      remove = false;
      result[visited] = order.front();
      order.pop();
      visited++;
    } else {
      remove = true;
      order.push(order.front());
      order.pop();
    }
  }
  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int n;
  std::cin >> n;
#ifdef LOCAL
  TikTik tiktik;
  tiktik.tik();
#endif
  std::vector<int> result = josephus_queue(n);
  for (int i = 0; i < n; i++)
    std::cout << result[i] << " ";
  std::cout << std::endl;
#ifdef LOCAL
  std::cout << "Time taken: " << tiktik.tok() << "ms";
#endif
  return 0;
}