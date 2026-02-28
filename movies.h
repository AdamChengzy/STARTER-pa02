#ifndef MOVIES_H
#define MOVIES_H

#include <string>
#include <vector>

struct Movie {
    std::string name;
    double rating;
};

class Movies {
public:
    void add(const std::string& name, double rating);
    void finalize();

    const std::vector<Movie>& allByName() const;

    std::vector<Movie> matchesSortedForPrefix(const std::string& prefix) const;

    bool bestForPrefix(const std::string& prefix, Movie& best) const;

private:
    std::vector<Movie> byName;

    static bool startsWith(const std::string& s, const std::string& prefix);
};

#endif
