#define LOCAL

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#ifdef LOCAL
#include "../_header.hpp"
#endif

std::vector<int> josephus2_with_old_algo(int n, int k) {
  k += 1;
  std::vector<int> result(n, 1);
  std::queue<int> order;
  for (int i = 0; i < n; i++)
    order.push(i + 1);
  int remove = 1;
  int visited = 0;
  while (!order.empty()) {
    if (remove % k == 0) {
      remove = 1;
      result[visited] = order.front();
      order.pop();
      visited++;
    } else {
      remove += 1;
      order.push(order.front());
      order.pop();
    }
  }
  return result;
}

std::vector<int> josephus2(int N, int K) {
  std::vector<int> result(N, 1);
  std::vector<std::vector<int>> arr;
  int root = std::sqrt(N);
  int row = 0, col = 0, count = 0;
  std::vector<int> vec(root);
  // create a 2d array, having the sequence split into
  // approx root(N) rows and root(N) columns
  for (int i = 0; i < N; i++) {
    if (count > root) {
      count = 0;
      arr.push_back(vec);
      vec.clear();
      vec.reserve(root);
    }
    vec[count] = i + 1;
    count++;
  }
  // insert extra left but not enough elements as last row
  if (count > 0)
    arr.push_back(vec);

  for (int i = 0; i < N; i++) {
    int j = K % (N - i);
    // TODO: Figure out what the hell is this
  }
  return result;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int n, k;
  std::cin >> n >> k;
#ifdef LOCAL
  std::unique_ptr<TikTik> tiktik(new TikTik());
  tiktik->tik();
#endif
  std::vector<int> result = josephus2(n, k);
  for (int i = 0; i < n; i++) {
    std::cout << result[i] << " ";
  }
  std::cout << std::endl;
#ifdef LOCAL
  tiktik->tok();
  tiktik->print_time_taken();
#endif
}