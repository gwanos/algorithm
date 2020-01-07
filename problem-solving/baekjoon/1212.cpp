/*
    Time: O(N)
    Space: O(N)
*/
#include <iostream>
#include <string>
using namespace std;

void convert(string &number)
{
    string str = "000";
    int quotient, remainder;
    for (int i = 0; i < number.length(); i++) {
        quotient = number[i] - '0';
        for (int j = str.length() - 1; j >= 0; j--) {
            remainder = quotient % 2;
            quotient /= 2;
            str[j] = remainder + '0';
            if (0 == quotient) {
                break;
            }
        }

        if (i == 0) {
            if (str[0] == '0') {
                if (str[1] == '0') {
                    cout << str[2];
                }
                else {
                    cout << str[1] << str[2];
                }
            }
            else {
                cout << str;
            }
        }
        else {
            cout << str;
        }
        str = "000";
    }
}

void convert2(string &number)
{
    string eight[8] = {"000","001","010","011","100","101","110","111"};
    int num;


    for (int i = 0; i < number.length(); i++) {
        num = number[i] - '0';
        if (i == 0) {
            string str = eight[num];
            if (str[0] == '0') {
                if (str[1] == '0') {
                    cout << str[2];
                }
                else {
                    cout << str[1] << str[2];
                }
            }
            else {
                cout << str;
            }
        }
        else {
            cout << eight[num];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    cout.tie(nullptr);

    string number;
    cin >> number;

    convert(number);
    cout << '\n';

    return 0;
}