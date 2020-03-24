// External includes
#include <iostream>

// Internal includes
#include "group.h"


Group::Group(std::string id) : super(id){
    this->_id = id;

    std::cout << "New Group " << id << std::endl;
}

Group::Group(std::string id, Character* member) : super(id){
    this->_id = id;
    this->_members.emplace_back(member);

    std::cout << "New Group " << id << " with " << member->get_id() << " as a member"<< std::endl;
}

Group::Group(std::string id, std::list<Character*> members) : super(id){
    this->_id = id;
    this->_members.insert(this->_members.begin(), members.begin(), members.end());

    std::cout << "New Group " << id << " with " << members.size() << " members"<< std::endl;
}


void Group::receive_members_message(Message* message){
    for(std::list<Character*>::iterator member = this->_members.begin(); member != this->_members.end();
                member++){
        (*member)->receive_message(message);
    }
}

void Group::receive_members_message(Message* message, Character* to){
    to->receive_message(message);
}

void Group::receive_members_message(Character* from, Message* message){

}

void Group::receive_members_message(Character* from, Message* message, Character* to){
    
}

Message* Group::receive_members_message(Character* from, std::string content){
    
}

Message* Group::receive_members_message(Character* from, std::string content, Character* to){

}


bool Group::has_member(Character* character) const{
    for(std::list<Character*>::const_iterator member = this->_members.begin(); member != this->_members.end();
                member++){
        if(*member == character){
            return true;
        }
    }
    return false;
}


// // ADD
void Group::add_member(Character* new_character){
    this->_members.emplace_back(new_character);
}

void Group::add_members(std::list<Character*> new_members){
    this->_members.insert(this->_members.begin(), new_members.begin(), new_members.end());
}

void Group::add_members_relationship(std::string type){
    for(std::list<Character*>::iterator member = this->_members.begin(); member != this->_members.end();
                member++){
        for(std::list<Character*>::iterator to = this->_members.begin(); to != this->_members.end();
                to++){
            (*member)->add_relationship(new Relationship((*to), type));
        }
    }     
}

void Group::add_members_relationship(Character* to, std::string type){
    for(std::list<Character*>::iterator member = this->_members.begin(); member != this->_members.end();
                member++){
        (*member)->add_relationship(new Relationship(to, type));
    }
}

void Group::add_members_thought(Thought* new_thought){
    for(std::list<Character*>::iterator member = this->_members.begin(); member != this->_members.end();
                member++){
        (*member)->add_thought(new_thought);
    }
}

void Group::add_members_thought(std::string content){
    for(std::list<Character*>::iterator member = this->_members.begin(); member != this->_members.end();
                member++){
        (*member)->add_thought(content);
    }
}

void Group::add_members_thought(std::string content, Character* receiver){
    for(std::list<Character*>::iterator member = this->_members.begin(); member != this->_members.end();
                member++){
        (*member)->add_thought(content, receiver);
    }
}

void Group::add_members_thought(std::string content, std::list<Character*> receivers){
    for(std::list<Character*>::iterator member = this->_members.begin(); member != this->_members.end();
                member++){
        (*member)->add_thought(content, receivers);
    }
}

void Group::add_members_knowledge(std::string id, Knowledge* knowledge){
    for(std::list<Character*>::iterator member = this->_members.begin(); member != this->_members.end();
                member++){
        (*member)->add_knowledge(id, knowledge);
    }
}

void Group::add_members_knowledge(std::unordered_map<std::string, Knowledge*> knowledge_dict){
    for(std::list<Character*>::iterator member = this->_members.begin(); member != this->_members.end();
                member++){
        (*member)->add_knowledge(knowledge_dict);
    }
}

// // REMOVE

Character* Group::remove_member(std::string to_remove){
    for(std::list<Character*>::iterator member = this->_members.begin(); member != this->_members.end();
                member++){
        if((*member)->get_id() == to_remove){
            this->_members.erase(member);
            return *member;
        }
    }
}

void Group::remove_member(Character* to_remove){
    this->_members.remove(to_remove);
}

Character* Group::remove_member(Character* expeller, std::string to_remove){ // Takes in accout members hierarchy
    bool expeller_is_higher = false;
    for(std::list<Character*>::iterator member = this->_members.begin(); member != this->_members.end();
                member++){
        if(*member == expeller) expeller_is_higher = true;
        if((*member)->get_id() == to_remove){
            if(expeller_is_higher){
                this->_members.erase(member);

                return *member;
            }

            return nullptr;
        }
    }
}


void Group::remove_member(Character* expeller, Character* to_remove){ // Takes in accout members hierarchy
    for(std::list<Character*>::iterator member = this->_members.begin(); member != this->_members.end();
                member++){
        if(*member == expeller){
            this->_members.remove(to_remove);
            return;
        }
        if((*member) == to_remove){
            return;
        }
    }
} 

// // GETTERS
Character* Group::get_member(std::string member_id) const{
    for(std::list<Character*>::const_iterator member = this->_members.begin(); member != this->_members.end();
                member++){
        if((*member)->get_id() == member_id){
            return *member;
        }
    }
}

std::list<Character*> Group::get_members() const{
    return this->_members;
}

// // SETTERS
void Group::set_members(std::list<Character*> members){
    this->_members = members;
}

