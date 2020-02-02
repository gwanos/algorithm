/*
    Time: O(N)
    Space: O(N)
    Note: N=1인 경우를 생각하지 않아서 오답처리됨. 주의할 것.
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int solve(int N, vector<int> &A)
{
    vector<vector<int> > dp(2, vector<int>(N + 1));
    dp[0][1] = 0; dp[1][1] = A[1];

    for (int n = 2; n <= N; n++) {
        dp[0][n] = max(dp[0][n - 1], dp[1][n - 1]);
        dp[1][n] = max(dp[0][n - 2] + A[n - 1] + A[n], dp[0][n - 1] + A[n]);

        //ans = max(ans, max(dp[0][n], dp[1][n]));
    }

    return max(dp[0][N], dp[1][N]);
}

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(nullptr);
    
    int N, num;
    cin >> N;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    cout << solve(N, A) << '\n';        

    return 0;
}