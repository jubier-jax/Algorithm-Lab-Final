#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<float, int> p1, pair<float, int> p2)
{
    return p1.first > p2.first;
}

float fractional_knapsack(vector<int> weights, vector<int> values, int capacity)
{
    int n = weights.size();

    vector<pair<float, int>> ratio(n);

    // Calculate value/weight ratio
    for(int i = 0; i < n; i++)
    {
        float r = (float)values[i] / weights[i];

        ratio[i] = make_pair(r, i);
    }

    // Sort according to ratio
    sort(ratio.begin(), ratio.end(), compare);

    float total_value = 0;

    // Select items
    for(int i = 0; i < n; i++)
    {
        if(capacity == 0)
            break;

        int index = ratio[i].second;

        // Whole item can be taken
        if(weights[index] <= capacity)
        {
            capacity = capacity - weights[index];

            total_value = total_value + values[index];
        }
        else
        {
            // Take fraction of the item
            float fraction = (float)capacity / weights[index];

            total_value = total_value + values[index] * fraction;

            capacity = 0;
        }
    }

    return total_value;
}

int main()
{
    int n;

    cout << "Enter number of items: ";
    cin >> n;

    vector<int> weights(n);
    vector<int> values(n);

    cout << "Enter weights: ";

    for(int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }

    cout << "Enter values: ";

    for(int i = 0; i < n; i++)
    {
        cin >> values[i];
    }

    int capacity;

    cout << "Enter capacity: ";
    cin >> capacity;

    float answer = fractional_knapsack(weights, values, capacity);

    cout << "Maximum value = " << answer << endl;

    return 0;
}