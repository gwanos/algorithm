/*
    Time: O(N^2)
    Space: O(N)
    Note: A[n]: 카드 n개를 구매하는 비용의 최대값
           1) 마지막에 1장을 사서 N개를 완성하는 방법
           2) 마지막에 2장을 사서 N개를 완성하는 방법
           ...
           N) 마지막에 N장을 사서 N개를 완성하는 방법
          A[n] = max(dp[n - i] + P[i])
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int solve(int N, vector<int> &P)
{
    vector<int> dp(N + 1, 0);

    int price = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            price = dp[i - j] + P[j];
            dp[i] = max(dp[i], price);
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
    vector<int> P(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> P[i];
    }
    cout << solve(N, P) << '\n';

    return 0;
}