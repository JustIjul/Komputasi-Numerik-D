#include <bits/stdc++.h>

using namespace std;

double f(double x) {
    return (1.0 - 0.6 * x) / x;
}

void metode_regula_falsi(double x1, double x2, int max_iter, double tol) {
    cout << string(80, '=') << endl;
    cout << left << setw(6) << "Iter" 
         << setw(12) << "x1 (Bawah)" 
         << setw(12) << "x2 (Atas)" 
         << setw(14) << "x3 (Akar)" 
         << setw(15) << "f(x1)" 
         << setw(15) << "f(x2)" 
         << setw(15) << "f(x3)" << endl;
    cout << string(80, '=') << endl;

    double f1 = f(x1);
    double f2 = f(x2);

    if (f1 * f2 > 0) {
        cout << "Tebakan awal tidak mengurung akar (f(x1) * f(x2) > 0)." << endl;
        return;
    }

    double x3;
    for (int i = 0; i < max_iter; i++) {
        f1 = f(x1);
        f2 = f(x2);
        
        x3 = x2 - (f2 * (x1 - x2)) / (f1 - f2);
        double f3 = f(x3);

        cout << left << setw(6) << i + 1
             << fixed << setprecision(5)
             << setw(12) << x1
             << setw(12) << x2
             << setw(14) << x3
             << setw(15) << f1
             << setw(15) << f2
             << setw(15) << f3 << endl;

        if (abs(f3) < tol) {
            cout << string(80, '=') << endl;
            cout << "Akar ditemukan pada x = " << x3 << " (Mencapai batas toleransi)" << endl;
            return;
        }

        if (f1 * f3 < 0) {
            x2 = x3;
        } else {
            x1 = x3;
        }
    }
    
    cout << string(80, '=') << endl;
    cout << "Akar aproksimasi setelah " << max_iter << " iterasi adalah x = " << x3 << endl;
}

int main() {
    cout << "EKSEKUSI PROGRAM METODE REGULA FALSI" << endl;
    
    double batas_bawah, batas_atas;
    int batas_iterasi = 10;
    double toleransi = 1e-5;
    
    cout << "Masukkan nilai x1 (batas bawah) : ";
    cin >> batas_bawah;
    cout << "Masukkan nilai x2 (batas atas)  : ";
    cin >> batas_atas;

    metode_regula_falsi(batas_bawah, batas_atas, batas_iterasi, toleransi);
    
    return 0;
}
