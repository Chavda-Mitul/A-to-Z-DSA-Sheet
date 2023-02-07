#include<stdio.h>
#include<math.h>
#define PI 3.14159265358979323846
int main(){
    float l,g,t;
    l = 50;
    g = 9.8;
    t = abs(2*PI*sqrt(l/g));
    printf("%.1f %.1f %.1f \n", l, g, t);
    return 0;
}