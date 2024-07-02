#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n, k;
    unordered_map<int,int>um;

    cin >> n >> k;

    for(int i=0;i<n;i++){
        int input;
        cin >> input;

        if(um.count(input) == 0) um[input]=1;
        else um[input]++;
    }

    int res=0;

    for(auto ele:um){
        int now = ele.first;

        if(um.count(k-now)==0) continue;

        res+= (um[now] * um[k-now]);
    }

    cout << res/2;

    return 0;
}