#include <iostream>
#include <vector>
using namespace std;

// 소수 리스팅
// 에라토스테네스의 체
void maskNonPrimeNumber(vector<bool> &numbers)
{
    vector<bool> ret;

    for (int i = 0; i < numbers.size(); i++) {
        if (i == 0 || i == 1) {
            numbers[i] = false;
            continue;
        }

        if (numbers[i] == true) {
            for (int j = i * 2; j < numbers.size(); j += i) {
                numbers[j] = false;
            }
        }
    }
}

int solve(int N, vector<bool> &numbers)
{
    int ret = 0;
    for (int i = 2; i <= N / 2; i++) {
        if (numbers[i] == true) {   // 소수
            if (numbers[N - i] == true) {
                ret += 1;
            }
        }
        else {
            continue;
        }
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    vector<bool> numbers(1000001, true);
    maskNonPrimeNumber(numbers);

    int T, N;
    cin >> T;
    while(T--) {
        cin >> N;
        cout << solve(N, numbers) << '\n';
    }

    return 0;
}