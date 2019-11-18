#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
    Time: O(mn)
    Space: O(1)
    Note: strs이 empty 일 때 예외처리를 하지 않았더니 다음과 같은 에러가 발생했다.
            - runtime error: reference binding to null pointer of type 'struct value_type'
          strs를 정렬 후, 가장 길이가 짧은 단어를 기준으로 잡는다면 수행시간 단축될 것.
    Tag: #scanning #binary_search
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (0 == strs.size()) {
            return "";
        }
        
        string prefix = "";
        for (int i = 0; strs[0].length(); i++) {
            char singlechar = strs[0][i];   // 기준.첫번째 단어
            for (string word : strs) {
                if (word[i] == NULL) {
                    return prefix;
                }
                if (singlechar != word[i]) { // 기준과 같은지 비교         
                    return prefix;
                }
            }
            prefix += singlechar;
        }
        return prefix;
    }
};