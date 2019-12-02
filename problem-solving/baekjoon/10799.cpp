/*
    Time: O(N)
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

    int count = 0;
    char before;
    string input = "";
    stack<char> stack;
    cin >> input;

    for (auto ch : input) {
        if ('(' == ch) {
            stack.push(ch);
        } else if (')' == ch) {
            stack.pop();
            if (')' == before) {
                count += 1;
            }
            else {
                count += stack.size();    
            }
        }
        before = ch;
    }

    cout << count << '\n';
    return 0;
}