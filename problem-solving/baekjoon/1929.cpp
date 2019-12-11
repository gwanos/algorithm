/*
    Time: O(NloglogN)
    Space: O(N) 
    Note: 에라토스테네스의 체
           아직 지워지지 않은 수 중 가장 작은 수를 찾고 그 수의 배수를 모두 지운다.
           이 과정을 N까지 반복 후 남아있는 수는 소수이다.
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> getPrimes(int from, int to) {
    bool check[1000001];
    vector<int> primes;

    for (int i = 2; i <= to; i++) {
        if (false == check[i]) {
            if (from <= i) {
                primes.push_back(i);
            }

            for (int j = i * 2; j <= to; j += i) {
                check[j] = true;
            }
        }
    }

    return primes;
}

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(nullptr);
    cout.tie(nullptr);

    int M, N;
    cin >> M >> N;

    auto primes = getPrimes(M, N);
    for (auto number : primes) {
        cout << number << '\n';
    }
    return 0;
}