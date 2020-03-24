// External includes

// Internal includes
#include <action.h>

Action::Action(Character* emitter, std::string action){
    this->_emitter = emitter;
    this->_action = action;
}

Action::Action(Character* emitter, std::string action, Character* receiver){
    this->_emitter = emitter;
    this->_action = action;
    this->_receivers.push_back(receiver);
}

Action::Action(Character* emitter, std::string action, std::list<Character*> receivers){
    this->_emitter = emitter;
    this->_action = action;
    this->_receivers.insert(this->_receivers.end(), receivers.begin(), receivers.end());
}

Character* Action::get_emitter() const{
    return this->_emitter;
}