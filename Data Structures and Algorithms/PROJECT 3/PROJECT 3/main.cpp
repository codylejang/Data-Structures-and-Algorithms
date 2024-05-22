#include <iostream>
#include <string>
#include <cassert>
#include "List.h"
#include "ListNode.h"

int main()
{
       using namespace std;

       // test code

       // the get function enables a client to iterate over all elements of a List
       cs32::List l1;
       assert( l1.min() == "" );
       l1.addToFront("Hawkeye");
       l1.addToFront("Thor");
       l1.addToFront("Hulk");
       l1.addToFront("Black Widow");
       l1.addToFront("Iron Man");
       l1.addToFront("Captain America");
       for (int k = 0; k < l1.size(); k++)
       {
          string x;
          l1.get(k, x);
          cout << x << endl;
       }
       // should print:
       // Captain America
       // Iron Man
       // Black Widow
       // Hulk
       // Thor
       // Hawkeye

       assert( l1.position( "Hawkeye" ) == 5 );
       assert( l1.position( "Thor" ) == 4 );
       assert( l1.position( "Hulk" ) == 3 );
       assert( l1.position( "Black Widow" ) == 2 );
       assert( l1.position( "Iron Man" ) == 1 );
       assert( l1.position( "Captain America" ) == 0 );
       assert( l1.position( "Not there" ) == -1 );

       assert( l1.before( "Not there", "Hulk" ) == false );
       assert( l1.before( "Hulk", "Not there" ) == false );
       assert( l1.before( "Hulk", "Captain America" ) == false );
       assert( l1.before( "Black Widow", "Hulk" ) == true );
       assert( l1.before( "Captain America", "Hulk" ) == true );

       assert( l1.min() == "Black Widow" );

    string c = "Happy";
       l1.removeAllBiggerThan( c );
        //now just "Captain America", "Black Widow"
       assert( l1.size() == 2 );
       assert( l1.position( "Hawkeye" ) == -1 );
       assert( l1.position( "Thor" ) == -1 );
       assert( l1.position( "Hulk" ) == -1 );
       assert( l1.position( "Black Widow" ) == 1 );
       assert( l1.position( "Iron Man" ) == -1 );
       assert( l1.position( "Captain America" ) == 0 );
       assert( l1.position( "Not there" ) == -1 );

       
    cs32::List l2;
    assert( l2.min() == "" ); //if empty list
    
    assert( l2.position( "Louis V" ) == -1 ); //check for item thats not there in empty list
    
    l2.addToFront("Ann");
    l2.addToFront("James");
    l2.addToFront("Cody");
    l2.addToFront("Paul");
    l2.addToFront("Matt");
    l2.addToFront("Louis V");
    l2.addToFront("Skylar");
    
    assert( l2.position( "Ann" ) == 6 );
    assert( l2.position( "James" ) == 5 );
    assert( l2.position( "Cody" ) == 4 );
    assert( l2.position( "Paul" ) == 3);
    assert( l2.position( "Matt" ) == 2 );
    assert( l2.position( "Louis V" ) == 1 );
    assert( l2.position( "Skylar" ) == 0 );
    
    //test for not in list
    assert( l2.position( "" ) == -1 );
    assert( l2.position( "asdfjasdfj" ) == -1 );
    
    //test for before if first, second, or both not in list
    assert( l2.before( "Ann", "Not there" ) == false );
    assert( l2.before( "Not there", "Ann" ) == false );
    assert( l2.before( "Not there", "Not there" ) == false );
    
    //size test
    assert( l2.size() == 7 );
    cout << l2.printItems() << endl;
    
    // min test
    assert( l2.min() == "Ann" );
    
    // get test
    for (int k = 0; k < l2.size(); k++)
    {
       string x;
       l2.get(k, x);
       cout << x << endl;
    }
    
    //remove bigger test
    string d = "L";
    l2.removeAllBiggerThan( d );
    assert( l2.size() == 3 );
    cout << l2.printItems() << endl;
    
    cout << "all tests passed!" << endl;
    return( 0 );
}
