/*
    Time: O(N)
    Space: O(1)
    Note: 이 문제의 경우 (와 ) 갯수만 알면 되기 때문에 굳이 stack을 굳이 사용 할 필요가 없다.
*/

#include <iostream>
#include <string>
using namespace std;

string valid(string& str)
{
    int cnt = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
        {
            cnt += 1;
        }
        else if (str[i] == ')') 
        {
            cnt -= 1;
        }
        
        if (cnt < 0)    // '(' 가 부족한 경우
        {
            return "NO";
        }
    }

    if (cnt == 0)
    {
        return "YES";
    }
    else 
    {
        return "NO";
    }
}

int main() 
{
    ios_base::sync_with_stdio;
    cin.tie(nullptr);

    //
    int T = 0;
    cin >> T;
    cin.ignore();

    while (T--)
    {
        string str = "";
        getline(cin, str);
        cout << valid(str) << '\n';
    }

    return 0;
}