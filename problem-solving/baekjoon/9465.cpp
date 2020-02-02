#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int solve(int N, vector<vector<int> > &A)
{
    vector<vector<int> > dp(3, vector<int>(N + 1));
    dp[0][1] = 0; dp[1][1] = A[0][1]; dp[2][1] = A[1][1];

    for (int n = 2; n <= N; n++) {
        dp[0][n] = max(dp[1][n - 1], dp[2][n - 1]);
        dp[1][n] = max(dp[0][n - 1], dp[2][n - 1]) + A[0][n];
        dp[2][n] = max(dp[0][n - 1], dp[1][n - 1]) + A[1][n];
    }

    return max(dp[0][N], max(dp[1][N], dp[2][N]));
}

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(nullptr);
    
    int T, N, num;
    cin >> T;
    while (T--) {
        cin >> N;
        vector<vector<int> > A(2, vector<int>(N + 1));
        for (int j = 0; j < 2; j++) {
            for (int i = 1; i <= N; i++) {
                cin >> A[j][i];
            }
        }
        
        cout << solve(N, A) << '\n';
    }
    

    return 0;
}