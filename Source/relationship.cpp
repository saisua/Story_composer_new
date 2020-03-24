// External include

// Internal include
#include <relationship.h>

Relationship::Relationship(){
    
}

Relationship::Relationship(std::variant<Character*, Item*, Trait*, Place*> other_party, std::string type){
    this->_other_party = other_party;
    this->_type = type;
}


// // SETTERS

void Relationship::set_other_party(std::variant<Character*, Item*, Trait*, Place*> other_party){
    this->_other_party = other_party;
}

void Relationship::set_type(std::string type){
    this->_type = type;
}

void Relationship::set_description(std::string description){
    this->_description = description;
}


// // GETTERS

std::variant<Character*, Item*, Trait*, Place*> Relationship::get_other_party() const{
    return this->_other_party;
}

std::string Relationship::get_type() const{
    return this->_type;
}

std::string Relationship::get_description() const{
    return this->_description;
}