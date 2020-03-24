#ifndef SCENE_BOX_H
#define SCENE_BOX_H

// External includes
#include <vector>

// Internal includes
#include "scene.h"
#include "narrative_thread.h"

// Forward Declarations


class Scene_box
{

private:
    // Identifier for Scene_box, should not be changed
    std::string _id;
    // The Scene to be accessed from this Scene_box
    Scene* _scene;

public:
    explicit Scene_box();
    explicit Scene_box(std::string);

    // GETTERS
    std::string get_id() const;
    Scene* get_scene() const;

    // SETTERS
    void set_id(std::string);
    void set_scene(Scene*);

    void show();
};

#endif