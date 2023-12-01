// for vec and offset declarations
// and for file names
#include "globals.h"
#include <cassert>
#include <string>
#include <vector>
#include <map>
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
private:
    std::map<std::string, offset> offsets;
    std::vector<struct combonation> combos;
};
