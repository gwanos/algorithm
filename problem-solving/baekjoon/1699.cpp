/*
    Note: O(N rtN)
    Note: 마지막에 더할 수 있는 수가 너무 많다 => 변수 사용!
          마지막에 오는 수 = i^2
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int solve(int N)
{
    vector<int> dp(N + 1);

    //
    for (int i = 1; i <= N; i++) {
        dp[i] = i;
        for (int j = 1; j * j <= i; j++) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
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