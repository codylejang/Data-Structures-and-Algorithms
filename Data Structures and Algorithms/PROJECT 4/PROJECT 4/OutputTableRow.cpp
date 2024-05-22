//
//  OutputTableRow.cpp
//  PROJECT 4
//
//  Created by Cody Lejang on 11/15/23.
//

#include "OutputTableRow.h"
#include "iostream"
#include <map>
#include <string>
#include <vector>
namespace cs32{

OutputTableRow::OutputTableRow(){
    mSurvived = 0;
    mTotal = 0;
}
void OutputTableRow::setDescription(std::string description){
    mDescription = description;
}

void OutputTableRow::setSurvived(int survived){
    mSurvived = survived;
}

void OutputTableRow::setTotal(int total){
    mTotal = total;
}

std::string OutputTableRow::getDescription(){
    return mDescription;
}

int OutputTableRow::getSurvived(){
    return mSurvived;
}

int OutputTableRow::getTotal(){
    return mTotal;
}

double OutputTableRow::getPercentage(){
    if (mTotal == 0){ //check for dividing by 0
        return 0.0;
    }
    double percentage = double(mSurvived) / double(mTotal);
    return percentage;
}

//std::string OutputTableRow::padToThreeCharacters(int value){
//    
//}

void OutputTableRow::OutputTableRow::display(){
    std::cout << getDescription() << "      " << getSurvived() << "/" << getTotal() << "         %" << getPercentage() << std::endl;
}

}
