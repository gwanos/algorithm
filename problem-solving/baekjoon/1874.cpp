/*
    Time: O(N)
    Space: O(N)
*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool isPossible(vector<int> &seq, vector<char> &arr)
{
    int current = 1;    // 다음번 스택에 들어가야 할 수
    stack<int> stack;

    for (int i = 0; i < seq.size(); i++) 
    {
        if (current < seq[i]) 
        {
            for (int j = current; j <= seq[i]; j++)
            {
                stack.push(j);
                arr.push_back('+');
            }
            stack.pop();
            arr.push_back('-');
            current = seq[i] + 1;
        }
        else if (current == seq[i])
        {
            stack.push(seq[i]);
            arr.push_back('+');
            
            stack.pop();
            arr.push_back('-');
            current += 1;
        }
        else 
        {
            int top = stack.top();   
            if (top == seq[i]) 
            {
                stack.pop();
                arr.push_back('-');
            }
            else 
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(nullptr); 
    cout.tie(nullptr);

    int T;
    cin >> T;
    vector<int> seq(T, 0);
    vector<char> arr;
    for (int i = 0; i < T; i++)
    {
        int num;
        cin >> num;
        seq[i] = num;
    }

    bool ret = isPossible(seq, arr);
    if (true == ret) 
    {
        for (auto ch : arr) 
        {
            cout << ch << '\n';
        }
    }
    else 
    {   
        cout << "NO" << '\n';
    }

    return 0;
}