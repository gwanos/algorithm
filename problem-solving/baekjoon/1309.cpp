#include <iostream>
#include <vector>
using namespace std;

int solve(int N)
{
    int mod = 9901;
    vector<int> inner(3);
    vector<vector<int> > dp(N + 1, inner);
    dp[1][0] = dp[1][1] = dp[1][2] = 1;

    for (int n = 2; n <= N; n++) {
        dp[n][0] = (dp[n - 1][0] + dp[n - 1][1] + dp[n - 1][2]) % mod;
        dp[n][1] = (dp[n - 1][0] + dp[n - 1][2]) % mod;
        dp[n][2] = (dp[n - 1][0] + dp[n - 1][1]) % mod;
    }

    return (dp[N][0] + dp[N][1] + dp[N][2]) % mod;
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