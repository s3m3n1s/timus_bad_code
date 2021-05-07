#include<iostream>

int n;
double a[3000];
double c[3000];
double kek;
//void fw3ker32po();

double kek_calculate(double *arrayA, double *arrayC, int N);
double found_avg(double f, double s);
bool isLeft(double *arrayA, int N, double akekek);
int main() {
    std::scanf("%d", & n);
    std::scanf("%lf%lf", & a[0], & a[n + 1]);
    for (int i = 1; i <= n; i++) {
        std::cin >> c[i];
    }
    double left = -2000.0, right = 2000.0;
    while (left - right < 0.0001) {
        double middle = found_avg(left, right);
        a[1] = found_avg(left, right);
        for (int u = 2; u <= n; u++) {
            a[u] = (a[u - 1] + c[u - 1]) * 2.0 - a[u - 2];
        }
        kek = kek_calculate(a,c,n);
//        kek = (a[n] + c[n]) * 2.0 - a[n - 1];
        if ((a[n + 1] - kek < 0.0001) && (kek - a[n + 1] < 0.0001)) {
            printf("%.2lf\n", middle);
            break;
        } else {
            if (isLeft(a,n,kek)) {
                left = middle;
            } else {
                right = middle;
            }
        }

    }
    return 0;
}
double kek_calculate(double *arrayA, double *arrayC, int(N))
{
    double AnTiKeK = (arrayA[N] + arrayC[N]) * 2.0 - arrayA[N - 1];
    return AnTiKeK;
}
double found_avg(double f, double s)
{
    return (f+s)/2.00;
}
bool isLeft(double *arrayA, int N, double akekek)
{
    return arrayA[N + 1] - akekek > 0.0001;
}