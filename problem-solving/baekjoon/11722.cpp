#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int solve(int N, vector<int> &A)
{
    vector<int> dp(N + 1);
    dp[1] = 1;

    int ans = dp[1];
    for (int n = 2; n <= N; n++) {
        int sum = 0;
        for (int k = 1; k < n; k++) {
            if (A[k] > A[n]) {
                sum = max(sum, dp[k]);
            }
        }
        dp[n] = sum + 1;
        ans = max(ans, dp[n]);
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