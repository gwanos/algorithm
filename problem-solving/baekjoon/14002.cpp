/*
    Note: 역추적
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> solve(int N, vector<int> &A, vector<int> &before)
{
    int max = 0;
    int max_index = 0;
    vector<int> dp(N + 1, 1);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            if (A[j] < A[i] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                before[i] = j;
            }
        }
        if (max < dp[i]) {
            max = dp[i];
            max_index = i;
        }
    }

    vector<int> ret;
    ret.push_back(max);
    ret.push_back(max_index);

    return ret;
}

void trace(int index, vector<int> &before, vector<int> &A) {
    if (index == 0) {
        return;
    }

    trace(before[index], before, A);
    cout << A[index] << ' ';
}

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<int> A(N + 1);
    vector<int> before(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    
    auto ret = solve(N, A, before);
    cout << ret[0] << '\n';
    trace(ret[1], before, A);
    cout << '\n';

    return 0;
}