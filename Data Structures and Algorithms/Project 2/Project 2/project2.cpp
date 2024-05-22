//
//  project2.cpp
//  Project 2
//
//  Created by Cody Lejang on 10/15/23.
//

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int modulo( unsigned int m, unsigned int n ){
    if (m < n){
        return m;
    }
    else {
        return modulo(m - n, n);
    }
}

int occurrences( int number, int d ){
    if (number == 0){
        return 0;
    }
    else if (number % 10 == d){
        return 1 + occurrences(number / 10, d);
    }
    else {
        return occurrences(number / 10, d);
    }
}

std::string lucky7s( std::string s ){
    if (s.size() == 0 || s.size() == 1){
        return s;
    }
    else if (s[0] == s[1]){
        return (s.substr(0, 1) + "77" + lucky7s(s.substr(1, s.size() - 1)));
    }
    else {
        return (s.substr(0, 1) + lucky7s(s.substr(1, s.size() - 1)));
    }
}
    
bool combinations( int array[ ], int size, int target ){
    if (target == 0) {
        return true;
    }
    if (size == 0) {
        return false;
    }
    if (combinations(array + 1, size - 1, target)) {
        return true;
    }
    else if (combinations(array + 1, size - 1, target - array[0])) {
        return true;
    }
    else {
        return false;
    }
}
    
int main()
{
      // test code
    assert( modulo( 100, 10 ) == 0 );
    assert( modulo( 1, 13 ) == 1 );
    assert( modulo( 12, 5 ) == 2 );
    assert( modulo( 33, 6 ) == 3 );
    
    assert(modulo(45, 9) == 0); //test for 0 result
    assert(modulo(0, 12) == 0); //test for 0
    assert(modulo(82, 5) == 2);
    assert(modulo(165, 7) == 4);

    assert( occurrences( 567, 2 ) ==  0 );
    assert( occurrences( 128874, 2 ) == 1 );
    assert( occurrences( 212121, 2 ) == 3 );
    
    assert( occurrences( 3333, 5 ) ==  0); //test for no occurrences
    assert( occurrences( 1111, 1 ) == 4 ); //test if every number is an occurrence
    assert( occurrences( 136696, 6 ) == 3);

    assert( lucky7s( "cs32" ) == "cs32" );
    assert( lucky7s( "Apple Baseball" ) == "Ap77ple Basebal77l" );
    assert( lucky7s( "abbba" ) == "ab77b77ba" );
    
    assert( lucky7s( "ss" ) == "s77s" ); //only two letter string w/ matching chars
    assert( lucky7s( "sss" ) == "s77s77s" ); //3 repeating letters

    int array[ 5 ] = { 2, 4, 6, 8, 10 };
    assert( combinations( array, 5, 10 ) == true );
    assert( combinations( array, 5, 18 ) == true );
    assert( combinations( array, 5, 15 ) == false );
    
    int array2[ 3 ] = { 1,3,5 }; //test with different array
    assert( combinations( array2, 3, 8 ) == true );
    assert( combinations( array2, 3, 6 ) == true );
    assert( combinations( array2, 3, 4 ) == true );
    assert( combinations( array2, 3, 9 ) == true ); //total of all numbers
    assert( combinations( array2, 3, 15 ) == false );
    assert( combinations( array2, 3, 1 ) == true ); //target is only one number

    int array3[ 3 ] = { 1,0,5 }; //test with different array w/ 0
    assert( combinations( array3, 3, 1 ) == true );
    assert( combinations( array3, 3, 5 ) == true );
    assert( combinations( array3, 3, 6 ) == true );
    assert( combinations( array3, 3, 0 ) == true );
    
    cout << "all tests passed!" << endl;
    return( 0 );
  }
