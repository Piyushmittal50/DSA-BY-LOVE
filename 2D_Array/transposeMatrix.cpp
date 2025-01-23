#include<iostream>
using namespace std;
#define M 3
#define N 4

int main(){
    int arr[M][N] = { {1,1,1,1},
                      {2,2,2,2},
                      {3,3,3,3},
                     };
    int ans[N][M];
    for (int i = 0; i < M;i++){
        for (int j = 0; j < N;j++){
            ans[j][i] = arr[i][j];
        }
    }

    cout << "after transpose : " << endl;
    for (int i = 0; i < N;i++){
        for (int j = 0; j < M;j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}