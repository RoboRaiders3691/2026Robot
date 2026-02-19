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
  m_XboxController.RightTrigger().OnTrue(m_shooter.SetFlywheelVel(shooterFlywheelConstant)); // SHOOTS FUEL
  m_XboxController.LeftTrigger().OnTrue(m_intake.SetVel(intakeVelocityConstant)); // INTAKES FUEL
  m_XboxController.LeftBumper().OnTrue(m_intake.SetAngle(m_intake.GetPivotMin())); // LOWERS INTAKE
  m_XboxController.RightBumper().OnTrue(m_intake.SetAngle(m_intake.GetPivotMax())); // RAISES INTAKE
  m_XboxController.Y().OnTrue(m_climber.RaiseClimber()); // CLIMBS UP A LEVEL
  m_XboxController.A().OnTrue(m_climber.LowerClimber()); // LOWERS FROM L1 TO FLOOR
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return autos::ExampleAuto(&m_subsystem);
}





