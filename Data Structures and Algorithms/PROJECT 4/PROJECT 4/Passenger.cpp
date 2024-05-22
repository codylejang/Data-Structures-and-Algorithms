//
//  Passenger.cpp
//  PROJECT 4
//
//  Created by Cody Lejang on 11/15/23.
//

#include "Passenger.h"
#include <string>

namespace cs32{
Passenger::Passenger(){
    mFare = 0;
}

void Passenger::setName(std::string name){
    mName = name;
}
std::string Passenger::getName(){
    return mName;
}

void Passenger::setEmbarcation(std::string embarked){
    mEmbarked = Embarcation::NOTKNOWN;
    if (embarked == "C"){
        mEmbarked = Embarcation::CHERBOURG;
    }
    if (embarked == "Q"){
        mEmbarked = Embarcation::QUEENSTOWN;
    }
    if (embarked == "S"){
        mEmbarked = Embarcation::SOUTHHAMPTON;
    }
    
}

void Passenger::setClass(std::string classofFare){
    mClass = Class::NOTKNOWN;
    if (classofFare == "1"){
        mClass = Class::FIRST;
    }
    if (classofFare == "2"){
        mClass = Class::SECOND;
    }
    if (classofFare == "3"){
        mClass = Class::THIRD;
    }
}

void Passenger::setSurvived(std::string survived){
    mSurvived = false;
    if (survived == "1"){
        mSurvived = true;
    }
    if (survived == "0"){
        mSurvived = false;
    }
}


void Passenger::setFare(std::string fare){
    if (fare == ""){
        mFare = 0;
        return;
    }
    mFare = std::stof( fare );
}

Embarcation Passenger::getEmbarcation(){
    return mEmbarked;
}

Class Passenger::getClass(){
    return mClass;
}

bool Passenger::getSurvived(){
    return mSurvived;
}

double Passenger::getFare(){
    return mFare;
}

}
