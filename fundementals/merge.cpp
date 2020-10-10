//二路归并，合并两个已排序好的数组
//目标数组从小到大排列
//具体实现类似于用三个指针分别指向第一个数组，第二个数组和返回数组

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> merge(vector<int> &num1, vector<int> &num2)
{
    int size1 = num1.size();
    int size2 = num2.size();
    int cur1 = 0;
    int cur2 = 0;
    int resCur = 0;
    vector<int> res(size1 + size2);
    while (cur1 < size1 && cur2 < size2) //注意小于号还是等于号的边界条件，vector的size值比下标最大索引值要大1
    {
        if (num1[cur1] <= num2[cur2])
        {
            res[resCur] = num1[cur1];
            resCur++;
            cur1++;
        }
        else
        {
            res[resCur] = num2[cur2];
            resCur++;
            cur2++;
        }
    }
    if (cur1 >= size1)
    {
        while (cur2 <= size2)
        {
            res[resCur] = num2[cur2];
            resCur++;
            cur2++;
        }
    }
    else
    {
        while (cur1 <= size1)
        {
            res[resCur] = num1[cur1];
            resCur++;
            cur1++;
        }
    }
    return res;
}

int main()
{
    vector<int> a{9, 21, 34, 50};
    vector<int> b{4, 16, 69, 90};
    vector<int> res = merge(a, b);
    for_each(res.begin(), res.end(), [](int &n) { cout << n << " "; });
    cout << endl;
}