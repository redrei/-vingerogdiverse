//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

#include "cannonball.h"
#include "utilities.h"
#include "cannonball_viz.h"
//------------------------------------------------------------------------------'

// C++ programs start by executing the function main
void testDeviation(double compareOperand, double toOperand, double maxError, string name);
void playTargetPractice();

int main()
{
    cout << "I´ve got the ÆØÅ, you ain´t got the æøå" << endl;
    const double maxError = 0.0001;
    printTime(9800.213);
    for(double t=0;t<=5;t += 2.5){
        cout << acclY() << endl;
        cout << velY(25,t)<< endl;
        cout << posX(0,50,t) << endl;
        cout << posY(0,25,t) << endl;
    }

    srand(static_cast<unsigned int>(time(nullptr)));
    testDeviation(posX(0.0,50.0,5.0), 250.0, maxError, "posX(0.0,50.0,5.0)");
    testDeviation(posY(0.0,25.0,5.0), 2.375, maxError, "posY(0.0,25.0,5.0)");
    testDeviation(velY(25,5.0), -24.05, maxError,"velY(25,5.0");
    testDeviation(acclY(), -9.81, maxError, "acclY()");

    for(int i = 1; i <= 10000; i++){
        assert(randomWithLimits(0,i) <= i and randomWithLimits(0,i) >= 0);
    }
    playTargetPractice();
}



void testDeviation(double compareOperand, double toOperand, double maxError, string name){
    if(abs(compareOperand - toOperand) <= maxError){
        cout << name << " er tilnærmet lik " << toOperand << endl;
    }else{
        cout << name << " er ikke tilnærmet lik " << toOperand << endl;
    }
}

void playTargetPractice(){
    double target = randomWithLimits(100,1000);
    for(int i=10; i>0; i--){
        double theta = degToRad(getUserInputTheta());
        double absVel = getUserInputAbsVelocity();
        double distance = targetPractice(target,getVelocityX(theta,absVel),getVelocityY(theta,absVel));
        cout << -distance << "m fra målet"<< endl;
        cout << "tiden var ";
        printTime(flightTime(getVelocityY(theta,absVel)));
        cannonBallViz(target, 1000,getVelocityX(theta,absVel),getVelocityY(theta,absVel),20);
        if(abs(distance) < 5.0){
            cout << "Du vant!" << endl;
            return;
        }else{
            cout << "Fortsatt et stykke unna, prøv igjen." << endl << "Du har " << i-1 << " forsøk igjen." << endl;
        }
    }
    cout << "Du tapte... bedre lykke neste gang!";
}
//------------------------------------------------------------------------------
