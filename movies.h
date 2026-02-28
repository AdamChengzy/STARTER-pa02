#ifndef MOVIES_H
#define MOVIES_H

#include <string>
#include <vector>

struct Movie {
    std::string title;
    int year = 0;
    double rating = 0.0;
    int runtime = 0;
};

class MovieDB {
public:
    void loadFromFile(const std::string& filename);
    void sortByTitle();
    void sortByYear();
    void sortByRatingDesc();
    std::vector<Movie> filterByYear(int lo, int hi) const;
    std::vector<Movie> topKByRating(int k) const;
    const std::vector<Movie>& all() const;

private:
    std::vector<Movie> movies;
};

#endif
