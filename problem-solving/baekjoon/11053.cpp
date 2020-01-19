#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int solve(int N, vector<int> &A)
{
    int ret = 0;
    vector<int> dp(N + 1, 1);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            if (A[j] < A[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ret = max(ret, dp[i]);
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    cout << solve(N, A) << '\n';

    return 0;
}