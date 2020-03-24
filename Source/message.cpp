// External includes
#include <iostream>

// Internal includes
#include "message.h"
#include "character.h" // Only use cout

Message::Message(Character* emitter, std::string content, Character* receiver) : super(emitter, this->_action, receiver){
    this->_content = content;

    std::cout << "Created new Message from " << emitter->get_id() << " to " << receiver->get_id() << std::endl;
}

Message::Message(Character* emitter, std::string content, std::list<Character*> receivers) : super(emitter, this->_action, receivers){
    this->_content = content;

    std::cout << "Created new Message from " << emitter->get_id() << " to " << receivers.size() << " receivers" << std::endl;
}


// // GETTERS

std::string Message::get_content() const{
    return this->_content;
}