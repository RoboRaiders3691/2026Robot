// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Climber.h"

using namespace ClimberConstants;

Climber::Climber(): 
m_Motor(kCanIDOne, kCanBus), m_PoseRequest(0_tr), m_VelRequest(0_rpm) {
    m_Motor.GetConfigurator().Apply(KMotorConfigs);
};

// This method will be called once per scheduler run
void Climber::Periodic() {}


   ////////   MOTOR

   //Intake motor Units: Turns

   frc2::CommandPtr Climber::SetMotorPosition(units::angle::turn_t position){
            return RunOnce([this, position] {
                m_Motor.SetControl(m_PoseRequest.WithPosition(position));
        });
   };

   units::angle::turn_t Climber::GetMotorPosition(){
        return m_Motor.GetPosition().GetValue();
   };
