#include <iostream>
#include <vector>
using namespace std;

int solve(int N)
{
    int mod = 10007;
    vector<long long> inner(10);
    vector<vector<long long> > dp(N + 1, inner);

    for (int n = 1; n <= N; n++) {
        for (int m = 0; m <= 9; m++) {
            if (n == 1) {
                dp[n][m] = 1;
            }
            else {
                for (int i = m; i >= 0; i--) {
                    dp[n][m] += dp[n - 1][m - i];
                }
                dp[n][m] %= mod;
            }
        }
    }

    long long ans = 0;
    for (auto num : dp[N]) {
        ans += num;
    }
    return ans % mod;
}

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    cout << solve(N) << '\n';

    return 0;
}