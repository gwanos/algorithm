/*
    Time: O(N)
    Space: O(N)
    Note: A[n]: n을 1,2,3의 합으로 나타낼 수 있는 방법의 수
            1) 마지막에 1을 더해 n을 완성하는 경우
            2) 마지막에 2를 더해 n을 완성하는 경우
            3) 마지막에 3을 더해 n을 완성하는 경우
          A[n] = A[n - 1] + A[n - 2] + A[n - 3];
          A[0] = 1 (왜냐하면 1,2,3을 하나도 사용하지 않으면 0을 만들 수 있기 때문)
*/

#include <iostream>
#include <vector>
using namespace std;

int solve(int n)
{
    vector<int> dp(n + 1);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int k = 4; k <= n; k++) {
        dp[k] = dp[k - 1] + dp[k - 2] + dp[k - 3];
    }

    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(nullptr);
    
    int T, n;
    cin >> T;
    while(T--) {
        cin >> n;
        cout << solve(n) << '\n';
    }
    
    return 0;
}