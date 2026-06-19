#include <bits/stdc++.h>

double f(double x) {
    return exp(x);
}

double trapezoidal(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = (f(a) + f(b)) / 2.0;
    for (int i = 1; i < n; i++) {
        sum += f(a + i * h);
    }
    return sum * h;
}

int main() {
    double a = 0.0, b = 4.0;
    int n_max = 5; // level ekstrapolasi (pakai 1,2,4,...,32 pias)
    double R[10][10];

    for (int i = 0; i <= n_max; i++) {
        int n_pias = 1 << i; // 2^i
        R[i][0] = trapezoidal(a, b, n_pias);

        for (int j = 1; j <= i; j++) {
            double p = pow(4.0, j);
            R[i][j] = R[i][j-1] + (R[i][j-1] - R[i-1][j-1]) / (p - 1.0);
        }
    }

    printf("Tabel Romberg:\n");
    for (int i = 0; i <= n_max; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%.6f\t", R[i][j]);
        }
        printf("\n");
    }

    printf("\nHasil integral terbaik: %.6f\n", R[n_max][n_max]);
    return 0;
}
