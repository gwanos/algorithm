/*
    Note: 마지막에 어떤 조각을 놓아 직사각형을 완성하는가
          A[n]: 2xn 직사각형을 타일로 채우는 방법의 수
           1) 마지막에 1x2 타일 2개를 가로로 놓는 방법: A[n - 2]
           2) 마지막에 2x1 타일 1개를 세로로 놓는 방법: A[n - 1]
          따라서, A[n] = A[n - 2] + A[n - 1]
*/
#include <iostream>
#include <vector>
using namespace std;

int solve(int n)
{
    int divisor = 10007;
    vector<int> dp(n + 1);
    dp[1] = 1; dp[2] = 2;

    for (int k = 3; k <= n; k++) {
        int op1 = dp[k - 2] % divisor;
        int op2 = dp[k - 1] % divisor;
        dp[k] = (op1 + op2) % divisor;
    } 

    return dp[n] % divisor;
}

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    cout << solve(n) << '\n';
    
    return 0;
}