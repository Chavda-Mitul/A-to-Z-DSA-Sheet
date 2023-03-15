#include <bits/stdc++.h>
using namespace std;
int f(int i, int j, string s1, string s2)
{
    if (j < 0)
        return 1;
    if (i < 0)
        return 0;

    if (s1[i] == s2[j])
    {
        return f(i - 1, j - 1, s1, s2) + f(i - 1, j, s1, s2);
    }
    else
    {
        return f(i - 1, j, s1, s2);
    }
}

int main()
{
    string s1 = "rabbbit", s2 = "rabbit";
    int n = s1.size() - 1;
    int m = s2.size() - 1;
    int ans = f(n, m, s1, s2);
    cout << ans << endl;
    return 0;
}