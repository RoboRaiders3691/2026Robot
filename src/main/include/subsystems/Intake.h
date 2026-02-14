// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc2/command/Command.h>
#include <frc2/command/CommandPtr.h>

#include "Constants.h"

#include <ctre/phoenix6/CANBus.hpp>

class Intake : public frc2::SubsystemBase {
 public:
  Intake();

  void Periodic() override;

  ////////   MOTOR ONE

  //Intake motor one (The one that pivots the intake) Units: Turns

  frc2::CommandPtr SetAngle(units::turn_t turns);

  units::turn_t GetAngleMotorOne();


  ////////   MOTOR TWO

  //Intake motor two (The one that actually spins) Units: Turns per second

  frc2::CommandPtr SetVel(units::turns_per_second_t vel);

  units::turns_per_second_t GetSpeedMotorTwo();



  //void Periodic() override;

 private:

  ctre::phoenix6::hardware::TalonFX m_MotorOne;

  ctre::phoenix6::controls::MotionMagicVoltage m_PoseRequestOne;
  ctre::phoenix6::controls::MotionMagicVelocityVoltage m_VelRequestOne;


  ctre::phoenix6::hardware::TalonFX m_MotorTwo;

  ctre::phoenix6::controls::MotionMagicVoltage m_PoseRequestTwo;
  ctre::phoenix6::controls::MotionMagicVelocityVoltage m_VelRequestTwo;
};
