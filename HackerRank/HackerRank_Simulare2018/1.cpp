#include <iostream>
using namespace std;

struct Matrix {
    int **a;
    int n;
    int m;

    Matrix() {
        n = m = 0;
        a = nullptr;
    }

    Matrix(int **mat, int n, int m) {
        this->n = n;
        this->m = m;

        a = new int*[n];
        for (int i = 0; i < n; ++i) {
            a[i] = new int[m];
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                a[i][j] = mat[i][j];
            }
        }
    }

    Matrix(const Matrix &other) {
        n = other.n;
        m = other.m;

        a = new int*[n];
        for (int i = 0; i < n; ++i) {
            a[i] = new int[m];
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                a[i][j] = other.a[i][j];
            }
        }
    }

    void operator=(const Matrix &other) {
        if (a) {
            for (int i = 0; i < n; ++i) {
                delete[] a[i];
            }
            delete[] a;
        }

        n = other.n;
        m = other.m;

        a = new int*[n];
        for (int i = 0; i < n; ++i) {
            a[i] = new int[m];
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                a[i][j] = other.a[i][j];
            }
        }
    }

    ~Matrix() {
        if (a) {
            for (int i = 0; i < n; ++i) {
                delete[] a[i];
            }
            delete[] a;
        }
    }

    Matrix operator+(const Matrix &other) {
      //TODO: supraincarcati opera
      Matrix nou(this->a, this->n, this->m);
      for (int i = 0; i < n; i++) {
        for (int j = 0;  j < m; j++) {
          nou.a[i][j] = a[i][j] + other.a[i][j];
        }
      }
      return nou;
    }
};

int main()
{
    int n, m;
    int **mat;

    cin >> n >> m;

    mat = new int*[n];
    for (int i = 0; i < n; ++i) {
        mat[i] = new int[m];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> mat[i][j];
        }
    }

    Matrix first_matrix(mat, n, m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> mat[i][j];
        }
    }

    Matrix second_matrix(mat, n, m);
    Matrix sum_matrix;
    sum_matrix = first_matrix + second_matrix;

    for (int i = 0; i < sum_matrix.n; ++i) {
        for (int j = 0; j < sum_matrix.m; ++j) {
            cout << sum_matrix.a[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
