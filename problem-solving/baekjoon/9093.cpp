/*
    Time: O(N)  // 입력 전체가 길이 N인 한 단어 일 때. push, pop은 O(1)
    Space: O(N)
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio;
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    //
    int T = 0;
    cin >> T;
    cin.ignore();   // 입력 버퍼 비우기
    while (T--)
    {
        string str = "";
        getline(cin, str);  // '\n' 전까지 읽음
        str += '\n';
        stack<char> words;
        for (auto ch : str)
        {
            if (ch == ' ' || ch == '\n')
            {
                while (false == words.empty())
                {
                    cout << words.top();
                    words.pop();
                }
                cout << ch;
            }
            else 
            {
                words.push(ch);
            }    
        }
    }

    return 0;
}