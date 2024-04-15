#include <iostream>

using namespace std;

// Klasa bazowa Shape
class Shape {
public:
    [[nodiscard]] virtual float area() const = 0; // czysto wirtualna, wymaga nadpisania w klasach
};

// Klasa pochodna Circle
class Circle : public Shape {
private:
    float radius;
public:
    explicit Circle(float r) : radius(r) {}

    //Implementacja metody area() dla Circle
    [[nodiscard]] float area() const override {
        return 3.14f * radius * radius;
    }
};

// Klasa pochodna Rectangle
class Rectangle : public Shape {
private:
    float width;
    float height;
public:
    Rectangle(float w, float h) : width(w), height(h) {}

    // Implementacja metody area() dla Rectangle
    [[nodiscard]] float area() const override {
        return width * height;
    }
};

int main() {
    // Tworzenie instancji klas
    Circle circle(5);
    Rectangle rectangle(4,6);

    // Tablica wskaŸników na obiekty Shape
    Shape *shapes[] = { &circle, &rectangle };

    // Liczenie pól
    for(const auto &shape : shapes) {
        cout << "\n\n\nArea: " << shape->area() << endl;
    }

    return 0;
}