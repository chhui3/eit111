#include <iostream>
using namespace std;

const int colnum = 4;
const int rownum = 4;

int problem[rownum][colnum] = {
    {0,3,/**/ 0,0},
    {0,2,/**/ 3,0},
    ///////////////
    {0,0,/**/ 0,0},
    {0,0,/**/ 0,4}
};
// problem2 减去了右下角的4, 应有两个解
int problem2[rownum][colnum] = {
    {0,3,/**/ 0,0},
    {0,2,/**/ 3,0},
    ///////////////
    {0,0,/**/ 0,0},
    {0,0,/**/ 0,0}
};
// problem3 只留4个空格，有2个解，观察递归调用的变化
int problem3[rownum][colnum] = {
    {1,3,/**/ 2,4},
    {4,2,/**/ 3,1},
    ///////////////
    {2,0,/**/ 0,3},
    {3,0,/**/ 0,2}
};


void printMatrix(int p[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << p[i][j] << " ";
        }
        cout << endl;
    }
}


//写一个判断函数，判断是否将数字n填写到y行x列的位置
bool possible(int a[4][4], int n, int y, int x) {
    // 看看第y行是否有该数字？
    for (int i = 0; i < colnum; i++) {
        if (a[y][i] == n) return false;
    }
    // 看看第x列是否有该数字？
    for (int i = 0; i < rownum; i++) {
        if (a[i][x] == n) return false;
    }
    // 看看第y行第x列所在的大格子是否有该数字？
    int x0 = (x / 2) * 2;
    int y0 = (y / 2) * 2;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
        {
            if (a[y0 + i][x0 + j] == n) return false;
        }
    }   
    return true;
}




//写一个递归函数solve(int a[4][4])
void solve(int a[4][4]) {
    //嵌套循环遍历数组
    for (int y = 0; y < rownum; y++)
    {
        for (int x = 0; x < colnum; x++)
        {
            //      如果当前a[y][x]的值是零
            if (a[y][x] == 0) {
            //      遍历待填写数的范围（1 - 4） ，设变量n
                for (int n = 1; n <= 4; n++)
                {
                    //     如果判断possible(a, n, y, x)返回
                    if (possible(a, n, y, x) == true) {
                        //                    将n填入当前格子（a[y][x] = n）（试填）
                        a[y][x] = n;
                        //                    调用自己（solve(a)）
                        solve(a);
                        //                    将0填入当前格子（a[y][x] = 0）（擦除）
                        a[y][x] = 0;
                        
                    } // if possible
                } // for n
                return; //         在某空格上所有的数字尝试完了，返回
            } // for a[y][x] == 0
        } // for col
    } // for row

    //      求得解，打印
    printMatrix(a);
    // 
}

int main() {
    solve(problem3);
    return 0;
}
