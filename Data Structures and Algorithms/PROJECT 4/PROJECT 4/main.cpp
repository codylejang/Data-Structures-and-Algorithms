//
//  main.cpp
//  Titanic
//
//  Created by Howard Stahl on 7/1/23.
//


#include "Settings.h"
#include "CSVFile.h"
//#include "ExampleDataCollector.h"
#include <iostream>
#include <cassert>

// once you get things working...
 #include "Passenger.h"
 #include "PassengerDatabase.h"
 #include "PassengerOutputTable.h"

//int example()
//{
//    using namespace cs32;
//
//    // work with the ExampleDataCollector
//    ExampleDataCollector * collector = new ExampleDataCollector();
//    CSVFile file( collector );
//    file.readFile( PATH_TO_SAMPLE_DATA_MAC );
//
//    return( 0 );
//}


int sample( ) {
    /*
     CS 32 Students should uncomment what they see below once they think they have everything working...
     */
    
    using namespace std;
    using namespace cs32;
    
     
     
    Passenger passenger;
    passenger.setName( "Jack Dawson" );
    passenger.setEmbarcation( "S" );
    passenger.setClass( "3" );
    passenger.setSurvived( "0" );
    passenger.setFare( "12.50" );
    assert( passenger.getName() == "Jack Dawson" );
    assert( passenger.getClass() == Class::THIRD );
    assert( passenger.getEmbarcation() == Embarcation::SOUTHHAMPTON );
    assert( std::to_string(passenger.getFare()) == "12.500000" );
    assert( passenger.getSurvived() == false );
     
    OutputTableRow row;
    row.setDescription( "testing" );
    row.setSurvived( 5 );
    row.setTotal( 10 );
    assert( row.getDescription() == "testing" );
    assert( row.getSurvived() == 5 );
    assert( row.getTotal() == 10 );
    assert( std::to_string(row.getPercentage()) == "0.500000" );
     
    PassengerDatabase database;
    database.load( PATH_TO_MOVIE_DATA_MAC );
    if (database.loaded())
    {
        vector< Passenger * > byclass = database.getPassengers_byClass(Class::FIRST, true, -10.00);
        vector< Passenger * > byembark = database.getPassengers_byEmbarcation(Embarcation::SOUTHHAMPTON, true, 0.00);
        
        Passenger * p = database.getPassenger_byName( "Howard" );
        if (p)
            p->setEmbarcation( "S" );
       
 
        PassengerOutputTable t( byclass );
        t.setDescription( "List of First Class Survivors With Fare > 0" );
        t.setOutputField( Field::BYCLASS );
        assert( t.getDescription() == "List of First Class Survivors With Fare > 0" );
        assert( t.getOutputField() == Field::BYCLASS );
        t.display();
        
        vector< Passenger * > byclassdied = database.getPassengers_byClass(Class::FIRST, false, -10.00);
        PassengerOutputTable t1( byclassdied );
        t1.setDescription( "List of First Class Died With Fare > 0" );
        t1.setOutputField( Field::BYCLASS );
        t1.display();

        
        vector< Passenger * > all = database.getPassengers();
        PassengerOutputTable t2( all );
        t2.setDescription( "List of all passengers by class" );
        t2.setOutputField( Field::BYCLASS );
        t2.display();
     
        assert( t2.rowCount() == 4 );
 
        row = t2.getRow( 0 );
        assert( row.getSurvived() == 4 );
        assert( row.getTotal() == 5 );
        assert( std::to_string(row.getPercentage()) == "0.800000" );
        
        t2.setDescription( "List of all passengers by embarcation" );
        t2.setOutputField( Field::BYEMBARCATION );
        t2.display();
        
        t2.setDescription( "List of all passengers by fare" );
        t2.setOutputField( Field::BYFARE );
        t2.display();
        
        t2.setDescription( "What is shown by NOVALUE??" );
        t2.setOutputField( Field::NOVALUE );
        t2.display();
        
    }
    else
    {
        cout << "database was not loaded correctly" << endl;
        cout << PATH_TO_MOVIE_DATA_MAC << " is not working!" << endl;
    }
    
    //test clear and destructor
    database.clearAllPassengers();
    assert( database.loaded() == false );
    
    //test for titanic case
    PassengerDatabase database2;
    database2.load( PATH_TO_BIGGER_DATA_MAC );
    
    if (database2.loaded())
    {
    vector< Passenger * > all2 = database2.getPassengers();
    PassengerOutputTable t3( all2 );
    
    t3.setDescription( "List of all passengers by embarcation" );
    t3.setOutputField( Field::BYEMBARCATION );
    t3.display();
    
    t3.setDescription( "List of all passengers by fare" );
    t3.setOutputField( Field::BYFARE );
    t3.display();
    
    t3.setDescription( "What is shown by class??" );
    t3.setOutputField( Field::BYCLASS );
    t3.display();
    
    t3.setDescription( "What is shown by NOVALUE??" );
    t3.setOutputField( Field::NOVALUE );
    t3.display();
    }
    else {
        cout << "FAILURE" << endl;
        return 0;
    }
    
    cout << "All tests passed!" << endl;
    return( 0 );
}

int main()
{
//    example();
    sample();
    
    return( 0 );
}
