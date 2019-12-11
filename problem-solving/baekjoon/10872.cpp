/*
    Time: O(1)
    Space: O(N)
*/

#include <iostream>
#include <vector>
using namespace std;

long long factorial(int n) {
    if (0 == n) {
        return 1;
    }

    vector<long long> dp(n + 1, 1);
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] * i;
    }

    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    cout << factorial(n) << '\n';

    return 0;
}