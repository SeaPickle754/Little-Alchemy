// for vec and offset declarations
// and for file names
#pragma once
#include <SFML/System/String.hpp>
#include "globals.h"
#include <cassert>
#include <string>
#include <vector>
#include <map>
#include <printf.h>
// csv.h is https://github.com/ben-strasser/fast-cpp-csv-parser
#include "csv.h"

struct combonation{
    offset react1;
    offset react2;
    offset product;
};

class FileParser{
public:
    FileParser();
    offset getProduct(offset, offset);
    sf::String getName(offset);
    inline int getElementNumber(){return m_offsetSize;}
private:
    std::map<sf::String, offset> offsets;
    std::vector<struct combonation> combos;
    int m_offsetSize;
};
