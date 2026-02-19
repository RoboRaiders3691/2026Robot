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

   units::angle::turn_t Climber::InchToTurns(units::length::inch_t inch){
          return units::turn_t(inch.value()*kTurnsPerInch.value()); 
   }


   ////////   MOTOR ONE

   //Intake motor Units: Turns

   units::angle::turn_t Climber::GetMotorOnePosition(){
        return m_MotorOne.GetPosition().GetValue();
   };


   ////////   MOTOR TWO

   //Intake motor Units: Turns

   units::angle::turn_t Climber::GetMotorTwoPosition(){
        return m_MotorTwo.GetPosition().GetValue();
   };


   ////////   BOTH MOTORS

   //Things like going straight to L1, L2, L3, and lowering the climber

   frc2::CommandPtr Climber::SetMotorPositions(units::inch_t positionOne, units::inch_t positionTwo){
            return RunOnce([this, positionOne, positionTwo] {
                m_MotorOne.SetControl(m_PoseRequestOne.WithPosition(InchToTurns(positionOne)));
                m_MotorTwo.SetControl(m_PoseRequestTwo.WithPosition(InchToTurns(positionTwo)));
        });
   };

   frc2::CommandPtr Climber::LowerClimber(){
            return RunOnce([this] {
                if(climbLevel == 1){
                    SetMotorPositions(kLowerLimitOne, kLowerLimitTwo);
                    climbLevel--;
                }
        });
   };

   frc2::CommandPtr Climber::RaiseClimber(){
            return RunOnce([this] {
                if(climbLevel==0){ //Climb from floor
                    SetMotorPositions(kUpperLimitOne, kLowerLimitTwo);
                    SetMotorPositions(kLowerLimitOne, kLowerLimitTwo);
                    climbLevel++;
                } else { //climb from L1 or higher
                    SetMotorPositions(kUpperLimitOne, kLowerLimitTwo);
                    SetMotorPositions(kLowerLimitOne, kUpperLimitTwo);
                    SetMotorPositions(kLowerLimitOne, kLowerLimitTwo);
                    climbLevel++;
                }
        });
   };

