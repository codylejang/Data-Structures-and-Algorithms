//
//  main.cpp
//  Blackjack 
//
//  Created by Howard Stahl on 6/6/23.
//

#include <iostream>
#include <cassert>
#include "Enums.h"
#include "Card.h"
#include "Hand.h"

using namespace std;
using namespace cs32;

int main() {
    Card c;

    
    
    Card c1;
    Card c2;
    Hand h( c1, c2);
    Card ace( Suit::CLUBS, Face::ACE );
    Card two( Suit::CLUBS, Face::DEUCE );
    Card three( Suit::CLUBS, Face::THREE );
    Card four( Suit::CLUBS, Face::FOUR );
    Card five( Suit::CLUBS, Face::FIVE );
    Card six( Suit::CLUBS, Face::SIX );
    Card seven( Suit::CLUBS, Face::SEVEN );
    Card eight( Suit::CLUBS, Face::EIGHT );
    Card nine( Suit::CLUBS, Face::NINE );
    Card ten( Suit::CLUBS, Face::TEN );
    Card jack( Suit::CLUBS, Face::JACK );
    Card queen( Suit::CLUBS, Face::QUEEN );
    Card king( Suit::CLUBS, Face::KING );
    
    //test suit setter
    assert(ace.getSuit() == Suit::CLUBS);
    ace.setSuit(Suit::DIAMONDS);
    assert(ace.getSuit() == Suit::DIAMONDS);
    
    // two aces...
    assert( h.evaluateHand(two) == Choice::SPLIT );
    assert(h.isSoft() == true); //test for ace in hand
    
    Hand h1( two, two ); //evaluate specific hand with 2 twos
    assert(h.isPair() == true); //test for pair function
    
    assert( h1.evaluateHand(two) == Choice::SPLITHIT );
    assert( h1.evaluateHand(three) == Choice::SPLITHIT );
    assert( h1.evaluateHand(four) == Choice::SPLIT );
    assert( h1.evaluateHand(five) == Choice::SPLIT );
    assert( h1.evaluateHand(six) == Choice::SPLIT );
    assert( h1.evaluateHand(seven) == Choice::SPLIT );
    assert( h1.evaluateHand(eight) == Choice::HIT );
    assert( h1.evaluateHand(nine) == Choice::HIT );
    assert( h1.evaluateHand(ten) == Choice::HIT );
    assert( h1.evaluateHand(jack) == Choice::HIT );
    assert( h1.evaluateHand(queen) == Choice::HIT );
    assert( h1.evaluateHand(king) == Choice::HIT );
    
    Hand h2( three, three ); //evaluate hand with 2 threes
    assert( h2.evaluateHand(two) == Choice::SPLITHIT );
    assert( h2.evaluateHand(three) == Choice::SPLITHIT );
    assert( h2.evaluateHand(four) == Choice::SPLIT );
    assert( h2.evaluateHand(five) == Choice::SPLIT );
    assert( h2.evaluateHand(six) == Choice::SPLIT );
    assert( h2.evaluateHand(seven) == Choice::SPLIT );
    assert( h2.evaluateHand(eight) == Choice::HIT );
    assert( h2.evaluateHand(nine) == Choice::HIT );
    assert( h2.evaluateHand(ten) == Choice::HIT );
    assert( h2.evaluateHand(jack) == Choice::HIT );
    assert( h2.evaluateHand(queen) == Choice::HIT );
    assert( h2.evaluateHand(king) == Choice::HIT );
    
    Hand h3( four, four ); //evaluate a hand with 2 fours
    assert( h3.evaluateHand(two) == Choice::HIT );
    assert( h3.evaluateHand(three) == Choice::HIT );
    assert( h3.evaluateHand(four) == Choice::HIT );
    assert( h3.evaluateHand(five) == Choice::SPLITHIT );
    assert( h3.evaluateHand(six) == Choice::SPLITHIT );
    assert( h3.evaluateHand(seven) == Choice::HIT );
    assert( h3.evaluateHand(eight) == Choice::HIT );
    assert( h3.evaluateHand(nine) == Choice::HIT );
    assert( h3.evaluateHand(ten) == Choice::HIT );
    assert( h3.evaluateHand(jack) == Choice::HIT );
    assert( h3.evaluateHand(queen) == Choice::HIT );
    assert( h3.evaluateHand(king) == Choice::HIT );
    
    Hand h4( ace, two ); //evaluate a hand with an ace
    assert( h4.evaluateHand(two) == Choice::HIT );
    assert( h4.evaluateHand(three) == Choice::HIT );
    assert( h4.evaluateHand(four) == Choice::HIT );
    assert( h4.evaluateHand(five) == Choice::DOUBLEHIT );
    assert( h4.evaluateHand(six) == Choice::DOUBLEHIT );
    assert( h4.evaluateHand(seven) == Choice::HIT );
    assert( h4.evaluateHand(eight) == Choice::HIT );
    assert( h4.evaluateHand(nine) == Choice::HIT );
    assert( h4.evaluateHand(ten) == Choice::HIT );
    assert( h4.evaluateHand(jack) == Choice::HIT );
    assert( h4.evaluateHand(queen) == Choice::HIT );
    assert( h4.evaluateHand(king) == Choice::HIT );
    
    Hand h42( two, ace ); //evaluate a hand with an ace and two reversed
    assert( h42.evaluateHand(two) == Choice::HIT );
    assert( h42.evaluateHand(three) == Choice::HIT );
    assert( h42.evaluateHand(four) == Choice::HIT );
    assert( h42.evaluateHand(five) == Choice::DOUBLEHIT );
    assert( h42.evaluateHand(six) == Choice::DOUBLEHIT );
    assert( h42.evaluateHand(seven) == Choice::HIT );
    assert( h42.evaluateHand(eight) == Choice::HIT );
    assert( h42.evaluateHand(nine) == Choice::HIT );
    assert( h42.evaluateHand(ten) == Choice::HIT );
    assert( h42.evaluateHand(jack) == Choice::HIT );
    assert( h42.evaluateHand(queen) == Choice::HIT );
    assert( h42.evaluateHand(king) == Choice::HIT );
    
    Hand h5( king, two ); //evaluate a hand with a royal
    assert( h5.evaluateHand(two) == Choice::HIT );
    assert( h5.evaluateHand(three) == Choice::HIT );
    assert( h5.evaluateHand(four) == Choice::STAND );
    assert( h5.evaluateHand(five) == Choice::STAND );
    assert( h5.evaluateHand(six) == Choice::STAND );
    assert( h5.evaluateHand(seven) == Choice::HIT );
    assert( h5.evaluateHand(eight) == Choice::HIT );
    assert( h5.evaluateHand(nine) == Choice::HIT );
    assert( h5.evaluateHand(ten) == Choice::HIT );
    assert( h5.evaluateHand(jack) == Choice::HIT );
    assert( h5.evaluateHand(queen) == Choice::HIT );
    assert( h5.evaluateHand(king) == Choice::HIT );
    
    Hand h6( six, ace ); //evaluate a hand with an ace as the second card
    assert( h6.evaluateHand(two) == Choice::HIT );
    assert( h6.evaluateHand(three) == Choice::DOUBLEHIT );
    assert( h6.evaluateHand(four) == Choice::DOUBLEHIT );
    assert( h6.evaluateHand(five) == Choice::DOUBLEHIT );
    assert( h6.evaluateHand(six) == Choice::DOUBLEHIT );
    assert( h6.evaluateHand(seven) == Choice::HIT );
    assert( h6.evaluateHand(eight) == Choice::HIT );
    assert( h6.evaluateHand(nine) == Choice::HIT );
    assert( h6.evaluateHand(ten) == Choice::HIT );
    assert( h6.evaluateHand(jack) == Choice::HIT );
    assert( h6.evaluateHand(queen) == Choice::HIT );
    assert( h6.evaluateHand(king) == Choice::HIT );
    
    Hand h7( five, three ); //evaluate a hand with 2 different numerical cards
    assert( h7.evaluateHand(two) == Choice::HIT );
    assert( h7.evaluateHand(three) == Choice::HIT );
    assert( h7.evaluateHand(four) == Choice::HIT );
    assert( h7.evaluateHand(five) == Choice::HIT );
    assert( h7.evaluateHand(six) == Choice::HIT );
    assert( h7.evaluateHand(seven) == Choice::HIT );
    assert( h7.evaluateHand(eight) == Choice::HIT );
    assert( h7.evaluateHand(nine) == Choice::HIT );
    assert( h7.evaluateHand(ten) == Choice::HIT );
    assert( h7.evaluateHand(jack) == Choice::HIT );
    assert( h7.evaluateHand(queen) == Choice::HIT );
    assert( h7.evaluateHand(king) == Choice::HIT );
    
    Hand h8( ten, ten ); //evaluate double 10
    assert( h8.evaluateHand(two) == Choice::STAND );
    assert( h8.evaluateHand(three) == Choice::STAND );
    assert( h8.evaluateHand(four) == Choice::STAND );
    assert( h8.evaluateHand(five) == Choice::STAND );
    assert( h8.evaluateHand(six) == Choice::STAND );
    assert( h8.evaluateHand(seven) == Choice::STAND );
    assert( h8.evaluateHand(eight) == Choice::STAND );
    assert( h8.evaluateHand(nine) == Choice::STAND );
    assert( h8.evaluateHand(ten) == Choice::STAND );
    assert( h8.evaluateHand(jack) == Choice::STAND );
    assert( h8.evaluateHand(queen) == Choice::STAND );
    assert( h8.evaluateHand(king) == Choice::STAND );
    cout << "All tests succeeded" << endl;
    return( 0 );
}
