#ifndef dataGeneratorTools
#define dataGeneratorTools

#include <bits/stdc++.h>
using namespace std;

void generateNumbers(int count, string filename)
{
    ofstream file;
    file.open(filename);

    for (int i = 0; i < count; i++)
    {
        file << rand() % 1000 << " ";
    }
    file.close();
}

void readData(string filename, int array[])
{
    ifstream file;
    file.open(filename);

    int i = 0;
    while (file >> array[i])
    {
        i++;
    }
    file.close();
}
#endif