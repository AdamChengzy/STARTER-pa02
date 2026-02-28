#include "movies.h"
#include <iostream>
#include <iomanip>

using namespace std;

void Movies::add(const string& name, double rating) {
    mp[name] = rating;
}

void Movies::printAll() const {
    for (const auto& [name, rating] : mp) {
        cout << name << ", " << fixed << setprecision(1) << rating << "\n";
    }
}

bool Movies::startsWith(const string& s, const string& prefix) {
    if (prefix.size() > s.size()) return false;
    return s.compare(0, prefix.size(), prefix) == 0;
}

bool Movies::bestWithPrefix(const string& prefix, string& bestName, double& bestRating) const {
    auto it = mp.lower_bound(prefix);

    bool found = false;
    double best = -1e18;
    string bestMovie;

    while (it != mp.end() && startsWith(it->first, prefix)) {
        if (!found || it->second > best) {
            found = true;
            best = it->second;
            bestMovie = it->first;
        }
        ++it;
    }

    if (!found) return false;

    bestName = bestMovie;
    bestRating = best;
    return true;
}
