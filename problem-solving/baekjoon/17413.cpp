/*
    Time: O(N)  // 모든 글자가 스택에 들어갔다가 나오는 케이스
    Space: O(N)
*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(nullptr);
    cout.tie(nullptr);

    bool toStack = true;
    string input = "";
    stack<char> stack;
    getline(cin, input);
    input += '\n';
    
    for (auto ch : input) {
        if ('<' == ch) {
            toStack = false;
            while(!stack.empty()) {
                cout << stack.top();
                stack.pop();
            }
            cout << ch;
            continue;
        } else if ('>' == ch) {
            toStack = true;
            cout << ch;
            continue;
        }

        if (toStack) {
            if (' ' == ch || '\n' == ch) {
                while(!stack.empty()) {
                    cout << stack.top();
                    stack.pop();
                }
                cout << ch;
            }
            else {
                stack.push(ch);
            }
        }
        else { 
            cout << ch;
        }
    }

    return 0;
}