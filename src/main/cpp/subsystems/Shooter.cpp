// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Shooter.h"

Shooter::Shooter() = default;

////////   FLYWHEELS

//Flywheel one and two (one is left, two is right) use Rpm

frc2::CommandPtr Shooter::SetFlywheelSpeed(units::revolutions_per_minute_per_second_t Speed){

}

units::revolutions_per_minute_per_second_t GetFlywheelSpeed(){

}

////////   FLAP

//Flap (rotates to angle the fuel) use Angle

frc2::CommandPtr Shooter::SetFlapPosition(units::angle::degree_t Position){
    
}

units::angle::degree_t GetFlapPosition(){

}

// This method will be called once per scheduler run
void Shooter::Periodic() {}
