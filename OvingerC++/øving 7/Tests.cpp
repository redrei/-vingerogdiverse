#include "Tests.h"
void testAnimal(){
    Cat cat1{"Findus", 11};
    Cat cat2{"Karlson", 19};
    Cat cat3{"Blitzy", 8};

    Dog dog1{"Festus", 10};
    Dog dog2{"Frøya", 4};
    Dog dog3{"Sofus", 9};
    Dog dog4{"Jacob", 13};

    //Animal monster{"Godzilla", 250000000};

    cout << cat1.toString() << "; " << cat2.toString() << "; " << cat3.toString() << endl;
    cout << dog1.toString() << "; " << dog2.toString() << "; " << dog3.toString() << "; " << dog4.toString() << endl;
    //cout << monster.toString() << endl;
    Graph_lib::Vector_ref<Animal> animalRef{};
    animalRef.push_back(cat1);
    animalRef.push_back(cat2);
    animalRef.push_back(cat3);
    animalRef.push_back(dog1);
    animalRef.push_back(dog2);
    animalRef.push_back(dog3);
    animalRef.push_back(dog4);
    //animalRef.push_back(monster);

    for(auto i:animalRef){
        cout << i->toString() << endl;
    }
}