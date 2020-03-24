#ifndef NARRATIVE_THREAD_H
#define NARRATIVE_THREAD_H

// External includes
#include <string>

// Internal includes

// Forward Declarations
class Scene;

class Narrative_thread
{

private:
    std::string _description;

    Scene* _final;

public:
    explicit Narrative_thread(std::string);
    explicit Narrative_thread(std::string, Scene*);
};

#endif