#include <vector>

using namespace std;

/**
 * 59. 螺旋矩阵 II
 * https://leetcode.cn/problems/spiral-matrix-ii/
 */
class LeetCode59 {
public:
    vector<vector<int>> generateMatrix(int n) {
        //开始循环的列
        int startCol = 0;
        //开始循环的行
        int startRow = 0;
        //限制索引，每次for循环完成后，由于最后还有个++和--操作，row和col都会处于下一次循环开始的位置
        int offset = 1;
        //循环的次数
        int loop = n / 2;

        int count = 0;
        int col, row;

        vector<vector<int>> resultMatrix(n, vector<int>(n));

        while (loop--) {
            for (col = startCol; col < n - offset; ++col)
                resultMatrix[startRow][col] = ++count;

            for (row = startRow; row < n - offset; ++row)
                resultMatrix[row][col] = ++count;

            for (; col > startCol; --col)
                resultMatrix[row][col] = ++count;

            for (; row > startRow; --row)
                resultMatrix[row][startCol] = ++count;

            startCol++;
            startRow++;
            offset++;
        }

        //矩阵的n为奇数，最后会剩下一个坐标为(row,col)的中心点
        if (n % 2 == 1)
            resultMatrix[startRow][startCol] = ++count;

        return resultMatrix;
    }
};
