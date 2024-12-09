#include <memory>
#include <vector>

template <typename S, typename Impl> struct SegmentTreeBase {
  explicit SegmentTreeBase(int n_) : n(n_), nodes(n << 1) {}

  S &root() { return get_node(0, n - 1); }

  const S &root() const { return get_node(0, n - 1); }

  template <typename H> H traverse_all(H &&h) {
    traverse_all(std::forward<H>(h), 0, n - 1);
    return h;
  }

  template <typename H> H traverse(H &&h, int a, int b) {
    traverse<H, 0>(std::forward<H>(h), 0, n - 1, a, b);
    return h;
  }

  template <typename H> H reverse_traverse(H &&h, int a, int b) {
    traverse<H, 1>(std::forward<H>(h), 0, n - 1, a, b);
    return h;
  }

  S &get_node(int l, int r) { return nodes[l + r | (l != r)]; }

protected:
  template <typename Op> void traverse_all(Op &&op, int l, int r) {
    S &n = get_node(l, r);
    op(l, r, n);
    if (l < r) {
      int m = (l + r) >> 1;
      S &ln = get_node(l, m);
      S &rn = get_node(m + 1, r);
      static_cast<Impl *>(this)->propagate(l, m, r, n, ln, rn);
      traverse_all(std::forward<Op>(op), l, m);
      traverse_all(std::forward<Op>(op), m + 1, r);
      static_cast<Impl *>(this)->collect(l, m, r, n, ln, rn);
    }
  }

  template <typename Op, int direction>
  void traverse(Op &&op, int l, int r, int a, int b) {
    if (b < l || r < a) {
      return;
    }
    S &n = get_node(l, r);
    if (a <= l && r <= b) {
      op(l, r, n);
    } else {
      int m = (l + r) >> 1;
      S &ln = get_node(l, m);
      S &rn = get_node(m + 1, r);
      static_cast<Impl *>(this)->propagate(l, m, r, n, ln, rn);
      if (direction) {
        traverse<Op, 1>(std::forward<Op>(op), m + 1, r, a, b);
        traverse<Op, 1>(std::forward<Op>(op), l, m, a, b);
      } else {
        traverse<Op, 0>(std::forward<Op>(op), l, m, a, b);
        traverse<Op, 0>(std::forward<Op>(op), m + 1, r, a, b);
      }
      static_cast<Impl *>(this)->collect(l, m, r, n, ln, rn);
    }
  }

  int n;
  std::vector<S> nodes;
};

/*
namespace segment_tree {
struct S {
};

struct Build {
  void operator()(int l, int r, S &n) const {
    if (l == r) {
      n = S{a[l]};
    } else {
      n = S{};
    }
  }
  const std::vector<int> &a;
};

struct Modify {
  void operator()(int l, int r, S &n) { n = d; }
  S d;
};

struct Sum {
  void operator()(int l, int r, S &n) {
  }

  S result = S{};
};

struct SegmentTree : public SegmentTreeBase<S, SegmentTree> {
  explicit SegmentTree(const std::string &a) : SegmentTreeBase(a.size()) {
    traverse_all(Build{a});
  }

  static void propagate(int l, int m, int r, S &n, S &ln, S &rn) {}

  static void collect(int l, int m, int r, S &n, S &ln, S &rn) {
    n = ln + rn;
  }
};
} // namespace segment_tree
*/