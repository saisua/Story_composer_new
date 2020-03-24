#ifndef TIMELINE_H
#define TIMELINE_H

// External includes
#include <vector>
#include <string>

// Internal includes
#include "scene_box.h"

// Forward Declarations

class TimeLine
{
    int scenes_num = 0;
    std::vector<std::vector<Scene_box*>>* rows;

private:
    std::size_t _last_row;

public:
    explicit TimeLine();

    std::size_t size();

    // ADD
    Scene_box* new_scene();
    Scene_box* new_scene(std::string);
    void new_row();

    // REMOVE
    void remove_scene(Scene_box*);
    Scene_box* remove_scene(std::string);
    void remove_row(std::vector<Scene_box*>*);
    void remove_row(int);
    void remove_row(size_t);

    // GETTERS
    std::vector<Scene_box*> get_row(size_t) const;
    std::vector<Scene_box*> get_row(int) const;
    int get_scenes_num() const;

    // SETTERS
    void set_last_row(size_t);
    void set_last_row(int);

    void show();
};

#endif