// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Climber.h"

using namespace ClimberConstants;

Climber::Climber(): 
m_MotorOne(kCanIDOne, kCanBus), m_PoseRequestOne(0_tr), m_VelRequestOne(0_rpm),
m_MotorTwo(kCanIDOne, kCanBus), m_PoseRequestTwo(0_tr), m_VelRequestTwo(0_rpm) {
    m_MotorOne.GetConfigurator().Apply(KMotorOneConfigs);
    m_MotorTwo.GetConfigurator().Apply(KMotorTwoConfigs);
};

// This method will be called once per scheduler run
void Climber::Periodic() {}

   ////////   HELPER 
   
   //converts inches to turns

   units::angle::turn_t Climber::InchToTurns(units::inch_t inch){
          return units::turn_t(inch.value()*kTurnsPerInch.value()); 
   }


   ////////   MOTOR ONE

   //Intake motor Units: Turns

   frc2::CommandPtr Climber::SetMotorOnePosition(units::angle::turn_t position){
            return RunOnce([this, position] {
                m_MotorOne.SetControl(m_PoseRequestOne.WithPosition(position));
        });
   };

   units::angle::turn_t Climber::GetMotorOnePosition(){
        return m_MotorOne.GetPosition().GetValue();
   };


   ////////   MOTOR TWO

   //Intake motor Units: Turns

   frc2::CommandPtr Climber::SetMotorTwoPosition(units::angle::turn_t position){
            return RunOnce([this, position] {
                m_MotorTwo.SetControl(m_PoseRequestTwo.WithPosition(position));
        });
   };

   units::angle::turn_t Climber::GetMotorTwoPosition(){
        return m_MotorTwo.GetPosition().GetValue();
   };


   ////////   BOTH MOTORS

   //Things like going straight to L1, L2, L3, and lowering the climber

   frc2::CommandPtr Climber::SetMotorPositions(units::inch positionOne, units::inch positionTwo){
            return RunOnce([this, positionOne, positionTwo] {
                m_MotorOne.SetControl(m_PoseRequestOne.WithPosition(positionOne));
                m_MotorTwo.SetControl(m_PoseRequestTwo.WithPosition(positionTwo));
        });
   };

   frc2::CommandPtr Climber::LowerClimber(){
            return RunOnce([this] {
                SetMotorPositions(0_in, 0_in);
        });
   };
