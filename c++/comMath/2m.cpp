#include <iostream>
#include <vector>
#include <iomanip>
#include "2mModul.h"
using namespace std;

int main()
{

    cout << fixed << setprecision(3);
    
    const int n = 5;

    vector<vector<double>> A(n, vector<double>(n+1, 0.0));
    vector<vector<double>> L(n, vector<double>(n, 0.0));
    vector<vector<double>> U(n, vector<double>(n, 0.0));
    vector<double> Y(n, 0.0);
    vector<double> X(n, 0.0);

    
    // Первичное заполнение L и U
    fillMatrix(A);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            L[i][j] = 0.0;
            U[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }


    // Слой 0
    for (int i = 0; i < n; ++i)
        L[i][0] = A[i][0];

    for (int j = 1; j < n; ++j)
        U[0][j] = A[0][j] / L[0][0];

    // Пересчёт остальных слоёв
    for (int k = 1; k < n; ++k)
    {
        int p = k;
        for (int i = k + 1; i < n; i++)
            if (abs(A[i][k])> abs(A[p][k]))
            p = i;

            if (p !=k){
                swap(A[k], A[p]);

                for (int j = 0; j < k; j++)
                    swap(L[k][j], L[p][j]);
                
                for (int i = 0; i < k; i++)
                    swap(U[k][i],U[p][i]);
            }
        
        // Вычисляем L(i, k)
        for (int i = k; i < n; ++i)
        {
            L[i][k] = A[i][k];
            for (int m = 0; m < k; ++m)
                L[i][k] -= L[i][m] * U[m][k];
        }


        if (k < n - 1)
        {
            for (int j = k + 1; j < n; ++j)
            {
                U[k][j] = A[k][j];
                for (int m = 0; m < k; ++m)
                    U[k][j] -= L[k][m] * U[m][j];
                U[k][j] /= L[k][k];
            }
        }
    }

    // ===== Вывод матриц L и U =====
    cout << "\nМатрица A:\n";
    for (unsigned int i = 0; i < A.size(); i++)
    {
        for (unsigned int j = 0; j <= A.size(); j++)
            cout << setw(10) << A[i][j] << " ";
        cout << "\n";
    }

    cout << "\nМатрица L:\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << setw(10) << L[i][j] << " ";
        cout << "\n";
    }

    cout << "\nМатрица U:\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << setw(10) << U[i][j] << " ";
        cout << "\n";
    }

    // ===== Этап 2: вычисляем Y =====
    Y[0] = A[0][n] / L[0][0];
    for (int k = 1; k < n; ++k)
    {
        Y[k] = A[k][n];
        for (int m = 0; m < k; ++m)
            Y[k] -= L[k][m] * Y[m];
        Y[k] /= L[k][k];
    }

    cout << "\nВектор Y:\n";
    for (int k = 0; k < n; ++k)
        cout << setw(10) << Y[k] << " ";
    cout << "\n";

    // ===== Этап 3: вычисляем X =====
    X[n - 1] = Y[n - 1];
    for (int k = n - 2; k >= 0; --k)
    {
        X[k] = Y[k];
        for (int m = k + 1; m < n; ++m)
            X[k] -= U[k][m] * X[m];
    }

    cout << "\nВектор X (решение):\n";
    for (int k = 0; k < n; ++k)
        cout << setw(10) << X[k] << " ";
    cout << "\n";

    return 0;
}