#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job
{
    int weight;
    int profit;
};

bool compare(Job j1, Job j2)
{
    return (j1.profit / j1.weight) > (j2.profit / j2.weight);
}

int knapsackGreedy(int capacity, vector<Job> &jobs)
{
    sort(jobs.begin(), jobs.end(), compare);

    int totalProfit = 0;
    int currentWeight = 0;

    for (auto job : jobs)
    {
        if (currentWeight + job.weight <= capacity)
        {
            currentWeight += job.weight;
            totalProfit += job.profit;
        }
    }

    return totalProfit;
}

int main()
{
    ifstream inputFile("knapsack.txt");

    if (!inputFile.is_open())
    {
        cerr << "Error opening the file." << endl;
        return 1;
    }

    int numJobs, knapsackCapacity;
    inputFile >> numJobs;
    inputFile >> knapsackCapacity;

    vector<Job> jobs(numJobs);

    // Read weights
    for (int i = 0; i < numJobs; i++)
    {
        inputFile >> jobs[i].weight;
    }

    // Read profits
    for (int i = 0; i < numJobs; i++)
    {
        inputFile >> jobs[i].profit;
    }

    int maxProfit = knapsackGreedy(knapsackCapacity, jobs);

    cout << "Maximum profit using greedy approach: " << maxProfit << endl;

    inputFile.close();
    return 0;
}
