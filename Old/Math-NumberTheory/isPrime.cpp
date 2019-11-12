#include <iostream>
using namespace std;

bool isPrime(int x){
    if(x<2) return false;
    if(x==2) return true;
    if(!(x&1)) return false;
    for (int i = 3; i * i <= x ; i += 2)
    {
        /* code */
        if(x%i == 0)
            return false;
    }

    return true;

}

 