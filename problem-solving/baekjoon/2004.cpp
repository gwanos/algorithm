/*
    Note: 어떤 수 N의 끝자리 0의 개수는 N을 소인수분해 했을 때, min(2의 개수, 5의 개수)이다.
*/
#include <algorithm>
#include <iostream>
using namespace std;

long long getZeroCount(long long n, long long m) {
    long long two = 0, five = 0;
    long long nm = n - m;

    for (long long i = 2; i <= n; i *= 2) {
        two += n / i;
    }
    for (long long i = 2; i <= nm; i *= 2) {
        two -= nm / i;
    }
    for (long long i = 2; i <= m; i *= 2) {
        two -= m / i;
    }

    for (long long i = 5; i <= n; i *= 5) {
        five += n / i;
    }
    for (long long i = 5; i <= nm; i *= 5) {
        five -= nm / i;
    }
    for (long long i = 5; i <= m; i *= 5) {
        five -= m / i;
    }

    return min(two, five);
}

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    cout << getZeroCount(n, m) << '\n';

    return 0;
}