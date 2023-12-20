#include "itemparser.hpp"

FileParser::FileParser(){
    // this code simply populates offsets, the std::map with
      io::CSVReader<3> offse(OFFSET_FILE);
      offse.read_header(io::ignore_extra_column, "offsetX", "offsetY", "name");
      int offsetX, offsetY; std::string name;
      while(offse.read_row(offsetX, offsetY, name)){
        offsets[name] = offset(offsetX, offsetY);
      }
      io::CSVReader<3> in(REACTION_FILE);
      in.read_header(io::ignore_extra_column, "react1", "react2", "products");
      std::string react1, react2, products;
      while(in.read_row(react1, react2, products)){
            struct combonation combo;
            combo.react1=offsets[react1];
            combo.react2=offsets[react2];
            combo.product=offsets[products];
            combos.push_back(combo);
      }
}

offset FileParser::getProduct(offset react1, offset react2){
    for(auto i = combos.begin(); i != combos.end(); i++){
        // this horrible code is (probably) a mess of bugs.
        // dirty hack, but best way to do it?!?!?
        // creates 2 bools named flag1 & 2, and sets them to false
        if(react1 == react2 && i->react1 == react1 && i->react2 == react2){
            return i->product;
        }
        bool flag1, flag2; flag1 = false; flag2 = false;
        if(i->react1 == react1 || i->react1 == react2){
            flag1 = true;
        }
        if(i->react2 == react1 || i->react2 == react2){
            flag2 = true;
        }
        if (flag1 && flag2){
            return i->product;
        }

    }
    // TODO: implement code to handle this case
    return offset(-1, -1);
}
