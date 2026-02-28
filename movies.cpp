#include "movies.h"
#include <fstream>
#include <algorithm>
#include <stdexcept>

using namespace std;

void MovieDB::loadFromFile(const string& filename) {
    ifstream fin(filename);
    if (!fin) throw runtime_error("Cannot open file: " + filename);
}

void MovieDB::sortByTitle() {
    sort(movies.begin(), movies.end(),
         [](const Movie& a, const Movie& b){ return a.title < b.title; });
}

void MovieDB::sortByYear() {
    sort(movies.begin(), movies.end(),
         [](const Movie& a, const Movie& b){ return a.year < b.year; });
}

void MovieDB::sortByRatingDesc() {
    sort(movies.begin(), movies.end(),
         [](const Movie& a, const Movie& b){ return a.rating > b.rating; });
}

vector<Movie> MovieDB::filterByYear(int lo, int hi) const {
    vector<Movie> res;
    for (const auto& m : movies) {
        if (m.year >= lo && m.year <= hi) res.push_back(m);
    }
    return res;
}

vector<Movie> MovieDB::topKByRating(int k) const {
    vector<Movie> copy = movies;
    sort(copy.begin(), copy.end(),
         [](const Movie& a, const Movie& b){ return a.rating > b.rating; });
    if (k < (int)copy.size()) copy.resize(k);
    return copy;
}

const vector<Movie>& MovieDB::all() const {
    return movies;
}
