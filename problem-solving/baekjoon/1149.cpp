#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int solve(int N, vector<vector<int> > &A)
{
    vector<int> inner(3);
    vector<vector<int> > dp(N + 1, inner);
    dp[1][0] = A[1][0];
    dp[1][1] = A[1][1];
    dp[1][2] = A[1][2];

    for (int n = 2; n <= N; n++) {
        dp[n][0] = min(dp[n - 1][1], dp[n - 1][2]) + A[n][0];
        dp[n][1] = min(dp[n - 1][0], dp[n - 1][2]) + A[n][1];
        dp[n][2] = min(dp[n - 1][0], dp[n - 1][1]) + A[n][2];
    }

    int ans = min(dp[N][0], min(dp[N][1], dp[N][2]));
    return ans;
}

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(nullptr);
    
    int N, cost;
    cin >> N;
    vector<int> inner(3, 0);
    vector<vector<int> > A(N + 1, inner);

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> A[i][j];
        }
    }
    cout << solve(N, A) << '\n';
    
    return 0;
}