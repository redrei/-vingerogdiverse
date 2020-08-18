#include "Emojiis.h"

void Face::attach_to(Graph_lib::Window& win){
    win.attach(circ);
}

void EmptyFace::attach_to(Graph_lib::Window& win){
    Face::attach_to(win);
    win.attach(leftE);
    win.attach(rightE);
    win.attach(leftP);
    win.attach(rightP);
}

void SmilingFace::attach_to(Graph_lib::Window& win){
    EmptyFace::attach_to(win);
    smile.draw_lines();
    win.attach(smile);
}

void SadFace::attach_to(Graph_lib::Window& win){
    EmptyFace::attach_to(win);
    smile.draw_lines();
    win.attach(smile);
}

void AngryFace::attach_to(Graph_lib::Window& win){
    SadFace::attach_to(win);
    win.attach(rEB);
    win.attach(lEB);
}

void WinkingFace::attach_to(Graph_lib::Window& win){
    EmptyFace::attach_to(win);
    win.attach(eyeRemover);
    win.attach(wink);
    win.attach(smile);
}

void SurprisedFace::attach_to(Graph_lib::Window& win){
    EmptyFace::attach_to(win);
    win.attach(oh);
}