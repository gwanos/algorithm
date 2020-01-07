/*
    Time: O(N^2)
    Space: O(N)
    Note: 계산 결과가 int범위를 초과하여 오답.
          합이 대략 20억을 넘는다 싶으면 long long 타입을 사용하도록 하자.
*/
#include <numeric>
#include <iostream>
#include <vector>
using namespace std;

long long sumOfGcd(int n, vector<int> &numbers)
{
    if (n == 1) {
        return numbers[0];
    }

    long long sum = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j ++) {
            sum += gcd(numbers[i], numbers[j]);
        }
    }

    return sum;
}

int main() 
{
    ios_base::sync_with_stdio();
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t, n, num;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<int> numbers(n);
        for (int i = 0; i < n; i++) {
            cin >> numbers[i];
        }

        cout << sumOfGcd(n, numbers) << '\n';
    } 

    return 0;
}