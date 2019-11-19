#include <iostream>
using namespace std;

/*
    Note: cin/count은 느리다. 하지만, 아래 코드를 사용한다면 scanf/printf만큼 빨라진다.
			ios_base::sync_with_stdio(false);
    		cin.tie(nullptr);
    		cout.tie(nullptr);
*/
int main(void)
{
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
	int a, b;
	while (cin >> a >> b)
	{
		cout << a + b << endl;
	}
	
	return 0;
}