#include<bits/stdc++.h>
using namespace std;
string lcs(string s1, string s2 ,int i1, int i2){
    //base case
    if(i1<0 || i2<0){
        return "";
    }
    // matched
    if(s1[i1] == s2[i2]){
        return s1[i1] + lcs(s1,s2,i1-1,i2-1);
    }
    //not matched
    return "" + (lcs(s1,s2,i1-1,i2),lcs(s1,s2,i1,i2-1));
}
int main()
{
    string s1 = "abcde", s2 = "bdgek";
    int n1 = s1.length() , n2 = s2.length(); 
    cout << lcs(s1,s2,n1-1,n2-1) << endl;    
    return 0;
}
