#pragma once

#include "Location.h"

using namespace std;

class Church : public Location
{
private:
public:
    void drawImage() const override;
    string getName() const override;
    string areaDescription() const override;

};