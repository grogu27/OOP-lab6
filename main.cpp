#include "my_class.hpp"
using namespace std;


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