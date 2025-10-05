#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
static const i64 MOD = 676767677LL;

/* ---------- modular helpers ---------- */
static inline i64 modmul(i64 a, i64 b){ return (a%MOD) * (b%MOD) % MOD; }
static inline i64 modadd(i64 a, i64 b){ a += b; if(a>=MOD) a-=MOD; return a; }
static inline i64 modpow(i64 a, i64 e){
    i64 r = 1 % MOD; a %= MOD;
    while(e){
        if(e&1) r = modmul(r,a);
        a = modmul(a,a);
        e >>= 1;
    }
    return r;
}
static inline i64 invmod(i64 x){ return modpow(x, MOD-2); }

/* ---------- combinatorics (precompute fact & invfact) ---------- */
static vector<i64> FACT, INVF;
static void ensure_fact(int n){
    if((int)FACT.size() > n) return;
    int old = max(1, (int)FACT.size());
    FACT.resize(n+1);
    INVF.resize(n+1);
    if(old == 1){ FACT[0] = 1; INVF[0] = 1; }
    for(int i=old; i<=n; ++i) FACT[i] = modmul(FACT[i-1], i);
    // compute INVF[n] via Fermat once, then go down
    INVF[n] = invmod(FACT[n]);
    for(int i=n; i>0; --i) INVF[i-1] = modmul(INVF[i], i);
}
static inline i64 nCr(int n, i64 r){
    if(r < 0 || r > n) return 0;
    ensure_fact(n);
    return modmul(FACT[n], modmul(INVF[(int)r], INVF[n-(int)r]));
}

/* ---------- DSU with min-index & sizes ---------- */
struct UF {
    vector<int> p, sz, lo; // parent, size, min-index in component
    UF(int n=0){ init(n); }
    void init(int n){
        p.resize(n); sz.assign(n,1); lo.resize(n);
        for(int i=0;i<n;++i){ p[i]=i; lo[i]=i; }
    }
    int find(int x){ return p[x]==x? x : p[x]=find(p[x]); }
    void join(int a, int b){
        a = find(a); b = find(b);
        if(a==b) return;
        if(sz[a] < sz[b]) swap(a,b);
        p[b]=a; sz[a]+=sz[b]; lo[a]=min(lo[a], lo[b]);
    }
    int size(int x){ return sz[find(x)]; }
    int minidx(int x){ return lo[find(x)]; }
};

/* ---------- core ---------- */
static void run(){
    int n;
    if(!(cin >> n)) return;
    vector<int> A(n);
    for(int i=0;i<n;++i) cin >> A[i];

    // step 1: local diffs s[i] = A[i]-A[i-1]+1 in {0,1,2} else impossible
    vector<int> tag(n, 0); // tag[0] unused
    for(int i=1;i<n;++i){
        int v = A[i] - A[i-1] + 1;
        if(v < 0 || v > 2){ cout << 0 << '\n'; return; }
        tag[i] = v;
    }

    // forced assignment per index: -1 unknown, 0 or 1 fixed
    vector<int> pin(n, -1);
    for(int i=1;i<n;++i){
        if(tag[i]==0){
            if((pin[i-1]!=-1 && pin[i-1]!=0) || (pin[i]!=-1 && pin[i]!=0)){ cout<<0<<'\n'; return; }
            pin[i-1]=0; pin[i]=0;
        }else if(tag[i]==2){
            if((pin[i-1]!=-1 && pin[i-1]!=1) || (pin[i]!=-1 && pin[i]!=1)){ cout<<0<<'\n'; return; }
            pin[i-1]=1; pin[i]=1;
        }
    }

    // step 2: build components with edges where tag==1
    UF uf(n);
    for(int i=1;i<n;++i) if(tag[i]==1) uf.join(i-1,i);

    // propagate forced values inside components with parity checks
    vector<int> compFixVal(n, -1);
    vector<int> compFixPos(n, -1);
    for(int i=0;i<n;++i){
        if(pin[i]==-1) continue;
        int r = uf.find(i);
        if(compFixVal[r] == -1){
            compFixVal[r] = pin[i];
            compFixPos[r] = i;
        }else{
            int d = abs(i - compFixPos[r]);
            int expect = (d%2==0) ? compFixVal[r] : 1 - compFixVal[r];
            if(expect != pin[i]){ cout << 0 << '\n'; return; }
        }
    }

    // step 3: compute L_fixed and gather free chains
    i64 L_fixed = 0;
    vector<int> freeChains; // lengths of free components (no forced value)
    vector<char> seen(n, 0);
    int root0 = uf.find(0);
    int len0 = -1; // length of the component containing index 0 if it's free

    for(int i=0;i<n;++i){
        int r = uf.find(i);
        if(seen[r]) continue;
        seen[r] = 1;

        int len = uf.sz[r];
        if(compFixVal[r] != -1){
            // deduce starting color at the minimum index of the component
            int pos = compFixPos[r], val = compFixVal[r];
            int anchor = uf.lo[r];
            int dist = pos - anchor; // >=0
            int start = (dist%2==0) ? val : 1 - val;
            // count ones in this component under fixed start
            L_fixed += (start==1) ? ( (len+1)/2 ) : ( len/2 );
        }else{
            if(r == root0) len0 = len;
            else freeChains.push_back(len);
        }
    }

    // step 4: combinatorics over free chains
    i64 mOdd = 0, mEven = 0, sumHalf = 0;
    for(int L : freeChains){
        if(L&1) ++mOdd;
        else ++mEven;
        sumHalf += L/2;
    }
    i64 pow2Even = modpow(2, mEven);

    i64 answer = 0;
    if(len0 == -1){
        // component containing index 0 is forced: determine c1 (color at index 0)
        int r = uf.find(0);
        int pos = compFixPos[r], val = compFixVal[r];
        int c1 = ( (abs(0 - pos) % 2) == 0 ) ? val : 1 - val;

        // total ones target across all positions:
        // L_total = c1 + (n - A[0])  (from original logic)
        i64 Ltarget = (i64)c1 + (i64)n - (i64)A[0];
        i64 need = Ltarget - L_fixed - sumHalf; // choose how many odd chains start with 1
        answer = modmul(nCr((int)mOdd, need), pow2Even);
    }else{
        // case c1 = 0
        i64 l0 = (i64)len0 / 2;
        i64 target0 = (i64)n - (i64)A[0];
        i64 k0 = target0 - L_fixed - l0 - sumHalf;
        answer = modadd(answer, modmul(nCr((int)mOdd, k0), pow2Even));

        // case c1 = 1
        i64 l1 = (i64)(len0 + 1) / 2;
        i64 target1 = 1 + (i64)n - (i64)A[0];
        i64 k1 = target1 - L_fixed - l1 - sumHalf;
        answer = modadd(answer, modmul(nCr((int)mOdd, k1), pow2Even));
    }

    cout << answer % MOD << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) run();
    return 0;
}
