#include <algorithm>
#include <vector>
using namespace std;

/*
    Time: O(n)
    Space: O(n)
    Note: 인덱스 기반 for 문을 사용할 때는 runtime range_error 발생에 주의!
    Tag: #DP #SlidingWindow
*/
class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int size = A.size();
        vector<vector<int> > dp(2, vector<int>(size + 1, 1));
        int currentMaxA = dp[0][0];
        int currentMaxB = dp[1][0];
        
        for (int k = 1; k < size; k++) {
            //
            if ((this->isAFirstPattern(A, k, size))){
                currentMaxA += 1;
            }
            else {
                currentMaxA = 1;
            }
            
            //
            if (this->isASecondPattern(A, k, size)) {
                currentMaxB += 1;
            }
            else {
                currentMaxB = 1;
            }
            //
            dp[0][k] = max(currentMaxA, dp[0][k - 1]);
            dp[1][k] = max(currentMaxB, dp[1][k - 1]);
        }
        
        return max(dp[0][size - 1], dp[1][size - 1]);
    }

private:    
    bool isAFirstPattern(vector<int>& A, int k, int size) {
        if (k == 0) {
            return true;
        }
        if ((0 != k % 2) && (A[k] > A[k - 1])) {
            return true;
        }
        if ((0 == k % 2) && (A[k] < A[k - 1])) {
            return true;
        }
        return false;
    }
    
    bool isASecondPattern(vector<int>& A, int k, int size) {
        if (k == 0) {
            return true;
        }
        if ((0 != k % 2) && (A[k] < A[k - 1])) {
            return true;
        }
        if ((0 == k % 2) && (A[k] > A[k - 1])) {
            return true;
        }
        return false;
    }
};