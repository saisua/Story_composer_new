// External includes

// Internal includes
#include "narrative_thread.h"

Narrative_thread::Narrative_thread(std::string description){
    this->_description = description;
}

Narrative_thread::Narrative_thread(std::string description, Scene* final){
    this->_description = description;
    this->_final = final;
}