/*
    Time: O(N)
    Space: O(N)
    Note: 거리의 차이의 약수. 즉, 모든 거리 차이의 최대공약수
*/

#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int solve(vector<int> &diffs)
{
    if (diffs.size() == 0) {
        return 0;
    }

    int gcd = diffs[0];
    for (int i = 1; i < diffs.size(); i++) {
        gcd = std::gcd(gcd, diffs[i]);
    }

    return gcd;
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    
    int N, S, A;
    cin >> N >> S;
    vector<int> diffs;
    for (int i = 0; i < N; i++) {
        cin >> A;
        if (A == S) {
            continue;
        }
        diffs.push_back(abs(A - S));
    }    

    cout << solve(diffs) << '\n';
    return 0;
}