#include <iostream>
#include <unordered_map>

using namespace std;

int n, m;
unordered_map<int,int> um;

int main() {
    cin >> n >> m;

    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;

        if(um.count(tmp) == 0) um[tmp] = 1;
        else um[tmp]++;
    }

    for(int i=0;i<m;i++){
        int index;
        cin >> index;

        cout << um[index] << " ";
    }

    return 0;
}