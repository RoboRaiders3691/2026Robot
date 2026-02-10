// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.



#pragma once

#include <units/angle.h>
#include <units/angular_velocity.h>
#include <units/angular_acceleration.h>
#include <units/angular_jerk.h>

#include "ctre/phoenix6/TalonFX.hpp"

#include "ctre/phoenix6/configs/Configurator.hpp"
#include "ctre/phoenix6/configs/Slot0Configs.hpp"

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

namespace OperatorConstants {

inline constexpr int kDriverControllerPort = 0;

}

namespace IntakeConstants {

    inline constexpr int kCanIDOne = 0;
    inline constexpr units::angle::turn_t kUpperLimitOne = 0_tr;
    inline constexpr units::angle::turn_t kLowerLimitOne = -0_tr;

    inline constexpr int kCanIDTwo = 0;
    inline constexpr units::angle::turn_t kUpperLimitTwo = 0_tr;
    inline constexpr units::angle::turn_t kLowerLimitTwo = -0_tr;

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


