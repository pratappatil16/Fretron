#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compareApples(int a, int b) {
    return a > b;
}

void distributeApples(const vector<int>& apples, int ramShare, int shamShare, int rahimShare) {
    int totalWeight = 0;
    for (int weight : apples) {
        totalWeight += weight;
    }

    int totalRam = (ramShare * totalWeight) / 100;
    int totalSham = (shamShare * totalWeight) / 100;
    int totalRahim = (rahimShare * totalWeight) / 100;

    vector<int> ramApples, shamApples, rahimApples;

    for (int weight : apples) {
        if (totalRam >= weight) {
            ramApples.push_back(weight);
            totalRam -= weight;
        } else if (totalSham >= weight) {
            shamApples.push_back(weight);
            totalSham -= weight;
        } else if (totalRahim >= weight) {
            rahimApples.push_back(weight);
            totalRahim -= weight;
        } else {
            cout << "Apple of weight can not be distributed " << weight <<endl;
        }
    }

    cout << "Distribution Result:\n";
    cout << "Ram: ";
    for (int i : ramApples) {
        cout << i << " ";
    }
    cout << endl;
    cout << "Sham: ";
    for (int i : shamApples) {
        cout << i<< " ";
    }
    cout << endl;
    cout << "Rahim: ";
    for (int i : rahimApples) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> apples;
    int weight;

    cout << "Enter apple weight in grams (-1 to stop): " << endl;
    while (cin >> weight && weight != -1) {
        apples.push_back(weight);
    }

    sort(apples.begin(), apples.end(), compareApples);

    distributeApples(apples, 50, 30, 20);

    return 0;
}
