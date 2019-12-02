/*
    Time: O(N)
    Space: O(N)
*/
#include <iostream>
#include <string>
using namespace std;

class Deque {
private:
    static const int MAX = 10001;
    int front = 0;
    int rear = 0;
    int arr[MAX];

public:
    void push_front(int x) {
        arr[front] = x;
        front = (front - 1 + MAX);
    }

    void push_back(int x) {
        arr[rear] = x;
        rear += 1;
    }

    int pop_front() {
        if (this->empty()) {
            return -1;
        }
        else {
            int ret = arr[front];
            arr[front] = 0;
            front += 1;
            return ret;
        }
    }

    int pop_back() {
        if (this->empty()) {
            return -1;
        }
        else {
            int ret = arr[rear - 1];
            arr[rear] = 0;
            rear = (rear - 1 + MAX);
            return ret;
        }
    }

    int size() {
        return rear - front;
    }

    int empty() {
        return front == rear ? 1 : 0;
    }

    int Front() {
        if (this->empty()) {
            return -1;
        }
        else {
            return arr[front];
        }
    }

    int back() {
        if (this->empty()) {
            return -1;
        }
        else {
            return arr[rear - 1];
        }
    }
};

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(nullptr);
    cout.tie(nullptr);

    Deque deque;
    int N, X;
    string command = "";
    cin >> N;
    while (N--) {
        cin >> command;
        if ("push" == command) {
            cin >> X;
            queue.push(X);
        } else if ("pop" == command) {
            cout << queue.pop() << '\n';
        } else if ("size" == command) {
            cout << queue.size() << '\n';
        } else if ("empty" == command) {
            cout << queue.empty() << '\n';
        } else if ("front" == command) {
            cout << queue.Front() << '\n';
        } else if ("back" == command) {
            cout << queue.back() << '\n';
        }
    }
    return 0;
}