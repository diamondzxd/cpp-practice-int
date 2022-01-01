#include <bits/stdc++.h>
using namespace std;

class Vehicle
{
public:
    virtual void startAC() = 0;
    void toggleLight();
    void drive();

    ~Vehicle()
    {
        cout << "Vehicle Destroyed" << endl;
    }
};

class Audi : public Vehicle
{
public:
    void startAC()
    {
        cout << "Audi's AC Started" << endl;
    }

    ~Audi()
    {
        cout << "Audi Destroyed" << endl;
    }
};

class Toyota : public Vehicle
{
public:
    void startAC()
    {
        cout << "Toyota's AC Started" << endl;
    }
};

int main()
{
    Audi audi;
    audi.startAC();

    Toyota toyota;
    toyota.startAC();

    return 0;
}