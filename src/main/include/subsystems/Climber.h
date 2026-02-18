// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc2/command/Command.h>
#include <frc2/command/CommandPtr.h>

#include "Constants.h"

#include <ctre/phoenix6/CANBus.hpp>

class Climber : public frc2::SubsystemBase {
 public:
  Climber();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */

   units::angle::turn_t InchToTurns(units::inch_t inch);

   frc2::CommandPtr SetMotorOnePosition(units::angle::turn_t position);

   units::inch GetMotorOnePosition();

   frc2::CommandPtr SetMotorTwoPosition(units::angle::turn_t    position);

   units::inch GetMotorTwoPosition();

   frc2::CommandPtr LowerClimber();

   frc2::CommandPtr SetMotorPositions(units::inch positionOne, units::inch positionTwo);

  void Periodic() override;

 private:

  ctre::phoenix6::hardware::TalonFX m_MotorOne;

  ctre::phoenix6::controls::MotionMagicVoltage m_PoseRequestOne;
  ctre::phoenix6::controls::MotionMagicVelocityVoltage m_VelRequestOne;


  ctre::phoenix6::hardware::TalonFX m_MotorTwo;

  ctre::phoenix6::controls::MotionMagicVoltage m_PoseRequestTwo;
  ctre::phoenix6::controls::MotionMagicVelocityVoltage m_VelRequestTwo;
};
