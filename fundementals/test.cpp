#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> a{1, 2, 3, 4};
    for_each(a.begin(), a.end(), [](int &n) { cout << n; });
    cout << endl;
}