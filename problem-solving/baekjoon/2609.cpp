#include <iostream>
using namespace std;

int caculate_gcd(int x, int y)
{
    int gcd = 1;
    int to = x > y ? y : x;
    for (int i = 2; i <= to; i++) {
        if (x % i == 0 && y % i == 0) {
            gcd = i;
        }
    }

    return gcd;
}

// 유클리드 호제법 풀이
// Time: O(logN)
// GCD(a, b) = GCD(b, r), r = a % b
// r이 0이면 그 때 b가 최대공약수
int caculate_gcd_recursive(int x, int y)
{
    if (y == 0) {
        return x;
    } else {
        return caculate_gcd_recursive(y, x % y);
    }
}

int caculate_lcm(int x, int y)
{
    int gcd = caculate_gcd(x, y);
    int lcm = x * y / gcd;

    return lcm;
}

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(nullptr);
    cout.tie(nullptr);

    int x, y;
    cin >> x >> y;

    cout << caculate_gcd_recursive(x, y) << '\n';
    cout << caculate_lcm(x, y) << '\n';

    return 0;
}