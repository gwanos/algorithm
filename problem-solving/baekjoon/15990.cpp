#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

long long dp[100001][4] = { {0, 0, 0, 0}, };

long long solve(int N)
{
    if (N <= 2) {
        return 1;
    }
    
    long long divisor = 1000000009;
    dp[1][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1; dp[3][2] = 1; dp[3][3] = 1;

    for (int i = 4; i <= N; i++) {
        dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % divisor;
        dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % divisor;
        dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % divisor;
    }

    // 세 값을 더하면 int 범위를 초과할 수도 있기 때문에,
    // long long 타입에 저장해야 한다.
    long long ret = 0;
    for (auto num : dp[N]) {
        ret += num;
    }
    return (ret % divisor);
}

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(nullptr);
    
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        cout << solve(N) << '\n';
    }

    return 0;
}