#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Define a map to store roll and score, with roll as the key and score as the value
    map<int, int> studentScores;

    // Inserting values into the map
    studentScores[101] = 85;
    studentScores[102] = 90;
    studentScores[103] = 78;
    studentScores[104] = 95;
    studentScores[105] = 88;

    // Create a vector of pairs to store rolls and scores
    vector<pair<int, int>> sortedScores(studentScores.begin(), studentScores.end());

    // Sort the vector based on roll (first element in the pair)
    sort(sortedScores.begin(), sortedScores.end());

    // Displaying scores in sorted order of roll
    cout << "Roll\tScore" << endl;
    for (const auto& pair : sortedScores) {
        cout << pair.first << "\t" << pair.second << endl;
    }

    // Retrieving the score for a given roll (e.g., roll = 103)
    int rollToFind = 103;
    auto it = find_if(sortedScores.begin(), sortedScores.end(),
                      [rollToFind](const pair<int, int>& p) { return p.first == rollToFind; });

    if (it != sortedScores.end()) {
        cout << "Score for Roll " << rollToFind << ": " << it->second << endl;
    } else {
        cout << "Roll " << rollToFind << " not found." << endl;
    }

    return 0;
}
