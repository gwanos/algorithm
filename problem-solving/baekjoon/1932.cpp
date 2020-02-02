#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int dp[501][501];
int A[501][501];

int solve(int N)
{
    dp[1][1] = A[1][1];

    for (int n = 1; n <= N; n++) {
        for (int m = 1; m <= n; m++) {
            if (m == 1) {
                dp[n][m] = dp[n - 1][m] + A[n][m];
            }
            else if (m == n) {
                dp[n][m] = dp[n - 1][m - 1] + A[n][m];
            }
            else {
                dp[n][m] = max(dp[n - 1][m - 1], dp[n - 1][m]) + A[n][m];
            }
            
        }
    }

    int ans = 0;
    for (auto num : dp[N]) {
        if (num > ans) {
            ans = num;
        }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(nullptr);
    
    int N, num;
    cin >> N;
    for (int n = 1; n <= N; n++) {
        for (int m = 1; m <= n; m++) {
            cin >> A[n][m];
        }
    }

    cout << solve(N) << '\n';        
    return 0;
}