#include <iostream>

using namespace std;
void account();
void twoDReversed();
void twoDReversed2();
void multiDimArray();
void chess_horse();
int main()
{
    chess_horse();
    return 0;
}

void account() {

    short int n, m;
    cin >> n >> m;
    long long int a[m] = {0};
    for(int i = 0; i < m*n; i++)
    {
        int num = 0;
        cin >> num;
        a[i%m]+= num;
    }
    for(int i = 0; i < m; i++)
    {
        cout << a[i] << " ";
    }
}

void twoDReversed() {
    short int n = 0, m = 0;
    cin >> n >> m;
    int arr[n][m];

    for(short int i = n - 1; i >= 0; i--) {
        for(short int j = m - 1; j >= 0; j--) {
            cin >> arr[i][j];
        }
    }

    for(short int i = 0; i < n; i++) {
        for(short int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void twoDReversed2() {
    short int n = 0;

    cin >> n;

    int arr[n][n];

    for(short int i = 0; i < n; i++) {
        for(short int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    for(short int i = n -1; i >= 0; i--) {
        for(short int j = n - 1; j >= 0; j--) {
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }
}

void multiDimArray() {
    short int k, n, m;
    cin >> k >> n >> m;
    int three_d[k][n][m];

    for(int i = 0; i < k; i++) {
        for(int j = 0; j < n; j++) {
            for(int l = 0; l < m; l++) {
                cin >> three_d[i][j][l];
            }
        }
    }

    short int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> k >> n >> m;
        cout << three_d[--k][--n][--m] << endl;
    }
}

void chess_horse() {

    int x = 0, y = 0;
    int MOVES[8][2] = {
            {1, 2},
            {2, 1},
            {2, -1},
            {1, -2},
            {-1, -2},
            {-2, -1},
            {-2, 1},
            {-1, 2},
    };
    bool flag = false;
    size_t board[8][8] = {
        {46, 46, 46, 46, 46, 46, 46, 46},
        {46, 46, 46, 46, 46, 46, 46, 46},
        {46, 46, 46, 46, 46, 46, 46, 46},
        {46, 46, 46, 46, 46, 46, 46, 46},
        {46, 46, 46, 46, 46, 46, 46, 46},
        {46, 46, 46, 46, 46, 46, 46, 46},
        {46, 46, 46, 46, 46, 46, 46, 46},
        {46, 46, 46, 46, 46, 46, 46, 46}
    };
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            char cell = 0;
            cin >> cell;
            if(cell == 75) {
                board[i][j] = 75;
                for(int k=0; k < 8; k++) {
                    if(i+MOVES[k][1] < 8 && i+MOVES[k][1] >= 0 && j+MOVES[k][0] < 8 && j+MOVES[k][0] >= 0) {
                        board[i+MOVES[k][1]][j+MOVES[k][0]] = 33;
                    }
                }
                flag = true;
                break;
            }
        }
        if(flag) {break;}
    }

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            cout << (char)board[i][j];
        }
        cout << endl;
    }
}
//0 1 2 3 4 5 6 7
//4 6 5 1 9 1 0 8
//3 8 9 2 9 1 8 4
//9 1 8 7 9 8 0 4
//9 1 0 4 8 1 0 4
//9 1 0 8 9 1 0 4
//9 1 8 4 9 1 0 4
//9 8 0 4 9 1 0 4
//8 1 0 4 9 1 0 4
//
//
//5
//0 1 2 3 4
//0 1 2 3 4
//0 1 2 3 4
//0 1 2 3 4
//0 1 2 3 4
