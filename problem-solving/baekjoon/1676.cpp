/*
    Time: O(1)
    Space: O(1)
    Note: 소인수분해.
          0을 만들 수 있는 소수의 조합은 2x5 뿐.
          소인수 분해 후, 2x5의 개수가 0의 개수가 된다.
          이 중 출현 빈도수가 더 낮은 5의 개수를 세는데, 
          이 때 5가 여러번 곱해진 수 (25 등)은 5의 개수를 여러번 세어준다.
          N! 0의 개수 = [N/5] + [N/5^2] + [N/5^3] + ...
*/

#include <iostream>
#include <vector>
using namespace std;

/* 틀린 풀이
   1의 자리수만 dp 배열에 저장하고, 그 숫자와 i를 곱했을 때의 결과가 10의 배수인지를 검사하는 방법이었는데
   5가 여러번 곱해진 숫자를 체크할 수 없어서 틀린 풀이.
*/
int getZeroCount_Wrong(int n) {
    if (0 == n) {
        return 0;
    }

    int count = 0, multi = 0, remainder = 0, quotient = 0;
    int divisor = 10;
    vector<int> dp(n + 1, 1); // 마지막 자리 저장
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        multi = dp[i - 1] * i;
        do {
            remainder = multi % divisor;
            if (remainder == 0) {
                count += 1;
                multi = multi / divisor;
            }
        } while (remainder == 0);
        dp[i] = remainder;
    }

    return count;
}

int getZeroCount(int n) {
    int ret = 0;
    for (int i = 5; i <= n; i *= 5) {
        ret += n / i;
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    cout << getZeroCount(n) << '\n';

    return 0;
}