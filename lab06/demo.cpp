#include <iostream>         
#include <chrono>       // 获取时间
#include <vector>       // vector容器，与c++的内建数组相似
#include <algorithm>    // 标准算法，包含sort
#include <ctime>        // C标准库的时间函数，用于对随机序列进行播种（seed）
#include <cstdlib>      // C标准库，包含随机数产生函数rand()
using namespace std;

// # 程序框架：
// --------
// ## 自定义并实现的bubblesort函数
void bubblesort(int data[], int length) {
    bool flag;
    int end = length - 1;
    do {
        for (int i = 0; i < end; i++) {
            if (data[i] > data[i + 1]) {
                int temp = data[i];
                data[i] = data[i + 1];
                data[i + 1] = temp;
            }
        }
        end--;
    } while (end > 0);
}


// ## 主程序
// 1. 声明变量
// 1.1 声明存储随机数的数组 a[nSize]；
// 1.2 声明测试的次数const nTest = 50;
// 1.3 声明存储数据的数组 dataLength[nTest], bubbleSortTime[nTest], stlSortTime[nTest];
// 1.4 声明存储时间的start和stop=chrono::high_resolution_clock::now();
// 1.5 声明存储时长的double duration;
// 2. 进行测试
// 2.1 为随机函数播种 srand(time(0));
// 2.2 构建测试循环，循环变量int testId=0，边界nTest; for(;testId<nTest;testID++){}
// 2.3 计算本次测试的随机序列个数 int N = dataLength[testID] = 50*(testId+1);
// 2.4 产生随机序列，长度为N，for(;i<N;i++){a[i]=rand();}
// 2.5 构建vector容器并存储随机序列：vector<int> v(a, a+N);
// 2.6 记录开始时间 start=chrono::high_resolution_clock::now(); 
// 2.8 对v进行排序 sort(v.begin(), v.end());
// 2.9 记录结束时间 stop=chrono::high_resolution_clock::now(); 
// 2.10 计算排序耗时 
// duration=chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count()*1e-9;
// 2.11 存储耗时到数组 stlSortTime[testId]=duration;
// 2.13 记录开始时间 start=chrono::high_resolution_clock::now(); 
// 2.14 对v进行排序 sort(v.begin(), v.end());
// 2.15 记录结束时间 stop=chrono::high_resolution_clock::now(); 
// 2.16 计算排序耗时 
// duration=chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count()*1e-9;
// 2.17 存储耗时到数组 bubbleSortTime[testId]=duration;
// 2.18 结束测试循环---> 2.2
// 3. 输出数据
// 3.1 打印数据头 cout << "Length," << "bubbleSort," << "stlSort\n"; 
// 3.2 遍历各测试结果的循环 for(int i=0; i<nTest; i++)
// 3.3 输出 cout << dataLength[i] << "," << bubbleSortTime[i] << "," << stlSortTime[i] << "\n";
// 4 返回 return 0;



