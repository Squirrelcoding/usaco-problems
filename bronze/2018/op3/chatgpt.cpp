#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ifstream fin("family.in");
    ofstream fout("family.out");

    int N;
    string cow1, cow2;
    fin >> N >> cow1 >> cow2;

    unordered_map<string, int> nameToIndex;
    vector<string> indexToName;
    vector<int> parent; // parent[i] = index of parent of i, or -1 if no parent

    auto getIndex = [&](const string& name) -> int {
        if (nameToIndex.count(name)) return nameToIndex[name];
        int idx = indexToName.size();
        nameToIndex[name] = idx;
        indexToName.push_back(name);
        parent.push_back(-1);
        return idx;
    };

    // Build graph
    for (int i = 0; i < N; ++i) {
        string mother, child;
        fin >> mother >> child;
        int mIdx = getIndex(mother);
        int cIdx = getIndex(child);
        parent[cIdx] = mIdx;
    }

    int idx1 = getIndex(cow1);
    int idx2 = getIndex(cow2);

    // Build ancestor chains (from cow up to root)
    auto getAncestors = [&](int start) {
        vector<int> ancestors;
        int cur = start;
        while (parent[cur] != -1) {
            cur = parent[cur];
            ancestors.push_back(cur);
        }
        return ancestors;
    };

    vector<int> anc1 = getAncestors(idx1);
    vector<int> anc2 = getAncestors(idx2);

    // Check if one is direct descendant of other
    auto findInAncestors = [](const vector<int>& ancestors, int target) -> int {
        for (int i = 0; i < ancestors.size(); ++i)
            if (ancestors[i] == target)
                return i;
        return -1;
    };

    int pos = findInAncestors(anc1, idx2);
    if (pos != -1) {
        fout << cow2 << " is the ";
        for (int i = 0; i < pos; ++i) fout << "great-";
        fout << "grand-mother of " << cow1 << endl;
        return 0;
    }

    pos = findInAncestors(anc2, idx1);
    if (pos != -1) {
        fout << cow1 << " is the ";
        for (int i = 0; i < pos; ++i) fout << "great-";
        fout << "grand-mother of " << cow2 << endl;
        return 0;
    }

    // Check siblings
    if (parent[idx1] != -1 && parent[idx1] == parent[idx2]) {
        fout << "SIBLINGS" << endl;
        return 0;
    }
// Check if cow2 is an aunt / great-aunt of cow1
for (int i = 1; i < anc1.size(); ++i) {
    int grandmother = anc1[i];
    for (int j = 0; j < parent.size(); ++j) {
        if (parent[j] == grandmother && j != anc1[i-1]) {
            if (j == idx2) {
                fout << cow2 << " is the ";
                for (int g = 0; g < i-1; ++g) fout << "great-";
                fout << "aunt of " << cow1 << endl;
                return 0;
            }
        }
    }
}

// Now check if cow1 is an aunt / great-aunt of cow2
for (int i = 1; i < anc2.size(); ++i) {
    int grandmother = anc2[i];
    for (int j = 0; j < parent.size(); ++j) {
        if (parent[j] == grandmother && j != anc2[i-1]) {
            if (j == idx1) {
                fout << cow1 << " is the ";
                for (int g = 0; g < i-1; ++g) fout << "great-";
                fout << "aunt of " << cow2 << endl;
                return 0;
            }
        }
    }
}



    // Check cousins: any common ancestor
    for (int a : anc1) {
        if (find(anc2.begin(), anc2.end(), a) != anc2.end()) {
            fout << "COUSINS" << endl;
            return 0;
        }
    }

    fout << "NOT RELATED" << endl;
    return 0;
}

