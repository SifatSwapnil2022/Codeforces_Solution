#include <bits/stdc++.h>
using namespace std;

using LL = long long;

static inline LL clip(LL x, LL lo, LL hi) { return x < lo ? lo : (x > hi ? hi : x); }
static inline bool inGrid(LL r, LL c, LL n) { return (0 <= r && r <= n && 0 <= c && c <= n); }
static inline bool doranCan(LL r, LL c, LL rD, LL cD, LL T){ return max(llabs(r - rD), llabs(c - cD)) <= T; }

// True if Doran can cover every extreme/edge-intersection point of Krug's T-diamond
static bool covered(LL n, LL rK, LL cK, LL rD, LL cD, LL T) {
    // We enumerate all candidate escape points of Krug's L1 ball (diamond) clipped to the grid.
    // Max distinct candidates here: 4 tips + up to 8 edge-intersections = 12. We'll over-allocate a bit.
    pair<LL,LL> P[16];
    int cnt = 0;

    // 4 diamond tips
    const LL up    = rK - T, dn = rK + T;
    const LL left  = cK - T, rt = cK + T;
    if (inGrid(up,   cK, n))  P[cnt++] = {up,   cK};
    if (inGrid(dn,   cK, n))  P[cnt++] = {dn,   cK};
    if (inGrid(rK,  left, n)) P[cnt++] = {rK,  left};
    if (inGrid(rK,    rt, n)) P[cnt++] = {rK,    rt};

    // Intersections with boundaries of the square board [0..n]×[0..n].
    // For row = 0 and row = n:
    //   |r - rK| + |c - cK| <= T  → at r=const, |c - cK| <= T - |r - rK|
    auto addRowIntersections = [&](LL rowConst){
        LL rem = T - llabs(rowConst - rK);
        if (rem < 0) return;
        LL c1 = clip(cK - rem, 0, n);
        LL c2 = clip(cK + rem, 0, n);
        P[cnt++] = {rowConst, c1};
        P[cnt++] = {rowConst, c2};
    };
    addRowIntersections(0);
    addRowIntersections(n);

    // For col = 0 and col = n:
    //   |r - rK| + |c - cK| <= T  → at c=const, |r - rK| <= T - |c - cK|
    auto addColIntersections = [&](LL colConst){
        LL rem = T - llabs(colConst - cK);
        if (rem < 0) return;
        LL r1 = clip(rK - rem, 0, n);
        LL r2 = clip(rK + rem, 0, n);
        P[cnt++] = {r1, colConst};
        P[cnt++] = {r2, colConst};
    };
    addColIntersections(0);
    addColIntersections(n);

    // Every candidate point must be reachable by Doran within T (Chebyshev radius T).
    for (int i = 0; i < cnt; ++i) {
        const LL r = P[i].first, c = P[i].second;
        if (!doranCan(r, c, rD, cD, T)) return false; // an escape exists
    }
    return true; // all extreme/intersection points are inside Doran's T-square
}

static void runCase() {
    LL n, rK, cK, rD, cD;
    cin >> n >> rK >> cK >> rD >> cD;

    // Binary search for the minimum T such that covered(...) is true
    LL lo = 0, hi = 2 * n; // safe upper bound
    while (lo < hi) {
        LL mid = lo + ((hi - lo) >> 1);
        if (covered(n, rK, cK, rD, cD, mid)) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) runCase();
    return 0;
}
