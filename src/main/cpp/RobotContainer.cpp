// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>

#include "commands/Autos.h"
#include "commands/ExampleCommand.h"

RobotContainer::RobotContainer(){
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureBindings();
}


void RobotContainer::ConfigureBindings() {
  m_XboxController.RightTrigger().OnTrue(m_shooter.SetFlywheelVel(1_tps)); // CHANGE NUMBER LATER
  m_XboxController.LeftTrigger().OnTrue(m_intake.SetVel(1_tps)); // CHANGE NUMBER LATER
  m_XboxController.LeftBumper().OnTrue(m_intake.SetAngle(0.5_tr)); // CHANGE NUMBER LATER
  m_XboxController.RightBumper().OnTrue(m_intake.SetAngle(1.5_tr)); // CHANGE NUMBER LATER
  m_XboxController.X().OnTrue(m_climber.SetMotorPosition(1_tr)); // CHANGE NUMBER LATER
  m_XboxController.Y().OnTrue(m_climber.SetMotorPosition(0_tr)); // CHANGE NUMBER LATER
  m_XboxController.A().OnTrue(m_climber.SetMotorPosition(-1_tr)); // CHANGE NUMBER LATER
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return autos::ExampleAuto(&m_subsystem);
}





