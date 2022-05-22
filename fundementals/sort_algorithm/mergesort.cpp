//归并排序
//目标数组从小到大排列
//具体实现调用归并的子过程

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//假设num[start1]~num[end1]和num[start2]~num[end2]是有序的,并且start2=end1+1
void merge_alg(vector<int> &num, int start1, int end1, int start2, int end2)
{
    vector<int> leftPart(num.begin() + start1, num.begin() + end1 + 1);
    vector<int> rightPart(num.begin() + start2, num.begin() + end2 + 1);
    auto p1 = leftPart.begin();
    auto p2 = rightPart.begin();
    auto endp1 = leftPart.end();
    auto endp2 = rightPart.end();

    auto res_p = num.begin() + start1;

    while (p1 != endp1 && p2 != endp2)
    {
        if (*p1 <= *p2)
        {
            *res_p = *p1;
            res_p++;
            p1++;
        }
        else
        {
            *res_p = *p2;
            res_p++;
            p2++;
        }
    }
    if (p1 == endp1)
    {
        while (p2 != endp2)
        {
            *res_p = *p2;
            res_p++;
            p2++;
        }
    }
    else
    {
        while (p1 != endp1)
        {
            *res_p = *p1;
            res_p++;
            p1++;
        }
    }
}

void mergeSortLoop(vector<int> &nums)
{
}

void mergeSortRecurse(vector<int> &num, int start, int end)
{
    if (start == end)
        return;
    mergeSortRecurse(num, start, (start + end) / 2);
    mergeSortRecurse(num, (start + end) / 2 + 1, end);
    merge_alg(num, start, (start + end) / 2, (start + end) / 2 + 1, end);
}

int main()
{
    vector<int> a{9, 21, 34, 50, 4, 16, 69, 90};
    merge_alg(a, 0, 3, 4, 7);
    vector<int> test{54, 64, 12, 90, 32, 83, 22};
    mergeSortRecurse(test, 0, test.size() - 1);
    for_each(test.begin(), test.end(), [](int &n) { cout << n << " "; });
    cout << endl;
}