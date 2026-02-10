// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>

#include "Constants.h"

class Shooter : public frc2::SubsystemBase {
 public:
  Shooter();

  ////////   FLYWHEELS

  //Flywheel one and two (one is left, two is right) use Rpm

  frc2::CommandPtr SetFlywheelSpeed(units::revolutions_per_minute_per_second_t Speed);

  units::revolutions_per_minute_per_second_t GetFlywheelSpeed();

  ////////   FLAP

  //Flap (rotates to angle the fuel) use Angle

  frc2::CommandPtr SetFlapPosition(units::angle::degree_t Position);

  units::angle::degree_t GetFlapPosition();


  
  //Will be called periodically whenever the CommandScheduler runs.
  void Periodic() override;

 private:

 
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
