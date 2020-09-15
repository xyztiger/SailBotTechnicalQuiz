//
// Created by TigerZhao on 2020-09-13.
//

#include "StandardCalc.h"
#include <math.h>

float StandardCalc::BoundTo180(float angle) {
  angle = fmod(angle, 360); // angle in interval (-360, 360)
  if (angle >= 180) {
    angle -= 360; // convert to negative angle if >= 180
  } else if (angle < -180) {
    angle += 360; // convert to positive angle if < -180
  }
  return angle;
}

bool StandardCalc::isAngleBetween(float first_angle, float middle_angle, float second_angle) {
  float greater_angle = fmax(first_angle, second_angle);
  float lesser_angle = fmin(first_angle, second_angle);
  if (greater_angle - lesser_angle > 180) {
    return middle_angle > greater_angle || middle_angle < lesser_angle;
  } else {
    return middle_angle < greater_angle && middle_angle > lesser_angle;
  }
}