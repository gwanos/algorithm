#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int solve(int N, vector<int> &A)
{
    vector<int> dl(N + 1);
    vector<int> dr(N + 1);

    // 정
    dl[1] = A[1];
    for (int n = 2; n <= N; n++) {
        dl[n] = max(dl[n - 1] + A[n], A[n]);
    }

    // 역
    dr[N] = A[N];
    for (int n = N - 1; n >= 1; n--) {
        dr[n] = max(dr[n + 1] + A[n], A[n]);
    }

    // 초기화
    // 제거하지 않는게 이득인 케이스 포함
    int ans = dl[1];
    for (int n = 2; n <= N; n++) {
        ans = max(ans, dl[n]);
    }

    ans = max(ans, dr[2]);  // 첫번째 수를 제거하는 케이스
    for (int n = 2; n < N; n++) {
        ans = max(ans, dl[n - 1] + dr[n + 1]);
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<int> A(N + 1);

    for (int n = 1; n <= N; n++) {
        cin >> A[n];        
    }

    cout << solve(N, A) << '\n';
    return 0;
}