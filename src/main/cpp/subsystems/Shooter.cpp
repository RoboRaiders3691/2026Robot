// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Shooter.h"

using namespace ShooterConstants;

Shooter::Shooter() : 
m_FlywheelL(kCanIDOne), m_VelRequestOne(0_rpm), 
m_FlywheelR(kCanIDTwo), m_VelRequestTwo(0_rpm),  
m_Flap(kCanIDTwo), m_PoseRequestFlap(0_tr) {
    m_FlywheelL.GetConfigurator().Apply(KMotorOneConfigs);
    m_FlywheelR.GetConfigurator().Apply(KMotorTwoConfigs);
    m_Flap.GetConfigurator().Apply(KFlapConfigs);
    m_FlywheelL.SetControl(ctre::phoenix6::controls::Follower{m_FlywheelR.GetDeviceID(), InvertFollowDir});
}

////////   FLYWHEELS

//Flywheel one and two (one is left, two is right) units: Revolution per minute

frc2::CommandPtr Shooter::SetFlywheelSpeed(units::revolutions_per_minute_t vel){
    return RunOnce([this, vel] {
                m_FlywheelR.SetControl(m_VelRequestTwo.WithVelocity(vel));
                m_FlywheelL.SetControl(m_VelRequestTwo.WithVelocity(-vel));
        });
}

units::angular_velocity::revolutions_per_minute_t Shooter::GetFlywheelSpeed(){
    return m_FlywheelR.GetVelocity().GetValue();
    return m_FlywheelL.GetVelocity().GetValue();
}

////////   FLAP

//Flap (rotates to angle the fuel) units: Degree

frc2::CommandPtr Shooter::SetFlapPosition(units::angle::degree_t position){
    return RunOnce([this, position] {
            m_Flap.SetControl(m_PoseRequestFlap.WithPosition(position));
    });
}

units::angle::degree_t Shooter::GetFlapPosition(){
    return m_Flap.GetPosition().GetValue();
}

// This method will be called once per scheduler run
void Shooter::Periodic() {}
