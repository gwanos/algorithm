/*
    Time: O(N)
    Space: O(N)
    Note: 가능하다면 3으로 나누는게 가장 빨리 1을 만들 수 있을 것 처럼 보이나, 실제로는 그렇지 않음.
          세 가지 연산의 사용 횟수를 비교하고 그 중 최소값을 구해야 함.
          A[n] = min(A[n/3], A[n/2], A[n-1]) + 1
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int solve(int N)
{
    vector<int> dp(N + 1);
    if (N == 1) {
        dp[1] = 0;
        return 0; 
    }

    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0) {
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }
        if (i % 3 == 0) {
            dp[i] = min(dp[i], dp[i / 3] + 1);
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