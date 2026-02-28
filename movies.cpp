#include "movies.h"
#include <algorithm>

using namespace std;

void Movies::add(const string& name, double rating) {
    byName.push_back({name, rating});
}

void Movies::finalize() {
    sort(byName.begin(), byName.end(),
         [](const Movie& a, const Movie& b) {
             return a.name < b.name;
         });
}

const vector<Movie>& Movies::allByName() const {
    return byName;
}

bool Movies::startsWith(const string& s, const string& prefix) {
    if (prefix.size() > s.size()) return false;
    return s.compare(0, prefix.size(), prefix) == 0;
}

vector<Movie> Movies::matchesSortedForPrefix(const string& prefix) const {
    vector<Movie> res;

    auto it = lower_bound(byName.begin(), byName.end(), prefix,
                          [](const Movie& m, const string& p) {
                              return m.name < p;
                          });

    while (it != byName.end() && startsWith(it->name, prefix)) {
        res.push_back(*it);
        ++it;
    }

    sort(res.begin(), res.end(),
         [](const Movie& a, const Movie& b) {
             if (a.rating != b.rating) return a.rating > b.rating;
             return a.name < b.name;
         });

    return res;
}

bool Movies::bestForPrefix(const string& prefix, Movie& best) const {
    auto it = lower_bound(byName.begin(), byName.end(), prefix,
                          [](const Movie& m, const string& p) {
                              return m.name < p;
                          });

    bool found = false;
    Movie curBest;

    while (it != byName.end() && startsWith(it->name, prefix)) {
        if (!found ||
            it->rating > curBest.rating ||
            (it->rating == curBest.rating && it->name < curBest.name)) {
            curBest = *it;
            found = true;
        }
        ++it;
    }

    if (!found) return false;
    best = curBest;
    return true;
}
