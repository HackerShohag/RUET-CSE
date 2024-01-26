#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include "headers/datageneratortools.h"
using namespace std;

int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0)
        return 0;
    return (val > 0) ? 1 : 2;
}

void convexHullBruteForce(vector<Point> &points)
{
    int n = points.size();
    if (n < 3)
        return;

    vector<Point> hull;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            bool isOnHull = true;
            for (int k = 0; k < n; k++)
            {
                if (k == i || k == j)
                    continue;
                if (orientation(points[i], points[j], points[k]) != 2)
                {
                    isOnHull = false;
                    break;
                }
            }
            if (isOnHull)
            {
                hull.push_back(points[i]);
                hull.push_back(points[j]);
            }
        }
    }
    cout << "Convex Hull Points: ";
    for (auto p : hull)
        cout << "(" << p.x << ", " << p.y << ") ";
    cout << endl;
}

int findSide(Point a, Point b, Point p)
{
    int val = (p.y - a.y) * (b.x - a.x) - (b.y - a.y) * (p.x - a.x);
    if (val > 0)
        return 1;
    if (val < 0)
        return -1;
    return 0;
}

void quickHull(vector<Point> &points, Point a, Point b, int side, vector<Point> &hull)
{
    int ind = -1;
    int maxDist = 0;
    for (int i = 0; i < points.size(); i++)
    {
        int temp = findSide(a, b, points[i]);
        if (temp == side)
        {
            int distance = abs((points[i].y - a.y) * (b.x - a.x) - (b.y - a.y) * (points[i].x - a.x));
            if (distance > maxDist)
            {
                ind = i;
                maxDist = distance;
            }
        }
    }
    if (ind == -1)
    {
        hull.push_back(a);
        hull.push_back(b);
        return;
    }
    quickHull(points, points[ind], a, -findSide(points[ind], a, b), hull);
    quickHull(points, points[ind], b, -findSide(points[ind], b, a), hull);
}

void convexHullQuick(vector<Point> &points)
{
    int n = points.size();
    if (n < 3)
    {
        cout << "Convex Hull not possible with less than 3 points." << endl;
        return;
    }

    vector<Point> hull;
    int minX = 0, maxX = 0;
    for (int i = 1; i < n; i++)
    {
        if (points[i].x < points[minX].x)
            minX = i;
        if (points[i].x > points[maxX].x)
            maxX = i;
    }

    quickHull(points, points[minX], points[maxX], 1, hull);
    quickHull(points, points[minX], points[maxX], -1, hull);

    cout << "Convex Hull Points: ";
    for (auto p : hull)
        cout << "(" << p.x << ", " << p.y << ") ";
    cout << endl;
}

int main()
{

    vector<int> inputSizes = {1000, 5000, 10000, 12000, 15000};
    for (int numbers : inputSizes)
    {
        FILE *file;
        int array[numbers];
        string filename = "lab05_assets/";
        filename.append(to_string(numbers));
        filename.append(".txt");

        if (file = fopen(filename.c_str(), "r"))
        {
            fclose(file);
            printf("Files exist. Skipping data generate.\n");
        }
        else
        {
            generatePointsToFile(numbers, filename);
            printf("Files deosn't exist. Generating data.\n");
        }
        ifstream inputFile(filename);
        vector<Point> points;
        Point pt;
        while (inputFile >> pt.x >> pt.y)
            points.push_back(pt);
        inputFile.close();
        auto start1 = chrono::high_resolution_clock::now();
        convexHullBruteForce(points);
        auto stop1 = chrono::high_resolution_clock::now();
        auto duration1 = chrono::duration_cast<chrono::milliseconds>(stop1 - start1);
        cout << "\nBy Iterative Method for " << numbers << " points"
             << "took " << duration1.count() << " milliseconds" << endl;
        cout << "------------------------------------------\n\n"
             << endl;

        auto start2 = chrono::high_resolution_clock::now();
        convexHullQuick(points);
        auto stop2 = chrono::high_resolution_clock::now();
        auto duration2 = chrono::duration_cast<chrono::milliseconds>(stop2 - start2);
        cout << "\nBy Quick Hull Method for " << numbers << " points"
             << "took " << duration2.count() << " milliseconds" << endl;
        cout << "------------------------------------------\n\n"
             << endl;
    }
}