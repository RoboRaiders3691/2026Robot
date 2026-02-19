// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.



#pragma once


#include <units/angle.h>
#include <units/angular_velocity.h>
#include <units/angular_acceleration.h>
#include <units/angular_jerk.h>
#include <units/length.h>

#include "ctre/phoenix6/TalonFX.hpp"

#include "ctre/phoenix6/configs/Configurator.hpp"
#include "ctre/phoenix6/configs/Slot0Configs.hpp"


// Define the compound unit type: turns per inch (uses camel case for units name to match units library conventions)
using turns_per_inch = units::compound_unit<units::turns, units::inverse<units::inches>>;



namespace OperatorConstants {

inline constexpr int kDriverControllerPort = 0;

}

namespace IntakeConstants {
    inline constexpr ctre::phoenix6::CANBus kCanBus{"*"};

    inline constexpr int kCanIDOne = 0;
    inline constexpr units::angle::turn_t kUpperLimitOne = 0_tr;
    inline constexpr units::angle::turn_t kLowerLimitOne = -0_tr;

    inline constexpr int kCanIDTwo = 0;

    static constexpr ctre::phoenix6::configs::TalonFXConfiguration KMotorOneConfigs = ctre::phoenix6::configs::TalonFXConfiguration{}
        .WithSlot0(ctre::phoenix6::configs::Slot0Configs{}
                    
            .WithKP(0)
            .WithKI(0)
            .WithKD(0)

            .WithKS(0)
            .WithKV(0)
            .WithKA(0)
            .WithKG(0)
            .WithGravityType(ctre::phoenix6::signals::GravityTypeValue::Arm_Cosine)
        )
        .WithMotionMagic(ctre::phoenix6::configs::MotionMagicConfigs{}
            .WithMotionMagicCruiseVelocity(5_tps)
            .WithMotionMagicAcceleration(10_tr_per_s_sq)
            .WithMotionMagicJerk(100_tr_per_s_cu)
        )
        .WithFeedback(ctre::phoenix6::configs::FeedbackConfigs{}
            .WithSensorToMechanismRatio(0)
        );

        static constexpr ctre::phoenix6::configs::TalonFXConfiguration KMotorTwoConfigs = ctre::phoenix6::configs::TalonFXConfiguration{}
        .WithSlot0(ctre::phoenix6::configs::Slot0Configs{}
                    
            .WithKP(0)
            .WithKI(0)
            .WithKD(0)

            .WithKS(0)
            .WithKV(0)
            .WithKA(0)
            .WithKG(0)
            .WithGravityType(ctre::phoenix6::signals::GravityTypeValue::Arm_Cosine)
        )
        .WithMotionMagic(ctre::phoenix6::configs::MotionMagicConfigs{}
            .WithMotionMagicCruiseVelocity(5_tps)
            .WithMotionMagicAcceleration(10_tr_per_s_sq)
            .WithMotionMagicJerk(100_tr_per_s_cu)
        )
        .WithFeedback(ctre::phoenix6::configs::FeedbackConfigs{}
            .WithSensorToMechanismRatio(0)
        );
}

namespace ShooterConstants {
    inline constexpr ctre::phoenix6::CANBus kCanBus{"*"};

    inline constexpr bool InvertFollowDir = true;

    inline constexpr int kCanIDOne = 0;
    inline constexpr units::angle::turn_t kUpperLimitOne = 0_tr;
    inline constexpr units::angle::turn_t kLowerLimitOne = -0_tr;

    inline constexpr int kCanIDTwo = 0;
    inline constexpr units::angle::turn_t kUpperLimitTwo = 0_tr;
    inline constexpr units::angle::turn_t kLowerLimitTwo = -0_tr;

    inline constexpr int kCanIDFlap = 0;
    inline constexpr units::angle::turn_t kUpperLimitFlap = 0_tr;
    inline constexpr units::angle::turn_t kLowerLimitFlap = -0_tr;

    static constexpr ctre::phoenix6::configs::TalonFXConfiguration KMotorOneConfigs = ctre::phoenix6::configs::TalonFXConfiguration{}
        .WithSlot0(ctre::phoenix6::configs::Slot0Configs{}
                    
            .WithKP(0)
            .WithKI(0)
            .WithKD(0)

            .WithKS(0)
            .WithKV(0)
            .WithKA(0)
            .WithKG(0)
            .WithGravityType(ctre::phoenix6::signals::GravityTypeValue::Arm_Cosine)
        )
        .WithMotionMagic(ctre::phoenix6::configs::MotionMagicConfigs{}
            .WithMotionMagicCruiseVelocity(5_tps)
            .WithMotionMagicAcceleration(10_tr_per_s_sq)
            .WithMotionMagicJerk(100_tr_per_s_cu)
        )
        .WithFeedback(ctre::phoenix6::configs::FeedbackConfigs{}
            .WithSensorToMechanismRatio(0)
        );

        static constexpr ctre::phoenix6::configs::TalonFXConfiguration KMotorTwoConfigs = ctre::phoenix6::configs::TalonFXConfiguration{}
        .WithSlot0(ctre::phoenix6::configs::Slot0Configs{}
                    
            .WithKP(0)
            .WithKI(0)
            .WithKD(0)

            .WithKS(0)
            .WithKV(0)
            .WithKA(0)
            .WithKG(0)
            .WithGravityType(ctre::phoenix6::signals::GravityTypeValue::Arm_Cosine)
        )
        .WithMotionMagic(ctre::phoenix6::configs::MotionMagicConfigs{}
            .WithMotionMagicCruiseVelocity(5_tps)
            .WithMotionMagicAcceleration(10_tr_per_s_sq)
            .WithMotionMagicJerk(100_tr_per_s_cu)
        )
        .WithFeedback(ctre::phoenix6::configs::FeedbackConfigs{}
            .WithSensorToMechanismRatio(0)
        );

        static constexpr ctre::phoenix6::configs::TalonFXConfiguration KFlapConfigs = ctre::phoenix6::configs::TalonFXConfiguration{}
        .WithSlot0(ctre::phoenix6::configs::Slot0Configs{}
                    
            .WithKP(0)
            .WithKI(0)
            .WithKD(0)

            .WithKS(0)
            .WithKV(0)
            .WithKA(0)
            .WithKG(0)
            .WithGravityType(ctre::phoenix6::signals::GravityTypeValue::Arm_Cosine)
        )
        .WithMotionMagic(ctre::phoenix6::configs::MotionMagicConfigs{}
            .WithMotionMagicCruiseVelocity(5_tps)
            .WithMotionMagicAcceleration(10_tr_per_s_sq)
            .WithMotionMagicJerk(100_tr_per_s_cu)
        )
        .WithFeedback(ctre::phoenix6::configs::FeedbackConfigs{}
            .WithSensorToMechanismRatio(0)
        );
}

namespace ClimberConstants {
    inline constexpr ctre::phoenix6::CANBus kCanBus{"*"};

    inline constexpr int kCanIDOne = 0;
    inline constexpr units::length::inch_t kUpperLimitOne = 0_in;
    inline constexpr units::length::inch_t kLowerLimitOne = -0_in;

    inline constexpr int kCanIDTwo = 0;
    inline constexpr units::length::inch_t kUpperLimitTwo = 0_in;
    inline constexpr units::length::inch_t kLowerLimitTwo = -0_in;

    inline constexpr units::unit_t<turns_per_inch> kTurnsPerInch{1.5};


    static constexpr ctre::phoenix6::configs::TalonFXConfiguration KMotorOneConfigs = ctre::phoenix6::configs::TalonFXConfiguration{}
        .WithSlot0(ctre::phoenix6::configs::Slot0Configs{}
                    
            .WithKP(0)
            .WithKI(0)
            .WithKD(0)

            .WithKS(0)
            .WithKV(0)
            .WithKA(0)
            .WithKG(0)
            .WithGravityType(ctre::phoenix6::signals::GravityTypeValue::Arm_Cosine)
        )
        .WithMotionMagic(ctre::phoenix6::configs::MotionMagicConfigs{}
            .WithMotionMagicCruiseVelocity(5_tps)
            .WithMotionMagicAcceleration(10_tr_per_s_sq)
            .WithMotionMagicJerk(100_tr_per_s_cu)
        )
        .WithFeedback(ctre::phoenix6::configs::FeedbackConfigs{}
            .WithSensorToMechanismRatio(0)
        );

        static constexpr ctre::phoenix6::configs::TalonFXConfiguration KMotorTwoConfigs = ctre::phoenix6::configs::TalonFXConfiguration{}
        .WithSlot0(ctre::phoenix6::configs::Slot0Configs{}
                    
            .WithKP(0)
            .WithKI(0)
            .WithKD(0)

            .WithKS(0)
            .WithKV(0)
            .WithKA(0)
            .WithKG(0)
            .WithGravityType(ctre::phoenix6::signals::GravityTypeValue::Arm_Cosine)
        )
        .WithMotionMagic(ctre::phoenix6::configs::MotionMagicConfigs{}
            .WithMotionMagicCruiseVelocity(5_tps)
            .WithMotionMagicAcceleration(10_tr_per_s_sq)
            .WithMotionMagicJerk(100_tr_per_s_cu)
        )
        .WithFeedback(ctre::phoenix6::configs::FeedbackConfigs{}
            .WithSensorToMechanismRatio(0)
        );

}

