/*
    Note: 
      (A + B) mod M = ((A mod M) + (B mod M)) mod M
      (A * B) mod M = ((A mod M) * (B mod M)) mod M
      (A - B) mod M = ((A mod M) - (B mod M) + M) mod M // +M하는 이유? 결과가 음수가 나오는 것 방지
*/
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(nullptr);
    cout.tie(nullptr);

    int A, B, C;
    cin >> A >> B >> C;

    cout << (A + B) % C << '\n';
    cout << (A % C + B % C) % C << '\n';
    cout << (A * B) % C << '\n';
    cout << (A % C * B % C) % C << '\n';
    
    return 0;
}