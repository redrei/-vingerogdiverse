#include "cannonball.h"
double acclY(){
    return -9.81;
}

double velY(double initVelocityY,double time){
    return initVelocityY + acclY()*time;
}

double posX(double initPosition, double initVelocity, double time){
    return initPosition + initVelocity*time;
}

double posY(double initPosition, double initVelocity, double time){
    return initPosition + initVelocity*time + acclY()*time*time/2;
}

void printTime(double time){
    double sec = std::fmod(time,60);
    time -= sec;
    int min = std::fmod(time,3600)/60;
    time -= min;
    int h = time/3600;
    cout << h <<":"<<min<<":"<<sec << endl;
}

double flightTime(double initVelocityY){
    initVelocityY = fabs(initVelocityY);
    return -2*initVelocityY/acclY();
}

double getUserInputTheta(){
    cout << "skriv inn en vinkel i grader" << endl;
    double vinkel;
    cin >> vinkel;
    cout << endl;
    return vinkel;
}

double getUserInputAbsVelocity(){
    double fart;
    do{
        cout << "skriv inn absoluttfart" << endl;
        cin >> fart;
        cout << endl;
    }while(fart < 0);
    return fart;
}

double degToRad(double deg){
    return deg*(3.1416)/180;
}

double getVelocityX(double theta, double absVelocity){
    return absVelocity*cos(theta);
}

double getVelocityY(double theta, double absVelocity){
    return absVelocity*sin(theta);
}

vector<double> getVelocityVector(double theta, double absVelocity){
    vector<double> velvector{getVelocityX(theta,absVelocity),getVelocityY(theta,absVelocity)};
    return velvector;
}

double getDistanceTraveled(double velocityX, double velocityY){
    return flightTime(abs(velocityY))*velocityX;
}

double targetPractice(double distanceToTarget, double velocityX,double velocityY){
    return distanceToTarget-getDistanceTraveled(velocityX,velocityY);
}