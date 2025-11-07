#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long total_sum = 0;
    long long sum_of_squares = 0;
    for (int i = 0; i < n; ++i)
    {
        long long val;
        cin >> val;
        total_sum += val;
        sum_of_squares += val * val;
    }

    long long result = (total_sum * total_sum - sum_of_squares) / 2;

    cout << result << endl;

    return 0;
}
