#include <EEPROM.h>
#include "Robot.h"
#include "Controllers/Display/DisplayController.h"
#include "Hardware/Config.h"
#include "logger.h"

/*
   (servo index, pin to attach pwm)
   __________ __________ _________________
  |(3,9)_____)(1,8)      (0,2)(______(2,3)|
  |__|       |left FRONT right|        |__|
             |                |
             |                |
             |                |
   _________ |                | __________
  |(7,7)_____)(5,6)______(4,4)(______(6,5)|
  |__|                                 |__|

*/
// comment below manually setting trim in MiniKame() constructor
#define __LOAD_TRIM_FROM_EEPROM__
#define EEPROM_MAGIC 0xabcd
#define EEPROM_OFFSET 2 // eeprom starting offset to store trim[]

;
Robot::Robot(unsigned long currentTime) : /* reverse{0, 0, 0, 0, 0, 0, 0, 0}, */
  currentTime(currentTime),
 trim{0, 0, 0, 0, 0, 0, 0, 0}
{
  this->displayController = new DisplayController(this, LED_MATRIX_DIN, LED_MATRIX_CLK, LED_MATRIX_CS, LED_MATRIX_FLIP_X);
  this->soundController = new SoundController(this, PIN_BUZZER);
  this->gestureController = new GestureController(this,
      FRONT_RIGHT_HIP_SERVO_PIN,
      FRONT_LEFT_HIP_SERVO_PIN,
      FRONT_RIGHT_LEG_SERVO_PIN,
      FRONT_LEFT_LEG_SERVO_PIN,
      BACK_RIGHT_HIP_SERVO_PIN,
      BACK_LEFT_HIP_SERVO_PIN,
      BACK_RIGHT_LEG_SERVO_PIN,
      BACK_LEFT_LEG_SERVO_PIN);

  this->displayActions = new DisplayActions(displayController);
  this->soundActions = new SoundActions(soundController);
}

DisplayActions *Robot::getDisplayActions()
{
  return displayActions;
}

SoundActions *Robot::getSoundActions()
{
  return soundActions;
}



void Robot::reverseServo(int id)
{
  if (reverse[id])
    reverse[id] = 0;
  else
    reverse[id] = 1;
}
void Robot::init(int Buzzer)
{
  // Buzzer & noise sensor pins:

  // Buzzer & noise sensor pins:
  pinBuzzer = Buzzer;
  // pinMode(NoiseSensor,INPUT);

  /*
     trim[] for calibrating servo deviation,
     initial posture (home) should like below
     in symmetric
        \       / front left
         \_____/
         |     |->
         |_____|->
         /     \
        /       \ front right
  */
  /*
    trim[FRONT_LEFT_HIP] = 0;
    trim[FRONT_RIGHT_HIP] = -8;
    trim[BACK_LEFT_HIP] = 8;
    trim[BACK_RIGHT_HIP] = 5;

    trim[FRONT_LEFT_LEG] = 2;
    trim[FRONT_RIGHT_LEG] = -6;
    trim[BACK_LEFT_LEG] = 6;
    trim[BACK_RIGHT_LEG] = 5;
  */
#ifdef __LOAD_TRIM_FROM_EEPROM__
  int val = EEPROMReadWord(0);
  if (val != EEPROM_MAGIC)
  {
    EEPROMWriteWord(0, EEPROM_MAGIC);
    storeTrim();
  }
#endif

  for (int i = 0; i < 8; i++)
  {
    //   servo[i].attach(board_pins[i]);

#ifdef __LOAD_TRIM_FROM_EEPROM__
    int val = EEPROMReadWord(i * 2 + EEPROM_OFFSET);
    if (val >= -90 && val <= 90)
    {
      trim[i] = val;
    }
#endif
  }

  home();
  us.init(12, 11);
}
void Robot::attachServo()
{
  //  for (int i = 0; i < 8; i++) {
  //   servo[i].attach(board_pins[i]);
  // }
}
void Robot::detachServo()
{
  for (int i = 0; i < 8; i++)
  {
    // servo[i].detach();
  }
}
void Robot::turnL(float steps, float T)
{
  if (getRestState() == true)
  {
    setRestState(false);
  }

  int x_amp = 15;
  int z_amp = 15;
  int ap = 15;
  // int hi = 23;
  int hi = 0;
  float period[] = {T, T, T, T, T, T, T, T};
  int amplitude[] = {x_amp, x_amp, z_amp, z_amp, x_amp, x_amp, z_amp, z_amp};
  int offset[] = {90 + ap, 90 - ap, 90 - hi, 90 + hi, 90 - ap, 90 + ap, 90 + hi, 90 - hi};
  int phase[] = {0, 180, 90, 90, 180, 0, 90, 90};

  execute(steps, period, amplitude, offset, phase);
}

void Robot::turnR(float steps, float T)
{
  if (getRestState() == true)
  {
    setRestState(false);
  }

  int x_amp = 15;
  int z_amp = 15;
  int ap = 15;
  int hi = 0;
  float period[] = {T, T, T, T, T, T, T, T};
  int amplitude[] = {x_amp, x_amp, z_amp, z_amp, x_amp, x_amp, z_amp, z_amp};
  int offset[] = {90 + ap, 90 - ap, 90 - hi, 90 + hi, 90 - ap, 90 + ap, 90 + hi, 90 - hi};
  int phase[] = {180, 0, 90, 90, 0, 180, 90, 90};

  execute(steps, period, amplitude, offset, phase);
}

void Robot::dance(float steps, float T)
{
  if (getRestState() == true)
  {
    setRestState(false);
  }
  digitalWrite(13, 0);
  int x_amp = 0;
  int z_amp = 40;
  int ap = 30;
  int hi = 0;
  float period[] = {T, T, T, T, T, T, T, T};
  int amplitude[] = {x_amp, x_amp, z_amp, z_amp, x_amp, x_amp, z_amp, z_amp};
  int offset[] = {90 + ap, 90 - ap, 90 - hi, 90 + hi, 90 - ap, 90 + ap, 90 + hi, 90 - hi};
  int phase[] = {0, 0, 0, 270, 0, 0, 90, 180};

  execute(steps, period, amplitude, offset, phase);
}

void Robot::frontBack(float steps, float T)
{
  if (getRestState() == true)
  {
    setRestState(false);
  }

  int x_amp = 30;
  int z_amp = 25;
  int ap = 20;
  int hi = 0;
  float period[] = {T, T, T, T, T, T, T, T};
  int amplitude[] = {x_amp, x_amp, z_amp, z_amp, x_amp, x_amp, z_amp, z_amp};
  int offset[] = {90 + ap, 90 - ap, 90 - hi, 90 + hi, 90 - ap, 90 + ap, 90 + hi, 90 - hi};
  int phase[] = {0, 180, 270, 90, 0, 180, 90, 270};

  execute(steps, period, amplitude, offset, phase);
}

void Robot::run(int dir, float steps, float T)
{

  setRestState(true);

  digitalWrite(13, 0);
  int x_amp = 15;
  int z_amp = 15;
  int ap = 15;
  int hi = 0;
  int front_x = 0;
  float period[] = {T, T, T, T, T, T, T, T};
  int amplitude[] = {x_amp, x_amp, z_amp, z_amp, x_amp, x_amp, z_amp, z_amp};
  int offset[] = {90 + ap - front_x,
                  90 - ap + front_x,
                  90 - hi,
                  90 + hi,
                  90 - ap - front_x,
                  90 + ap + front_x,
                  90 + hi,
                  90 - hi};
  int phase[] = {0, 0, 90, 90, 180, 180, 90, 90};
  if (dir == 1)
  {
    phase[0] = phase[1] = 180;
    phase[4] = phase[5] = 0;
  }
  execute(steps, period, amplitude, offset, phase);
  setRestState(false);
}

void Robot::omniWalk(bool side, float T, float turn_factor)
{
  if (getRestState() == true)
  {
    setRestState(false);
  }
  digitalWrite(13, 0);
  int x_amp = 15;
  int z_amp = 15;
  int ap = 15;
  int hi = 23;
  int front_x = 6 * (1 - pow(turn_factor, 2));
  float period[] = {T, T, T, T, T, T, T, T};
  int amplitude[] = {x_amp, x_amp, z_amp, z_amp, x_amp, x_amp, z_amp, z_amp};
  int offset[] = {90 + ap - front_x,
                  90 - ap + front_x,
                  90 - hi,
                  90 + hi,
                  90 - ap - front_x,
                  90 + ap + front_x,
                  90 + hi,
                  90 - hi};

  int phase[8];
  if (side)
  {
    int phase1[] = {0, 0, 90, 90, 180, 180, 90, 90};
    int phase2R[] = {0, 180, 90, 90, 180, 0, 90, 90};
    for (int i = 0; i < 8; i++)
      phase[i] = phase1[i] * (1 - turn_factor) + phase2R[i] * turn_factor;
  }
  else
  {
    int phase1[] = {0, 0, 90, 90, 180, 180, 90, 90};
    int phase2L[] = {180, 0, 90, 90, 0, 180, 90, 90};
    for (int i = 0; i < 8; i++)
      phase[i] = phase1[i] * (1 - turn_factor) + phase2L[i] * turn_factor; // + oscillator[i].getPhaseProgress();
  }

  execute(1, period, amplitude, offset, phase);
}

void Robot::moonwalkL(float steps, float T)
{
  if (getRestState() == true)
  {
    setRestState(false);
  }

  int z_amp = 45;
  float period[] = {T, T, T, T, T, T, T, T};
  int amplitude[] = {0, 0, z_amp, z_amp, 0, 0, z_amp, z_amp};
  int offset[] = {90, 90, 90, 90, 90, 90, 90, 90};
  int phase[] = {0, 0, 0, 120, 0, 0, 180, 290};

  execute(steps, period, amplitude, offset, phase);
}

void Robot::walk(int dir, float steps, float T)
{
  if (getRestState() == true)
  {
    setRestState(false);
  }

  int x_amp = 15;
  int z_amp = 20;
  int ap = 20;
  int hi = -10;
  float period[] = {T, T, T / 2, T / 2, T, T, T / 2, T / 2};
  int amplitude[] = {x_amp, x_amp, z_amp, z_amp, x_amp, x_amp, z_amp, z_amp};
  int offset[] = {90 + ap,
                  90 - ap,
                  90 - hi,
                  90 + hi,
                  90 - ap,
                  90 + ap,
                  90 + hi,
                  90 - hi};
  int phase[] = {270, 270, 270, 90, 90, 90, 90, 270};
  if (dir == 0)
  { // backward
    phase[0] = phase[1] = 90;
    phase[4] = phase[5] = 270;
  }
  for (int i = 0; i < 8; i++)
  {
    oscillator[i].reset();
    oscillator[i].setPeriod(period[i]);
    oscillator[i].setAmplitude(amplitude[i]);
    oscillator[i].setPhase(phase[i]);
    oscillator[i].setOffset(offset[i]);
    oscillator[i].start();
  }
  unsigned long _init_time = millis();
  unsigned long _now_time = _init_time;
  unsigned long _final_time = _init_time + period[0] * steps;
  bool side;

  while (_now_time < _final_time)
  {
    side = (int)((_now_time - _init_time) / (period[0] / 2)) % 2;

    setServo(0, oscillator[0].update()); // FRONT_RIGHT_HIP
    setServo(1, oscillator[1].update()); // FRONT_LEFT_HIP
    setServo(4, oscillator[4].update()); // BACK_RIGHT_HIP
    setServo(5, oscillator[5].update()); // BACK_LEFT_HIP

    if (side == 0)
    {
      setServo(3, oscillator[3].update()); // FRONT_LEFT_LEG
      setServo(6, oscillator[6].update()); // BACK_RIGHT_LEG
    }
    else
    {
      setServo(2, oscillator[2].update()); // FRONT_RIGHT_LEG
      setServo(7, oscillator[7].update()); // BACK_LEFT_LEG
    }
    pause(1);
    _now_time = millis();
  }
}

void Robot::upDown(float steps, float T)
{
  if (getRestState() == true)
  {
    setRestState(false);
  }

  int x_amp = 0;
  int z_amp = 35;
  int ap = 20;
  // int hi = 25;
  int hi = 0;
  int front_x = 0;
  float period[] = {T, T, T, T, T, T, T, T};
  int amplitude[] = {x_amp, x_amp, z_amp, z_amp, x_amp, x_amp, z_amp, z_amp};
  int offset[] = {90 + ap - front_x,
                  90 - ap + front_x,
                  90 - hi,
                  90 + hi,
                  90 - ap - front_x,
                  90 + ap + front_x,
                  90 + hi,
                  90 - hi};
  int phase[] = {0, 0, 90, 270, 180, 180, 270, 90};

  execute(steps, period, amplitude, offset, phase);
}

void Robot::pushUp(float steps, float T)
{
  if (getRestState() == true)
  {
    setRestState(false);
  }

  int z_amp = 40;
  int x_amp = 65;
  int hi = 0;
  float period[] = {T, T, T, T, T, T, T, T};
  int amplitude[] = {0, 0, z_amp, z_amp, 0, 0, 0, 0};
  int offset[] = {90, 90, 90 - hi, 90 + hi, 90 - x_amp, 90 + x_amp, 90 + hi, 90 - hi};
  int phase[] = {0, 0, 0, 180, 0, 0, 0, 180};

  execute(steps, period, amplitude, offset, phase);
}

void Robot::home()
{

  int ap = 20;
  int hi = 0;
  int position[] = {90 + ap, 90 - ap, 90 - hi, 90 + hi, 90 - ap, 90 + ap, 90 + hi, 90 - hi};
  for (int i = 0; i < 8; i++)
  {
    if (position[i] + trim[i] <= 180 && position[i] + trim[i] > 0)
    {
      oscillator[i].stop();
      setServo(i, position[i] + trim[i]);
    }
    isOttoResting = true;
  }
}

void Robot::waveHAND(float steps, float T)
{
  if (getRestState() == true)
  {
    setRestState(false);
  }

  int z_amp = 40;
  int x_amp = 65;
  int hi = 0;
  // (left front hip, right front hip, left front foot, right front foot,left rear hip, right rear hip, left rear foot, right rear foot)
  float period[] = {T, T, T, T, T, T, T, T};
  int amplitude[] = {0, 0, -20, 0, 0, 0, 0, 0};
  int offset[] = {90, 90, 30, 60 + hi, 90 - x_amp, 110 + x_amp, 90 + hi, 90 - hi};
  int phase[] = {0, 0, 0, 0, 0, 0, 0, 0};

  execute(steps, period, amplitude, offset, phase);
}

void Robot::Hide(float steps, float T)
{
  if (getRestState() == true)
  {
    setRestState(false);
  }

  int z_amp = 40;
  int x_amp = 65;
  int hi = 0;
  // 0 - 90 mid pos - 180
  // (left front hip, right front hip, left front foot, right front foot,left rear hip, right rear hip, left rear foot, right rear foot)
  float period[] = {T, T, T, T, T, T, T, T};
  int amplitude[] = {0, 0, 0, 0, 0, 0, 0, 0};
  int offset[] = {90, 90, 10, 170, 90, 90, 170, 10};
  int phase[] = {0, 0, 0, 0, 0, 0, 0, 0};

  execute(steps, period, amplitude, offset, phase);
}

void Robot::hello()
{
  float sentado[] = {90 + 15, 90 - 15, 90 - 65, 90 + 65, 90 + 20, 90 - 20, 90 + 10, 90 - 10};
  moveServos(150, sentado);
  pause(200);

  int z_amp = 40;
  int x_amp = 60;
  int T = 350;
  float period[] = {T, T, T, T, T, T, T, T};
  int amplitude[] = {0, 50, 0, 50, 0, 0, 0, 0};
  int offset[] = {
      90 + 15, 40,
      90 - 10, 90 + 10,
      90 + 20, 90 - 20,
      90 + 65, 90};

  int phase[] = {0, 0, 0, 90, 0, 0, 0, 0};

  execute(4, period, amplitude, offset, phase);

  float goingUp[] = {160, 20, 90, 90, 90 - 20, 90 + 20, 90 + 10, 90 - 10};
  moveServos(500, goingUp);
  pause(200);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Robot::jump()
{
  float sentado[] = {90 + 15, 90 - 15, 30, 150, 90 + 20, 90 - 20, 150, 30};

  int ap = 20;
  int hi = 35;
  float salto[] = {90 + ap, 90 - ap, 170, 10, 90 - ap * 3, 90 + ap * 3, 10, 170};
  // (left front hip, right front hip, left front foot, right front foot,left rear hip, right rear hip, left rear foot, right rear foot)
  moveServos(10, sentado);

  delay(1000);

  moveServos(1, salto);
  delay(100);

  home();
}
void Robot::scared()
{
  float sentado[] = {90 + 15, 90 - 15, 30, 150, 90 + 20, 90 - 20, 150, 30};

  int ap = 20;
  int hi = 35;
  float salto[] = {90 + ap, 90 - ap, 170, 10, 90 - ap * 3, 90 + ap * 3, 10, 170};
  moveServos(10, salto);

  delay(2000);

  moveServos(1, sentado);
  delay(100);

  home();
}

bool Robot::getRestState()
{

  return isOttoResting;
}

void Robot::setRestState(bool state)
{

  isOttoResting = state;
}

//////////////////////////////////////////////////////////////////////////////////////
void Robot::moveServos(int time, float target[8])
{
  if (getRestState() == true)
  {
    setRestState(false);
  }
  attachServo();
  float _increment[8];
  float _servo_position[8] = {90, 90, 90, 90, 90, 90, 90, 90};
  unsigned long _final_time;
  unsigned long _partial_time;
  if (time > 10)
  {
    for (int i = 0; i < 8; i++)
      _increment[i] = (target[i] - (_servo_position[i] + trim[i])) / (time / 10.0);
    _final_time = millis() + time;

    while (millis() < _final_time)
    {
      _partial_time = millis() + 10;
      for (int i = 0; i < 8; i++)
        setServo(i, (_servo_position[i] + trim[i]) + _increment[i]);
      // while (millis() < _partial_time); //pause
      pause(_partial_time);
    }
  }
  else
  {
    for (int i = 0; i < 8; i++)
      setServo(i, target[i]);
  }
  for (int i = 0; i < 8; i++)
    _servo_position[i] = target[i];
}

void Robot::setServo(int id, float target)
{
  attachServo();
  // if (!reverse[id])
  // servo[id].write(target + trim[id]);

  // else
  // servo[id].write(180 - (target + trim[id]));
}

void Robot::execute(float steps, float period[8], int amplitude[8], int offset[8], int phase[8])
{
  if (getRestState() == true)
  {
    setRestState(false);
  }
  attachServo();
  for (int i = 0; i < 8; i++)
  {
    oscillator[i].setPeriod(period[i]);
    oscillator[i].setAmplitude(amplitude[i]);
    oscillator[i].setPhase(phase[i]);
    oscillator[i].setOffset(offset[i]);
    oscillator[i].start();
    oscillator[i].setTime(millis());
  }
}

void Robot::update(unsigned long currentTime)
{
  this->currentTime = currentTime;
  // Update servos states
  this->gestureController->update();

  // Update LED matrix
  this->displayController->update();
  // Update sound controller
  this->soundController->update();
}

unsigned long Robot::getCurrentTime() {
    return currentTime;
}

void Robot::storeTrim()
{
  for (int i = 0; i < 8; i++)
  {
    EEPROMWriteWord(i * 2 + EEPROM_OFFSET, trim[i]);
    delay(100);
  }
}

// load/send only trim of hip servo
void Robot::loadTrim()
{
  // FRONT_LEFT/RIGHT_HIP
  for (int i = 0; i < 4; i++)
  {
    Serial.write(EEPROM.read(i + EEPROM_OFFSET));
  }

  // BACK_LEFT/RIGHT_HIP
  for (int i = 8; i < 12; i++)
  {
    Serial.write(EEPROM.read(i + EEPROM_OFFSET));
  }
}

int Robot::EEPROMReadWord(int p_address)
{
  byte lowByte = EEPROM.read(p_address);
  byte highByte = EEPROM.read(p_address + 1);

  return ((lowByte << 0) & 0xFF) + ((highByte << 8) & 0xFF00);
}

void Robot::EEPROMWriteWord(int p_address, int p_value)
{
  byte lowByte = ((p_value >> 0) & 0xFF);
  byte highByte = ((p_value >> 8) & 0xFF);

  EEPROM.write(p_address, lowByte);
  EEPROM.write(p_address + 1, highByte);
}

///////////////////////////////////////////////////////////////////
//-- SENSORS FUNCTIONS  -----------------------------------------//
///////////////////////////////////////////////////////////////////

//---------------------------------------------------------
//-- Otto getDistance: return Otto's ultrasonic sensor measure
//---------------------------------------------------------
float Robot::getDistance()
{

  return us.read();
}

//---------------------------------------------------------
//-- Otto getNoise: return Otto's noise sensor measure
//---------------------------------------------------------
int Robot::getNoise()
{

  int noiseLevel = 0;
  int noiseReadings = 0;
  int numReadings = 2;

  noiseLevel = analogRead(pinNoiseSensor);

  for (int i = 0; i < numReadings; i++)
  {
    noiseReadings += analogRead(pinNoiseSensor);
    delay(4); // delay in between reads for stability
  }

  noiseLevel = noiseReadings / numReadings;

  return noiseLevel;
}
//---------------------------------------------------------
//-- Otto getBatteryLevel: return battery voltage percent
//---------------------------------------------------------
double Robot::getBatteryLevel()
{

  // The first read of the batery is often a wrong reading, so we will discard this value.
  double batteryLevel = battery.readBatPercent();
  double batteryReadings = 0;
  int numReadings = 10;

  for (int i = 0; i < numReadings; i++)
  {
    batteryReadings += battery.readBatPercent();
    delay(1); // delay in between reads for stability
  }

  batteryLevel = batteryReadings / numReadings;

  return batteryLevel;
}

double Robot::getBatteryVoltage()
{

  // The first read of the batery is often a wrong reading, so we will discard this value.
  double batteryLevel = battery.readBatVoltage();
  double batteryReadings = 0;
  int numReadings = 10;

  for (int i = 0; i < numReadings; i++)
  {
    batteryReadings += battery.readBatVoltage();
    delay(1); // delay in between reads for stability
  }

  batteryLevel = batteryReadings / numReadings;

  return batteryLevel;
}

///////////////////////////////////////////////////////////////////
//-- SOUNDS -----------------------------------------------------//
///////////////////////////////////////////////////////////////////

void Robot::_tone(float noteFrequency, long noteDuration, int silentDuration)
{

  // tone(10,261,500);
  // delay(500);

  if (silentDuration == 0)
  {
    silentDuration = 1;
  }

  TimerFreeTone(Robot::pinBuzzer, noteFrequency, noteDuration);
  // delay(noteDuration);       //REMOVED FOR TimerFreeTone, PUT BACK for TONE       milliseconds to microseconds
  // noTone(PIN_Buzzer);

  // delay(silentDuration);     //REMOVED FOR TimerFreeTone, PUT BACK for TONE
}

void Robot::bendTones(float initFrequency, float finalFrequency, float prop, long noteDuration, int silentDuration)
{

  // Examples:
  //   bendTones (880, 2093, 1.02, 18, 1);
  //   bendTones (NOTE_A5, NOTE_C7, 1.02, 18, 0);

  if (silentDuration == 0)
  {
    silentDuration = 1;
  }

  if (initFrequency < finalFrequency)
  {
    for (int i = initFrequency; i < finalFrequency; i = i * prop)
    {
      _tone(i, noteDuration, silentDuration);
    }
  }
  else
  {

    for (int i = initFrequency; i > finalFrequency; i = i / prop)
    {
      _tone(i, noteDuration, silentDuration);
    }
  }
}

///////////////////////////////////////////////////////////////////
//-- GESTURES ---------------------------------------------------//
///////////////////////////////////////////////////////////////////

// void Robot::playGesture(int gesture){

// int sadPos[4]=      {110, 70, 20, 160};
// int bedPos[4]=      {100, 80, 60, 120};
// int fartPos_1[4]=   {90, 90, 145, 122}; //rightBend
// int fartPos_2[4]=   {90, 90, 80, 122};
// int fartPos_3[4]=   {90, 90, 145, 80};
// int confusedPos[4]= {110, 70, 90, 90};
// int angryPos[4]=    {90, 90, 70, 110};
// int headLeft[4]=    {110, 110, 90, 90};
// int headRight[4]=   {70, 70, 90, 90};
// int fretfulPos[4]=  {90, 90, 90, 110};
// int bendPos_1[4]=   {90, 90, 70, 35};
// int bendPos_2[4]=   {90, 90, 55, 35};
// int bendPos_3[4]=   {90, 90, 42, 35};
// int bendPos_4[4]=   {90, 90, 34, 35};

// switch(gesture){

//   case OttoHappy:
//       //_tone(NOTE_E5,50,30);
//       displayController->displayIcon(SMILE_ICON_INDEX);
//      // sing(S_happy_short);
//      // swing(1,800,20);
//      // sing(S_happy_short);

//       home();
//       displayController->displayIcon(HAPPY_OPEN_ICON_INDEX);
//   break;

//   case OttoSuperHappy:
//       displayController->displayIcon(HAPPY_OPEN_ICON_INDEX);
//       //sing(S_happy);
//       delay(500);
//       displayController->displayIcon(HAPPY_CLOSED_ICON_INDEX);
//      // tiptoeSwing(1,500,20);
//      delay(500);
//       displayController->displayIcon(HAPPY_OPEN_ICON_INDEX);
//      // sing(S_superHappy);
//      delay(500);
//       displayController->displayIcon(HAPPY_CLOSED_ICON_INDEX);
//      // tiptoeSwing(1,500,20);

//       home();
//       delay(1000);
//       displayController->displayIcon(HAPPY_OPEN_ICON_INDEX);
//   break;

//   case OttoSad:
//       displayController->displayIcon(SAD_ICON_INDEX);
//      // _moveServos(700, sadPos);
//      // bendTones(880, 830, 1.02, 20, 200);
//       displayController->displayIcon(SAD_CLOSED_ICON_INDEX);
//      // bendTones(830, 790, 1.02, 20, 200);
//       displayController->displayIcon(SAD_OPEN_ICON_INDEX);
//      // bendTones(790, 740, 1.02, 20, 200);
//       displayController->displayIcon(SAD_CLOSED_ICON_INDEX);
//      // bendTones(740, 700, 1.02, 20, 200);
//       displayController->displayIcon(SAD_OPEN_ICON_INDEX);
//       //bendTones(700, 669, 1.02, 20, 200);
//       displayController->displayIcon(SAD_ICON_INDEX);
//       delay(500);

//       home();
//       delay(1000);
//       displayController->displayIcon(HAPPY_OPEN_ICON_INDEX);
//   break;

//   case OttoLove:
//       displayController->displayIcon(HEART_ICON_INDEX);
//      // sing(S_cuddly);
//       //crusaito(2,1500,15,1);

//       home();
//      // sing(S_happy_short);
//      delay(500);
//      displayController->displayIcon(HAPPY_OPEN_ICON_INDEX);
//       delay(500);
//        displayController->displayIcon(HEART_ICON_INDEX);
//      // sing(S_cuddly);
//       //crusaito(2,1500,15,1);
//       home();
//      // sing(S_happy_short);
//       delay(1000);

//       displayController->displayIcon(HAPPY_OPEN_ICON_INDEX);
//   break;

// }
// }
