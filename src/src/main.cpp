#include<iostream>
#include "sum.h"


using namespace std;

int main()
{   

    int a = 10;
    int b = 20;
    auto c = add_num(a,b);
    std::cout<< "Sum is: " << c << '\n';
    return 0;
}