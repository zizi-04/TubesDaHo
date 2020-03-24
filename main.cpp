#include <iostream>
#include "Car.hpp"
#include <cmath>
#include <math.h>
#define PI 3.14159265
using namespace std;


//Public Class : Position

//Constructor

Position::Position() {

    x=0;
    y=0;
    orientation=0;
}

Position::Position(double x, double y, double theta) {
    double theta;
    this -> x=x;
    this -> y=y;
    theta = orientation;
}
//Setter
void Position::setX(double x) {this -> x=x;}
void Position::setX(double y) {this -> y=y;}
void Position::setOrientation(double orientation){this -> orientation=orientation;}

//Getter
double Position::getX(){return x;}
double Position::getY(){return y;}
double Position::getOrientation(){return orientation;}

//Methods Lain
double Position::euclideanDistance(double x1, double y1, double x2, double y2) {
    //Deklarasi
    this -> x=x1;
    this -> x=x2;
    this -> y=y1;
    this -> y=y2;
    //Rumus cari jarak (pythagoras)
    return sqrt(pow((y1-y),2)+pow((x1-x),2));
}
void Position::printPosition(){
    cout<<"X : "<< getX() <<" m"<< endl << "Y : "<< getY() << " m" << endl <<"Orientation : " << getOrientation() <<" degree(s)"<< endl;
}

//Public Class: Car

//Constructor
Car::Car(double fuel, double max, double min) : maxSpeed(max), minSpeed(min) {
    this -> fuel = fuel;
    speed = 0;
    accel = 0;
    gear = 0;
    distanceTraveled = 0;
    gasOn = false;
    brakeOn = false;
}

//Getter
Position Car :: getPost() {return P;}
double Car::getSpeed() {return speed;}
void Car::changeGear(int val) {gear=val;}

//Methods Lain
void Car::applyPedal(double pressureLevel) {
    
    gasOn = true;
    if (fuel > 0) {
        accel = ( pressureLevel * pedalConst * gear );
    }
    else {
        On = false;
    }
    
}

void Car::applyBrake(double pressureLevel){
    
    brakeOn=true;
    if (On && speed > 0.001 && speed < -0.001) {
        accel = (pressureLevel * brakeConst * (-1) * abs(speed)/speed) ;
    }
    else {
        accel = 0;
    }
}

void Car::start() {
    On = true;
}

void Car::stop() {
    On = false;
    gasOn = false;
    brakeOn = false;
    speed = 0;
    accel = 0;
}

void Car::speedControl() {
    if (gasOn = true) {
        if (minSpeed<speed<maxSpeed) {
            speed = (speed + accel);
        }
        else if (speed >= maxSpeed) {
            speed = maxSpeed;
        }
        else if (speed < 0) {
            speed = minSpeed;
        }
    }
    if (gasOn = false) {
        if (-0.001 <= speed <= maxSpeed) {
            speed = speed + accel;
        }
        else if (speed < -0.001 || speed > 0.001) {
            speed = 0;
        }
    }

}

void Car::fuelControl(double newDistance, double oldDistance) {
    fuel = fuel - (newDistance - oldDistance);
    if (fuel<0){
        fuel = 0;
    }
}

void Car::move(){
    double newDistance;
    //Speedcontrol
    speedControl();
    //Update X dan Y
    double x0;
    double y0;
    x0 = P.getX();
    P.setX(x0 + (speed*cos(P.getOrientation()* PI / 180.0)));
    y0 = P.getY();
    P.setY(y0 + (speed*sin(P.getOrientation()* PI / 180.0)) );
    //Fuelcontrol
    fuelControl(newDistance, distanceTraveled);
    //Update DistanceTravelled
    distanceTraveled = newDistance;
}
void Car::addFuel(double amount){
    fuel = (fuel + amount);
}

void Car::printCarStatus() {
    cout<<"---STATUS---"<< endl;
    cout<<"DistanceTraveled : " << distanceTraveled << endl;
    cout<< "fuelConsumptionConst: " << fuel << " ltr/m" << endl;
    cout<<"speed: " << speed << endl;
    cout<<"maxSpeed: " << maxSpeed << endl;
    cout<<"fuel: " <<fuel<< endl;
    cout<<"gear" << gear << endl;
}