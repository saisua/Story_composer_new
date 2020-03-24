// External includes
#include <iostream>

// Internal includes
#include "trait.h"
#include "group.h" // includes character.h and knowledge.h

Trait::Trait(Character* owner, std::string content){
    this->_owner = owner;
    this->_content = content;

    std::cout << "new " << owner->get_id() << "'s Trait (" << content << " )" << std::endl;
}

Trait::Trait(Group* owner, std::string content){
    this->_owner = owner;
    this->_content = content;

    std::cout << "new " << owner->get_id() << "'s Trait (" << content << " )" << std::endl;
}

Trait::Trait(Knowledge* owner, std::string content){
    this->_owner = owner;
    this->_content = content;

    std::cout << "new " << owner->get_id() << "'s Trait (" << content << " )" << std::endl;
}