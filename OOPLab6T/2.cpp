#include <iostream>
#include <cmath>

// ����������� ������� ����
class Equation {
public:
    // ³�������� ������� ��� ����������� ������ �������
    virtual void findRoots() const = 0;
};

// �������� ���� ��� ������� ������� (ax + b = 0)
class LinearEquation : public Equation {
private:
    double a, b;
public:
    // �����������
    LinearEquation(double _a, double _b) : a(_a), b(_b) {}

    // ��������� ������ ��� ����������� ������ �������
    void findRoots() const override {
        if (a == 0) {
            std::cout << "No solution: it's not a linear equation" << std::endl;
        }
        else {
            std::cout << "Root of the equation: " << -b / a << std::endl;
        }
    }
};

// �������� ���� ��� ����������� ������� (ax^2 + bx + c = 0)
class QuadraticEquation : public Equation {
private:
    double a, b, c;
public:
    // �����������
    QuadraticEquation(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}

    // ��������� ������ ��� ����������� ������ �������
    void findRoots() const override {
        double discriminant = b * b - 4 * a * c;
        if (discriminant < 0) {
            std::cout << "No real roots: discriminant < 0" << std::endl;
        }
        else if (discriminant == 0) {
            std::cout << "Root of the equation: " << -b / (2 * a) << std::endl;
        }
        else {
            double root1 = (-b + sqrt(discriminant)) / (2 * a);
            double root2 = (-b - sqrt(discriminant)) / (2 * a);
            std::cout << "Roots of the equation: " << root1 << " and " << root2 << std::endl;
        }
    }
};

// �������� ���� ��� ������������ ������� (ax^4 + bx^2 + c = 0)
class BiquadraticEquation : public Equation {
private:
    double a, b, c;
public:
    // �����������
    BiquadraticEquation(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}

    // ��������� ������ ��� ����������� ������ �������
    void findRoots() const override {
        // ������� biquadratic ������� �� �����������, �������� x^2 �� y:
        // ay^2 + by + c = 0
        QuadraticEquation quadraticEquation(a, b, c);
        quadraticEquation.findRoots();
    }
};

int main() {
    // ��������� ��'���� ����� ����� ������
    LinearEquation linearEquation(2, -4);
    QuadraticEquation quadraticEquation(1, -3, 2);
    BiquadraticEquation biquadraticEquation(1, -5, 6);

    // ��������� ����� ��� ����������� ������ ������� �������
    std::cout << "Linear equation: ";
    linearEquation.findRoots();

    std::cout << "Quadratic equation: ";
    quadraticEquation.findRoots();

    std::cout << "Biquadratic equation: ";
    biquadraticEquation.findRoots();

    return 0;
}
