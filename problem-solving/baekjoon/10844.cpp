#include <iostream>
#include <vector>
using namespace std;

int solve(int N)
{
    int divisor = 1000000000;
    vector<int> inner(10, 0);
    vector<vector<int> > dp(N + 1, inner);

    for (int j = 1; j <= 9; j++) {
        dp[1][j] = 1;
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= 9; j++) {
            if (j == 0) {
                dp[i][j] = dp[i - 1][j + 1];
            }
            else if (j == 9) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % divisor;
            }
        }
    }

    long long ret = 0;
    for (auto num : dp[N]) {
        ret += num;
    }

    return ret % divisor;
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