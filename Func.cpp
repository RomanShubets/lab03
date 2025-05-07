#include "Func.h"
#include <iostream>
#include <cmath>

double fx(double x) {
    return cos(x) - exp(-x * x / 2) + x - 1;
}

double fdx(double x) {
    return -sin(x) + exp(-x * x / 2) * x + 1;
}

Dychotomia_class::Dychotomia_class() {}

Dychotomia_class::~Dychotomia_class() {}

void Dychotomia_class::setlimits(double left, double right) {
    left_limit = left;
    right_limit = right;
}

void Dychotomia_class::setTolerance(double tol) {
    tolerance = tol;
}

double Dychotomia_class::dichotomymethod() {
    double a = left_limit;
    double b = right_limit;
    double x;

    while (fabs(b - a) > tolerance) {
        x = (a + b) / 2;
        if (fx(x) > 0)
            b = x;
        else
            a = x;
    }

    return (a + b) / 2;
}

Newton_class::Newton_class() {}

Newton_class::~Newton_class() {}

void Newton_class::setx0(double x) {
    x0 = x;
}

void Newton_class::setTolerance(double tol) {
    tolerance = tol;
}

double Newton_class::newtonmethod() {
    double x = x0;
    double x_next;

    while (true) {
        double fx_nm = fx(x);
        double dfx_nm = fdx(x);

        x_next = x - fx_nm / dfx_nm;

        if (fabs(x_next - x) < tolerance)
            break;

        x = x_next;
    }

    return x_next;
}
