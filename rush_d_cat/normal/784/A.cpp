#include <iostream>
using namespace std;
const int a[]={0,4, 22, 27, 58, 85, 94, 121, 166, 202, 265, 274, 319, 346, 355, 378, 382, 391, 438, 454, 483, 517, 526, 535, 562, 576, 588, 627, 634, 636, 645};
int main()
{
    int x;
    cin >> x;
    if(x<=30) cout << a[x];
    else cout << "";
}