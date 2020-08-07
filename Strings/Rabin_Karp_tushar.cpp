#include <bits/stdc++.h>
using namespace std; 

const int p = 31;
vector<int> power;

void power_precalc(int m){
    power.resize(m);
    power[0] = 1;// p^0
    for(int i = 1; i < m; i++)
        power[i] = power[i - 1] * p;        
}
// get hash of a string
int getHash(string str, int n){
    int val = 0;
    for(int i = 0; i < n; i++){
        val = val + str[i] * power[i];
    }

    return val;
}

// check if 2 strings are identical
bool isEqual(string& pattern, int i, int m, string& text, int j, int n){
    // pattern [0..m-1]
    // text [j..n-1]

    for(int k = 0; k < m; k++){
        if(pattern[i + k] != text[j + k])
            return false;            
    }

    return true;
}

// update the rolling hash
void recalc(int& t_h, string& text, int oldIdx, int newIdx, int m){
    t_h = t_h - text[oldIdx];
    t_h = t_h/p;
    t_h = t_h + text[newIdx] * power[m-1];    
}

void rabinKarp(string text, string pattern){
    // text = "madamadamadam"
    // pattern = "madam"
    vector<int> ids;
    int n = text.size();
    int m = pattern.size();    
    power_precalc(m);

    int p_h = getHash(pattern, m);
    int t_h = getHash(text, m);

    for(int i = 1; i <= n - m + 1; i++){
        if(p_h == t_h and isEqual(pattern, 0, m, text, i - 1, i - 1 + m)){
            ids.push_back(i - 1);            
        }

        // if not the last window
        if(i < n - m + 1){
            recalc(t_h, text, i - 1, i - 1 + m, m);
        }
    }

    for(auto x: ids)
        cout << x << " ";
}

int main() {    
    rabinKarp("madamadamadam", "madam");
    return 0;
}
