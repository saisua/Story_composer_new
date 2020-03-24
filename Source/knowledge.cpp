// External includes

// Internal includes
#include "group.h" // Includes knowledge.h and character.h

Knowledge::Knowledge(std::string id,
                    std::variant<Character*, Trait*, Message*, Conversation*, Place*, Relationship*, Item*, Group*> knowledge){
    this->_id = id;
    this->_knowledge = knowledge;
}

Knowledge::Knowledge(std::string id,
                    std::variant<Character*, Trait*, Message*, Conversation*, Place*, Relationship*, Item*, Group*> owner,
                    std::variant<Character*, Trait*, Message*, Conversation*, Place*, Relationship*, Item*, Group*> knowledge){
    this->_id = id;
    this->_from = owner;
    this->_towards = owner;
    this->_knowledge = knowledge;
}

Knowledge::Knowledge(std::string id,
                std::variant<Character*, Trait*, Message*, Conversation*, Place*, Relationship*, Item*, Group*> from,
                std::variant<Character*, Trait*, Message*, Conversation*, Place*, Relationship*, Item*, Group*> towards,
                std::variant<Character*, Trait*, Message*, Conversation*, Place*, Relationship*, Item*, Group*> knowledge){
    this->_id = id;
    this->_from = from;
    this->_towards = towards;
    this->_knowledge = knowledge;               
}

void Knowledge::share(Character* with_character){
    with_character->add_knowledge(this->_id, this); // Make deepcopy
}

void Knowledge::share(Group* with_group){
    with_group->add_members_knowledge(this->_id, this); // Make deepcopy
}

void Knowledge::share(Conversation* conversation){
    for(std::list<Character*>::iterator member = conversation->get_participants().begin(); member != conversation->get_participants().end();
                member++){
        (*member)->add_knowledge(this->_id, this); // Make deepcopy
    }
}

// // ADD
void Knowledge::add_trait(Trait* new_trait){
    this->_traits.push_back(new_trait);
}

// // GETTERS
std::string Knowledge::get_id() const{
    return this->_id;
}

std::variant<Character*, Trait*, Message*, Conversation*, Place*, Relationship*, Item*, Group*>
            Knowledge::get_from() const{
    return this->_from;
}
std::variant<Character*, Trait*, Message*, Conversation*, Place*, Relationship*, Item*, Group*>
            Knowledge::get_towards() const{
    return this->_towards;
}
std::variant<Character*, Trait*, Message*, Conversation*, Place*, Relationship*, Item*, Group*>
            Knowledge::get_knowledge() const{
    return this->_knowledge;
}

// // SETTERS
void Knowledge::set_from(std::variant<Character*, Trait*, Message*, Conversation*, Place*, Relationship*, Item*, Group*> new_from){
    this->_from = new_from;
}

void Knowledge::set_towards(std::variant<Character*, Trait*, Message*, Conversation*, Place*, Relationship*, Item*, Group*> new_towards){
    this->_towards = new_towards;
}

void Knowledge::set_knowledge(std::variant<Character*, Trait*, Message*, Conversation*, Place*, Relationship*, Item*, Group*> new_knowledge){
    this->_knowledge = new_knowledge;
}