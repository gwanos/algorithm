/*
    Time: O(sqrt(N))
    Space: O(1)
*/
#include <iostream>
using namespace std;

/* Time: O(N) 
   Note: 
    N = a x b로 나타낼 수 있는데, a가 작을수록 b는 크다.
    가능한 a 중에서 가장 작은 값은 2이고, 이 때 b는 N/2이다. 
    따라서 N/2까지만 검사해보면 된다.
*/
bool isPrime_N(int number) {
    if (number < 2) {
        return false;
    }

    for (int i = 2; i <= number/2; i++) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}

/* Time: O(square root N) 
   Note: 
    N = a x b 일 때, 
    a > sqrt(N) && b > sqrt(N) 이면 a x b > N 이고
    a < sqrt(N) && b < sqrt(N) 이면 a x b < N 이므로
    a < sqrt(N) && b > sqrt(N) 이라야 a x b = N 이 된다.
    따라서 sqrt(N)까지만 검사해보면 된다.
*/
bool isPrime_sqrtN(int number) {
    if (number < 2) {
        return false;
    }

    // 실수 표현 대신 정수 사용: i*i
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, number, count = 0;
    cin >> N;
    while (N--) {
        cin >> number;
        if (isPrime_sqrtN(number)) {
            count += 1;
        }
    }

    cout << count << '\n';

    return 0;
} 