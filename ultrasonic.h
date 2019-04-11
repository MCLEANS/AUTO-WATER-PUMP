#ifndef roboken_ultrasonic
#define roboken_ultrasonic
#include <Arduino.h>

class Ultrasonic {
  public:
    int trigPin;
    int echoPin;
    long duration;
    int distance;

    Ultrasonic(int trig, int echo);
    void initialize();
    int getDistance();

  private:
  protected:

};







#endif //roboken_ultrasonic
