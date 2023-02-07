#include<bits/stdc++.h>
using namespace std;

// power function
long int power(long long int a, long long int b, long long int p)
{
    if (b == 0)
        return 1;
 
    if (b == 1)
        return a % p;
 
    long int t = power(a, b / 2, p);
    t = (t * t) % p;
 
    
    if (b % 2 == 0)
        return t;
 

    else
        return ((a % p) * t) % p;
}


void diffieHellmanAlgorithm(int p,int g,int a,int b){
    int x = power(g,a,p);
    int y = power(g,b,p);

    int Ka = power(y,a,p);
    int Kb = power(x,b,p);

    cout << "Ka = " << Ka << endl;
    cout << "Kb = " << Kb << endl;
 }



int main(){
    diffieHellmanAlgorithm(23,5,6,15);
    return 0;
}