#include "my_class.hpp"
using namespace std;

    // void Figure::Get_val() = 0;
    // Figure::~Figure() {};



    void Circle::Set_val(int x, int y, double radius) 
    {
        this->x = x;
        this->y = y;
        this->r = radius;
    }

    Circle::Circle()
    {
        //cout <<"Конструктор по умолчанию Circle"<< endl;
        Set_val(rand() % 10, rand() % 10, rand() % 10);
        //cout << "x = " << this->x << "\t" << "y = " << this->y << "\t" << "radius = " << this->r << endl;
    } 

    Circle::Circle(int x, int y, double radius) 
    {
        //cout <<"Конструктор с параметрами Circle"<< endl;
        Set_val(x, y, radius);
        //cout << "x = " << this->x << "\t" << "y = " << this->y << "\t" << "radius = " << this->r << endl;
    }

    void Circle::Get_val() 
    {
         cout << "x = " << x << "\t" << "y = " << y << "\t" << "radius: " << r << endl;
    }



    void Ellipse::Set_val(float rx, float ry)
    {
        this->rx = rx;
        this->ry = ry;
    }

    Ellipse::Ellipse()
    {
        //cout <<"Конструктор по умолчанию Ellipse"<< endl;
        Set_val(rand() % 10, rand() % 10);
        //cout << "x = " << this->x << "\t" << "y = " << this->y << "\t" << "radius = " << this->r << "\t" << "rx = " << this->rx << "\t" << "ry = " << this->ry << endl;
    } 
    
    Ellipse::Ellipse(int x, int y, float rx, float ry) : Circle(x, y, rx)
    {
        //cout <<"Конструктор с параметрами Ellipse"<< endl;
        Set_val(rx, ry); 
        //cout << "x = " << this->x << "\t" << "y = " << this->y << "\t" << "radius = " << this->r << "\t" << "rx = " << this->rx << "\t" << "ry = " << this->ry << endl;
    }

    void Ellipse::Get_val() 
    {
       cout << "x = " << x << "\t" << "y = " << y << "\t" << "rx: " << rx << "\t" << "ry: " << ry << endl;
    }




    float Line::GetLength(int x1, int y1, int x2, int y2) {
        float len = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        return len;
    }
    
    void Line::Set_val(int x1, int y1, int x2, int y2) 
    {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
        this->line_len = GetLength(x1, y1, x2, y2);
    }

    Line::Line() 
    {
        //cout <<"Конструктор по умолчанию Line"<< endl;
        Set_val(rand() % 10, rand() % 10, rand() % 10, rand() % 10); 
        //cout << "x1 = " << this->x1 << "\t" << "y1 = " << this->y1 << "\t" << "x2 = " << this->x2 << "\t" << "y2 = " << this->y2 << endl;
    }
    Line::Line(int x1, int y1, int x2, int y2) 
    {
        //cout <<"Конструктор с параметрами Line"<< endl;
        Set_val(x1, y1, x2, y2);
        //cout << "x1 = " << this->x1 << "\t" << "y1 = " << this->y1 << "\t" << "x2 = " << this->x2 << "\t" << "y2 = " << this->y2 << "\t" << "Length: " << this->line_len << endl;
    }
    
    void Line::Get_val() 
    {
        cout << "x1 = " << x1 << "\t" << "y1 = " << y1 << endl << "x2 = " << x2 << "\t" << "y2 = " << y2 << endl << "Длина линии: " << line_len << endl;
    }



    float Square::GetSquare(float first_side, float second_side) {
        return first_side * second_side;
    }

    float Square::GetPerimetr(float first_side, float second_side) {
        return (first_side + second_side) * 2;
    }

    void Square::Set_val() 
    {
        //this->line_len = GetLength(x1, y1, x2, y2);
        this->side_len = GetLength(x1, y1, x2, y2);
        S = GetSquare(side_len, side_len);
        P = GetPerimetr(side_len, side_len);
    }

    Square::Square()
    {
        //cout <<"Конструктор по умолчанию Square"<< endl;
        Set_val();
        //cout << "x1 = " << this->x1 << "\t" << "y1 = " << this->y1 << "\t" << "x2 = " << this->x2 << "\t" << "y2 = " << this->y2 << endl;
    }
    Square::Square(int x1, int y1, int x2, int y2) : Line(x1, y1, x2, y2)
    {
        Set_val();
    };
    void Square::Get_val() 
    {
        cout << "x1 = " << x1 << "\t" << "y1 = " << y1 << endl << "x2 = " << x2 << "\t" << "y2 = " << y2 << endl << "Длина линии: " << side_len << endl << "Периметр квадрата: "<< P << endl << "Площадь квадрата: " << S << endl;
    }



    void Rectangle::Set_val(int x3, int y3, int x4, int y4) 
    {
        this->x3 = this->x1;
        this->y3 = this->y2;
        this->x4 = this->x2;
        this->y4 = this->y1;
        float first_side = abs(x1 - x2);
        float second_side = abs(y1 - y2);
        S = GetSquare(first_side, second_side);
        P = GetPerimetr(first_side, second_side);
    }

    Rectangle::Rectangle()
    {
        //cout <<"Конструктор по умолчанию Rectangle"<< endl;
        Set_val(rand() % 10, rand() % 10, rand() % 10, rand() % 10);
        createdCount += 1;
        existingCount += 1;
    }
    Rectangle::Rectangle(int x1, int y1, int x2, int y2) : Square(x1, y1, x2, y2)
    {
        //cout <<"Конструктор с параметрами Rectangle"<< endl;
        Set_val(x3, y3, x4, y4);
        createdCount += 1;
        existingCount += 1;
    }

    void Rectangle::Get_val() 
    {
        cout << "x1 = " << x1 << "\t" << "y1 = " << y1 << endl << "x2 = " << x2 << "\t" << "y2 = " << y2 << endl <<"x3 = "<< x3 << "\t"<<"y3 = "<< y3 << endl <<"x4 = "<< x4 << "\t"<<"y4 = "<< y4 << endl  << "Периметр прямоугольника: "<< P << endl << "Площадь прямоугольника: " << S << endl;
    }


    int Rectangle::GetCreatedCount() {
        return createdCount;
    };

    int Rectangle::GetExistingCount() {
        return existingCount;
    };

    Rectangle::~Rectangle() {
        existingCount -= 1;
    }


int Rectangle::createdCount = 0;
int Rectangle::existingCount = 0;
