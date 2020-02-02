#include <iostream>
#include <vector>
using namespace std;

int solve(int N)
{
    vector<int> dp(N + 1);
    dp[0] = 1; dp[2] = 3;

    for (int n = 4; n <= N; n += 2) {
        dp[n] = dp[n - 2] * 3;
        for (int m = 4; m <= n; m += 2) {
            dp[n] += dp[n - m] * 2;
        }
    }

    return dp[N];
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