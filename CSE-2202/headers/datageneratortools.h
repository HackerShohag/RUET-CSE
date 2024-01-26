#ifndef dataGeneratorTools
#define dataGeneratorTools

#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x, y;
};

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

void generatePointsToFile(int numPoints, string filename)
{
    ofstream outputFile(filename);
    if (!outputFile.is_open())
    {
        cout << "Unable to open file." << endl;
        return;
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1, 1000);

    for (int i = 0; i < numPoints; i++)
    {
        Point p;
        p.x = distrib(gen);
        p.y = distrib(gen);
        outputFile << p.x << " " << p.y << endl;
    }

    outputFile.close();
    cout << "Generated " << numPoints << " points and saved them to input.txt" << endl;
}
#endif