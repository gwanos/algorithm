/*
	Time: O(1)
	Space: O(N)
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Stack {
private:
	int size;
	int vec[10001];
public:
	Stack() {
		size = 0;
	}

	void push(int X) {
		vec[size] = X;
		size++;
	}

	int pop() {
		if (0 == size) {
			return -1;
		}
		int ret = vec[size - 1];
		vec[size - 1] = 0;
		size--;
		return ret;
	}

	int Size() {
		return size;
	}

	int empty() {
		return 0 == size ? 1 : 0;
	}

	int top() {
		if (0 == size) {
			return -1;
		}
		return vec[size - 1];
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Stack stack;
	int N = 0;
	string command = "";
	cin >> N;

	while (N--) {
		cin >> command;
		if ("push" == command) {
			int X;
			cin >> X;
			stack.push(X);
		}
		else if ("pop" == command) {
			cout << stack.pop() << '\n';
		}
		else if ("size" == command) {
			cout << stack.Size() << '\n';
		}
		else if ("empty" == command) {
			cout << stack.empty() << '\n';
		}
		else if ("top" == command) {
			cout << stack.top() << '\n';
		}
	}

	return 0;
}