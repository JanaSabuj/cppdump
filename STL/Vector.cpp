#include <bits/stdc++.h>
using namespace std;

template <class T>
class Vector{
    T* data;// dynamic array
    int sz;// total size
    int curr;// curr size

    public:
    Vector(){
        data = new T[1];
        sz = 1;
        curr = 0;
    }

    int getSize(){
        return curr;
    }

    T& operator[](int idx){
        return data[idx];
    }

    void push_back(T x){                
        if(curr == sz){
            T* temp = new T[2*sz];
            
            for(int i = 0; i < curr; i++)
                temp[i] = data[i];// copy old

            sz = 2*sz;
            delete[] data;
            data = temp;
        }

        data[curr] = x;
        curr++;        
    }

    void pop_back(){
        curr--;
    }

    ~Vector(){
        delete[] data;
    }

};


int main() {
    Vector<double> v;
    v.push_back(15.252);
    v.push_back(20.123);
    v.push_back(1.455);
    v.push_back(5.544);
    v.push_back(15.55);

    v[1] = 28.1132;

    v.pop_back();

    for(int i = 0; i < v.getSize(); i++)
        cout << v[i] << " ";

    return 0;
}
