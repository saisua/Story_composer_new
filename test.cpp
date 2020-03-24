// External includes
#include <iostream>
#include <stdlib.h>
#include <vector>


// Internal includes
#include "timeline.h"

// Forward Declarations
class Scene;

Scene* test_Timeline();
void test_Character(Scene*);

// main
int main(){
    Scene* next_test = test_Timeline();

    std::cout << "End of test_Timeline" << std::endl;

    test_Character(next_test);

    std::cout << "End of test_Character" << std::endl;

    return 0;
}

Scene* test_Timeline(){
    TimeLine test1 = TimeLine();

    // test on add rows
    std::cout << test1.size() << std::endl;
    test1.new_row();
    std::cout << test1.size() << std::endl << std::endl << std::endl;

    test1.set_last_row(0);
    std::vector<Scene_box*> row_test = test1.get_row(0);

    // test on row
    std::cout << test1.get_scenes_num() << std::endl;

    Scene_box* scene_test = test1.new_scene("whatev");

    std::cout << test1.get_scenes_num() << std::endl; 
    std::cout << row_test.size() << std::endl << std::endl;
    std::cout << test1.get_row(1).size() << std::endl;

    std::cout << scene_test->get_id() << std::endl;
    scene_test->set_id("It works!");
    std::cout << scene_test->get_id() << std::endl << std::endl;

    // test on remove rows
    std::cout << test1.size() << std::endl;
    test1.remove_row(0);
    std::cout << test1.size() << std::endl << std::endl << std::endl;

    Scene* scene = scene_test->get_scene();

    return scene;
}
void test_Character(Scene* scene){

    // Character setup
    Character* Ausias = new Character("Ausiàs");
    Ausias->set_name("Ausias");
    Ausias->set_alias("Alias"); 

    Character* Victor = new Character("Víctor");
    Victor->set_name("Victor");

    Character* Gerard = new Character("Gerard");
    Gerard->set_name("Gerard");

    Character* Aitana = new Character("Aitana");
    Aitana->set_name("Aitana");

    scene->add_character(Ausias);
    scene->add_characters(std::list<Character*>{Gerard,Aitana,Victor});

    // Place setup
    Place* Valencia = new Place("Valencia");
    Place* Benimaclet = new Place("Benimaclet", new Place("Amigo"));
    Valencia->add_place(Benimaclet);

    scene->add_place(Benimaclet->get_place("Amigo"));

    // Group setup
    Group* Printemps = new Group("Printemps", scene->get_characters());

    // Conversation setup
    Conversation* conver = new Conversation(Printemps->get_members());
    conver->message_says_to_all(Ausias, "Hola");
    conver->message_says_to(Victor, "Hola a tu també", Ausias);

    scene->add_conversation(conver);

    Character* Zoo = new Character("Zoo");

    // Group attr
    Printemps->add_relationship(new Relationship(Zoo, "odi"));
    Printemps->add_thought("Puto Zoo", Zoo);
    Printemps->add_members_relationship("amics");

    // Item setup
    Item* spaguetti_chuche = new Item("Spaguetti de chuche", Gerard);

    Gerard->give_item("Spaguetti de chuche", Aitana);

    std::cout << "0";

    Victor->say(Printemps, "Zoo mola");

    std::cout << "1";

    Aitana->remove_from_group(Victor, Printemps);

    std::cout << "2";

    Printemps->add_members_thought("Puto victor", Victor);

    std::cout << "3";

    Ausias->add_to_group(Victor, Printemps);

    std::cout << "4" << std::endl;
}