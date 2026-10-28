#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
    const int n = 5;

    vector<double> c(n, 0.0);
    vector<double> l(n, 0.0);
    vector<double> r(n, 0.0);
    vector<double> p(n, 0.0);
    vector<double> q(n, 0.0);
    vector<double> x(n, 0.0);

    // === Входные данные (аналог ячеек Excel) ===
    // Матрица A (трёхдиагональная) и вектор правой части f
    // Задайте свои значения:
    double Matrix[n][n] = {
        {9, 9, 0, 0, 0},
        {7, 3, 6, 0, 0},
        {0, 3, 4, 5, 0},
        {0, 0, 2, 6, 5},
        {0, 0, 0, 6, 4}
    };
    double f[n] = {18, 16, 12, 13, 10};

    // Заполнение векторов (аналог строк 12-29)
    for (int k = 0; k < n; ++k) {
        if (k >= 1)      l[k] = Matrix[k + 1][k];
        c[k] = Matrix[k+1][k+1];
        if (k <= n - 2)  r[k] = Matrix[k +1][k + 2];
        p[k] = 0.0;
        q[k] = 0.0;
        x[k] = 0.0;
    }


    p[0] = f[0] / c[0];
    q[0] = r[0] / c[0];
    for (int k = 1; k < n; ++k){
        p[k] = (f[k] - l[k] * p[k - 1]) / (c[k] - l[k] * q[k - 1]);
        q[k] = r[k] / (c[k] - l[k] * q[k - 1]);
    }

    

    // === Обратный ход: вычисление x ===
    x[n - 1] = p[n - 1];
    for (int k = n - 2; k >= 0; --k) {
        x[k] = p[k] - q[k] * x[k + 1];
    }
    
// Вывод исходных данных
    cout << fixed << setprecision(4);
    cout << " k |    l     |    c     |    r     |    f     |    p     |    q     |    x\n";
    for (int k = 0; k < n; ++k) {
        cout << setw(2) << k << " | "<<setw(8) << l[k] << " | "
        <<setw(8) << c[k] << " | "<<setw(8) << r[k] << " | "<<setw(8) << f[k] 
        << " | "<< setw(8) << p[k] << " | "<< setw(8) << q[k] << setw(8) << x[k] << "\n";

    }
    cout << "\n\n";

    return 0;
}