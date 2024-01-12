#include <iostream>

using namespace std;

class clientInfo
{
    string name;
public:
    void getdata(string name)
    {
        this->name=name;
    }
    void displayInfo()
    {
        cout<<name<<endl;
    }
};

int main()
{
    clientInfo c1;
    c1.getdata("ritik");
    c1.displayInfo();
    return 0;
}
