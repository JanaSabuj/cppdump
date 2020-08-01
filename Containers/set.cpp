#include <bits/stdc++.h>
using namespace std;

int main() {
    
    multiset<int> s;
    s.insert(2);s.insert(78);s.insert(-3);s.insert(-3);s.insert(-3);
    // -3 -3 -3 2 78
    cout << *s.begin() << endl;// -3
    cout << *s.rbegin() << endl;// 78

    s.erase(s.find(-3));// -3 -3 2 78
    cout << *s.begin() << endl;// -3

    s.erase(s.find(-3));// -3 2 78
    cout << *s.begin() << endl;// -3

    s.erase(s.find(-3));// 2 78
    cout << *s.begin() << endl;// 2

    // s.erase(s.find(-3));// error
    
    if(s.find(-3) != s.end()) // do check for no error
        s.erase(s.find(-3));// no-error
    cout << *s.begin() << endl;

    return 0;
}
