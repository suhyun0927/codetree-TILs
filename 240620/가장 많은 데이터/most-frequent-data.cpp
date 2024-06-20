#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, int> um;

int main() {    
    int n, Max = 0;
    cin >> n;

    for(int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;

        if(um.count(tmp) == 0) um[tmp] = 1;
        else um[tmp]++;

        Max = max(um[tmp], Max);
    }

    cout << Max;

    return 0;
}