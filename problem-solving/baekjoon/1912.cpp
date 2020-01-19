/*
    Time: O(N)
    Note: 음수에 주의!
          ret 초기값을 0으로하면, 모두 음수일 때 오답임.
          D[i] = i번째 수로 끝나는 가장 큰 연속합
            1) i번째수가 i-1번째와 연속하는 경우
            2) i번째수가 i-1번째와 연속하지 않는 경우
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int solve(int N, vector<int> &seq)
{
    vector<int> dp(seq);

    for (int i = 1; i <= N; i++) {
        dp[i] = max(seq[i], dp[i - 1] + seq[i]);
    }

    int ret = dp[1];
    for (int i = 2; i <= N; i++) {
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
    vector<int> seq(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> seq[i];
    }

    cout << solve(N, seq) << '\n';
}