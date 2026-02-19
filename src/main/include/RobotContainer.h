// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandPtr.h>
#include <frc2/command/button/CommandXboxController.h>
#include <ctre/phoenix6/CANBus.hpp>

#include "Constants.h"
#include "subsystems/ExampleSubsystem.h"
#include "subsystems/Intake.h"
#include "subsystems/Shooter.h"
#include "subsystems/Climber.h"


/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and trigger mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::CommandPtr GetAutonomousCommand();

 private:
  // Replace with CommandPS4Controller or CommandJoystick if needed
  frc2::CommandXboxController m_XboxController{
      OperatorConstants::kDriverControllerPort};

  //input constants
  units::turns_per_second_t shooterFlywheelConstant = 0_tps;
  units::turns_per_second_t intakeVelocityConstant = 0_tps;
 

  // The robot's subsystems are defined here...
  ExampleSubsystem m_subsystem;
  Intake m_intake;
  Shooter m_shooter;
  Climber m_climber;

  void ConfigureBindings();
};
