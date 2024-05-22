//
//  PassengerOutputTable.hpp
//  PROJECT 4
//
//  Created by Cody Lejang on 11/15/23.
//

#ifndef PassengerOutputTable_h
#define PassengerOutputTable_h

#include "Enums.h"
#include "Passenger.h"
#include "PassengerDatabase.h"
#include "OutputTableRow.h"
#include "iostream"
#include <map>
#include <string>
#include <vector>

namespace cs32{

class PassengerOutputTable{
    
public:
    PassengerOutputTable(std::vector<Passenger*>);
    void setOutputField(Field f);
    void setDescription(std::string description );
    Field getOutputField();
    std::string getDescription();

    void display();

    size_t rowCount();
    OutputTableRow getRow( int index);

private:
    std::vector<Passenger *> mPassengerList;
    std::vector<OutputTableRow> mRows;
    Field mField;
    std::string mDescription;

};

}
#endif /* PassengerOutputTable_h */
