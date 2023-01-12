#include <iostream>

using namespace std;

void show_diagonals() {
    int d = 4;
    int matrix[d][d];
    cout << "Enter matrix: " << endl;

    for(int i= 0; i < d; i++) {
        for(int j= 0; j < d; j++) {
            cin >> matrix[i][j];
        }
    }

    int i = 0, j = d-1;
    while(true) {
        cout << matrix[i][j] << " ";
        ++i; ++j;

        if(i == d && j == 1) {
            break;
        }

         if (i == d) {
            i = d - j + 1;
            j = 0;
            cout << endl;
        } else if(j == d) {
            j = d - i - 1;
            i = 0;
            cout << endl;
        }
    }
}

void find_negativ() {
    int r = 3, c = 4;
    int matrix[r][c] = {{}};

    cout << "Enter matrix: " << endl;

    for(int i= 0; i < r; i++) {
        for(int j= 0; j < c; j++) {
            cin >> matrix[i][j];
        }
    }

    int neg_val = 0, r_min = 0, c_min= 0;
    bool OK = false;

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(matrix[i][j] < 0) {
                neg_val = matrix[i][j];
                r_min = i;
                c_min = j;
                OK = true;
                break;
            }
        }
        if(OK) {
            break;
        }
    }

    cout << "min : " << neg_val << " at " << r_min << " " << c_min << endl;
}

void find_min_max() {

    int r = 3, c = 4;
    int matrix[r][c] = {{}};

    cout << "Enter matrix: " << endl;

    for(int i= 0; i < r; i++) {
        for(int j= 0; j < c; j++) {
            cin >> matrix[i][j];
        }
    }

    int a_min= matrix[0][0], r_min = 0, c_min= 0;
    int a_max = matrix[0][0], r_max = 0, c_max = 0;

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(a_min > matrix[i][j]) {
                a_min = matrix[i][j];
                r_min = i;
                c_min = j;
            } else if(a_max < matrix[i][j]) {
                a_max = matrix[i][j];
                r_max = i;
                c_max = j;
            }
        }
    }

    cout << "neg : " << a_min << " at " << r_min << " " << c_min << endl;
}

void diagonal_sum_sq_matrix() {
    int r = 3;
    int matrix[r][r] = {{0}};

    cout << "Enter matrix: " << endl;

    for(int i= 0; i < r; i++) {
        for(int j= 0; j < r; j++) {
            cin >> matrix[i][j];
        }
    }

    int m_sum = 0, s_sum = 0;
    for(int i = 0; i < 3; i++) {
        m_sum += matrix[i][i];
        s_sum += matrix[i][3-i-1];
    }

    cout << "main diagonal sum: " << m_sum << ", secondary diagonal sum: " << s_sum << endl;
}

int main()
{
    // a[rows][columns]
    //2D
    //int a[3][4];

    //3D
    //int b[5][5][5];


//    int n = 3, m = 4;
//    int a[n][m];
//    for(int j = 0; j < n; j++) {
//        for(int i = 0; i < m; i++) {
//            cin >> a[j][i];
//        }
//    }
//
//    cout << "Regular matrix: " << endl;
//    for(int j = 0; j < n; j++) {
//        for(int i = 0; i < m; i++) {
//            cout <<  a[j][i] << " ";
//        }
//        cout << endl;
//    }
//
//
//    // transposing matrix
//    int b[m][n];
//    cout << "Transposed matrix: " << endl;
//    for(int j = 0; j < m; j++) {
//        for(int i = 0; i < n; i++) {
//            cout <<  a[i][j] << " ";
//            b[j][i] = a[i][j];
//        }
//        cout << endl;
//    }
//
//    cout << "Transposed matrix2: " << endl;
//    for(int j = 0; j < m; j++) {
//        for(int i = 0; i < n; i++) {
//            cout <<  b[j][i] << " ";
//        }
//        cout << endl;
//    }

//    find_min_max();



//    find_negativ();



//    diagonal_sum_sq_matrix();



    show_diagonals();

    return 0;
}
/*
1 2 3 4
5 6 7 8
9 0 1 2
5 8 3 4
*/
