//
//  OutputTableRow.hpp
//  PROJECT 4
//
//  Created by Cody Lejang on 11/15/23.
//

#ifndef OUTPUTTABLEROW_H
#define OUTPUTTABLEROW_H

#include <stdio.h>
#include <map>
#include <string>
#include <vector>

namespace cs32{

class OutputTableRow{

public:
    OutputTableRow();
    void setDescription(std::string description);
    void setSurvived(int survived);
    void setTotal(int total);
    
    std::string getDescription();
    int getSurvived();
    int getTotal();
    double getPercentage();
    
    void display();

private:
    std::string mDescription;
    int mSurvived;
    int mTotal;
    std::string padToThreeCharacters(int value);
};

}
#endif
