//
//  PassengerDatabase.hpp
//  PROJECT 4
//
//  Created by Cody Lejang on 11/15/23.
//

#ifndef PassengerDatabase_h
#define PassengerDatabase_h

#include "Enums.h"
#include "Passenger.h"
#include "DataCollectorCallback.h"
#include "CSVFile.h"
#include "iostream"
#include <map>
#include <string>
#include <vector>

namespace cs32{

class PassengerDatabase : public DataCollectorCallback{

public:
     PassengerDatabase();
     ~PassengerDatabase();
    
     int load(std::string filePath);
     void clearAllPassengers();
     bool loaded();
    
     Passenger* getPassenger_byName(std::string name);
     std::vector<Passenger*> getPassengers();
     std::vector<Passenger*> getPassengers_byClass(Class paidClass, bool survived, double minimumFare);
     std::vector<Passenger*> getPassengers_byEmbarcation(Embarcation embarked, bool survived, double minimumFare);
    
     virtual void csvData (std::map<std::string,std::string> row);

private:
     std::vector<Passenger*> passengers;
     bool isLoaded;
};
}
#endif /* PassengerDatabase_h */
