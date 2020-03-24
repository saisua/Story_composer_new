// External includes
#include <iostream>

// Internal includes
#include "thought.h"
#include "character.h" // Only use cout

Thought::Thought(Character* emitter, std::string content) : super(emitter, this->_action){
    this->_content = content;

    std::cout << "New thought from " << emitter->get_id() << " (" << content << ")" << std::endl;
}

Thought::Thought(Character* emitter, std::string content, Character* about) : super(emitter, this->_action, about){
    this->_content = content;

    std::cout << "New thought from " << emitter->get_id() << " about " << about->get_id() << " (" << content << ")" << std::endl;
}

Thought::Thought(Character* emitter, std::string content, std::list<Character*> about) : super(emitter, this->_action, about){
    this->_content = content;

    std::cout << "New thought from " << emitter->get_id() << " about " << about.size() << " characters (" << content << ")" << std::endl;
}