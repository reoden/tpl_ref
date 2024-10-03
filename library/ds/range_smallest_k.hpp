#pragma once
#include <algorithm>
#include <vector>

// CUT begin
// 0-indexed BIT (binary indexed tree / Fenwick tree) (i : [0, len))
template <class T> struct BIT {
    int n;
    std::vector<T> data;
    BIT(int len = 0) : n(len), data(len) {}
    void reset() { std::fill(data.begin(), data.end(), T(0)); }
    void add(int pos, T v) { // a[pos] += v
        pos++;
        while (pos > 0 and pos <= n) data[pos - 1] += v, pos += pos & -pos;
    }
    T sum(int k) const { // a[0] + ... + a[k - 1]
        T res = 0;
        while (k > 0) res += data[k - 1], k -= k & -k;
        return res;
    }

    T sum(int l, int r) const { return sum(r) - sum(l); } // a[l] + ... + a[r - 1]

    template <class OStream> friend OStream &operator<<(OStream &os, const BIT &bit) {
        T prv = 0;
        os << '[';
        for (int i = 1; i <= bit.n; i++) {
            T now = bit.sum(i);
            os << now - prv << ',', prv = now;
        }
        return os << ']';
    }
};

#include <algorithm>
#include <cassert>
#include <numeric>
#include <vector>

// Offline solver to find k-th smallest elements in continuous subsequences
// - Problem statement: <https://judge.yosupo.jp/problem/range_kth_smallest>
// - Complexity: O((N + Q) lg(N + Q))
struct range_kth_smallest {
    int N;
    std::vector<int> idx;
    std::vector<int> QL, QR, QK;
    template <typename T> range_kth_smallest(const std::vector<T> A) : N(A.size()) {
        idx.resize(N);
        std::iota(idx.begin(), idx.end(), 0);
        std::sort(idx.begin(), idx.end(), [&](int l, int r) { return A[l] < A[r]; });
    }

    // Add a query to find (k + 1)-th smallest value in [l, r)
    void add_query(int l, int r, int k) {
        assert(l >= 0 and l <= r and r <= N);
        assert(r - l > k);
        QL.push_back(l), QR.push_back(r), QK.push_back(k);
    }

    // Solve all queries: ret[q] = (position of the K[q]-th smallest element in [L[q], R[q]))
    std::vector<int> _ret_arg;
    std::vector<int> solve() {
        const int Q = QL.size();
        std::vector<int> lo(Q, 0), hi(Q, N);
        std::vector<std::vector<int>> vs(N);
        while (true) {
            bool stop = true;
            for (int q = 0; q < Q; q++) {
                if (lo[q] + 1 < hi[q]) {
                    stop = false;
                    vs[(lo[q] + hi[q]) / 2].emplace_back(q);
                }
            }
            if (stop) break;
            BIT<int> bit(N);
            for (int t = 0; t < N; t++) {
                for (auto q : vs[t])
                    (bit.sum(QR[q]) - bit.sum(QL[q]) <= QK[q] ? lo[q] : hi[q]) = t;
                bit.add(idx[t], 1);
                vs[t].clear();
            }
        }
        _ret_arg.resize(Q);
        for (int i = 0; i < Q; i++) _ret_arg[i] = idx[lo[i]];
        return _ret_arg;
    }
};