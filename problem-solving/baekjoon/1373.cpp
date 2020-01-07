/*
    Time: O(N)
    Space: O(N)
    Note: 주어진 수가 너무 크기 때문에 자료형에 저장할 수 없어서 
          long long 타입을 사용했지만 오답이 났었다.
          자료형에 저장하지 않고, 변환하는 즉시 출력하는 방식으로 풀어야 한다.
*/
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

void convert(string &number)
{
    long long n = 0;
    long long ret = 0;
    int len = number.length();
    int num = 0;

    if (len % 3 == 1) {
        num = number[0] - '0'; // 1의 자리는 변환 필요 없음
        cout << num;
    }
    else if (len % 3 == 2) {
        int a = (number[0] - '0') << 1;
        int aa = (number[0] - '0') * 2;
        int b = (number[1] - '0');

        num = ((number[0] - '0') << 1) + (number[1] - '0');
        cout << num;
    }
    for (int i = len % 3; i < len; i+= 3) {
        num = ((number[i] - '0') << 2) + ((number[i + 1] - '0') << 1) + (number[i + 2] - '0');
        cout << num;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    string number;
    cin >> number;

    convert(number);
    cout << '\n';
    
    return 0;
}