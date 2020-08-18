#include "Emoji.h"
#pragma once
class Face: public Emoji{
    protected:
        Circle circ;
    public:
        Face(Point c, int r):circ{c,r}{
            circ.set_fill_color(Color::yellow);
        };
        virtual void attach_to(Graph_lib::Window&) = 0;

};

class EmptyFace: public Face{
    protected:
        Circle leftE;
        Circle rightE;
        Circle leftP;
        Circle rightP;
    public:
        EmptyFace(int cx,int cy,int eyer, int r):Face{Point{cx,cy},r},leftE{{cx-25,cy-10},20},rightE{{cx+25,cy-10},20},leftP{{cx-20,cy-10},4},rightP{{cx+20,cy-10},4}{
            leftE.set_fill_color(Color::white);
            rightP.set_fill_color(Color::black);
            rightE.set_fill_color(Color::white);
            leftP.set_fill_color(Color::black);
        };
        void attach_to(Graph_lib::Window&) override;

};

class SmilingFace: public EmptyFace{
    protected:
        Arc smile;
    public:
        SmilingFace(int cx,int cy,int eyer, int r):EmptyFace{cx,cy,eyer,r},smile{{cx,cy+20},70,50,180,0}{
            smile.set_fill_color(Color::red);
            smile.set_color(Color::black);
        };
        void attach_to(Graph_lib::Window&)override;
    
};

class SadFace: public EmptyFace{
    protected:
        Arc smile;
    public:
        SadFace(int cx,int cy,int eyer, int r):EmptyFace{cx,cy,eyer,r},smile{{cx,cy+40},70,50,0,180}{
            smile.set_fill_color(Color::red);
            smile.set_color(Color::black);
        };
        void attach_to(Graph_lib::Window&)override;
    
};

class AngryFace: public SadFace{
    protected:
        Line rEB;
        Line lEB;
    public:
        AngryFace(int cx,int cy,int eyer, int r):SadFace{cx,cy,eyer,r},rEB{{cx-32,cy-44},{cx-7,cy-17}},lEB{{cx+32,cy-44},{cx+7,cy-17}}{
                rEB.set_color(Color::black);
                lEB.set_color(Color::black);
        };
        void attach_to(Graph_lib::Window&)override;
};

class WinkingFace: public EmptyFace{
    protected:
        Arc smile;
        Circle eyeRemover;
        Arc wink;
    public:
        WinkingFace(int cx,int cy,int eyer, int r):EmptyFace{cx,cy,eyer,r},smile{{cx,cy+20},70,50,180,0},eyeRemover{{cx+25,cy-10},21},wink{{cx+25,cy},30,10,0,150}{
            smile.set_fill_color(Color::red);
            smile.set_color(Color::black);
            eyeRemover.set_fill_color(Color::yellow);
            eyeRemover.set_color(Color::yellow);
            wink.set_fill_color(Color::black);
        };
        void attach_to(Graph_lib::Window&)override;

};

class SurprisedFace: public EmptyFace{
    protected:
        Ellipse oh;
    public:
        SurprisedFace(int cx,int cy,int eyer, int r):EmptyFace{cx,cy,eyer,r},oh{{cx,cy+30},17,20}{
            oh.set_fill_color(Color::dark_red);
            oh.set_color(Color::black);
        };
        void attach_to(Graph_lib::Window&)override;
};