#include <iostream>
#include <cmath>
using namespace std;

class Figure {
public:
    virtual void Get_val() = 0;
    virtual ~Figure() {};
};

class Circle : public Figure {

protected:
    float r;
    int x, y;

    void Set_val(int x, int y, double radius) ;

public:
    Circle();
 
    Circle(int x, int y, double radius);

    void Get_val() override;
 
};

class Ellipse : public Circle {
protected:
    float rx, ry;

    void Set_val(float rx, float ry);

public:
    Ellipse();

    
    Ellipse(int x, int y, float rx, float ry);


    void Get_val() override;

};

class Line : public Figure {

protected:
    int x1, x2, y1, y2;
    float line_len;

    float GetLength(int x1, int y1, int x2, int y2);

    
    void Set_val(int x1, int y1, int x2, int y2) ;
    

public:
    Line();
    
    Line(int x1, int y1, int x2, int y2);
    
    
    void Get_val() override;
    
};

class Square : public Line {
private:
    float side_len;
protected:
    float S, P;
    float GetSquare(float first_side, float second_side);


    float GetPerimetr(float first_side, float second_side);

    void Set_val();
public:
    Square();
  
    Square(int x1, int y1, int x2, int y2) ;
 
    void Get_val() override;

};

class Rectangle : public Square {
protected:
    int x3;
    int y3;
    int x4;
    int y4;

    void Set_val(int x3, int y3, int x4, int y4) ;

private:
    static int createdCount;
    static int existingCount;

public:
    Rectangle();

    Rectangle(int x1, int y1, int x2, int y2);
  

    void Get_val() override;


    static int GetCreatedCount();

    static int GetExistingCount();


    ~Rectangle();

};
