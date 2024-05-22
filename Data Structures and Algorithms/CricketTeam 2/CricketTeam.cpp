//
//  CricketTeam.cpp
//  CricketTeam
//
//  Created by Cody Lejang on 7/19/23.
//

#include "CricketTeam.h"
#include <string>
#include <iostream>

CricketTeam::CricketTeam(){
    head=nullptr;
}

CricketTeam::CricketTeam(const CricketTeam& copy){
    if (copy.head == nullptr) {
         head = nullptr;
    }
    else {
        head = new Node;
        head->value = copy.head->value;
        head->firstName = copy.head->firstName;
        head->lastName = copy.head->lastName;
        head->next = nullptr;
        head->prev = nullptr;
        
        Node* newNode = head;
        Node* ogNode = copy.head;
        
        while (ogNode->next != nullptr) {
            newNode->next = new Node;
            newNode->next->value = ogNode->next->value;
            newNode->next->firstName = ogNode->next->firstName;
            newNode->next->lastName = ogNode->next->lastName;
            newNode->next->prev = newNode;
            newNode = newNode->next;
            ogNode = ogNode->next;
        }
        newNode->next = nullptr;
   
    }
}

CricketTeam::~CricketTeam(){ //destructor
     Node *p;
     p= head;
     while (p != nullptr){
        Node *n = p->next;
        delete p;
        p = n;
    }
}

const CricketTeam&CricketTeam:: operator=(const CricketTeam& copy){ //assignment operator
     if (&copy == this) { //check if lists are the same
          return *this;
     }
     
     //destruction
     Node* current = head;
         while (current != nullptr) {
             Node* next = current->next;
             delete current;
             current = next;
         }
         head = nullptr;
    
    //copy
    head = new Node;
    head->value = copy.head->value;
    head->firstName = copy.head->firstName;
    head->lastName = copy.head->lastName;
    head->next = nullptr;
    head->prev = nullptr;
    
    Node* newNode = head;
    Node* ogNode = copy.head;
    
    while (ogNode->next != nullptr) {
        newNode->next = new Node;
        newNode->next->value = ogNode->next->value;
        newNode->next->firstName = ogNode->next->firstName;
        newNode->next->lastName = ogNode->next->lastName;
        newNode->next->prev = newNode;
        newNode = newNode->next;
        ogNode = ogNode->next;
    }
    newNode->next = nullptr;
    
    return *this;
}

bool CricketTeam::noTeam() const{
    return (head==nullptr);
}

int CricketTeam::cricketerCount() const{
    Node *p;
    p = head;
    int count = 0;
    while (p != nullptr){
         count++;
         p = p->next;
    }
    return count;
}

bool CricketTeam::addCricketer(const std::string& firstName, const std::string& lastName, const CricketType& value){
    // case where person is already on list
    Node *p;
    p = head;
    while (p != nullptr){
        if (firstName == p->firstName && lastName == p->lastName){
            return false;
        }
        p = p->next;
    }
    
    // empty list case
    if (head == nullptr){
        Node *p;
        p = new Node;
        p->firstName = firstName;
        p->lastName = lastName;
        p->value = value;
        p->next = nullptr;
        p->prev = nullptr;
        head = p;
    }
    
    else {
        Node *i;
        i = head;
        Node* newCricket = new Node;
        newCricket->firstName = firstName;
        newCricket->lastName = lastName;
        newCricket->value = value;
        while (i != nullptr){
            
            if (i->lastName == lastName){ //same last name to first name comparison
                if (i->firstName > firstName){
                    
                    if (i->prev == nullptr){ // front check
                        head = newCricket;
                        i->prev = newCricket;
                        newCricket->prev = nullptr;
                        newCricket->next = i;
                        return true;
                    }
                    
                    i->prev->next = newCricket;
                    newCricket->prev = i->prev;
                    newCricket->next = i;
                    i->prev = newCricket;
                    return true;
                }
                else if (i->next == nullptr){ // end case
                    i->next = newCricket;
                    newCricket->next = nullptr;
                    newCricket->prev = i;

                    return true;
                }
            }
            
            else if (i->lastName > lastName){
                
                if (i->prev == nullptr){ // front check
                    head = newCricket;
                    i->prev = newCricket;
                    newCricket->prev = nullptr;
                    newCricket->next = i;
                    return true;
                }

                
                i->prev->next = newCricket;
                newCricket->prev = i->prev;
                newCricket->next = i;
                i->prev = newCricket;
                return true;
            }
            else if (i->next == nullptr){ // end case
                i->next = newCricket;
                newCricket->next = nullptr;
                newCricket->prev = i;

                return true;
            }
            i = i->next;
        }
    }
    return true;
}

    
bool CricketTeam::substituteCricketer(const std::string& firstName, const std::string& lastName, const CricketType & value){
    std::string fullName = firstName + lastName;
    
    Node* p = head;
    while (p != nullptr){
        if (p->firstName + p->lastName == fullName){
            p->value = value;
            return true;
        }
        p = p->next;
    }
    return false;
}

bool CricketTeam::addOrSubstitute(const std::string& firstName, const std::string& lastName, const CricketType& value){
    std::string fullName = firstName + lastName;
    
    Node* p = head;
    while (p != nullptr){
        if (p->firstName + p->lastName == fullName){
            p->value = value;
            return true;
        }
        p = p->next;
    }
    return addCricketer(firstName, lastName, value);
}

bool CricketTeam::releaseCricketer(const std::string& firstName, const std::string& lastName){
    std::string fullName = firstName + lastName;
    Node* p = head;
    while (p != nullptr) {
        if (p->firstName + p->lastName == fullName) {
            if (p->next == nullptr){ //nothing after
                p->prev->next = nullptr;
            }
            else if (p->prev == nullptr) { //nothing before
                head = p->next;
                p->next->prev = nullptr;
            }
            else { // middle
                p->prev->next = p->next;
                p->next->prev = p->prev;
            }
            delete p;
            return true;
        }
        p = p->next;
    }
    return false;
}

bool CricketTeam::rosteredOnCricketTeam(const std::string& firstName, const std::string& lastName) const{
    std::string fullName = firstName + lastName;
    Node* p = head;
    while (p != nullptr) {
        if (p->firstName + p->lastName == fullName) {
            return true;
        }
        p = p->next;
    }
    return false;
}

bool CricketTeam::searchForCricketer(const std::string& firstName, const std::string& lastName, CricketType& value) const{
    std::string fullName = firstName + lastName;
    Node* p = head;
    while (p != nullptr) {
        if (p->firstName + p->lastName == fullName) {
            value = p->value;
            return true;
        }
        p = p->next;
    }
    return false;
}

bool CricketTeam::checkTeamForCricketer(int i, std::string& firstName, std::string& lastName, CricketType & value) const{
    if (0 <= i && i < cricketerCount()){
        Node* p = head;
        for (int j = 1; j <= i; j++){
            p = p->next;
        }
        firstName = p->firstName;
        lastName = p->lastName;
        value = p->value;
        return true;
    }
    return false;
}

void CricketTeam::tradeCricketTeams(CricketTeam& other){
    Node* temp;
    temp = head;
    head = other.head;
    other.head = temp;
}

// non member

bool mergeCricketers(const CricketTeam & odOne, const CricketTeam & odTwo, CricketTeam & odJoined){
    bool status = true;
    std::string firstName;
    std::string lastName;
    CricketType value;
    for (int i = 0; i < odOne.cricketerCount(); i++) {
        odOne.checkTeamForCricketer(i, firstName, lastName, value);
        odJoined.addCricketer(firstName, lastName, value);
    }
    
    for (int i = 0; i < odTwo.cricketerCount(); i++) {
        odTwo.checkTeamForCricketer(i, firstName, lastName, value);
        if (odJoined.rosteredOnCricketTeam(firstName, lastName) == false){
            if (odJoined.checkTeamForCricketer(i, firstName, lastName, value)==false){
                status = false;
            }
            odJoined.addCricketer(firstName, lastName, value);
        }
    }
    return status;
}

void checkCricketers (const std::string& fsearch, const std::string& lsearch, const CricketTeam& odOne, CricketTeam& odResult){
    std::string firstName;
    std::string lastName;
    CricketType value;
    bool fmatch = false;
    bool lmatch = false;
    
    for (int i = 0; i < odOne.cricketerCount(); i++) {
        odOne.checkTeamForCricketer(i, firstName, lastName, value);
        if (fsearch == "*" || firstName == fsearch){
            fmatch = true;
        }
        if (lsearch == "*" || lastName == lsearch){
            lmatch = true;
        }
        if (fmatch == true && lmatch ==true){
            odResult.addCricketer(firstName, lastName, value);
        }
    }
}
