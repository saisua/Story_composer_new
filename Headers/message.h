#ifndef MESSAGE_H
#define MESSAGE_H

// External includes
#include <list>
#include <string>

// Internal includes
#include "action.h"

// Forward Declarations
class Character;

class Message : public Action //Should it be child of action?
{
    // To send a Message is an action
    typedef Action super;

private:
    // What action is done (predefined to speak)
    std::string _action = "speak";
    // What's the content in the message
    std::string _content;

public:
    explicit Message(Character*, std::string, Character*); // From, content, receiver
    explicit Message(Character*, std::string, std::list<Character*>); // From, content, receivers

    // GETTERS
    std::string get_content() const;
};

#endif