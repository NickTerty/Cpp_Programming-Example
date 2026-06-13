#include<iostream>
#include<vector>
#include<stdexcept>
using namespace std;

// const reference
double calculateAverage(const vector<double>& grades) {
    double sum = 0;
    int nonzeroCount = 0;

    // Modern C++'s Range-based for loop
    for (double score : grades) {
        if (score != 0) {
            sum += score;
            nonzeroCount++;
        }
    }

    if (nonzeroCount == 0) {
        throw logic_error("No nonzero grade exists!");
    }

    return sum / nonzeroCount;
}

int main() {
    vector<double> grades;
    bool allZero = true;

    cout << "Enter grades (end with -1): " << endl;
    while (true) {
        double input;
        cin >> input;
        if (input == -1) break;

        grades.push_back(input);
        if (input != 0) {
            allZero = false;
        }
    }

    if (grades.empty() || allZero) {
        cout << "Average: 0" << endl;
    } 
    else {
        try {
            double avg = calculateAverage(grades); 
            cout << "Average of nonzero grades: " << avg << endl;
        } 
        catch (const logic_error& e) {
            cout << "Caught an exception: " << e.what() << endl;
        }
    }

    return 0;
}