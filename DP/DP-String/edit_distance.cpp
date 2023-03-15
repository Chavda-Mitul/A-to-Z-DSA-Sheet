#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, string s1, string s2)
{
    if (i < 0 || j < 0)
        return 0;

    if (s1[i] == s2[j])
    {
        return 1 + f(i - 1, j - 1, s1, s2);
    }
    else
    {
        return 0 + max(f(i - 1, j, s1, s2), f(i, j - 1, s1, s2));
    }
}

int lcs(string &s1, string &s2)
{
    //	Write your code here.

    int n = s1.size();
    int m = s2.size();

    vector<int> prev(m + 1, 0), cur(m + 1, 0);

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                int val = 1 + prev[j - 1];
                cur[j] = val;
                ans = max(ans, val);
            }
            else
                cur[j] = 0;
        }
        prev = cur;
    }

    return ans;
}

int main()
{
    string s1 = "intention", s2 = "execution";
    int n = s1.size();
    int k = lcs(s1, s2);
    int ans = n - k;
    cout << ans << endl;
    return 0;
}