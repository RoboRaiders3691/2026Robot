// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Shooter.h"

using namespace ShooterConstants;

Shooter::Shooter(ctre::phoenix6::CANBus CANBus) : 
m_FlywheelL(kCanIDOne, CANBus), m_VelRequestOne(0_rpm), 
m_FlywheelR(kCanIDTwo, CANBus), m_VelRequestTwo(0_rpm),  
m_Flap(kCanIDTwo, CANBus), m_PoseRequestFlap(0_tr) {
    m_FlywheelL.GetConfigurator().Apply(KMotorOneConfigs);
    m_FlywheelR.GetConfigurator().Apply(KMotorTwoConfigs);
    m_Flap.GetConfigurator().Apply(KFlapConfigs);
    m_FlywheelL.SetControl(ctre::phoenix6::controls::Follower{m_FlywheelR.GetDeviceID(), InvertFollowDir});
}

////////   FLYWHEELS

//Flywheel one and two (one is left, two is right) Units: Turns per second

frc2::CommandPtr Shooter::SetFlywheelSpeed(units::turns_per_second_t vel){
    return RunOnce([this, vel] {
                m_FlywheelR.SetControl(m_VelRequestTwo.WithVelocity(vel));
        });
}

units::angular_velocity::turns_per_second_t Shooter::GetFlywheelSpeed(){
    return m_FlywheelR.GetVelocity().GetValue();
}

////////   FLAP

//Flap (rotates to angle the fuel) Units: Turns

frc2::CommandPtr Shooter::SetFlapPosition(units::angle::turn_t position){
    return RunOnce([this, position] {
            m_Flap.SetControl(m_PoseRequestFlap.WithPosition(position));
    });
}

units::angle::turn_t Shooter::GetFlapPosition(){
    return m_Flap.GetPosition().GetValue();
}

// This method will be called once per scheduler run
void Shooter::Periodic() {}
