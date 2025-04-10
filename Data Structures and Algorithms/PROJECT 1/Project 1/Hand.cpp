//
//  Hand.cpp
//  Blackjack 
//
//  Created by Howard Stahl on 6/6/23.
//

#include "Hand.h"

namespace cs32
{


Hand::Hand( Card card1, Card card2 ) : mCard1( card1 ), mCard2( card2 )
{
    
}

Card Hand::getCard1() const
{
    return( mCard1 );
}

Card Hand::getCard2() const
{
    return( mCard2 );
}

// TODO CS 32 students need to complete this operation
Choice Hand::evaluateHand( Card dealerCard ) const
{
    // by default STAND
    Choice c = Choice::STAND;
    Face face = dealerCard.getFace();
    
    Card Hand1 = getCard1();
    Card Hand2 = getCard2();
    
    int total = Hand1.getValue() + Hand2.getValue();
    
    //check pairs
    if (isPair()==true) {
        
        if (Hand1.getFace()==Face::DEUCE){ //two twos
            switch( face )
            {
                case Face::DEUCE:
                    c = Choice::SPLITHIT;
                    break;
                case Face::THREE:
                    c = Choice::SPLITHIT;
                    break;
                case Face::FOUR:
                    c = Choice::SPLIT;
                    break;
                case Face::FIVE:
                    c = Choice::SPLIT;
                    break;
                case Face::SIX:
                    c = Choice::SPLIT;
                    break;
                case Face::SEVEN:
                    c = Choice::SPLIT;
                    break;
                case Face::EIGHT:
                    c = Choice::HIT;
                    break;
                case Face::NINE:
                    c = Choice::HIT;
                    break;
                case Face::TEN:
                    c = Choice::HIT;
                    break;
                case Face::JACK:
                    c = Choice::HIT;
                    break;
                case Face::QUEEN:
                    c = Choice::HIT;
                    break;
                case Face::KING:
                    c = Choice::HIT;
                    break;
                case Face::ACE:
                    c = Choice::HIT;
                    break;
            }
        }
        if (Hand1.getFace()==Face::THREE){ //two threes
            switch( face )
            {
                case Face::DEUCE:
                    c = Choice::SPLITHIT;
                    break;
                case Face::THREE:
                    c = Choice::SPLITHIT;
                    break;
                case Face::FOUR:
                    c = Choice::SPLIT;
                    break;
                case Face::FIVE:
                    c = Choice::SPLIT;
                    break;
                case Face::SIX:
                    c = Choice::SPLIT;
                    break;
                case Face::SEVEN:
                    c = Choice::SPLIT;
                    break;
                case Face::EIGHT:
                    c = Choice::HIT;
                    break;
                case Face::NINE:
                    c = Choice::HIT;
                    break;
                case Face::TEN:
                    c = Choice::HIT;
                    break;
                case Face::JACK:
                    c = Choice::HIT;
                    break;
                case Face::QUEEN:
                    c = Choice::HIT;
                    break;
                case Face::KING:
                    c = Choice::HIT;
                    break;
                case Face::ACE:
                    c = Choice::HIT;
                    break;
            }
        }
        if (Hand1.getFace()==Face::FOUR){ //two fours
            switch( face )
            {
                case Face::DEUCE:
                    c = Choice::HIT;
                    break;
                case Face::THREE:
                    c = Choice::HIT;
                    break;
                case Face::FOUR:
                    c = Choice::HIT;
                    break;
                case Face::FIVE:
                    c = Choice::SPLITHIT;
                    break;
                case Face::SIX:
                    c = Choice::SPLITHIT;
                    break;
                case Face::SEVEN:
                    c = Choice::HIT;
                    break;
                case Face::EIGHT:
                    c = Choice::HIT;
                    break;
                case Face::NINE:
                    c = Choice::HIT;
                    break;
                case Face::TEN:
                    c = Choice::HIT;
                    break;
                case Face::JACK:
                    c = Choice::HIT;
                    break;
                case Face::QUEEN:
                    c = Choice::HIT;
                    break;
                case Face::KING:
                    c = Choice::HIT;
                    break;
                case Face::ACE:
                    c = Choice::HIT;
                    break;
            }
        }
        if (Hand1.getFace()==Face::FIVE){ //two fives
            switch( face )
            {
                case Face::DEUCE:
                    c = Choice::DOUBLEHIT;
                    break;
                case Face::THREE:
                    c = Choice::DOUBLEHIT;
                    break;
                case Face::FOUR:
                    c = Choice::DOUBLEHIT;
                    break;
                case Face::FIVE:
                    c = Choice::DOUBLEHIT;
                    break;
                case Face::SIX:
                    c = Choice::DOUBLEHIT;
                    break;
                case Face::SEVEN:
                    c = Choice::DOUBLEHIT;
                    break;
                case Face::EIGHT:
                    c = Choice::DOUBLEHIT;
                    break;
                case Face::NINE:
                    c = Choice::DOUBLEHIT;
                    break;
                case Face::TEN:
                    c = Choice::HIT;
                    break;
                case Face::JACK:
                    c = Choice::HIT;
                    break;
                case Face::QUEEN:
                    c = Choice::HIT;
                    break;
                case Face::KING:
                    c = Choice::HIT;
                    break;
                case Face::ACE:
                    c = Choice::HIT;
                    break;
            }
        }
        if (Hand1.getFace()==Face::SIX){ //two six
            switch( face )
            {
                case Face::DEUCE:
                    c = Choice::SPLITHIT;
                    break;
                case Face::THREE:
                    c = Choice::SPLIT;
                    break;
                case Face::FOUR:
                    c = Choice::SPLIT;
                    break;
                case Face::FIVE:
                    c = Choice::SPLIT;
                    break;
                case Face::SIX:
                    c = Choice::SPLIT;
                    break;
                case Face::SEVEN:
                    c = Choice::HIT;
                    break;
                case Face::EIGHT:
                    c = Choice::HIT;
                    break;
                case Face::NINE:
                    c = Choice::HIT;
                    break;
                case Face::TEN:
                    c = Choice::HIT;
                    break;
                case Face::JACK:
                    c = Choice::HIT;
                    break;
                case Face::QUEEN:
                    c = Choice::HIT;
                    break;
                case Face::KING:
                    c = Choice::HIT;
                    break;
                case Face::ACE:
                    c = Choice::HIT;
                    break;
            }
        }
        if (Hand1.getFace()==Face::SEVEN){ //two sevens
            switch( face )
            {
                case Face::DEUCE:
                    c = Choice::SPLIT;
                    break;
                case Face::THREE:
                    c = Choice::SPLIT;
                    break;
                case Face::FOUR:
                    c = Choice::SPLIT;
                    break;
                case Face::FIVE:
                    c = Choice::SPLIT;
                    break;
                case Face::SIX:
                    c = Choice::SPLIT;
                    break;
                case Face::SEVEN:
                    c = Choice::SPLIT;
                    break;
                case Face::EIGHT:
                    c = Choice::HIT;
                    break;
                case Face::NINE:
                    c = Choice::HIT;
                    break;
                case Face::TEN:
                    c = Choice::HIT;
                    break;
                case Face::JACK:
                    c = Choice::HIT;
                    break;
                case Face::QUEEN:
                    c = Choice::HIT;
                    break;
                case Face::KING:
                    c = Choice::HIT;
                    break;
                case Face::ACE:
                    c = Choice::HIT;
                    break;
            }
        }
        if (Hand1.getFace()==Face::EIGHT){ //two eight
            switch( face )
            {
                case Face::DEUCE:
                    c = Choice::SPLIT;
                    break;
                case Face::THREE:
                    c = Choice::SPLIT;
                    break;
                case Face::FOUR:
                    c = Choice::SPLIT;
                    break;
                case Face::FIVE:
                    c = Choice::SPLIT;
                    break;
                case Face::SIX:
                    c = Choice::SPLIT;
                    break;
                case Face::SEVEN:
                    c = Choice::SPLIT;
                    break;
                case Face::EIGHT:
                    c = Choice::SPLIT;
                    break;
                case Face::NINE:
                    c = Choice::SPLIT;
                    break;
                case Face::TEN:
                    c = Choice::SPLIT;
                    break;
                case Face::JACK:
                    c = Choice::SPLIT;
                    break;
                case Face::QUEEN:
                    c = Choice::SPLIT;
                    break;
                case Face::KING:
                    c = Choice::SPLIT;
                    break;
                case Face::ACE:
                    c = Choice::SPLIT;
                    break;
            }
        }
        if (Hand1.getFace()==Face::NINE){ //two nine
            switch( face )
            {
                case Face::DEUCE:
                    c = Choice::SPLIT;
                    break;
                case Face::THREE:
                    c = Choice::SPLIT;
                    break;
                case Face::FOUR:
                    c = Choice::SPLIT;
                    break;
                case Face::FIVE:
                    c = Choice::SPLIT;
                    break;
                case Face::SIX:
                    c = Choice::SPLIT;
                    break;
                case Face::SEVEN:
                    c = Choice::STAND;
                    break;
                case Face::EIGHT:
                    c = Choice::SPLIT;
                    break;
                case Face::NINE:
                    c = Choice::SPLIT;
                    break;
                case Face::TEN:
                    c = Choice::STAND;
                    break;
                case Face::JACK:
                    c = Choice::STAND;
                    break;
                case Face::QUEEN:
                    c = Choice::STAND;
                    break;
                case Face::KING:
                    c = Choice::STAND;
                    break;
                case Face::ACE:
                    c = Choice::STAND;
                    break;
            }
        }
        if (Hand1.getFace()==Face::TEN || Hand1.getFace()==Face::JACK || Hand1.getFace()==Face::QUEEN || Hand1.getFace()==Face::KING  ){ //two ten or royal
            switch( face )
            {
                case Face::DEUCE:
                    c = Choice::STAND;
                    break;
                case Face::THREE:
                    c = Choice::STAND;
                    break;
                case Face::FOUR:
                    c = Choice::STAND;
                    break;
                case Face::FIVE:
                    c = Choice::STAND;
                    break;
                case Face::SIX:
                    c = Choice::STAND;
                    break;
                case Face::SEVEN:
                    c = Choice::STAND;
                    break;
                case Face::EIGHT:
                    c = Choice::STAND;
                    break;
                case Face::NINE:
                    c = Choice::STAND;
                    break;
                case Face::TEN:
                    c = Choice::STAND;
                    break;
                case Face::JACK:
                    c = Choice::STAND;
                    break;
                case Face::QUEEN:
                    c = Choice::STAND;
                    break;
                case Face::KING:
                    c = Choice::STAND;
                    break;
                case Face::ACE:
                    c = Choice::STAND;
                    break;
            }
        }
        if (Hand1.getFace()==Face::ACE){ //two ace
            switch( face )
            {
                case Face::DEUCE:
                    c = Choice::SPLIT;
                    break;
                case Face::THREE:
                    c = Choice::SPLIT;
                    break;
                case Face::FOUR:
                    c = Choice::SPLIT;
                    break;
                case Face::FIVE:
                    c = Choice::SPLIT;
                    break;
                case Face::SIX:
                    c = Choice::SPLIT;
                    break;
                case Face::SEVEN:
                    c = Choice::SPLIT;
                    break;
                case Face::EIGHT:
                    c = Choice::SPLIT;
                    break;
                case Face::NINE:
                    c = Choice::SPLIT;
                    break;
                case Face::TEN:
                    c = Choice::SPLIT;
                    break;
                case Face::JACK:
                    c = Choice::SPLIT;
                    break;
                case Face::QUEEN:
                    c = Choice::SPLIT;
                    break;
                case Face::KING:
                    c = Choice::SPLIT;
                    break;
                case Face::ACE:
                    c = Choice::SPLIT;
                    break;
            }
        }
        
    }
    
    // check for soft hand
    else if (isSoft()==true) {
        if (Hand1.getFace()==Face::DEUCE || Hand2.getFace()==Face::DEUCE){ // two
            switch( face )
            {
                case Face::DEUCE:
                    c = Choice::HIT;
                    break;
                case Face::THREE:
                    c = Choice::HIT;
                    break;
                case Face::FOUR:
                    c = Choice::HIT;
                    break;
                case Face::FIVE:
                    c = Choice::DOUBLEHIT;
                    break;
                case Face::SIX:
                    c = Choice::DOUBLEHIT;
                    break;
                case Face::SEVEN:
                    c = Choice::HIT;
                    break;
                case Face::EIGHT:
                    c = Choice::HIT;
                    break;
                case Face::NINE:
                    c = Choice::HIT;
                    break;
                case Face::TEN:
                    c = Choice::HIT;
                    break;
                case Face::JACK:
                    c = Choice::HIT;
                    break;
                case Face::QUEEN:
                    c = Choice::HIT;
                    break;
                case Face::KING:
                    c = Choice::HIT;
                    break;
                case Face::ACE:
                    c = Choice::HIT;
                    break;
            }
        }
        if (Hand1.getFace()==Face::THREE || Hand2.getFace()==Face::THREE){ //three
            switch( face )
            {
                case Face::DEUCE:
                    c = Choice::HIT;
                    break;
                case Face::THREE:
                    c = Choice::HIT;
                    break;
                case Face::FOUR:
                    c = Choice::HIT;
                    break;
                case Face::FIVE:
                    c = Choice::DOUBLEHIT;
                    break;
                case Face::SIX:
                    c = Choice::DOUBLEHIT;
                    break;
                case Face::SEVEN:
                    c = Choice::HIT;
                    break;
                case Face::EIGHT:
                    c = Choice::HIT;
                    break;
                case Face::NINE:
                    c = Choice::HIT;
                    break;
                case Face::TEN:
                    c = Choice::HIT;
                    break;
                case Face::JACK:
                    c = Choice::HIT;
                    break;
                case Face::QUEEN:
                    c = Choice::HIT;
                    break;
                case Face::KING:
                    c = Choice::HIT;
                    break;
                case Face::ACE:
                    c = Choice::HIT;
                    break;
            }
        }
        if (Hand1.getFace()==Face::FOUR || Hand2.getFace()==Face::FOUR){ //four
            switch( face )
            {
                case Face::DEUCE:
                    c = Choice::HIT;
                    break;
                case Face::THREE:
                    c = Choice::HIT;
                    break;
                case Face::FOUR:
                    c = Choice::DOUBLEHIT;
                    break;
                case Face::FIVE:
                    c = Choice::DOUBLEHIT;
                    break;
                case Face::SIX:
                    c = Choice::DOUBLEHIT;
                    break;
                case Face::SEVEN:
                    c = Choice::HIT;
                    break;
                case Face::EIGHT:
                    c = Choice::HIT;
                    break;
                case Face::NINE:
                    c = Choice::HIT;
                    break;
                case Face::TEN:
                    c = Choice::HIT;
                    break;
                case Face::JACK:
                    c = Choice::HIT;
                    break;
                case Face::QUEEN:
                    c = Choice::HIT;
                    break;
                case Face::KING:
                    c = Choice::HIT;
                    break;
                case Face::ACE:
                    c = Choice::HIT;
                    break;
            }
        }
        if (Hand1.getFace()==Face::FIVE || Hand2.getFace()==Face::FIVE){ //five
            switch( face )
            {
                case Face::DEUCE:
                    c = Choice::HIT;
                    break;
                case Face::THREE:
                    c = Choice::HIT;
                    break;
                case Face::FOUR:
                    c = Choice::DOUBLEHIT;
                    break;
                case Face::FIVE:
                    c = Choice::DOUBLEHIT;
                    break;
                case Face::SIX:
                    c = Choice::DOUBLEHIT;
                    break;
                case Face::SEVEN:
                    c = Choice::HIT;
                    break;
                case Face::EIGHT:
                    c = Choice::HIT;
                    break;
                case Face::NINE:
                    c = Choice::HIT;
                    break;
                case Face::TEN:
                    c = Choice::HIT;
                    break;
                case Face::JACK:
                    c = Choice::HIT;
                    break;
                case Face::QUEEN:
                    c = Choice::HIT;
                    break;
                case Face::KING:
                    c = Choice::HIT;
                    break;
                case Face::ACE:
                    c = Choice::HIT;
                    break;
            }
        }
        if (Hand1.getFace()==Face::SIX || Hand2.getFace()==Face::SIX){ //six
            switch( face )
            {
                case Face::DEUCE:
                    c = Choice::HIT;
                    break;
                case Face::THREE:
                    c = Choice::DOUBLEHIT;
                    break;
                case Face::FOUR:
                    c = Choice::DOUBLEHIT;
                    break;
                case Face::FIVE:
                    c = Choice::DOUBLEHIT;
                    break;
                case Face::SIX:
                    c = Choice::DOUBLEHIT;
                    break;
                case Face::SEVEN:
                    c = Choice::HIT;
                    break;
                case Face::EIGHT:
                    c = Choice::HIT;
                    break;
                case Face::NINE:
                    c = Choice::HIT;
                    break;
                case Face::TEN:
                    c = Choice::HIT;
                    break;
                case Face::JACK:
                    c = Choice::HIT;
                    break;
                case Face::QUEEN:
                    c = Choice::HIT;
                    break;
                case Face::KING:
                    c = Choice::HIT;
                    break;
                case Face::ACE:
                    c = Choice::HIT;
                    break;
            }
        }
        if (Hand1.getFace()==Face::SEVEN || Hand2.getFace()==Face::SEVEN){ //seven
            switch( face )
            {
                case Face::DEUCE:
                    c = Choice::STAND;
                    break;
                case Face::THREE:
                    c = Choice::DOUBLESTAND;
                    break;
                case Face::FOUR:
                    c = Choice::DOUBLESTAND;
                    break;
                case Face::FIVE:
                    c = Choice::DOUBLESTAND;
                    break;
                case Face::SIX:
                    c = Choice::DOUBLESTAND;
                    break;
                case Face::SEVEN:
                    c = Choice::STAND;
                    break;
                case Face::EIGHT:
                    c = Choice::STAND;
                    break;
                case Face::NINE:
                    c = Choice::HIT;
                    break;
                case Face::TEN:
                    c = Choice::HIT;
                    break;
                case Face::JACK:
                    c = Choice::HIT;
                    break;
                case Face::QUEEN:
                    c = Choice::HIT;
                    break;
                case Face::KING:
                    c = Choice::HIT;
                    break;
                case Face::ACE:
                    c = Choice::HIT;
                    break;
            }
        }
        if (Hand1.getFace()==Face::EIGHT || Hand2.getFace()==Face::EIGHT){ //eight
            switch( face )
            {
                case Face::DEUCE:
                    c = Choice::STAND;
                    break;
                case Face::THREE:
                    c = Choice::STAND;
                    break;
                case Face::FOUR:
                    c = Choice::STAND;
                    break;
                case Face::FIVE:
                    c = Choice::STAND;
                    break;
                case Face::SIX:
                    c = Choice::STAND;
                    break;
                case Face::SEVEN:
                    c = Choice::STAND;
                    break;
                case Face::EIGHT:
                    c = Choice::STAND;
                    break;
                case Face::NINE:
                    c = Choice::STAND;
                    break;
                case Face::TEN:
                    c = Choice::STAND;
                    break;
                case Face::JACK:
                    c = Choice::STAND;
                    break;
                case Face::QUEEN:
                    c = Choice::STAND;
                    break;
                case Face::KING:
                    c = Choice::STAND;
                    break;
                case Face::ACE:
                    c = Choice::STAND;
                    break;
            }
        }
    }
    
    //use totals
    else {
        if (total == 8){
            switch( face )
            {
                case Face::DEUCE:
                    c = Choice::HIT;
                    break;
                case Face::THREE:
                    c = Choice::HIT;
                    break;
                case Face::FOUR:
                    c = Choice::HIT;
                    break;
                case Face::FIVE:
                    c = Choice::HIT;
                    break;
                case Face::SIX:
                    c = Choice::HIT;
                    break;
                case Face::SEVEN:
                    c = Choice::HIT;
                    break;
                case Face::EIGHT:
                    c = Choice::HIT;
                    break;
                case Face::NINE:
                    c = Choice::HIT;
                    break;
                case Face::TEN:
                    c = Choice::HIT;
                    break;
                case Face::JACK:
                    c = Choice::HIT;
                    break;
                case Face::QUEEN:
                    c = Choice::HIT;
                    break;
                case Face::KING:
                    c = Choice::HIT;
                    break;
                case Face::ACE:
                    c = Choice::HIT;
                    break;
            }
        }
        if (total == 9){
            switch( face )
            {
                case Face::DEUCE:
                    c = Choice::HIT;
                    break;
                case Face::THREE:
                    c = Choice::DOUBLEHIT;
                    break;
                case Face::FOUR:
                    c = Choice::DOUBLEHIT;
                    break;
                case Face::FIVE:
                    c = Choice::DOUBLEHIT;
                    break;
                case Face::SIX:
                    c = Choice::DOUBLEHIT;
                    break;
                case Face::SEVEN:
                    c = Choice::HIT;
                    break;
                case Face::EIGHT:
                    c = Choice::HIT;
                    break;
                case Face::NINE:
                    c = Choice::HIT;
                    break;
                case Face::TEN:
                    c = Choice::HIT;
                    break;
                case Face::JACK:
                    c = Choice::HIT;
                    break;
                case Face::QUEEN:
                    c = Choice::HIT;
                    break;
                case Face::KING:
                    c = Choice::HIT;
                    break;
                case Face::ACE:
                    c = Choice::HIT;
                    break;
            }
        }
        if (total == 10){
            switch( face )
            {
                case Face::DEUCE:
                    c = Choice::DOUBLEHIT;
                    break;
                case Face::THREE:
                    c = Choice::DOUBLEHIT;
                    break;
                case Face::FOUR:
                    c = Choice::DOUBLEHIT;
                    break;
                case Face::FIVE:
                    c = Choice::DOUBLEHIT;
                    break;
                case Face::SIX:
                    c = Choice::DOUBLEHIT;
                    break;
                case Face::SEVEN:
                    c = Choice::DOUBLEHIT;
                    break;
                case Face::EIGHT:
                    c = Choice::DOUBLEHIT;
                    break;
                case Face::NINE:
                    c = Choice::DOUBLEHIT;
                    break;
                case Face::TEN:
                    c = Choice::HIT;
                    break;
                case Face::JACK:
                    c = Choice::HIT;
                    break;
                case Face::QUEEN:
                    c = Choice::HIT;
                    break;
                case Face::KING:
                    c = Choice::HIT;
                    break;
                case Face::ACE:
                    c = Choice::HIT;
                    break;
            }
        }
        if (total == 11){
            switch( face )
            {
                case Face::DEUCE:
                    c = Choice::DOUBLEHIT;
                    break;
                case Face::THREE:
                    c = Choice::DOUBLEHIT;
                    break;
                case Face::FOUR:
                    c = Choice::DOUBLEHIT;
                    break;
                case Face::FIVE:
                    c = Choice::DOUBLEHIT;
                    break;
                case Face::SIX:
                    c = Choice::DOUBLEHIT;
                    break;
                case Face::SEVEN:
                    c = Choice::DOUBLEHIT;
                    break;
                case Face::EIGHT:
                    c = Choice::DOUBLEHIT;
                    break;
                case Face::NINE:
                    c = Choice::DOUBLEHIT;
                    break;
                case Face::TEN:
                    c = Choice::DOUBLEHIT;
                    break;
                case Face::JACK:
                    c = Choice::DOUBLEHIT;
                    break;
                case Face::QUEEN:
                    c = Choice::DOUBLEHIT;
                    break;
                case Face::KING:
                    c = Choice::DOUBLEHIT;
                    break;
                case Face::ACE:
                    c = Choice::DOUBLEHIT;
                    break;
            }
        }
        if (total == 12){
            switch( face )
            {
                case Face::DEUCE:
                    c = Choice::HIT;
                    break;
                case Face::THREE:
                    c = Choice::HIT;
                    break;
                case Face::FOUR:
                    c = Choice::STAND;
                    break;
                case Face::FIVE:
                    c = Choice::STAND;
                    break;
                case Face::SIX:
                    c = Choice::STAND;
                    break;
                case Face::SEVEN:
                    c = Choice::HIT;
                    break;
                case Face::EIGHT:
                    c = Choice::HIT;
                    break;
                case Face::NINE:
                    c = Choice::HIT;
                    break;
                case Face::TEN:
                    c = Choice::HIT;
                    break;
                case Face::JACK:
                    c = Choice::HIT;
                    break;
                case Face::QUEEN:
                    c = Choice::HIT;
                    break;
                case Face::KING:
                    c = Choice::HIT;
                    break;
                case Face::ACE:
                    c = Choice::HIT;
                    break;
            }
        }
        if (total == 13){
            switch( face )
            {
                case Face::DEUCE:
                    c = Choice::STAND;
                    break;
                case Face::THREE:
                    c = Choice::STAND;
                    break;
                case Face::FOUR:
                    c = Choice::STAND;
                    break;
                case Face::FIVE:
                    c = Choice::STAND;
                    break;
                case Face::SIX:
                    c = Choice::STAND;
                    break;
                case Face::SEVEN:
                    c = Choice::HIT;
                    break;
                case Face::EIGHT:
                    c = Choice::HIT;
                    break;
                case Face::NINE:
                    c = Choice::HIT;
                    break;
                case Face::TEN:
                    c = Choice::HIT;
                    break;
                case Face::JACK:
                    c = Choice::HIT;
                    break;
                case Face::QUEEN:
                    c = Choice::HIT;
                    break;
                case Face::KING:
                    c = Choice::HIT;
                    break;
                case Face::ACE:
                    c = Choice::HIT;
                    break;
            }
        }
        if (total == 14){
            switch( face )
            {
                case Face::DEUCE:
                    c = Choice::STAND;
                    break;
                case Face::THREE:
                    c = Choice::STAND;
                    break;
                case Face::FOUR:
                    c = Choice::STAND;
                    break;
                case Face::FIVE:
                    c = Choice::STAND;
                    break;
                case Face::SIX:
                    c = Choice::STAND;
                    break;
                case Face::SEVEN:
                    c = Choice::HIT;
                    break;
                case Face::EIGHT:
                    c = Choice::HIT;
                    break;
                case Face::NINE:
                    c = Choice::HIT;
                    break;
                case Face::TEN:
                    c = Choice::HIT;
                    break;
                case Face::JACK:
                    c = Choice::HIT;
                    break;
                case Face::QUEEN:
                    c = Choice::HIT;
                    break;
                case Face::KING:
                    c = Choice::HIT;
                    break;
                case Face::ACE:
                    c = Choice::HIT;
                    break;
            }
        }
        if (total == 15){
            switch( face )
            {
                case Face::DEUCE:
                    c = Choice::STAND;
                    break;
                case Face::THREE:
                    c = Choice::STAND;
                    break;
                case Face::FOUR:
                    c = Choice::STAND;
                    break;
                case Face::FIVE:
                    c = Choice::STAND;
                    break;
                case Face::SIX:
                    c = Choice::STAND;
                    break;
                case Face::SEVEN:
                    c = Choice::HIT;
                    break;
                case Face::EIGHT:
                    c = Choice::HIT;
                    break;
                case Face::NINE:
                    c = Choice::HIT;
                    break;
                case Face::TEN:
                    c = Choice::SURRENDERHIT;
                    break;
                case Face::JACK:
                    c = Choice::SURRENDERHIT;
                    break;
                case Face::QUEEN:
                    c = Choice::SURRENDERHIT;
                    break;
                case Face::KING:
                    c = Choice::SURRENDERHIT;
                    break;
                case Face::ACE:
                    c = Choice::HIT;
                    break;
            }
        }
        if (total == 16){
            switch( face )
            {
                case Face::DEUCE:
                    c = Choice::STAND;
                    break;
                case Face::THREE:
                    c = Choice::STAND;
                    break;
                case Face::FOUR:
                    c = Choice::STAND;
                    break;
                case Face::FIVE:
                    c = Choice::STAND;
                    break;
                case Face::SIX:
                    c = Choice::STAND;
                    break;
                case Face::SEVEN:
                    c = Choice::HIT;
                    break;
                case Face::EIGHT:
                    c = Choice::HIT;
                    break;
                case Face::NINE:
                    c = Choice::SURRENDERHIT;
                    break;
                case Face::TEN:
                    c = Choice::SURRENDERHIT;
                    break;
                case Face::JACK:
                    c = Choice::SURRENDERHIT;
                    break;
                case Face::QUEEN:
                    c = Choice::SURRENDERHIT;
                    break;
                case Face::KING:
                    c = Choice::SURRENDERHIT;
                    break;
                case Face::ACE:
                    c = Choice::SURRENDERHIT;
                    break;
            }
        }
        if (total == 17){
            switch( face )
            {
                case Face::DEUCE:
                    c = Choice::STAND;
                    break;
                case Face::THREE:
                    c = Choice::STAND;
                    break;
                case Face::FOUR:
                    c = Choice::STAND;
                    break;
                case Face::FIVE:
                    c = Choice::STAND;
                    break;
                case Face::SIX:
                    c = Choice::STAND;
                    break;
                case Face::SEVEN:
                    c = Choice::STAND;
                    break;
                case Face::EIGHT:
                    c = Choice::STAND;
                    break;
                case Face::NINE:
                    c = Choice::STAND;
                    break;
                case Face::TEN:
                    c = Choice::STAND;
                    break;
                case Face::JACK:
                    c = Choice::STAND;
                    break;
                case Face::QUEEN:
                    c = Choice::STAND;
                    break;
                case Face::KING:
                    c = Choice::STAND;
                    break;
                case Face::ACE:
                    c = Choice::STAND;
                    break;
            }
        }
    }
    
    return( c );
}

// TODO CS 32 students need to complete this operation
bool Hand::isPair() const
{
    if (mCard1.getValue() == mCard2.getValue()){
        return true;
    }
    return( false );
}

// TODO CS 32 students need to complete this operation
bool Hand::isSoft() const
{
    if (mCard1.getFace() == Face::ACE || mCard2.getFace() == Face::ACE){
        return true;
    }
    return( false );
}


}
