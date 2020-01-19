/*
    Time: O(KN^2)
*/
#include <iostream>
#include <vector>
using namespace std;

int solve(int N, int K)
{
    int divisor = 1000000000;
    vector<int> inner(K + 1);
    vector<vector<int> >dp(N + 1, inner);

    //
    for (int n = 0; n <= N; n++) {
        dp[n][1] = 1;
        for (int k = 2; k <= K; k++) {
            for (int i = 0; i <= n; i++) {
                dp[n][k] += dp[n - i][k - 1];
                dp[n][k] %= divisor;
            }
        }
    }

    return dp[N][K];
}

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    cout << solve(N, K) << '\n';

    return 0;
}