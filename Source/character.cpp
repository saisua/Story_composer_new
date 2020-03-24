// External includes
#include <iostream>

// Internal includes
#include "group.h" // includes character.h

// Forward declarations
std::string aux_message_id(std::size_t);
std::string aux_message_id(std::size_t, std::string);

Character::Character(std::string id){
    this->_id = id;

    std::forward_list<Trait*> _traits = std::forward_list<Trait*>(); // string or a separate object?
    std::forward_list<Relationship*> _relationships = std::forward_list<Relationship*>();
    std::forward_list<Thought*> _thoughts = std::forward_list<Thought*>();

    std::unordered_map<std::string, Knowledge> _knowledge = std::unordered_map<std::string, Knowledge>();

    std::vector<std::string> _images = std::vector<std::string>();

    std::cout << "Created new Character with id: " << id << std::endl;
}

void Character::give_item(Item* item, Character* receiver){ // Must update knowledge
    this->remove_item(item);
    this->_knowledge["Item_"+item->get_id()]->set_towards(receiver);
    receiver->add_item(item);

    std::cout << this->_id << " has given " << item->get_id() << " to " << receiver->get_id() << std::endl;
} 

void Character::give_item(std::string item_id, Character* receiver){ // Must update knowledge
    Item* item = this->remove_item(item_id);
    std::cout << "Yeah" << std::endl;
    std::cout << "Removed" << item->get_id() << std::endl;
    this->_knowledge["Item_"+item->get_id()]->set_towards(receiver);
    std::cout << "Acknowledged" << std::endl;
    receiver->add_item(item);
    std::cout << "Added" << std::endl;

    std::cout << this->_id << " has given " << item->get_id() << " to " << receiver->get_id() << std::endl;
}

void Character::receive_message(Message* message){
    std::string knowledge_id = aux_message_id(this->_knowledge.size());

    this->_knowledge[knowledge_id] = new Knowledge(knowledge_id, message);

    std::cout << this->_id << " has received the message \"" << message->get_content() << "\"" << std::endl;
}

void Character::receive_message(Message* message, Character* from){ // Must update knowledge
    std::string knowledge_id = aux_message_id(this->_knowledge.size(), from->get_id());

    this->_knowledge[knowledge_id] = new Knowledge(knowledge_id, from, message);

    std::cout << this->_id << " has received the message \"" << message->get_content() << "\" from " << from->get_id() << std::endl;
}

Message* Character::say(Character* to, std::string content){
    std::string knowledge_id = aux_message_id(this->_knowledge.size(), this->get_id());

    Message* message = new Message(this, content, to);
    this->_knowledge[knowledge_id] = new Knowledge(knowledge_id, this, to, message);

    to->receive_message(message, this);

    return message;
}

Message* Character::say(Group* group, std::string content){
    std::string knowledge_id = aux_message_id(this->_knowledge.size(), this->get_id());

    Message* message = group->receive_members_message(this, content);
    this->_knowledge[knowledge_id] = new Knowledge(knowledge_id, this, group, message);

    return message;
}

Message* Character::say(Group* group, std::string content, Character* to){
    std::string knowledge_id = aux_message_id(this->_knowledge.size(), this->get_id());

    Message* message = group->receive_members_message(this, content, to);
    this->_knowledge[knowledge_id] = new Knowledge(knowledge_id, this, to, message);

    return message;
}

Message* Character::say(Conversation* conversation, std::string content){
    std::string knowledge_id = aux_message_id(this->_knowledge.size(), this->get_id());

    Message* message = conversation->message_says_to_all(this, content);
    this->_knowledge[knowledge_id] = new Knowledge(knowledge_id, this, conversation, message);

    return message;
}

Message* Character::say(Conversation* conversation, std::string content, Character* to){
    std::string knowledge_id = aux_message_id(this->_knowledge.size(), this->get_id());

    Message* message = conversation->message_says_to(this, content, to);
    this->_knowledge[knowledge_id] = new Knowledge(knowledge_id, this, to, message);

    return message;
}

Message* Character::say_anonymous(Character* to, std::string content){
    std::string knowledge_id = aux_message_id(this->_knowledge.size(), this->get_id());

    Message* message = new Message(this, content, to);
    Knowledge* knowledge = new Knowledge(knowledge_id, this, to, message);

    knowledge->add_trait(new Trait(knowledge, "Anonymous"));

    this->_knowledge[knowledge_id] = knowledge;

    to->receive_message(message);

    return message;
}

Message* Character::say_anonymous(Group* group, std::string content){
    std::string knowledge_id = aux_message_id(this->_knowledge.size(), this->get_id());

    Message* message = group->receive_members_message(this, content);
    Knowledge* knowledge = new Knowledge(knowledge_id, this, group, message);

    knowledge->add_trait(new Trait(knowledge, "Anonymous"));

    this->_knowledge[knowledge_id] = knowledge;

    return message;
}

Message* Character::say_anonymous(Group* group, std::string content, Character* to){
    std::string knowledge_id = aux_message_id(this->_knowledge.size(), this->get_id());

    Message* message = group->receive_members_message(this, content, to);
    Knowledge* knowledge = new Knowledge(knowledge_id, this, to, message);

    knowledge->add_trait(new Trait(knowledge, "Anonymous"));

    this->_knowledge[knowledge_id] = knowledge;

    return message;
}

// // ADD
void Character::add_item(Item* new_item){ // Must add knowledge
    this->_inventory.push_front(new_item);
}

void Character::add_items(std::forward_list<Item*> new_items){
    this->_inventory.splice_after(this->_inventory.before_begin(), new_items);
}

void Character::add_trait(Trait* new_trait){
    this->_traits.push_front(new_trait);
}

void Character::add_traits(std::forward_list<Trait*> new_traits){
    this->_traits.splice_after(this->_traits.before_begin(), new_traits);
}

void Character::add_relationship(Relationship* new_relationship){
    this->_relationships.push_front(new_relationship);
}

void Character::add_relationships(std::forward_list<Relationship*> new_relationships){
    this->_relationships.splice_after(this->_relationships.before_begin(), new_relationships);
}

void Character::add_thought(Thought* new_thought){
    this->_thoughts.push_front(new_thought);
}

void Character::add_thought(std::string content){
    this->_thoughts.push_front(new Thought(this, content));
}

void Character::add_thought(std::string content, Character* receiver){
    this->_thoughts.push_front(new Thought(this, content, receiver));
}

void Character::add_thought(std::string content, std::list<Character*> receivers){
    this->_thoughts.push_front(new Thought(this, content, receivers));
}

void Character::add_thoughts(std::forward_list<Thought*> new_thoughts){
    this->_thoughts.splice_after(this->_thoughts.before_begin(), new_thoughts);
}

void Character::add_knowledge(std::string key, Knowledge* new_knowledege){
    this->_knowledge[key] = new_knowledege;
}

void Character::add_knowledge(std::unordered_map<std::string, Knowledge*> new_knowledge){
    this->_knowledge.insert(new_knowledge.begin(), new_knowledge.end());
}

void Character::add_to_group(Character* to_add, Group* group){
    if(group->has_member(this)){
        group->add_member(to_add);
    }
}


// // REMOVE

void Character::remove_self_group(Group* group){
    group->remove_member(this);
}

void Character::remove_from_group(Character* to_remove, Group* group){
    group->remove_member(this, to_remove);
}

void Character::remove_item(Item* to_remove){
    this->_inventory.remove(to_remove);
}

Item* Character::remove_item(std::string item_id){
    std::cout << "Character::remove_item(" << item_id << ')' << std::endl;
    for(std::forward_list<Item*>::iterator item = this->_inventory.begin(); item != this->_inventory.end();
                item++){
        std::cout << "Found Item " << (*item)->get_id() << std::endl;
        if((*item)->get_id() == item_id){
            std::cout << "Item was the one we were looking for" << std::endl;
            auto copy = item;
            Item* item_copy = *copy;
            this->_inventory.erase_after(item);

            std::cout << "Return" << std::endl;
            return item_copy;
        }
    }
}


// // GETTERS

std::string Character::get_id() const{
    return this->_id;
}

std::string Character::get_name() const{
    return this->_name;
}

std::string Character::get_alias() const{
    return this->_alias;
}


// // SETTERS

void Character::set_name(std::string new_name){
    this->_name = new_name;
}

void Character::set_alias(std::string new_alias){
    this->_alias = new_alias;
}

// // AUXILIAR STATIC

std::string aux_message_id(std::size_t uid_num){
    //return fmt::format("Message__{}", uid_num);
    return "";
}
std::string aux_message_id(std::size_t uid_num, std::string id){
    //return fmt::format("Message_{}_{}", id, uid_num);
    return "";
}