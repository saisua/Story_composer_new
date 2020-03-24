// External includes
#include <iostream>

// Internal includes
#include "item.h"
#include "character.h"

Item::Item(){
    std::cout << "New Item" << std::endl;
}

Item::Item(std::string id){
    this->_id = id;

    std::cout << "New Item " << id << std::endl;
}

Item::Item(std::string id, Character* owner){
    this->_id = id;
    this->_owners.push_back(owner);

    owner->add_item(this);

    std::cout << "New Item " << id << " owned by " << owner->get_id() << std::endl;
}

Item::Item(std::string id, std::list<Character*> owners){
    this->_id = id;
    this->_owners.insert(this->_owners.end(), owners.begin(), owners.end());

    for(std::list<Character*>::iterator owner = owners.begin(); owner != owners.end();
                owner++){
        (*owner)->add_item(this);
    }

    std::cout << "New Item " << id << " owned by " << owners.size() << " Characters" << std::endl;
}


// // ADD

void Item::add_owner(Character* new_owner){
    this->_owners.push_back(new_owner);

    new_owner->add_item(this);
}

void Item::add_trait(Trait* new_trait){
    this->_traits.push_back(new_trait);
}


// // GETTERS

std::string Item::get_id() const{
    return this->_id;
}


// // SETTERS

void Item::set_id(std::string id){
    this->_id = id;
}

void Item::set_name(std::string name){
    this->_name = name;
}

void Item::set_owners(std::list<Character*> owners){
    this->_owners = owners;
}

void Item::set_traits(std::list<Trait*> traits){
    this->_traits = traits;
}