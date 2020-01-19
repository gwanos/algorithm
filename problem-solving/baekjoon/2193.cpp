#include <iostream>
#include <vector>
using namespace std;

long long solve(int N)
{
    vector<long long> inner(2, 0);
    vector<vector<long long> > dp(N + 1, inner);
    dp[1][0] = 0; dp[1][1] = 1;

    for (int i = 2; i <= N; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
    }

    return dp[N][0] + dp[N][1];
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