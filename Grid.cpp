#include <iostream>
#include <vector>
#include <limits>
#include <cmath>

// Define your cost function here
double costFunction(std::vector<double> params) {
    // This is a placeholder for your actual cost function
    return 0.0;
}
double f(double x) {
    // This is a placeholder for your actual function
    return pow(x, 2);
}

std::vector<double> gridSearch(std::vector<std::vector<double>> grid) {
    double minCost = std::numeric_limits<double>::max();
    std::vector<double> bestParams;

    for (auto& params : grid) {
        double cost = costFunction(params);
        if (cost < minCost) {
            minCost = cost;
            bestParams = params;
        }
    }

    return bestParams;
}

double df(double x) {
    // This is a placeholder for the first derivative of your actual function
    return 2 * x;
}

double ddf(double x) {
    // This is a placeholder for the second derivative of your actual function
    return 2;
}


double findLocalMinima(double start, double end, double epsilon) {
    double x = start;

    while (x < end) {
        if (df(x) == 0 && ddf(x) > 0) {
            return x;
        }

        x += epsilon;
    }

    // Return NaN if no local minimum is found
    return std::nan("");
}

int main() {

    double start = -10;
    double end = 10;
    double epsilon = 0.01;

    double localMinima = findLocalMinima(start, end, epsilon);

    if (std::isnan(localMinima)) {
        std::cout << "No local minimum found in the given interval." << std::endl;
    }
    else {
        std::cout << "Local minimum found at x = " << localMinima << std::endl;
    }


    // Define your grid here. This is a 2D vector where each inner vector is a set of parameters to test.
    std::vector<std::vector<double>> grid = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };

    std::vector<double> bestParams = gridSearch(grid);

    std::cout << "Best parameters: ";
    for (double param : bestParams) {
        std::cout << param << " ";
    }
    std::cout << std::endl;

    return 0;
}