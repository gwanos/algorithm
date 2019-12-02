/*
    Time: O(N)
    Space: O(N)
    Note:
     0. 아직 오등큰수를 찾지 못한 A[i]의 인덱스i를 스택에 PUSH
     1. 오등큰수를 찾았다면 (즉, 스택의 TOP의 A[TOP] 값보다 큰 A[i]를 발견), 스택에서 POP
     1-1. 오등큰수를 찾은 지점의 인덱스i는 다시 스택에 PUSH
     2. 마지막으로 스택에 남아 있는 인덱스i에 해당하는 A[i]의 오등큰수는 -1
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, number;
    cin >> N;
    
    vector<int> seq(1000001, 0);    // index 0은 사용하지 않음.
    vector<int> F(1000001, 0);
    vector<int> NGF(1000001, -1);

    for (int i = 1; i <= N; i++) {
        cin >> number;
        seq[i] = number;
        F[number] += 1;
    }

    int current, top;
    stack<int> stack;
    stack.push(1);
    for (int i = 2; i <= N; i++) {
        if (stack.empty()) {
            stack.push(i);
        }

        current = seq[i];
        while (false == stack.empty() && F[seq[stack.top()]] < F[current]) {
            NGF[stack.top()] = current;
            stack.pop();      
        }

        stack.push(i);
    }

    for (int i = 1; i <= N; i++) {
        cout << NGF[i] << ' ';
    }
    cout << '\n';

    return 0;
}