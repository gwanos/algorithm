#include <iostream>
#include <numeric>
using namespace std;

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, x, y;
    cin >> T;
    while (T--) {
        cin >> x >> y;
        cout << std::lcm(x, y) << '\n';
    }

    return 0;
}