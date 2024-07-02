#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int n, m;
unordered_map<int,string>num;
unordered_map<string,int>str;

int main() {
    cin >> n >> m;

    // input
    for(int i=1;i<=n;i++){
        string tmp;
        cin >> tmp;

        num[i] = tmp;
        str[tmp] = i;
    }

    for(int i = 0;i<m;i++){
        string tmp;
        cin >> tmp;

        if(tmp[0] >= '1' && tmp[0] <= '9'){
            int res = stoi(tmp);
            cout << num[res] << "\n";
        }
        else{
            cout << str[tmp] << "\n";
        }
    }

    return 0;
}