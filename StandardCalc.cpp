//
// Created by TigerZhao on 2020-09-13.
//

#include "StandardCalc.h"
#include <cmath>

float StandardCalc::BoundTo180(float angle) {
  angle = fmod(angle, 360); // angle in interval (-360, 360)
  if (angle >= 180) {
    angle -= 360; // convert to negative angle if >= 180
  } else if (angle < -180) {
    angle += 360; // convert to positive angle if < -180
  }
  return angle;
}

bool StandardCalc::IsAngleBetween(float first_angle, float middle_angle, float second_angle) {
//  following three lines of code are commented out based on the assumption given in the note that input
//  angles will be bound to 180 according to the definition of binding to 180 for the BoundTo180 method;
//  they must be uncommented if the method should be modified to accept angles not already bound to 180.
//  first_angle = StandardCalc::BoundTo180(first_angle);
//  middle_angle = StandardCalc::BoundTo180(middle_angle);
//  second_angle = StandardCalc::BoundTo180(second_angle);
  float greater_angle = fmax(first_angle, second_angle);
  float lesser_angle = fmin(first_angle, second_angle);
  if (greater_angle - lesser_angle > 180) {
    return middle_angle > greater_angle || middle_angle < lesser_angle;
  } else if (greater_angle - lesser_angle < 180) {
    return middle_angle < greater_angle && middle_angle > lesser_angle;
  } else { //angle between first_angle and second_angle is exactly 180
    return middle_angle != greater_angle && middle_angle != lesser_angle;
  }
}