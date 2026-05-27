class Solution {
    double pow(double x, long long n) {
        if (n == 0) {
            return 1;
        }
        double res = pow(x, n / 2);
        res *= res;
        if (n % 2) {
            res *= x;
        }
        return res;
    }

public:
    double myPow(double x, int n) {
        if (n < 0) {
            return pow(1 / x, -(long long) n);
        }
        return pow(x, n);
    }
};