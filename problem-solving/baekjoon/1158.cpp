/*
    Time: O(KN)
    Space: O(N)
*/
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K;
    queue<int> queue;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        queue.push(i);
    }

    int i = 1;
    cout << "<";
    while (!queue.empty()) {
        if (i % K == 0) {
            int num = queue.front();
            queue.pop();
            cout << num;
            if (!queue.empty()) {
                cout <<", "; 
            }
        }
        else {
            int num = queue.front();
            queue.pop();
            queue.push(num);
        }

        i += 1;
        i %= K;
    }
    cout << ">";
    return 0;
}