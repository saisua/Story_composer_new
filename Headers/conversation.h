#ifndef CONVERSATION_H
#define CONVERSATION_H

// External includes
#include <vector>
#include <string>
#include <list>

// Internal includes
#include "message.h"

// Forward Declarations
class Character;

class Conversation{

private:
    std::vector<Message*> _messages;
    std::list<Character*> _participants;

public:
    explicit Conversation();
    explicit Conversation(std::list<Character*>);
    explicit Conversation(std::vector<Message*>);

    Message* message_says_to(Character*, std::string, Character*); // from, content, to
    Message* message_says_to_all(Character*, std::string); // from, content

    // ADD
    void add_message(Message*);
    void add_messages(std::vector<Message*>);
    void add_participant(Character*);
    void add_participants(std::vector<Character*>);

    // GETTERS
    std::vector<Message*> get_messages() const;
    std::list<Character*> get_participants() const;

};

#endif