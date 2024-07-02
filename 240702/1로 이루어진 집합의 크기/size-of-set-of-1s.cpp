#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct Node{
    int y;
    int x;
};

int n, m;
int arr[500][500];
int flag[500][500];
int island[20000];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int res;

void checkSize(){
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == 0) continue;
            if(flag[i][j] == 1) continue;

            queue<Node>q;
            q.push({i,j});
            arr[i][j] = ++cnt;
            flag[i][j] = 1;
            int local = 1;

            while(!q.empty()){
                Node now = q.front();
                q.pop();

                for(int k=0;k<4;k++){
                    int ny = now.y+dy[k];
                    int nx = now.x+dx[k];

                    if(ny<0||ny>=n||nx<0||nx>=m) continue;
                    if(arr[ny][nx] == 0) continue;
                    if(flag[ny][nx] == 1) continue;
                    
                    arr[ny][nx] = cnt;
                    flag[ny][nx] = 1;
                    q.push({ny,nx});
                    local++;
                }
            }
            island[cnt] = local;
            res = max(res, local);
        }
    }
}

int main() {
    cin >> n >> m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }

    checkSize();

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] != 0) continue;

            unordered_map<int,int>un;

            for(int k=0;k<4;k++){
                int ny = i+dy[k];
                int nx = j+dx[k];

                if(ny<0||ny>=n||nx<0||nx>=m) continue;
                if(arr[ny][nx] == 0) continue;
                
                un[arr[ny][nx]] = 1;
            }

            int tmp = 1;
            for(auto ele:un){
                tmp += island[ele.first];
            }

            res = max(res, tmp);
        }
    }

    cout << res;

    return 0;
}