// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc2/command/Command.h>
#include <frc2/command/CommandPtr.h>

#include <ctre/phoenix6/controls/Follower.hpp>

#include "Constants.h"

class Shooter : public frc2::SubsystemBase {
 public:
  Shooter();

  ////////   FLYWHEELS

  //Flywheel one and two (one is left, two is right) use Rpm

  frc2::CommandPtr SetFlywheelSpeed(units::revolutions_per_minute_t vel);

  units::revolutions_per_minute_t GetFlywheelSpeed();

  ////////   FLAP

  //Flap (rotates to angle the fuel) use Angle

  frc2::CommandPtr SetFlapPosition(units::angle::degree_t position);

  units::angle::degree_t GetFlapPosition();


  
  //Will be called periodically whenever the CommandScheduler runs.
  void Periodic() override;

 private:


  ctre::phoenix6::hardware::TalonFX m_FlywheelL;

  ctre::phoenix6::controls::MotionMagicVelocityVoltage m_VelRequestOne;

  
  ctre::phoenix6::hardware::TalonFX m_FlywheelR;

  ctre::phoenix6::controls::MotionMagicVelocityVoltage m_VelRequestTwo;


  ctre::phoenix6::hardware::TalonFX m_Flap;

  ctre::phoenix6::controls::MotionMagicVoltage m_PoseRequestFlap;

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
