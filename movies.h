#ifndef MOVIES_H
#define MOVIES_H

#include <string>
#include <map>

class Movies {
public:
    void add(const std::string& name, double rating);

    void printAll() const;

    bool bestWithPrefix(const std::string& prefix, std::string& bestName, double& bestRating) const;

private:
    std::map<std::string, double> mp;

    static bool startsWith(const std::string& s, const std::string& prefix);
};

#endif
