// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Intake.h"

using namespace IntakeConstants;

Intake::Intake(): 
m_MotorOne(kCanIDOne, kCanBus), m_PoseRequestOne(0_tr), m_VelRequestOne(0_rpm), 
m_MotorTwo(kCanIDTwo, kCanBus), m_PoseRequestTwo(0_tr), m_VelRequestTwo(0_rpm) {
    m_MotorOne.GetConfigurator().Apply(KMotorOneConfigs);
    m_MotorTwo.GetConfigurator().Apply(KMotorTwoConfigs);
}

   ////////   MOTOR ONE

  //Intake motor one (The one that pivots the intake) Units: Turns

  frc2::CommandPtr Intake::SetAngle(units::turn_t turns){
        return RunOnce([this, turns] {
            m_MotorOne.SetControl(m_PoseRequestOne.WithPosition(turns));
    });
  }

  units::turn_t Intake::GetAngleMotorOne(){
    return m_MotorOne.GetPosition().GetValue();
  }


  ////////   MOTOR TWO

  //Intake motor two (The one that actually spins) Units: Turns per second

  frc2::CommandPtr Intake::SetVel(units::turns_per_second_t vel){
        return RunOnce([this, vel] {
            m_MotorTwo.SetControl(m_VelRequestTwo.WithVelocity(vel));
    });
  }

  units::angular_velocity::turns_per_second_t Intake::GetSpeedMotorTwo(){
    return m_MotorOne.GetVelocity().GetValue();
  }



// This method will be called once per scheduler run
void Intake::Periodic() {}
