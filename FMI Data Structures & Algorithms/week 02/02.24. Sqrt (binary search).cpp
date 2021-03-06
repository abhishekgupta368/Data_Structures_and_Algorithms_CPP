// github.com/andy489

/*
Напишете функция, която пресмята корен квадратен от
дадено естествено число с точност eps=0.00001
и времева сложност log(N)
*/

#include <iostream>

using namespace std;

double myfabs(double d) {
    return d > 0 ? d : -d;
}

double sqrt_x(int x) {
    double left(0), right(1000000000), mid, eps(0.00001);

    while (true) {
        mid = (left + right) / 2;
        if (myfabs(mid * mid - x) < eps)
            return mid;
        else if (mid * mid - x > 0)
            right = mid;
        else
            left = mid;
    }
}

int main() {
    int x;
    cin >> x;
    return cout << sqrt_x(x), 0;
}
