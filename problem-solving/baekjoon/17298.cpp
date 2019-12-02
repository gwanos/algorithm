/*
    Time: O(N)
    Space: O(N)
    Note:
     0. 아직 오큰수를 찾지 못한 A[i]의 인덱스i를 스택에 PUSH
     1. 오큰수를 찾았다면 (즉, 스택의 TOP의 A[TOP] 값보다 큰 A[i]를 발견), 스택에서 POP
     1-1. 오큰수를 찾은 지점의 인덱스i는 다시 스택에 PUSH
     2. 마지막으로 스택에 남아 있는 인덱스i에 해당하는 A[i]의 오큰수는 -1
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

    int N, number, MAX = 1000001;
    cin >> N;
    stack<int> stack;
    vector<int> seq, nges(N, -1);
    while (N--) {
        cin >> number;
        seq.push_back(number);// index 0은 사용하지 않음.
    }

    stack.push(0);
    int current, top;
    for (int i = 1; i < seq.size(); i++) {
        current = seq[i];
        top = seq[stack.top()];
        if (top >= current) {
            stack.push(i);    
        }
        else {
            while (top < current) {
                nges[stack.top()] = current;
                stack.pop();
                top = stack.empty() ? MAX : seq[stack.top()];
            }
            stack.push(i);
        }
    }

    for (auto num : nges) {
        cout << num << " ";
    }
    cout << '\n';

    return 0;
}