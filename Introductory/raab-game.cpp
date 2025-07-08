#include <iostream>
#include <utility>
#include <vector>

void raab_game(const int N, const int A, const int B) {
  if (A + B > N || A > N - 1 || B > N - 1 || (A == 0 && B > 0) ||
      (B == 0 && A > 0)) {
    std::cout << "NO\n";
    return;
  }
  std::cout << "YES\n";
  std::vector<int> Aout(N + 1);
  std::vector<int> Bout(N + 1);
  for (int i = N; i > A + B; i--) {
    Aout[i] = i;
    Bout[i] = i;
  }
  int lowestA = B;
  int highestB = A + B;
  for (int i = A + B; i > A; i--) {
    // choose lowest B numbers out of a
    // choose highest B numbers out of b
    Aout[i] = lowestA--;
    Bout[i] = highestB--;
  }
  int highestA = A + B;
  int lowestB = A;
  for (int i = A; i > 0; i--) {
    // choose highest A numbers out of a
    // choose lowest A numbers out of b
    Aout[i] = highestA--;
    Bout[i] = lowestB--;
  }
  for (int i = 1; i <= N; i++)
    std::cout << Aout[i] << " ";
  std::cout << "\n";
  for (int i = 1; i <= N; i++)
    std::cout << Bout[i] << " ";
  std::cout << std::endl;
}

int main() {
  int t;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    int n, a, b;
    std::cin >> n >> a >> b;
    raab_game(n, a, b);
  }
  return 0;
}