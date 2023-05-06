#include <iostream>

using namespace std;

int main()
{
    int i;
    int ax[5] = {10, 20, 60, 40, 30};
    cout << "enter index:";
    cin >> i;
    try
    {
        if (i < 1 || i > 5)
            throw "Out of index error";
        cout << "ax[" << i << "]=" << ax[i - 1] << endl;
    }
    catch (int i)
    {
        cout << i << " is out of range.\n";
    }
    catch (char const *e)
    {
        cerr << e;
    }
    catch (...)
    {
        cout << "Unknown error detected.\n";
    }
}