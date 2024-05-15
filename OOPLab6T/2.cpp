#include <iostream>
#include <cmath>

// Абстрактний базовий клас
class Equation {
public:
    // Віртуальна функція для знаходження коренів рівняння
    virtual void findRoots() const = 0;
};

// Похідний клас для лінійного рівняння (ax + b = 0)
class LinearEquation : public Equation {
private:
    double a, b;
public:
    // Конструктор
    LinearEquation(double _a, double _b) : a(_a), b(_b) {}

    // Реалізація методу для знаходження кореня рівняння
    void findRoots() const override {
        if (a == 0) {
            std::cout << "No solution: it's not a linear equation" << std::endl;
        }
        else {
            std::cout << "Root of the equation: " << -b / a << std::endl;
        }
    }
};

// Похідний клас для квадратного рівняння (ax^2 + bx + c = 0)
class QuadraticEquation : public Equation {
private:
    double a, b, c;
public:
    // Конструктор
    QuadraticEquation(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}

    // Реалізація методу для знаходження коренів рівняння
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

// Похідний клас для біквадратного рівняння (ax^4 + bx^2 + c = 0)
class BiquadraticEquation : public Equation {
private:
    double a, b, c;
public:
    // Конструктор
    BiquadraticEquation(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}

    // Реалізація методу для знаходження коренів рівняння
    void findRoots() const override {
        // Зведемо biquadratic рівняння до квадратного, замінивши x^2 на y:
        // ay^2 + by + c = 0
        QuadraticEquation quadraticEquation(a, b, c);
        quadraticEquation.findRoots();
    }
};

int main() {
    // Створюємо об'єкти різних класів рівнянь
    LinearEquation linearEquation(2, -4);
    QuadraticEquation quadraticEquation(1, -3, 2);
    BiquadraticEquation biquadraticEquation(1, -5, 6);

    // Викликаємо метод для знаходження коренів кожного рівняння
    std::cout << "Linear equation: ";
    linearEquation.findRoots();

    std::cout << "Quadratic equation: ";
    quadraticEquation.findRoots();

    std::cout << "Biquadratic equation: ";
    biquadraticEquation.findRoots();

    return 0;
}
