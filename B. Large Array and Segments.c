#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

void solve() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n, k;
        ll x;
        scanf("%d %d %lld", &n, &k, &x);

        ll *arr = (ll*)malloc(n * sizeof(ll));
        ll sum = 0;

        for (int i = 0; i < n; i++) {
            scanf("%lld", &arr[i]);
            sum += arr[i];
        }

        ll *m = (ll*)calloc(n + 1, sizeof(ll));
        for (int i = 1; i <= n; i++) {
            m[i] = m[i - 1] + arr[i - 1];
        }

        ll x_value = k * sum - x;
        ll ans = 0;

        if (x_value < 0) {
            printf("0\n");
            free(arr);
            free(m);
            continue;
        }

        for (int j = 0; j < n; j++) {
            if (m[j] > x_value) continue;

            ll max_m = (x_value - m[j]) / sum;
            ll count_m = (k < max_m + 1) ? k : (max_m + 1);
            ans += count_m;
        }

        printf("%lld\n", ans);
        free(arr);
        free(m);
    }
}

int main() {
    solve();
    return 0;
}
