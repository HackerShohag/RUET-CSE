#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item
{
    double weight;
    double profit;
    double portion;
};

bool compareItems(Item i1, Item i2)
{
    return (i1.profit / i1.weight) > (i2.profit / i2.weight);
}

double knapsackGreedy(int capacity, vector<Item> &Items)
{
    sort(Items.begin(), Items.end(), compareItems);

    double totalProfit = 0;

    for (auto &Item : Items)
    {
        if (capacity > 0 && Item.weight <= capacity)
        {
            totalProfit += Item.profit;
            capacity -= Item.weight;
            Item.portion = 1;
        }
        else if (capacity > 0 && Item.weight > capacity)
        {
            totalProfit += (Item.profit / Item.weight) * capacity;
            Item.portion = capacity / Item.weight;
            capacity = 0;
            break;
        }
    }
    return totalProfit;
}

struct Job
{
    int profit;
    int deadline;
    int jobID;
};

bool compareJobs(Job j1, Job j2)
{
    return j1.profit > j2.profit;
}

int jobSequencingGreedy(vector<Job> &Jobs, int &maxDeadline)
{
    sort(Jobs.begin(), Jobs.end(), compareJobs);

    for (auto Job : Jobs)
        if (Job.deadline > maxDeadline)
            maxDeadline = Job.deadline;

    vector<int> timeSlots(maxDeadline, -1);

    int totalProfit = 0;
    for (auto Job : Jobs)
    {
        for (int i = Job.deadline - 1; i >= 0; i--)
        {
            if (timeSlots[i] == -1)
            {
                timeSlots[i] = Job.jobID;
                totalProfit += Job.profit;
                break;
            }
        }
    }
    return totalProfit;
}

int main()
{
    cout << "1. Knapsack Problem" << endl;
    cout << "2. Job Sequencing Problem" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        ifstream inputFile("lab04_assets/knapsack.txt");

        if (!inputFile.is_open())
        {
            cerr << "Error opening the file." << endl;
            return 1;
        }

        int numItems, knapsackCapacity;
        inputFile >> numItems;
        inputFile >> knapsackCapacity;

        vector<Item> Items(numItems);

        // Read weights
        for (int i = 0; i < numItems; i++)
            inputFile >> Items[i].weight;

        // Read profits
        for (int i = 0; i < numItems; i++)
            inputFile >> Items[i].profit;

        double maxProfit = knapsackGreedy(knapsackCapacity, Items);

        cout << "\nWeight : ";
        for (auto Item : Items)
            cout << Item.weight << "\t";

        cout << "\nProfit : ";
        for (auto Item : Items)
            cout << Item.profit << "\t";

        cout << "\nRatio  : ";
        for (auto Item : Items)
            cout << Item.profit / Item.weight << "\t";

        cout << "\nPortion: ";
        for (auto Item : Items)
            cout << Item.portion << "\t";

        cout << "\nMaximum profit using greedy approach: " << maxProfit << endl;

        inputFile.close();
        return 0;
    }
    case 2:
    {
        ifstream inputFile("lab04_assets/jobsequence.txt");

        if (!inputFile.is_open())
        {
            cerr << "Error opening the file." << endl;
            return 1;
        }

        int numJobs, maxDeadline = 0;
        inputFile >> numJobs;

        vector<Job> Jobs(numJobs);

        // Read profits
        for (int i = 0; i < numJobs; i++)
        {
            inputFile >> Jobs[i].profit;
            Jobs[i].jobID = i + 1;
        }

        // Read deadlines
        for (int i = 0; i < numJobs; i++)
            inputFile >> Jobs[i].deadline;

        int maxProfit = jobSequencingGreedy(Jobs, maxDeadline);

        cout << "\nJob ID : ";
        for (auto Job : Jobs)
            cout << Job.jobID << "\t";

        cout << "\nProfit : ";
        for (auto Job : Jobs)
            cout << Job.profit << "\t";

        cout << "\nDeadline: ";
        for (auto Job : Jobs)
            cout << Job.deadline << "\t";

        cout << "\nChosen Jobs: ";
        for (int i = 0; i < maxDeadline; i++)
            cout << Jobs[i].jobID << "\t";

        cout << "\nMaximum profit using greedy approach: " << maxProfit << endl;

        inputFile.close();
        return 0;
    }
    }
}
