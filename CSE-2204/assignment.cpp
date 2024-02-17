#include <bits/stdc++.h>

using namespace std;

struct PopulationData
{
    double year;
    double population;
};

struct LinearizedExponential
{
    double a;
    double b;
};

vector<PopulationData> readPopulationData(const string &filename)
{
    vector<PopulationData> data;

    ifstream txtFile(filename);
    string line;

    while (getline(txtFile, line))
    {
        try
        {
            double year, population;
            istringstream iss(line);
            iss >> year >> population;
            data.push_back({year, population});
        }
        catch (const invalid_argument &e)
        {
            continue;
        }
    }

    return data;
}

double populationFunction(double x)
{
    return exp(x);
}

double populationDerivative(double x)
{
    return exp(x);
}

double newtonsMethod(double targetPopulation, const vector<PopulationData> &data, double initialGuess, double tolerance = 1e-5, int maxIterations = 100)
{
    double x = initialGuess;
    int iteration = 0;

    while (abs(populationFunction(x) - targetPopulation) > tolerance && iteration < maxIterations)
    {
        double fx = 0.0;
        double fpx = 0.0;

        for (const auto &d : data)
        {
            double diff = x - d.year;
            fx += d.population * exp(-diff);
            fpx += d.population * diff * exp(-diff);
        }

        x = x - (fx - targetPopulation) / fpx;
        iteration++;
    }

    return x;
}

LinearizedExponential linearizeExponential(const vector<PopulationData> &data)
{
    double sumX = 0.0;
    double sumLnY = 0.0;
    double sumXLnY = 0.0;
    double sumXX = 0.0;

    for (const auto &d : data)
    {
        sumX += d.year;
        sumLnY += log(d.population);
        sumXLnY += d.year * log(d.population);
        sumXX += d.year * d.year;
    }

    double n = data.size();

    double b = (n * sumXLnY - sumX * sumLnY) / (n * sumXX - sumX * sumX);
    double lnA = (sumLnY - b * sumX) / n;

    double a = exp(lnA);

    return {a, b};
}

vector<double> predictValues(const vector<double> &x, double a, double b)
{
    vector<double> yPredicted;
    for (double val : x)
    {
        yPredicted.push_back(a * exp(b * val));
    }
    return yPredicted;
}

int main()
{
    string filename = "sample_data.txt";
    auto data = readPopulationData(filename);

    double targetPopulation = 100000000;
    double initialGuess = 50.0;

    double root = newtonsMethod(targetPopulation, data, initialGuess);

    cout << "The population is expected to reach " << round(targetPopulation) << " in year " << round(root) << "." << endl;

    auto linearizedExp = linearizeExponential(data);
    vector<double> newYears;
    for (int i = 1; i <= 10; ++i)
    {
        newYears.push_back(data.back().year + i);
    }
    vector<double> predictedPopulations = predictValues(newYears, linearizedExp.a, linearizedExp.b);

    for (size_t i = 0; i < newYears.size(); ++i)
    {
        cout << "Predicted population for year " << static_cast<int>(newYears[i]) << ": " << predictedPopulations[i] << endl;
    }

    double absoluteErrorNewton = abs(targetPopulation - populationFunction(root));

    vector<double> absoluteErrorCurveFitting;
    for (size_t i = 0; i < data.size(); ++i)
    {
        absoluteErrorCurveFitting.push_back(abs(data[i].population - predictedPopulations[i]));
    }

    cout << "Mean Absolute Error for Newton Raphson Method: " << absoluteErrorNewton << endl;

    if (!absoluteErrorCurveFitting.empty())
    {
        double meanAbsoluteErrorCurveFitting = accumulate(absoluteErrorCurveFitting.begin(), absoluteErrorCurveFitting.end(), 0.0) / absoluteErrorCurveFitting.size();
        cout << "Mean Absolute Error for Curve Fitting: " << meanAbsoluteErrorCurveFitting << endl;
    }
    else
    {
        cout << "Error: The vector absoluteErrorCurveFitting is empty." << endl;
    }

    return 0;
}
