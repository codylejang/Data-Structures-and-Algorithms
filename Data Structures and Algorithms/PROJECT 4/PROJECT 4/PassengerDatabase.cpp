//
//  PassengerDatabase.cpp
//  PROJECT 4
//
//  Created by Cody Lejang on 11/15/23.
//

#include "PassengerDatabase.h"
#include "Passenger.h"
#include "iostream"
#include "CSVFile.h"
#include <map>
#include <string>
#include <vector>
#include <algorithm>

namespace cs32{

PassengerDatabase::PassengerDatabase(){
    isLoaded = false;
}
PassengerDatabase::~PassengerDatabase(){
    std::vector<Passenger*>::iterator it;
    for (it = passengers.begin(); it != passengers.end(); ++it) {
        delete(*it); // del each dynamically allocated object
    }
    passengers.clear();
}

int PassengerDatabase::load(std::string filePath){
    CSVFile file( this );
    int recordCount = file.readFile( filePath );
    isLoaded = true;
    return( recordCount );
}

void PassengerDatabase::clearAllPassengers(){
    std::vector<Passenger*>::iterator it;
    for (it = passengers.begin(); it != passengers.end(); ++it) {
        delete(*it); // del each dynamically allocated object
    }
    passengers.clear();
    isLoaded = false;
}
bool PassengerDatabase::loaded(){
    return isLoaded;
}

Passenger* PassengerDatabase::getPassenger_byName(std::string name){ //fix
    std::vector<Passenger*> result;
    std::vector<Passenger*>::iterator it = passengers.begin();
    while (it != passengers.end()){
        if ((*it)->getName() == name){
            return *it;
        }
        it++;
    }
    return nullptr;
}

std::vector<Passenger*> PassengerDatabase::getPassengers(){
    return passengers;
}

std::vector<Passenger*> PassengerDatabase::getPassengers_byClass(Class paidClass, bool survived, double minimumFare){
    std::vector<Passenger*> result;
    std::vector<Passenger*>::iterator it = passengers.begin();
    
    while (it != passengers.end()){ //find passenger fitting criteria and add to new result vector
        if ((*it)->getClass() == paidClass && (*it)->getSurvived()==survived && (*it)->getFare()>minimumFare){
            result.push_back(*it);
        }
        it++;
    }
    return result;
}

std::vector<Passenger*> PassengerDatabase::getPassengers_byEmbarcation(Embarcation embarked, bool survived, double minimumFare){
    std::vector<Passenger*> result;
    std::vector<Passenger*>::iterator it = passengers.begin();
    while (it != passengers.end()){ //find passenger fitting criteria and add to new result vector
        if ((*it)->getEmbarcation() == embarked && (*it)->getSurvived()==survived && (*it)->getFare()>minimumFare){
            result.push_back(*it);
        }
        it++;
    }
    return result;
}

void PassengerDatabase::csvData (std::map<std::string,std::string> row){
    Passenger* passenger = new Passenger(); //create new passenger and assign its values
    passenger->setName(row.at("name"));
    passenger->setEmbarcation(row.at("embarked"));
    passenger->setClass(row.at("pclass"));
    passenger->setSurvived(row.at("survived"));
    passenger->setFare(row.at("fare"));
    passengers.push_back(passenger);
}

}
