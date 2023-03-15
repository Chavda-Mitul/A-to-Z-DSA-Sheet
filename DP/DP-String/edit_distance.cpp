#include <bits/stdc++.h>
using namespace std;
int editDistance(int i, int j, string s1, string s2)
{
    // base case
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;

    if (s1[i] == s2[j])
    {
        return 0 + editDistance(i - 1, j - 1, s1, s2);
    }
    return min(min(
                   1 + editDistance(i - 1, j, s1, s2),  // delete
                   1 + editDistance(i, j - 1, s1, s2)), // insert
               1 + editDistance(i - 1, j - 1, s1, s2)); // replace
}

int main()
{
    string s1 = "intention", s2 = "execution";
    int n = s1.size(), m = s2.size();
    cout << editDistance(n - 1, m - 1, s1, s2) << endl;
    return 0;
}