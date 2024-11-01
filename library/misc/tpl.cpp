#include <bits/stdc++.h>

using namespace std;

template <class T>
std::istream &operator>>(std::istream &is, std::vector<T> &v) {
  for (auto &e : v) {
    is >> e;
  }
  return is;
}

template <class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v) {
  for (std::string_view sep = ""; const auto &e : v) {
    os << std::exchange(sep, " ") << e;
  }
  return os;
}

template <class T, class U = T> bool chmin(T &x, U &&y) { return y < x and (x = std::forward<U>(y), true); }
template <class T, class U = T> bool chmax(T &x, U &&y) { return x < y and (x = std::forward<U>(y), true); }

template <class T> void mkuni(std::vector<T> &v) {
  std::ranges::sort(v);
  auto result = std::ranges::unique(v);
  v.erase(result.begin(), result.end());
}

template <class T> int lwb(const std::vector<T> &v, const T &x) {
  return std::distance(v.begin(), std::ranges::lower_bound(v, x));
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
}
