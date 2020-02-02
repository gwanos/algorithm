#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int solve(int N, vector<int> &A)
{
    vector<vector<int> > dp(2, vector<int>(N + 1, 1));

    // 정
    for (int n = 2; n <= N; n++) {
        for (int m = 1; m < n; m++) {
            if (A[m] < A[n]) {
                dp[0][n] = max(dp[0][n], dp[0][m] + 1);
            }
        }
    }

    // 역
    for (int n = N - 1; n >= 1; n--) {
        for (int m = N; m > n; m--) {
            if (A[m] < A[n]) {
                dp[1][n] = max(dp[1][n], dp[1][m] + 1);
            }
        }
    }

    int ans = 0, sum = 0;
    for (int n = 1; n <= N; n++) {
        sum = dp[0][n] + dp[1][n] - 1;
        if (sum > ans) {
            ans = sum;
        }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<int> A(N + 1);

    for (int n = 1; n <= N; n++) {
        cin >> A[n];        
    }

    cout << solve(N, A) << '\n';
    return 0;
}