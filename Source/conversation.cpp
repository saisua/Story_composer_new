// External includes
#include <set>
#include <iostream>

// Internal includes
#include <conversation.h>

Conversation::Conversation(){
    this->_messages = std::vector<Message*>();
    this->_participants = std::list<Character*>();

    std::cout << "Created new conversation" << std::endl;
}

Conversation::Conversation(std::list<Character*> participants){
    this->_messages = std::vector<Message*>();
    this->_participants = participants;

    std::cout << "Created new conversation with " << participants.size() << " participants" << std::endl;
}

Conversation::Conversation(std::vector<Message*> messages){
    this->_messages = messages;
    this->_participants = std::list<Character*>();

    std::set<Character*> tmp_participants = std::set<Character*>();
    for(std::vector<Message*>::iterator sender = messages.begin(); sender != messages.end();
                sender++){
        tmp_participants.insert((*sender)->get_emitter());
    }

    for(std::set<Character*>::iterator participant = tmp_participants.begin();
                participant != tmp_participants.end(); participant++){
        this->_participants.emplace_back(*participant);
    }
}

Message* Conversation::message_says_to(Character* emitter, std::string content, 
                                    Character* intended_receiver){
    Message* message = new Message(emitter, content, intended_receiver);
    this->_messages.push_back(message);

    return message;
}

Message* Conversation::message_says_to_all(Character* emitter, std::string content){
    // Copy this->_paricipants
    std::list<Character*> participants_copy = std::list<Character*>();
    participants_copy.insert(participants_copy.begin(), this->_participants.begin(), this->_participants.end());

    Message* message = new Message(emitter, content, participants_copy);

    this->_messages.push_back(message);

    return message;
}

// // ADD

void Conversation::add_message(Message* new_message){
    this->_messages.emplace_back(new_message);
}

void Conversation::add_messages(std::vector<Message*> new_messages){
    this->_messages.insert(this->_messages.begin(), new_messages.begin(), new_messages.end());
}

void Conversation::add_participant(Character* new_participant){
    this->_participants.emplace_back(new_participant);
}

void Conversation::add_participants(std::vector<Character*> new_participants){
    this->_participants.insert(this->_participants.begin(), new_participants.begin(),
                                new_participants.end());
}

// // GETTERS
std::vector<Message*> Conversation::get_messages() const{
    return this->_messages;
}

std::list<Character*> Conversation::get_participants() const{
    return this->_participants;
}