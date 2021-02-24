#include <iostream>
using namespace std;

string Big(char& num, int size)
{
    string out;
    char* point;
    for (int i = size - 1; i >= 0; i--)
    {
        point = &num + i;
        for (int j = 7; j >= 0; j--)
        {
            out += ((*point >> j) & 1) ? '1' : '0';
        }
    }
    return out;
}
string Little(char& num, int size)
{
    string out;
    char* point;
    for (int i = 0; i < size; i++)
    {
        point = &num + i;
        for (int j = 7; j >=0; j--)
        {
            out += ((*point >> j) & 1) ? '1' : '0';
        }
    }
    return out;
}

int main()
{
    cout << "Input your number: ";
    double numDouble;
    cin >> numDouble;

    int numInt = (int)numDouble;
    float numFloat = (float)numDouble;
    
    cout << "Int:" << endl;
    cout << "BigIndian: " + Big((char&)numInt, sizeof(int)) << endl;
    cout << "LittleIndian: " + Little((char&)numInt, sizeof(int)) << endl;

    cout << "Float:" << endl;
    cout << "BigIndian: " + Big((char&)numFloat, sizeof(float)) << endl;
    cout << "LittleIndian: " + Little((char&)numFloat, sizeof(float)) << endl;

    cout << "Double:" << endl;
    cout << "BigIndian: " + Big((char&)numDouble, sizeof(double)) << endl;
    cout << "LittleIndian: " + Little((char&)numDouble, sizeof(double)) << endl;

    
}