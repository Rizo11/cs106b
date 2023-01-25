#include <iostream>

using namespace std;
void account();
void twoDReversed();
void twoDReversed2();

int main()
{
    twoDReversed2();
    return 0;
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
    
    
    int i = 0, j = 0, c = 1;
    while (true) {
        if(n-i-1 == j){
            cout << arr[i][j] << " ";
            j++;
        } else {
            if (i < n/2 || j < n/2) {
                cout << arr[(j+(n-j-2))%n][(i+(n-i-1))%n] << " ";
                j++;
            } else {
                cout << arr[(j+(n-j-2))%n][(i+(n-i-1))%n] << " ";
                j++;
            }
        }
        
        if(j == n || i == n) {
            cout << endl;
            i++;
            j == 0;
        }
    }
}