#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int n;
unordered_map<int, int> m;

int main() {
    cin >> n;

    for(int i=0;i<n;i++){
        string tmp;
        cin >> tmp;

        if(tmp == "add"){
            int k, v;
            cin >> k >> v;

            m[k] = v;
        }
        else if(tmp == "remove"){
            int k;
            cin >> k;

            m.erase(k);
        }
        else{ // find
            int k;
            cin >> k;

            if(m.find(k) == m.end()) cout << "None\n";
            else cout << m[k] << "\n";
        }
    }
    
    return 0;
}