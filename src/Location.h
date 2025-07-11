#pragma once

#include <string>

using namespace std;

class Location {
public:
    virtual ~Location() = default;
    virtual void drawImage() const = 0;
    virtual string getName() const = 0;
    virtual string areaDescription() const = 0;
};