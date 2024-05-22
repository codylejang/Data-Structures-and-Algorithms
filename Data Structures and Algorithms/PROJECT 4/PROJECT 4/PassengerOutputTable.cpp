//
//  PassengerOutputTable.cpp
//  PROJECT 4
//
//  Created by Cody Lejang on 11/15/23.
//

#include "PassengerOutputTable.h"
#include "iostream"
#include <map>
#include <string>
#include <vector>

namespace cs32{


PassengerOutputTable::PassengerOutputTable(std::vector<Passenger*> passengers){
    mField = Field::NOVALUE;
    mPassengerList = passengers;
}

void PassengerOutputTable::setOutputField(Field f){
    mField = f;
}

void PassengerOutputTable::setDescription(std::string description ){
    mDescription = description;
}

Field PassengerOutputTable::getOutputField(){
    return mField;
}

std::string PassengerOutputTable::getDescription(){
    return mDescription;
}

void PassengerOutputTable::display(){
    mRows.clear(); //rest if doing multiple
    if (mField == Field::NOVALUE){
        return;
    }
    
    std::cout << mDescription << std::endl; //title creater
    std::cout << "            Survived/Total       %" << std::endl;
    
    //rowcounter to populate empty outputtablerows in mRows, doubles as counter for rowCount()
    size_t rowcount;
    if (getOutputField() == Field::BYCLASS || getOutputField() == Field::BYEMBARCATION){
        rowcount = 4;
    }
    else if (getOutputField() == Field::BYFARE){
        rowcount = 5;
    }
    else {
        rowcount = 0;
    }
    
    for (size_t i = 0; i<rowcount; i++){
        OutputTableRow newRow; //generate empty row and populate mRows
        mRows.push_back(newRow);
    }
    
    //survived and total counters
    int row0_s = 0;
    int row0_t = 0;
    int row1_s = 0;
    int row1_t = 0;
    int row2_s = 0;
    int row2_t = 0;
    int row3_s = 0;
    int row3_t = 0;
    int row4_s = 0;
    int row4_t = 0;
    
    if (getOutputField() == Field::BYCLASS){ //class case
        mRows[0].setDescription("First Class-   ");
        mRows[1].setDescription("Second Class-   ");
        mRows[2].setDescription("Third Class-   ");
        mRows[3].setDescription("Not Known-     ");
        for(auto it = mPassengerList.begin(); it != mPassengerList.end(); it++){
            if ((*it)->getClass() == Class::FIRST){
                row0_t++; //increment total by 1
                if ((*it)->getSurvived()==true){
                    row0_s++; //increment survived by 1 if surviving
                }
            }
            if ((*it)->getClass() == Class::SECOND){
                row1_t++; //increment total by 1
                if ((*it)->getSurvived()==true){
                    row1_s++; //increment survived by 1
                }
            }
            if ((*it)->getClass() == Class::THIRD){
                row2_t++; //increment total by 1
                if ((*it)->getSurvived()==true){
                    row2_s++; //increment survived by 1
                }
            }
            if ((*it)->getClass() == Class::NOTKNOWN){
                row3_t++; //increment total by 1
                if ((*it)->getSurvived()==true){
                    row3_s++; //increment survived by 1
                }
            }
        }
        mRows[0].setSurvived(row0_s);
        mRows[0].setTotal(row0_t);
        mRows[1].setSurvived(row1_s);
        mRows[1].setTotal(row1_t);
        mRows[2].setSurvived(row2_s);
        mRows[2].setTotal(row2_t);
        mRows[3].setSurvived(row3_s);
        mRows[3].setTotal(row3_t);
    }
    else if (getOutputField() == Field::BYEMBARCATION){ //embarked case
        mRows[0].setDescription("Cherbourg-   ");
        mRows[1].setDescription("Queenstown-   ");
        mRows[2].setDescription("Southhampton-   ");
        mRows[3].setDescription("Not Known-     ");
        for(auto it = mPassengerList.begin(); it != mPassengerList.end(); it++){
            if ((*it)->getEmbarcation() == Embarcation::CHERBOURG){
                row0_t++; //increment total by 1
                if ((*it)->getSurvived()==true){
                    row0_s++; //increment survived by 1 if surviving
                }
            }
            if ((*it)->getEmbarcation() == Embarcation::QUEENSTOWN){
                row1_t++; //increment total by 1
                if ((*it)->getSurvived()==true){
                    row1_s++; //increment survived by 1
                }
            }
            if ((*it)->getEmbarcation() == Embarcation::SOUTHHAMPTON){
                row2_t++; //increment total by 1
                if ((*it)->getSurvived()==true){
                    row2_s++; //increment survived by 1
                }
            }
            if ((*it)->getEmbarcation() == Embarcation::NOTKNOWN){
                row3_t++; //increment total by 1
                if ((*it)->getSurvived()==true){
                    row3_s++; //increment survived by 1
                }
            }
        }
        mRows[0].setSurvived(row0_s);
        mRows[0].setTotal(row0_t);
        mRows[1].setSurvived(row1_s);
        mRows[1].setTotal(row1_t);
        mRows[2].setSurvived(row2_s);
        mRows[2].setTotal(row2_t);
        mRows[3].setSurvived(row3_s);
        mRows[3].setTotal(row3_t);
    }
    else if (getOutputField() == Field::BYFARE){ //embarked case
        mRows[0].setDescription("Not Known-   ");
        mRows[1].setDescription("$ 1-$10-   ");
        mRows[2].setDescription("$10-$25-   ");
        mRows[3].setDescription("$25-$50-     ");
        mRows[4].setDescription("   >$50-     ");
        for(auto it = mPassengerList.begin(); it != mPassengerList.end(); it++){
            if ((*it)->getFare() == 0){
                row0_t++; //increment total by 1
                if ((*it)->getSurvived()==true){
                    row0_s++; //increment survived by 1 if surviving
                }
            }
            if ((*it)->getFare() >= 0.01 && (*it)->getFare() <= 10.00){
                row1_t++; //increment total by 1
                if ((*it)->getSurvived()==true){
                    row1_s++; //increment survived by 1
                }
            }
            if ((*it)->getFare() >= 10.01 && (*it)->getFare() <= 25.00){
                row2_t++; //increment total by 1
                if ((*it)->getSurvived()==true){
                    row2_s++; //increment survived by 1
                }
            }
            if ((*it)->getFare() >= 25.01 && (*it)->getFare() <= 50.00){
                row3_t++; //increment total by 1
                if ((*it)->getSurvived()==true){
                    row3_s++; //increment survived by 1
                }
            }
            if ((*it)->getFare() >= 50.01){
                row4_t++; //increment total by 1
                if ((*it)->getSurvived()==true){
                    row4_s++; //increment survived by 1
                }
            }
        }
        
        //set data vals for every row
        mRows[0].setSurvived(row0_s);
        mRows[0].setTotal(row0_t);
        mRows[1].setSurvived(row1_s);
        mRows[1].setTotal(row1_t);
        mRows[2].setSurvived(row2_s);
        mRows[2].setTotal(row2_t);
        mRows[3].setSurvived(row3_s);
        mRows[3].setTotal(row3_t);
        mRows[4].setSurvived(row4_s);
        mRows[4].setTotal(row4_t);
    }
    else {
        return;
    }
    
    //print every row
    for (int i = 0; i<mRows.size(); i++){
        mRows[i].display();
    }
}

size_t PassengerOutputTable::rowCount(){
    size_t rowcount;
    if (getOutputField() == Field::BYCLASS || getOutputField() == Field::BYEMBARCATION){
        rowcount = 4; //four rows if byclass and byembark
    }
    else if (getOutputField() == Field::BYFARE){
        rowcount = 5; //five rows if byfare
    }
    else {
        rowcount = 0; //no rows if invalid
    }
    return rowcount;
}

OutputTableRow PassengerOutputTable::getRow( int index){
    return mRows[index];
}
    
}

