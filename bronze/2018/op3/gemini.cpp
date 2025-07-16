#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Helper function to get the ancestor chain for a cow
vector<int> getAncestors(int startNode, const vector<int>& parent) {
    vector<int> ancestors;
    int curr = startNode;
    while (parent[curr] != -1) {
        curr = parent[curr];
        ancestors.push_back(curr);
    }
    return ancestors;
}

int main() {
    ifstream fin("family.in");
    ofstream fout("family.out");

    int N;
    string cow1_name, cow2_name;
    fin >> N >> cow1_name >> cow2_name;

    unordered_map<string, int> nameToIndex;
    vector<string> indexToName;
    // Initialize parent vector with a larger size to avoid reallocations
    vector<int> parent(2 * N + 2, -1); 

    auto getIndex = [&](const string& name) {
        if (nameToIndex.find(name) == nameToIndex.end()) {
            int newIndex = indexToName.size();
            nameToIndex[name] = newIndex;
            indexToName.push_back(name);
        }
        return nameToIndex[name];
    };

    // Build the parent relationship tree
    for (int i = 0; i < N; ++i) {
        string mother, child;
        fin >> mother >> child;
        int mIdx = getIndex(mother);
        int cIdx = getIndex(child);
        parent[cIdx] = mIdx;
    }

    // Ensure the two main cows have indices, even if they aren't children
    int idx1 = getIndex(cow1_name);
    int idx2 = getIndex(cow2_name);

    vector<int> anc1 = getAncestors(idx1, parent);
    vector<int> anc2 = getAncestors(idx2, parent);

    // Find if cow2 is an ancestor of cow1
    int k1 = -1; // k1 is the generational distance from cow1 to cow2
    for (int i = 0; i < anc1.size(); ++i) {
        if (anc1[i] == idx2) {
            k1 = i;
            break;
        }
    }

    // Find if cow1 is an ancestor of cow2
    int k2 = -1; // k2 is the generational distance from cow2 to cow1
    for (int i = 0; i < anc2.size(); ++i) {
        if (anc2[i] == idx1) {
            k2 = i;
            break;
        }
    }
    
    // --- Relationship Checking Logic ---

    if (k1 != -1) { // cow2 is a direct ancestor of cow1
        fout << cow2_name << " is the ";
        if (k1 == 0) {
            fout << "mother";
        } else {
            for (int i = 0; i < k1 - 1; ++i) {
                fout << "great-";
            }
            fout << "grand-mother";
        }
        fout << " of " << cow1_name << endl;

    } else if (k2 != -1) { // cow1 is a direct ancestor of cow2
        fout << cow1_name << " is the ";
        if (k2 == 0) {
            fout << "mother";
        } else {
            for (int i = 0; i < k2 - 1; ++i) {
                fout << "great-";
            }
            fout << "grand-mother";
        }
        fout << " of " << cow2_name << endl;
    
    } else if (parent[idx1] != -1 && parent[idx1] == parent[idx2]) {
        fout << "SIBLINGS" << endl;
    
    } else {
        // Find the closest common ancestor
        int common_ancestor = -1;
        int dist1 = -1, dist2 = -1; // Distance from each cow to the common ancestor

        for(int i = 0; i < anc1.size(); ++i) {
            for(int j = 0; j < anc2.size(); ++j) {
                if(anc1[i] == anc2[j]) {
                    common_ancestor = anc1[i];
                    dist1 = i + 1; // 1-based distance (mother is dist 1)
                    dist2 = j + 1; // 1-based distance (mother is dist 1)
                    goto found_common; // Exit both loops once the first common ancestor is found
                }
            }
        }
        
    found_common:
        if (common_ancestor != -1) {
            // Check for Aunt relationship
            if (dist1 > 1 && dist2 == 1) { // cow2's mother is an ancestor of cow1
                fout << cow2_name << " is the ";
                for (int i = 0; i < dist1 - 2; ++i) {
                    fout << "great-";
                }
                fout << "aunt of " << cow1_name << endl;
            } else if (dist2 > 1 && dist1 == 1) { // cow1's mother is an ancestor of cow2
                 fout << cow1_name << " is the ";
                for (int i = 0; i < dist2 - 2; ++i) {
                    fout << "great-";
                }
                fout << "aunt of " << cow2_name << endl;
            } else {
                fout << "COUSINS" << endl;
            }
        } else {
            fout << "NOT RELATED" << endl;
        }
    }

    return 0;
}
