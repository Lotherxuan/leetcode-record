/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
/* 递归,暴力法
class Solution
{
public:
    int fib(int N)
    {
        if (N == 0 || N == 1)
        {
            return N;
        }
        else
        {
            return fib(N - 1) + fib(N - 2);
        }
    }
}; */

/* #include <vector>
using namespace std; */
//带备忘录的动态规划，自底向上
class Solution
{
public:
    int fib(int N)
    {
        if (N == 0 || N == 1)
        {
            return N;
        }
        vector<int> fib_array(N + 1);
        fib_array[0] = 0;
        fib_array[1] = 1;
        for (size_t i = 2; i <= N; i++)
        {
            fib_array[i] = fib_array[i - 1] + fib_array[i - 2];
        }

        return fib_array[N];
    }
};
// @lc code=end
