#include <iostream>
#include <cmath>

using namespace std;

int rand_() {
    return rand() % 10;
}

class Figure {
public:
    virtual void Get_val() = 0;
    virtual ~Figure() {};
};

class Circle : public Figure {

protected:
    float r = 0;
    int x = 0, y = 0;
public:
    Circle()
    {
        cout <<"Конструктор по умолчанию Circle"<< endl;
        this->x = rand() % 10;
        this->y = rand() % 10;
        this->r = rand() % 10;
        cout << "x = " << this->x << "\t" << "y = " << this->y << "\t" << "radius = " << this->r << endl;
    } 

    Circle(int x, int y, float r) : x(x), y(y), r(r) {};
    Circle(int x, int y, double radius) 
    {
        cout <<"Конструктор с параметрами Circle"<< endl;
        this->x = x;
        this->y = y;
        this->r = radius;
        cout << "x = " << this->x << "\t" << "y = " << this->y << "\t" << "radius = " << this->r << endl;
    }

    void Get_val() override
    {
         cout << "x = " << x << "\t" << "y = " << y << "\t" << "radius: " << r << endl;
    }
};

class Ellipse : public Circle {
private:
    float rx = 0, ry = 0;
public:
    Ellipse()
    {
        cout <<"Конструктор по умолчанию Ellipse"<< endl;
        this->rx = rand() % 10;
        this->ry = rand() % 10;
        cout << "x = " << this->x << "\t" << "y = " << this->y << "\t" << "radius = " << this->r << "\t" << "rx = " << this->rx << "\t" << "ry = " << this->ry << endl;
    } 
    
    Ellipse(int x, int y, float rx, float ry) : Circle(x, y, rx)
    {
        cout <<"Конструктор с параметрами Ellipse"<< endl;
        this->rx = rx;
        this->ry = ry;
        cout << "x = " << this->x << "\t" << "y = " << this->y << "\t" << "radius = " << this->r << "\t" << "rx = " << this->rx << "\t" << "ry = " << this->ry << endl;
    }

    void Get_val() override
    {
       cout << "x = " << x << "\t" << "y = " << y << "\t" << "rx: " << rx << "\t" << "ry: " << ry << endl;
    }
};

class Line : public Figure {

protected:
    int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    float line_len = 0;
    float GetLength(int x1, int y1, int x2, int y2) {
        float len = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        return len;
    }

public:
    Line() 
    {
        cout <<"Конструктор по умолчанию Line"<< endl;
        this->x1 = rand() % 10;
        this->y1 = rand() % 10;
        this->x2 = rand() % 10;
        this->y2 = rand() % 10;
        cout << "x1 = " << this->x1 << "\t" << "y1 = " << this->y1 << "\t" << "x2 = " << this->x2 << "\t" << "y2 = " << this->y2 << endl;
    }
    Line(int x1, int y1, int x2, int y2) 
    {
        cout <<"Конструктор с параметрами Line"<< endl;
         this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
        this->line_len = GetLength(x1, y1, x2, y2);
        cout << "x1 = " << this->x1 << "\t" << "y1 = " << this->y1 << "\t" << "x2 = " << this->x2 << "\t" << "y2 = " << this->y2 << "\t" << "Length: " << this->line_len << endl;
    }
    
    void Get_val() override
    {
        cout << "x1 = " << x1 << "\t" << "y1 = " << y1 << endl << "x2 = " << x2 << "\t" << "y2 = " << y2 << endl << "Длина линии: " << line_len << endl;
    }
    

};

class Square : public Line {
protected:
    float S = 0, P = 0;

    float GetSquare(float first_side, float second_side) {
        return first_side * second_side;
    }

    float GetPerimetr(float first_side, float second_side) {
        return (first_side + second_side) * 2;
    }

public:
    Square()
    {
        cout <<"Конструктор по умолчанию Square"<< endl;
        cout << "x1 = " << this->x1 << "\t" << "y1 = " << this->y1 << "\t" << "x2 = " << this->x2 << "\t" << "y2 = " << this->y2 << endl;
    }
    //Square() : Square(rand_(), rand_(), rand_(), rand_()) {};
    Square(int x1, int y1, int x2, int y2) : Line(x1, y1, x2, y2)
    {
        this->x1 = x1;
        this->x2 = x2;
        this->y1 = y1;
        this->y2 = y2;

    };
    void Get_val() override
    {
        float side_len = GetLength(x1, y1, x2, y2);
        S = GetSquare(side_len, side_len);
        P = GetPerimetr(side_len, side_len);
        cout << "x1 = " << x1 << "\t" << "y1 = " << y1 << endl << "x2 = " << x2 << "\t" << "y2 = " << y2 << endl << "Длина линии: " << side_len << endl << "Периметр квадрата: "<< P << endl << "Площадь квадрата: " << S << endl;
    }

};

class Rectangle : public Square {
protected:
    int x3;
    int y3;
    int x4;
    int y4;
private:
    static int createdCount;
    static int existingCount;

public:
    Rectangle()
    {
        cout <<"Конструктор по умолчанию Rectangle"<< endl;
        this->x3 = this->x1;
        this->y3 = this->y2;
        this->x4 = this->x2;
        this->y4 = this->y1;
    }
    Rectangle(int x1, int y1, int x2, int y2) : Square(x1, y1, x2, y2)
    {
        cout <<"Конструктор с параметрами Rectangle"<< endl;
        this->x3 = this->x1;
        this->y3 = this->y2;
        this->x4 = this->x2;
        this->y4 = this->y1;
        createdCount += 1;
        existingCount += 1;
    }

    void Get_val() override
    {
        float first_side = abs(x1 - x2), second_side = abs(y1 - y2);
        S = GetSquare(first_side, second_side);
        P = GetPerimetr(first_side, second_side);
        cout << "x1 = " << x1 << "\t" << "y1 = " << y1 << endl << "x2 = " << x2 << "\t" << "y2 = " << y2 << endl <<"x3 = "<< x3 << "\t"<<"y3 = "<< y3 << endl <<"x4 = "<< x4 << "\t"<<"y4 = "<< y4 << endl  << "Периметр прямоугольника: "<< P << endl << "Площадь прямоугольника: " << S << endl;
    }

    static int GetCreatedCount() {
        return createdCount;
    };

    static int GetExistingCount() {
        return existingCount;
    };

    ~Rectangle() {
        existingCount -= 1;
    }
};

int Rectangle::createdCount = 0;
int Rectangle::existingCount = 0;

int main() 
{
    srand(time(NULL));
    cout << endl;
    Line l(1, 2, 13, 4);
    Square s;
    Rectangle r(1, 2, 13, 4);
    Circle c;
    Ellipse e(2, 13, 4, 7);

    cout <<"Line"<< endl;
    l.Get_val();
    cout << endl;

    cout <<"Square"<< endl;
    s.Get_val();
    cout << endl;

    cout <<"Rectangle"<< endl;
    r.Get_val();
    cout << endl;

    cout <<"Circle"<< endl;
    c.Get_val();
    cout << endl;

    cout <<"Ellipse"<< endl;
    e.Get_val();
    cout << endl;


    cout << ">\n |Created rect: " << Rectangle::GetCreatedCount() << endl;
    cout << " |Exist rect: " << Rectangle::GetExistingCount() << endl;

    Rectangle* pr;

    cout << ">\n |Created rect: " << Rectangle::GetCreatedCount() << endl;
    cout << " |Exist rect: " << Rectangle::GetExistingCount() << endl;

    pr = new Rectangle;

    cout << ">\n |Created rect: " << Rectangle::GetCreatedCount() << endl;
    cout << " |Exist rect: " << Rectangle::GetExistingCount() << endl;

    Figure* pf[4];
    pf[0] = new Square;
    pf[1] = new Rectangle;
    pf[2] = new Circle;
    pf[3] = new Ellipse;

    for (int i = 0; i < 4; i++) {
        pf[i]->Get_val();
    }

    cout << ">\n |Created rect: " << Rectangle::GetCreatedCount() << endl;
    cout << " |Exist rect: " << Rectangle::GetExistingCount() << endl;
    for (int i = 0; i < 4; i++) {
        delete pf[i];
    }

    cout << ">\n |Created rect: " << Rectangle::GetCreatedCount() << endl;
    cout << " |Exist rect: " << Rectangle::GetExistingCount() << endl;

    return 0;
}