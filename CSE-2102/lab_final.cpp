#include <iostream>

using namespace std;

bool implies(bool p, bool q)
{
    if (p)
        return q;
    return true;
}

char deform(bool x)
{
    if (x)
        return 'T';
    return 'F';
}

int main()
{
    cout << "P\tQ\tR\tS\tP=>(Q=>(R<=>S))\n";
    cout << "-----------------------------------------------\n";
    for (int p = 0; p < 2; p++)
    {
        for (int q = 0; q < 2; q++)
        {
            for (int r = 0; r < 2; r++)
            {
                for (int s = 0; s < 2; s++)
                {
                    bool x = false;
                    if (implies(r, s) && implies(s, r))
                        x = true;
                    cout << deform(p) << "\t" << deform(q) << "\t" << deform(r) << "\t" << deform(s) << "\t\t" << deform(x) << "\n";
                }
            }
        }
    }
}