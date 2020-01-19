/*
    Note: 런타임 에러. 주어진 수의 크기가 너무 커서 배열 사이즈가 커질 경우, 매번 메소드 안에서 vector를 초기화하면 런타임 에러가 발생한다.
            => 해결: 전역 변수로 dp 배열을 선언하고 사용.
          오버플로우. 마찬가지로 수의 합이 너무 클 경우, 아래와 같은 방법으로 합을 구하면 오버플로우가 발생한다.
          dp[n] = (a + b + c) % mod 
            => 해결: a, b, c 각각을 우선 변수에 더한 후, 마지막에 해당 변수를 MOD 연산해준다.
                dp[n] += a, dp[n] += b, dp[n] +=c 이후 dp[n] %= mod;
*/

#include <iostream>
#include <vector>
using namespace std;

long long dp[1000001];
const long long divisor = 1000000009LL;

void init()
{
    dp[1] = 1; dp[2] = 2; dp[3] = 4;
    for (int n = 4; n <= 1000000; n++) {
        dp[n] += dp[n - 1];
        dp[n] += dp[n - 2];
        dp[n] += dp[n - 3];
        dp[n] %= divisor;
    }
}

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(nullptr);
    
    init();
    int T, N;
    cin >> T;
    while(T--) {
        cin >> N;
        cout << dp[N] << '\n';
    }
    
    return 0;
}