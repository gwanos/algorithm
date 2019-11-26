/*
    Time: O(N + M)
    Space: O(N)
    Note: 두 개의 스택을 사용해서도 풀 수 있음. 
          커서를 기준으로 왼쪽, 오른쪽 문자들을 각각의 스택에 저장 
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

    int N = 0;
    string str = "";
    stack<char> left, right;

    cin >> str >> N;
    for (auto ch : str)
    {
        left.push(ch);
    }

    char ch;
    while (N--)
    {
        cin >> ch;
        if ('L' == ch) 
        {
            if (false == left.empty())
            {
                right.push(left.top());
                left.pop();
            }
        }
        else if ('D' == ch)
        {
            if (false == right.empty())
            {
                left.push(right.top());
                right.pop(); 
            }
        }
        else if ('B' == ch)
        {
            if (false == left.empty())
            {
                left.pop();
            }
        }
        else if ('P' == ch)
        {
            cin >> ch;
            left.push(ch);
        }
    }

    //
    while (false == left.empty())
    {
        right.push(left.top());
        left.pop();
    }
    while (false == right.empty())
    {
        char ch = right.top();
        cout << ch;
        right.pop();
    }
    cout << '\n';

    return 0;
}