#pragma once

#include <Servo.h>
#include "Oscillator.h"
#include "US.h"
#include <BatReader.h>
#include "TimerFreeTone.h"
#include "Controllers/Display/DisplayController.h"
#include "Controllers/Gesture/KinematicController.h"
#include "Controllers/Sound/SoundController.h"
#include "Actions/Display/DisplayActions.h"
#include "Actions/Sound/SoundActions.h"
#include "Controllers/TimeProvider.h"

// Servo indexes
#define FRONT_RIGHT_HIP   0
#define FRONT_LEFT_HIP    1
#define FRONT_RIGHT_LEG   2
#define FRONT_LEFT_LEG    3
#define BACK_RIGHT_HIP    4
#define BACK_LEFT_HIP     5
#define BACK_RIGHT_LEG    6
#define BACK_LEFT_LEG     7


//#define PIN_Buzzer  13
#define PIN_Trigger 12
#define PIN_Echo    11




#define OttoHappy     0
#define OttoSuperHappy  1
#define OttoSad     2
#define OttoSleeping  3
#define OttoFart    4
#define OttoConfused  5
#define OttoLove    6
#define OttoAngry     7
#define OttoFretful   8
#define OttoMagic     9
#define OttoWave    10
#define OttoVictory   11
#define OttoFail    12

//*** MOUTH ANIMATIONS***
#define littleUuh   0
#define dreamMouth    1   
#define adivinawi   2
#define wave      3


//#define PIN_NoiseSensor A6
extern "C" void pause(int);

class Robot : public TimeProvider {
  private:
    // Controllers of physical parts
    DisplayController* displayController;
    SoundController* soundController;
    KinematicController* kinematicController;

    // Sets of actions that 
    DisplayActions* displayActions;
    SoundActions* soundActions; 


    Oscillator oscillator[8];
    // Servo servo[8];
    int board_pins[8];
    int trim[8]; //deviation servo offset
    //unsigned long _init_time;
    // unsigned long _final_time;
    bool isOttoResting;
    void execute(float steps, float period[8], int amplitude[8], int offset[8], int phase[8]);

    int EEPROMReadWord(int p_address);
    void EEPROMWriteWord(int p_address, int p_value);
        //-- Mouth & Animations
    bool reverse[8];
    unsigned long int getMouthShape(int number);
    unsigned long int getAnimShape(int anim, int index);
    US us;
    int pinBuzzer;
    int pinNoiseSensor;
    BatReader battery;
    unsigned long currentTime; // Variable to store the current time

  public:
    Robot(HAL *hal, unsigned long currentTime);

    DisplayActions *getDisplayActions();
    SoundActions* getSoundActions();

    KinematicController* getKinematicController();
    DisplayController* getDisplayController();
    SoundController* getSoundController();
    
    void init(int Buzzer);
    void home();
    void custom();


    // Display


        //-- Sensors functions
    float getDistance(); //US sensor
    int getNoise();      //Noise Sensor
    
    // Positioning
    void setupPosition();

    // Movements
    void walk2();


    //-- Battery
    double getBatteryLevel();
    double getBatteryVoltage();
    void run(int dir = 1, float steps = 4, float T = 550);
    void walk(int dir = 1, float steps = 4, float T = 550);
    void turnL(float steps = 1, float period = 550);
    void turnR(float steps = 1, float period = 550);
    void omniWalk(bool side = true, float T = 1000, float turn_factor = 2);
    void moonwalkL(float steps = 10, float period = 2000);
    void dance(float steps = 1, float period = 2000);
    void upDown(float steps = 1, float period = 500);
    void waveHAND(float steps = 1, float period = 700);
    void Hide(float steps = 1, float period = 700);
    void pushUp(float steps = 1, float period = 5000);
    void frontBack(float steps = 1, float period = 2000);
    void reverseServo(int id);
    void hello();
    void jump();
    void scared();
    void moveServos(int time, float target[8]);
    void setServo(int id, float target);
    void setTrim(int index, int value) {
      trim[index] = value;
    }
    bool getRestState();
    void setRestState(bool state);
    

    void update(unsigned long currentTime);
    void storeTrim();
    void loadTrim();
    

    //-- Gestures
    void playGesture(int gesture);
     void attachServo();
     void detachServo();
      //-- Sounds
    void _tone (float noteFrequency, long noteDuration, int silentDuration);
    void bendTones (float initFrequency, float finalFrequency, float prop, long noteDuration, int silentDuration);
    void sing(int songName);

    /**
     * @brief Retrieves the current time.
     * @return The current time as an unsigned long.
     */
    unsigned long getCurrentTime() override;
   
};
