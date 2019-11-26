/*
    Time: O(N + M)
    Space: O(N)
    Note: list.erase(iterator)를 수행하면 해당 iterator는 invalidated 된다.
          즉, 사용 불가능해진다. 해당 iterator에 접근하려고하면 런타임에러가 발생한다.
    Note: 문자열 출력으로 인해 시간복잡도 O(N)을 가짐. 
          리스트 자체 insert, erase 연산은 O(1).
*/
#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N = 0;
    string str = "";
    cin >> str >> N;

    char ch, input;
    list<char> lst;
    for (auto ch : str)
    {
        lst.push_back(ch);
    }
    auto iter = lst.end();

    while (N--)
    {
        cin >> ch;
        if ('L' == ch) 
        {
            if (iter != lst.begin())
            {
                iter--;
            }           
        }
        else if ('D' == ch)
        {
            if (iter != lst.end())
            {
                iter++;
            }
        }
        else if ('B' == ch)
        {
            if (iter != lst.begin())
            {
                iter--;
                iter = lst.erase(iter);
            }
        }
        else if ('P' == ch)
        {
            cin >> input;
            lst.insert(iter, input);            
        }
    }

    //
    for (auto ch : lst)
    {
        cout << ch;
    }
    cout << '\n';
    return 0;
}