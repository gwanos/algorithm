//
// Created by 이관호 on 2019-06-23.
//

#ifndef LEETCODE_79WORDSEARCH_H
#define LEETCODE_79WORDSEARCH_H

#endif //LEETCODE_79WORDSEARCH_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        ySize = board.size();
        xSize = board[0].size();
        int depth = 0;
        vector<vector<bool>> isVisited(ySize, vector<bool>(xSize, false));

        auto ret = false;
        for (int y = 0; y < ySize; y++) {
            for (int x = 0; x < xSize; x++) {
                auto ret = visit(y, x, board, isVisited, word, depth);
                if (ret == true) {
                    return ret;
                }
            }
        }

        return ret;
    }

    bool visit(int y, int x, vector<vector<char>>& board, vector<vector<bool>> &isVisited, string word, int depth) {
        if (y >= ySize || y < 0) {
            return false;
        }
        if (x >= xSize || x < 0) {
            return false;
        }
        if (board[y][x] != word[depth]) {   // 글자 만들 수 있는지 검사
            return false;
        }
        if (isVisited[y][x]) {  // 사용했는지 검사
            return false;
        }

        //
        depth++;
        isVisited[y][x] = true;
        if (word.size() == depth) {
            return true;
        }

        for (int next = 0; next < 4; next++) {
            int nextY = y + yPos[next];
            int nextX = x + xPos[next];

            bool ret = visit(nextY, nextX, board, isVisited, word, depth);
            if (ret == true) {
                return true;
            }
        }

        depth--;
        isVisited[y][x] = false;
        return false;
    }
private:
    vector<int> yPos = { -1, 1, 0, 0 };
    vector<int> xPos = { 0, 0, -1, 1 };
    int ySize = 0;
    int xSize = 0;
};