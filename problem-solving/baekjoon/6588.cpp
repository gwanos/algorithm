/*
    Time: O(NloglogN)
    Space: O(N)    
*/
#include <iostream>
#include <vector>
using namespace std;

void goldbach(vector<int> &primes, vector<bool> &check, int n) {
    bool isPossible = false;
    int a = 0, b = 0;
    
    for (int i = 0; i < primes.size(); i++) {
        a = primes[i];
        b = n - a;  
        if (b <= 0) {
            break;
        }
        if (false == check[b] && 0 != b % 2) {
            isPossible = true;
            break;
        }
    }

    if (isPossible) {
        cout << n << " = " << a << " + " << b << '\n';
    }
    else {
        cout << "Goldbach's conjecture is wrong.\n";
    }
}

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(nullptr);
    cout.tie(nullptr);

    int max = 1000000;
    vector<int> primes;
    vector<bool> check(max + 1);

    for (int i = 2; i <= max; i++) {
        if (false == check[i]) {
            if (0 != i % 2) {
                primes.push_back(i);
            }

            for (int j = 2 * i; j <= max; j += i) {
                check[j] = true;
            }
        }
    }

    int n;
    cin >> n;
    while (n != 0) {
        goldbach(primes, check, n);
        cin >> n;
    } 

    return 0;
}