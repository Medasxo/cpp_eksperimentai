#ifndef LAIKMATIS_H
#define LAIKMATIS_H

#include <iostream>
#include <chrono>

class Laikmatis {
public:
    Laikmatis();
    ~Laikmatis();

    void Sustabdyti() const;

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> pradziosLaikas;
};

#endif
