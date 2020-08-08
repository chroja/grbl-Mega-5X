/*
  defaults.h - defaults settings configuration file
  Part of Grbl

  Copyright (c) 2017-2018 Gauthier Briere
  Copyright (c) 2012-2016 Sungeun K. Jeon for Gnea Research LLC

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

/* The defaults.h file serves as a central default settings selector for different machine
   types, from DIY CNC mills to CNC conversions of off-the-shelf machines. The settings
   files listed here are supplied by users, so your results may vary. However, this should
   give you a good starting point as you get to know your machine and tweak the settings for
   your nefarious needs.
   NOTE: Ensure one and only one of these DEFAULTS_XXX values is defined in config.h */

#ifndef defaults_h

#ifdef DEFAULTS_GENERIC
  // Grbl generic default settings. Should work across different machines.
  #define DEFAULT_AXIS1_STEPS_PER_UNIT 250.0
  #define DEFAULT_AXIS2_STEPS_PER_UNIT 250.0
  #define DEFAULT_AXIS3_STEPS_PER_UNIT 250.0
  #define DEFAULT_AXIS1_MAX_RATE 500.0 // mm/min
  #define DEFAULT_AXIS2_MAX_RATE 500.0 // mm/min
  #define DEFAULT_AXIS3_MAX_RATE 500.0 // mm/min
  #define DEFAULT_AXIS1_ACCELERATION (10.0*60*60) // 10*60*60 mm/min^2 = 10 mm/sec^2
  #define DEFAULT_AXIS2_ACCELERATION (10.0*60*60) // 10*60*60 mm/min^2 = 10 mm/sec^2
  #define DEFAULT_AXIS3_ACCELERATION (10.0*60*60) // 10*60*60 mm/min^2 = 10 mm/sec^2
  #define DEFAULT_AXIS1_MAX_TRAVEL 200.0 // mm NOTE: Must be a positive value.
  #define DEFAULT_AXIS2_MAX_TRAVEL 200.0 // mm NOTE: Must be a positive value.
  #define DEFAULT_AXIS3_MAX_TRAVEL 200.0 // mm NOTE: Must be a positive value.
  #define DEFAULT_SPINDLE_RPM_MAX 1000.0 // rpm
  #define DEFAULT_SPINDLE_RPM_MIN 0.0 // rpm
  #define DEFAULT_STEP_PULSE_MICROSECONDS 10
  #define DEFAULT_STEPPING_INVERT_MASK 0
  #define DEFAULT_DIRECTION_INVERT_MASK 0
  #define DEFAULT_STEPPER_IDLE_LOCK_TIME 25 // msec (0-254, 255 keeps steppers enabled)
  #define DEFAULT_STATUS_REPORT_MASK 1 // MPos enabled
  #define DEFAULT_JUNCTION_DEVIATION 0.01 // mm
  #define DEFAULT_ARC_TOLERANCE 0.002 // mm
  #define DEFAULT_REPORT_INCHES 0 // false
  #define DEFAULT_INVERT_ST_ENABLE 0 // false
  #define DEFAULT_INVERT_LIMIT_PINS 0 // false
  #define DEFAULT_SOFT_LIMIT_ENABLE 0 // false
  #define DEFAULT_HARD_LIMIT_ENABLE 0  // false
  #define DEFAULT_INVERT_PROBE_PIN 0 // false
  #define DEFAULT_LASER_MODE 0 // false
  #define DEFAULT_HOMING_ENABLE 0  // false
  #define DEFAULT_HOMING_DIR_MASK 0 // move positive dir
  #define DEFAULT_HOMING_FEED_RATE 25.0 // mm/min
  #define DEFAULT_HOMING_SEEK_RATE 500.0 // mm/min
  #define DEFAULT_HOMING_DEBOUNCE_DELAY 250 // msec (0-65k)
  #define DEFAULT_HOMING_PULLOFF 1.0 // mm
#endif

#ifdef DEFAULTS_SHERLINE_5400
  // Description: Sherline 5400 mill with three NEMA 23 Keling  KL23H256-21-8B 185 oz-in stepper motors,
  // driven by three Pololu A4988 stepper drivers with a 30V, 6A power supply at 1.5A per winding.
  #define MICROSTEPS 2
  #define STEPS_PER_REV 200.0
  #define MM_PER_REV (0.050*MM_PER_INCH) // 0.050 inch/rev leadscrew
  #define DEFAULT_AXIS1_STEPS_PER_UNIT (STEPS_PER_REV*MICROSTEPS/MM_PER_REV)
  #define DEFAULT_AXIS2_STEPS_PER_UNIT (STEPS_PER_REV*MICROSTEPS/MM_PER_REV)
  #define DEFAULT_AXIS3_STEPS_PER_UNIT (STEPS_PER_REV*MICROSTEPS/MM_PER_REV)
  #define DEFAULT_AXIS1_MAX_RATE 635.0 // mm/min (25 ipm)
  #define DEFAULT_AXIS2_MAX_RATE 635.0 // mm/min
  #define DEFAULT_AXIS3_MAX_RATE 635.0 // mm/min
  #define DEFAULT_AXIS1_ACCELERATION (50.0*60*60) // 50*60*60 mm/min^2 = 50 mm/sec^2
  #define DEFAULT_AXIS2_ACCELERATION (50.0*60*60) // 50*60*60 mm/min^2 = 50 mm/sec^2
  #define DEFAULT_AXIS3_ACCELERATION (50.0*60*60) // 50*60*60 mm/min^2 = 50 mm/sec^2
  #define DEFAULT_AXIS1_MAX_TRAVEL 225.0 // mm NOTE: Must be a positive value.
  #define DEFAULT_AXIS2_MAX_TRAVEL 125.0 // mm NOTE: Must be a positive value.
  #define DEFAULT_AXIS3_MAX_TRAVEL 170.0 // mm NOTE: Must be a positive value.
  #define DEFAULT_SPINDLE_RPM_MAX 2800.0 // rpm
  #define DEFAULT_SPINDLE_RPM_MIN 0.0 // rpm
  #define DEFAULT_STEP_PULSE_MICROSECONDS 10
  #define DEFAULT_STEPPING_INVERT_MASK 0
  #define DEFAULT_DIRECTION_INVERT_MASK ((1<<AXIS_2)|(1<<AXIS_3))
  #define DEFAULT_STEPPER_IDLE_LOCK_TIME 25 // msec (0-254, 255 keeps steppers enabled)
  #define DEFAULT_STATUS_REPORT_MASK 1 // MPos enabled
  #define DEFAULT_JUNCTION_DEVIATION 0.01 // mm
  #define DEFAULT_ARC_TOLERANCE 0.002 // mm
  #define DEFAULT_REPORT_INCHES 0 // true
  #define DEFAULT_INVERT_ST_ENABLE 0 // false
  #define DEFAULT_INVERT_LIMIT_PINS 0 // false
  #define DEFAULT_SOFT_LIMIT_ENABLE 0 // false
  #define DEFAULT_HARD_LIMIT_ENABLE 0  // false
  #define DEFAULT_INVERT_PROBE_PIN 0 // false
  #define DEFAULT_LASER_MODE 0 // false
  #define DEFAULT_HOMING_ENABLE 0  // false
  #define DEFAULT_HOMING_DIR_MASK 0 // move positive dir
  #define DEFAULT_HOMING_FEED_RATE 50.0 // mm/min
  #define DEFAULT_HOMING_SEEK_RATE 635.0 // mm/min
  #define DEFAULT_HOMING_DEBOUNCE_DELAY 250 // msec (0-65k)
  #define DEFAULT_HOMING_PULLOFF 1.0 // mm
#endif

#ifdef DEFAULTS_SHAPEOKO
  // Description: Shapeoko CNC mill with three NEMA 17 stepper motors, driven by Synthetos
  // grblShield with a 24V, 4.2A power supply.
  #define MICROSTEPS_XY 8
  #define STEP_REVS_XY 400
  #define MM_PER_REV_XY (0.08*18*MM_PER_INCH) // 0.08 in belt pitch, 18 pulley teeth
  #define MICROSTEPS_Z 2
  #define STEP_REVS_Z 400
  #define MM_PER_REV_Z 1.250 // 1.25 mm/rev leadscrew
  #define DEFAULT_AXIS1_STEPS_PER_UNIT (MICROSTEPS_XY*STEP_REVS_XY/MM_PER_REV_XY)
  #define DEFAULT_AXIS2_STEPS_PER_UNIT (MICROSTEPS_XY*STEP_REVS_XY/MM_PER_REV_XY)
  #define DEFAULT_AXIS3_STEPS_PER_UNIT (MICROSTEPS_Z*STEP_REVS_Z/MM_PER_REV_Z)
  #define DEFAULT_AXIS1_MAX_RATE 1000.0 // mm/min
  #define DEFAULT_AXIS2_MAX_RATE 1000.0 // mm/min
  #define DEFAULT_AXIS3_MAX_RATE 1000.0 // mm/min
  #define DEFAULT_AXIS1_ACCELERATION (15.0*60*60) // 15*60*60 mm/min^2 = 15 mm/sec^2
  #define DEFAULT_AXIS2_ACCELERATION (15.0*60*60) // 15*60*60 mm/min^2 = 15 mm/sec^2
  #define DEFAULT_AXIS3_ACCELERATION (15.0*60*60) // 15*60*60 mm/min^2 = 15 mm/sec^2
  #define DEFAULT_AXIS1_MAX_TRAVEL 200.0 // mm NOTE: Must be a positive value.
  #define DEFAULT_AXIS2_MAX_TRAVEL 200.0 // mm NOTE: Must be a positive value.
  #define DEFAULT_AXIS3_MAX_TRAVEL 200.0 // mm NOTE: Must be a positive value.
  #define DEFAULT_SPINDLE_RPM_MAX 10000.0 // rpm
  #define DEFAULT_SPINDLE_RPM_MIN 0.0 // rpm
  #define DEFAULT_STEP_PULSE_MICROSECONDS 10
  #define DEFAULT_STEPPING_INVERT_MASK 0
  #define DEFAULT_DIRECTION_INVERT_MASK ((1<<AXIS_2)|(1<<AXIS_3))
  #define DEFAULT_STEPPER_IDLE_LOCK_TIME 255 // msec (0-254, 255 keeps steppers enabled)
  #define DEFAULT_STATUS_REPORT_MASK 1 // MPos enabled
  #define DEFAULT_JUNCTION_DEVIATION 0.02 // mm
  #define DEFAULT_ARC_TOLERANCE 0.002 // mm
  #define DEFAULT_REPORT_INCHES 0 // false
  #define DEFAULT_INVERT_ST_ENABLE 0 // false
  #define DEFAULT_INVERT_LIMIT_PINS 0 // false
  #define DEFAULT_SOFT_LIMIT_ENABLE 0 // false
  #define DEFAULT_HARD_LIMIT_ENABLE 0  // false
  #define DEFAULT_INVERT_PROBE_PIN 0 // false
  #define DEFAULT_LASER_MODE 0 // false
  #define DEFAULT_HOMING_ENABLE 0  // false
  #define DEFAULT_HOMING_DIR_MASK 0 // move positive dir
  #define DEFAULT_HOMING_FEED_RATE 25.0 // mm/min
  #define DEFAULT_HOMING_SEEK_RATE 250.0 // mm/min
  #define DEFAULT_HOMING_DEBOUNCE_DELAY 250 // msec (0-65k)
  #define DEFAULT_HOMING_PULLOFF 1.0 // mm
#endif

#ifdef DEFAULTS_SHAPEOKO_2
  // Description: Shapeoko CNC mill with three NEMA 17 stepper motors, driven by Synthetos
  // grblShield at 28V.
  #define MICROSTEPS_XY 8
  #define STEP_REVS_XY 200
  #define MM_PER_REV_XY (2.0*20) // 2mm belt pitch, 20 pulley teeth
  #define MICROSTEPS_Z 2
  #define STEP_REVS_Z 200
  #define MM_PER_REV_Z 1.250 // 1.25 mm/rev leadscrew
  #define DEFAULT_AXIS1_STEPS_PER_UNIT (MICROSTEPS_XY*STEP_REVS_XY/MM_PER_REV_XY)
  #define DEFAULT_AXIS2_STEPS_PER_UNIT (MICROSTEPS_XY*STEP_REVS_XY/MM_PER_REV_XY)
  #define DEFAULT_AXIS3_STEPS_PER_UNIT (MICROSTEPS_Z*STEP_REVS_Z/MM_PER_REV_Z)
  #define DEFAULT_AXIS1_MAX_RATE 5000.0 // mm/min
  #define DEFAULT_AXIS2_MAX_RATE 5000.0 // mm/min
  #define DEFAULT_AXIS3_MAX_RATE 500.0 // mm/min
  #define DEFAULT_AXIS1_ACCELERATION (250.0*60*60) // 25*60*60 mm/min^2 = 25 mm/sec^2
  #define DEFAULT_AXIS2_ACCELERATION (250.0*60*60) // 25*60*60 mm/min^2 = 25 mm/sec^2
  #define DEFAULT_AXIS3_ACCELERATION (50.0*60*60) // 25*60*60 mm/min^2 = 25 mm/sec^2
  #define DEFAULT_AXIS1_MAX_TRAVEL 290.0 // mm NOTE: Must be a positive value.
  #define DEFAULT_AXIS2_MAX_TRAVEL 290.0 // mm NOTE: Must be a positive value.
  #define DEFAULT_AXIS3_MAX_TRAVEL 100.0 // mm NOTE: Must be a positive value.
  #define DEFAULT_SPINDLE_RPM_MAX 10000.0 // rpm
  #define DEFAULT_SPINDLE_RPM_MIN 0.0 // rpm
  #define DEFAULT_STEP_PULSE_MICROSECONDS 10
  #define DEFAULT_STEPPING_INVERT_MASK 0
  #define DEFAULT_DIRECTION_INVERT_MASK ((1<<AXIS_1)|(1<<AXIS_3))
  #define DEFAULT_STEPPER_IDLE_LOCK_TIME 255 // msec (0-254, 255 keeps steppers enabled)
  #define DEFAULT_STATUS_REPORT_MASK 1 // MPos enabled
  #define DEFAULT_JUNCTION_DEVIATION 0.02 // mm
  #define DEFAULT_ARC_TOLERANCE 0.002 // mm
  #define DEFAULT_REPORT_INCHES 0 // false
  #define DEFAULT_INVERT_ST_ENABLE 0 // false
  #define DEFAULT_INVERT_LIMIT_PINS 0 // false
  #define DEFAULT_SOFT_LIMIT_ENABLE 0 // false
  #define DEFAULT_HARD_LIMIT_ENABLE 0  // false
  #define DEFAULT_INVERT_PROBE_PIN 0 // false
  #define DEFAULT_LASER_MODE 0 // false
  #define DEFAULT_HOMING_ENABLE 0  // false
  #define DEFAULT_HOMING_DIR_MASK 0 // move positive dir
  #define DEFAULT_HOMING_FEED_RATE 25.0 // mm/min
  #define DEFAULT_HOMING_SEEK_RATE 250.0 // mm/min
  #define DEFAULT_HOMING_DEBOUNCE_DELAY 250 // msec (0-65k)
  #define DEFAULT_HOMING_PULLOFF 1.0 // mm
#endif

#ifdef DEFAULTS_SHAPEOKO_3
  // Description: Shapeoko CNC mill with three NEMA 23 stepper motors, driven by CarbideMotion
  #define MICROSTEPS_XY 8
  #define STEP_REVS_XY 200
  #define MM_PER_REV_XY (2.0*20) // 2mm belt pitch, 20 pulley teeth
  #define MICROSTEPS_Z 8
  #define STEP_REVS_Z 200
  #define MM_PER_REV_Z (2.0*20) // 2mm belt pitch, 20 pulley teeth
  #define DEFAULT_AXIS1_STEPS_PER_UNIT (MICROSTEPS_XY*STEP_REVS_XY/MM_PER_REV_XY)
  #define DEFAULT_AXIS2_STEPS_PER_UNIT (MICROSTEPS_XY*STEP_REVS_XY/MM_PER_REV_XY)
  #define DEFAULT_AXIS3_STEPS_PER_UNIT (MICROSTEPS_Z*STEP_REVS_Z/MM_PER_REV_Z)
  #define DEFAULT_AXIS1_MAX_RATE 5000.0 // mm/min
  #define DEFAULT_AXIS2_MAX_RATE 5000.0 // mm/min
  #define DEFAULT_AXIS3_MAX_RATE 5000.0 // mm/min
  #define DEFAULT_AXIS1_ACCELERATION (400.0*60*60) // 400*60*60 mm/min^2 = 400 mm/sec^2
  #define DEFAULT_AXIS2_ACCELERATION (400.0*60*60) // 400*60*60 mm/min^2 = 400 mm/sec^2
  #define DEFAULT_AXIS3_ACCELERATION (400.0*60*60) // 400*60*60 mm/min^2 = 400 mm/sec^2
  #define DEFAULT_AXIS1_MAX_TRAVEL 425.0 // mm NOTE: Must be a positive value.
  #define DEFAULT_AXIS2_MAX_TRAVEL 465.0 // mm NOTE: Must be a positive value.
  #define DEFAULT_AXIS3_MAX_TRAVEL 80.0 // mm NOTE: Must be a positive value.
  #define DEFAULT_SPINDLE_RPM_MAX 10000.0 // rpm
  #define DEFAULT_SPINDLE_RPM_MIN 0.0 // rpm
  #define DEFAULT_STEP_PULSE_MICROSECONDS 10
  #define DEFAULT_STEPPING_INVERT_MASK 0
  #define DEFAULT_DIRECTION_INVERT_MASK ((1<<AXIS_1)|(1<<AXIS_3))
  #define DEFAULT_STEPPER_IDLE_LOCK_TIME 255 // msec (0-254, 255 keeps steppers enabled)
  #define DEFAULT_STATUS_REPORT_MASK 1 // MPos enabled
  #define DEFAULT_JUNCTION_DEVIATION 0.02 // mm
  #define DEFAULT_ARC_TOLERANCE 0.01 // mm
  #define DEFAULT_REPORT_INCHES 0 // false
  #define DEFAULT_INVERT_ST_ENABLE 0 // false
  #define DEFAULT_INVERT_LIMIT_PINS 0 // false
  #define DEFAULT_SOFT_LIMIT_ENABLE 0 // false
  #define DEFAULT_HARD_LIMIT_ENABLE 0  // false
  #define DEFAULT_INVERT_PROBE_PIN 0 // false
  #define DEFAULT_LASER_MODE 0 // false
  #define DEFAULT_HOMING_ENABLE 0  // false
  #define DEFAULT_HOMING_DIR_MASK 0 // move positive dir
  #define DEFAULT_HOMING_FEED_RATE 100.0 // mm/min
  #define DEFAULT_HOMING_SEEK_RATE 1000.0 // mm/min
  #define DEFAULT_HOMING_DEBOUNCE_DELAY 25 // msec (0-65k)
  #define DEFAULT_HOMING_PULLOFF 5.0 // mm
#endif

#ifdef DEFAULTS_X_CARVE_500MM
  // Description: X-Carve 3D Carver CNC mill with three 200 step/rev motors driven by Synthetos
  // grblShield at 24V.
  #define MICROSTEPS_XY 8
  #define STEP_REVS_XY 200
  #define MM_PER_REV_XY (2.0*20) // 2mm belt pitch, 20 pulley teeth
  #define MICROSTEPS_Z 2
  #define STEP_REVS_Z 200
  #define MM_PER_REV_Z 2.117 // ACME 3/8-12 Leadscrew
  #define DEFAULT_AXIS1_STEPS_PER_UNIT (MICROSTEPS_XY*STEP_REVS_XY/MM_PER_REV_XY)
  #define DEFAULT_AXIS2_STEPS_PER_UNIT (MICROSTEPS_XY*STEP_REVS_XY/MM_PER_REV_XY)
  #define DEFAULT_AXIS3_STEPS_PER_UNIT (MICROSTEPS_Z*STEP_REVS_Z/MM_PER_REV_Z)
  #define DEFAULT_AXIS1_MAX_RATE 8000.0 // mm/min
  #define DEFAULT_AXIS2_MAX_RATE 8000.0 // mm/min
  #define DEFAULT_AXIS3_MAX_RATE 500.0 // mm/min
  #define DEFAULT_AXIS1_ACCELERATION (500.0*60*60) // 25*60*60 mm/min^2 = 25 mm/sec^2
  #define DEFAULT_AXIS2_ACCELERATION (500.0*60*60) // 25*60*60 mm/min^2 = 25 mm/sec^2
  #define DEFAULT_AXIS3_ACCELERATION (50.0*60*60) // 25*60*60 mm/min^2 = 25 mm/sec^2
  #define DEFAULT_AXIS1_MAX_TRAVEL 290.0 // mm NOTE: Must be a positive value.
  #define DEFAULT_AXIS2_MAX_TRAVEL 290.0 // mm NOTE: Must be a positive value.
  #define DEFAULT_AXIS3_MAX_TRAVEL 100.0 // mm NOTE: Must be a positive value.
  #define DEFAULT_SPINDLE_RPM_MAX 10000.0 // rpm
  #define DEFAULT_SPINDLE_RPM_MIN 0.0 // rpm
  #define DEFAULT_STEP_PULSE_MICROSECONDS 10
  #define DEFAULT_STEPPING_INVERT_MASK 0
  #define DEFAULT_DIRECTION_INVERT_MASK ((1<<AXIS_1)|(1<<AXIS_2))
  #define DEFAULT_STEPPER_IDLE_LOCK_TIME 255 // msec (0-254, 255 keeps steppers enabled)
  #define DEFAULT_STATUS_REPORT_MASK 1 // MPos enabled
  #define DEFAULT_JUNCTION_DEVIATION 0.02 // mm
  #define DEFAULT_ARC_TOLERANCE 0.002 // mm
  #define DEFAULT_REPORT_INCHES 0 // false
  #define DEFAULT_INVERT_ST_ENABLE 0 // false
  #define DEFAULT_INVERT_LIMIT_PINS 0 // false
  #define DEFAULT_SOFT_LIMIT_ENABLE 0 // false
  #define DEFAULT_HARD_LIMIT_ENABLE 0  // false
  #define DEFAULT_INVERT_PROBE_PIN 0 // false
  #define DEFAULT_LASER_MODE 0 // false
  #define DEFAULT_HOMING_ENABLE 0  // false
  #define DEFAULT_HOMING_DIR_MASK 3 // move positive dir
  #define DEFAULT_HOMING_FEED_RATE 25.0 // mm/min
  #define DEFAULT_HOMING_SEEK_RATE 750.0 // mm/min
  #define DEFAULT_HOMING_DEBOUNCE_DELAY 250 // msec (0-65k)
  #define DEFAULT_HOMING_PULLOFF 1.0 // mm
#endif

#ifdef DEFAULTS_X_CARVE_1000MM
  // Description: X-Carve 3D Carver CNC mill with three 200 step/rev motors driven by Synthetos
  // grblShield at 24V.
  #define MICROSTEPS_XY 8
  #define STEP_REVS_XY 200
  #define MM_PER_REV_XY (2.0*20) // 2mm belt pitch, 20 pulley teeth
  #define MICROSTEPS_Z 2
  #define STEP_REVS_Z 200
  #define MM_PER_REV_Z 2.117 // ACME 3/8-12 Leadscrew
  #define DEFAULT_AXIS1_STEPS_PER_UNIT (MICROSTEPS_XY*STEP_REVS_XY/MM_PER_REV_XY)
  #define DEFAULT_AXIS2_STEPS_PER_UNIT (MICROSTEPS_XY*STEP_REVS_XY/MM_PER_REV_XY)
  #define DEFAULT_AXIS3_STEPS_PER_UNIT (MICROSTEPS_Z*STEP_REVS_Z/MM_PER_REV_Z)
  #define DEFAULT_AXIS1_MAX_RATE 8000.0 // mm/min
  #define DEFAULT_AXIS2_MAX_RATE 8000.0 // mm/min
  #define DEFAULT_AXIS3_MAX_RATE 500.0 // mm/min
  #define DEFAULT_AXIS1_ACCELERATION (500.0*60*60) // 25*60*60 mm/min^2 = 25 mm/sec^2
  #define DEFAULT_AXIS2_ACCELERATION (500.0*60*60) // 25*60*60 mm/min^2 = 25 mm/sec^2
  #define DEFAULT_AXIS3_ACCELERATION (50.0*60*60) // 25*60*60 mm/min^2 = 25 mm/sec^2
  #define DEFAULT_AXIS1_MAX_TRAVEL 740.0 // mm NOTE: Must be a positive value.
  #define DEFAULT_AXIS2_MAX_TRAVEL 790.0 // mm NOTE: Must be a positive value.
  #define DEFAULT_AXIS3_MAX_TRAVEL 100.0 // mm NOTE: Must be a positive value.
  #define DEFAULT_SPINDLE_RPM_MAX 10000.0 // rpm
  #define DEFAULT_SPINDLE_RPM_MIN 0.0 // rpm
  #define DEFAULT_STEP_PULSE_MICROSECONDS 10
  #define DEFAULT_STEPPING_INVERT_MASK 0
  #define DEFAULT_DIRECTION_INVERT_MASK ((1<<AXIS_1)|(1<<AXIS_2))
  #define DEFAULT_STEPPER_IDLE_LOCK_TIME 255 // msec (0-254, 255 keeps steppers enabled)
  #define DEFAULT_STATUS_REPORT_MASK 1 // MPos enabled
  #define DEFAULT_JUNCTION_DEVIATION 0.02 // mm
  #define DEFAULT_ARC_TOLERANCE 0.002 // mm
  #define DEFAULT_REPORT_INCHES 0 // false
  #define DEFAULT_INVERT_ST_ENABLE 0 // false
  #define DEFAULT_INVERT_LIMIT_PINS 0 // false
  #define DEFAULT_SOFT_LIMIT_ENABLE 0 // false
  #define DEFAULT_HARD_LIMIT_ENABLE 0  // false
  #define DEFAULT_INVERT_PROBE_PIN 0 // false
  #define DEFAULT_LASER_MODE 0 // false
  #define DEFAULT_HOMING_ENABLE 0  // false
  #define DEFAULT_HOMING_DIR_MASK 3 // move positive dir
  #define DEFAULT_HOMING_FEED_RATE 25.0 // mm/min
  #define DEFAULT_HOMING_SEEK_RATE 750.0 // mm/min
  #define DEFAULT_HOMING_DEBOUNCE_DELAY 250 // msec (0-65k)
  #define DEFAULT_HOMING_PULLOFF 1.0 // mm
#endif

#ifdef DEFAULTS_ZEN_TOOLWORKS_7x7
  // Description: Zen Toolworks 7x7 mill with three Shinano SST43D2121 65oz-in NEMA 17 stepper motors.
  // Leadscrew is different from some ZTW kits, where most are 1.25mm/rev rather than 8.0mm/rev here.
  // Driven by 30V, 6A power supply and TI DRV8811 stepper motor drivers.
  #define MICROSTEPS 8
  #define STEPS_PER_REV 200.0
  #define MM_PER_REV 8.0 // 8 mm/rev leadscrew
  #define DEFAULT_AXIS1_STEPS_PER_UNIT (STEPS_PER_REV*MICROSTEPS/MM_PER_REV)
  #define DEFAULT_AXIS2_STEPS_PER_UNIT (STEPS_PER_REV*MICROSTEPS/MM_PER_REV)
  #define DEFAULT_AXIS3_STEPS_PER_UNIT (STEPS_PER_REV*MICROSTEPS/MM_PER_REV)
  #define DEFAULT_AXIS1_MAX_RATE 6000.0 // mm/min
  #define DEFAULT_AXIS2_MAX_RATE 6000.0 // mm/min
  #define DEFAULT_AXIS3_MAX_RATE 6000.0 // mm/min
  #define DEFAULT_AXIS1_ACCELERATION (600.0*60*60) // 600*60*60 mm/min^2 = 600 mm/sec^2
  #define DEFAULT_AXIS2_ACCELERATION (600.0*60*60) // 600*60*60 mm/min^2 = 600 mm/sec^2
  #define DEFAULT_AXIS3_ACCELERATION (600.0*60*60) // 600*60*60 mm/min^2 = 600 mm/sec^2
  #define DEFAULT_AXIS1_MAX_TRAVEL 190.0 // mm NOTE: Must be a positive value.
  #define DEFAULT_AXIS2_MAX_TRAVEL 180.0 // mm NOTE: Must be a positive value.
  #define DEFAULT_AXIS3_MAX_TRAVEL 150.0 // mm NOTE: Must be a positive value.
  #define DEFAULT_SPINDLE_RPM_MAX 10000.0 // rpm
  #define DEFAULT_SPINDLE_RPM_MIN 0.0 // rpm
  #define DEFAULT_STEP_PULSE_MICROSECONDS 10
  #define DEFAULT_STEPPING_INVERT_MASK 0
  #define DEFAULT_DIRECTION_INVERT_MASK ((1<<AXIS_2))
  #define DEFAULT_STEPPER_IDLE_LOCK_TIME 25 // msec (0-254, 255 keeps steppers enabled)
  #define DEFAULT_STATUS_REPORT_MASK 1 // MPos enabled
  #define DEFAULT_JUNCTION_DEVIATION 0.02 // mm
  #define DEFAULT_ARC_TOLERANCE 0.002 // mm
  #define DEFAULT_REPORT_INCHES 0 // false
  #define DEFAULT_INVERT_ST_ENABLE 0 // false
  #define DEFAULT_INVERT_LIMIT_PINS 0 // false
  #define DEFAULT_SOFT_LIMIT_ENABLE 0 // false
  #define DEFAULT_HARD_LIMIT_ENABLE 0  // false
  #define DEFAULT_INVERT_PROBE_PIN 0 // false
  #define DEFAULT_LASER_MODE 0 // false
  #define DEFAULT_HOMING_ENABLE 0  // false
  #define DEFAULT_HOMING_DIR_MASK 0 // move positive dir
  #define DEFAULT_HOMING_FEED_RATE 25.0 // mm/min
  #define DEFAULT_HOMING_SEEK_RATE 250.0 // mm/min
  #define DEFAULT_HOMING_DEBOUNCE_DELAY 250 // msec (0-65k)
  #define DEFAULT_HOMING_PULLOFF 1.0 // mm
#endif

#ifdef DEFAULTS_OXCNC
  // Grbl settings for OpenBuilds OX CNC Machine
  // http://www.openbuilds.com/builds/openbuilds-ox-cnc-machine.341/
  #define DEFAULT_AXIS1_STEPS_PER_UNIT 26.670
  #define DEFAULT_AXIS2_STEPS_PER_UNIT 26.670
  #define DEFAULT_AXIS3_STEPS_PER_UNIT 50
  #define DEFAULT_AXIS1_MAX_RATE 500.0 // mm/min
  #define DEFAULT_AXIS2_MAX_RATE 500.0 // mm/min
  #define DEFAULT_AXIS3_MAX_RATE 500.0 // mm/min
  #define DEFAULT_AXIS1_ACCELERATION (10.0*60*60) // 10*60*60 mm/min^2 = 10 mm/sec^2
  #define DEFAULT_AXIS2_ACCELERATION (10.0*60*60) // 10*60*60 mm/min^2 = 10 mm/sec^2
  #define DEFAULT_AXIS3_ACCELERATION (10.0*60*60) // 10*60*60 mm/min^2 = 10 mm/sec^2
  #define DEFAULT_AXIS1_MAX_TRAVEL 500.0 // mm NOTE: Must be a positive value.
  #define DEFAULT_AXIS2_MAX_TRAVEL 750.0 // mm NOTE: Must be a positive value.
  #define DEFAULT_AXIS3_MAX_TRAVEL 80.0 // mm NOTE: Must be a positive value.
  #define DEFAULT_SPINDLE_RPM_MAX 1000.0 // rpm
  #define DEFAULT_SPINDLE_RPM_MIN 0.0 // rpm
  #define DEFAULT_STEP_PULSE_MICROSECONDS 10
  #define DEFAULT_STEPPING_INVERT_MASK 0
  #define DEFAULT_DIRECTION_INVERT_MASK 0
  #define DEFAULT_STEPPER_IDLE_LOCK_TIME 25 // msec (0-254, 255 keeps steppers enabled)
  #define DEFAULT_STATUS_REPORT_MASK 1 // MPos enabled
  #define DEFAULT_JUNCTION_DEVIATION 0.02 // mm
  #define DEFAULT_ARC_TOLERANCE 0.002 // mm
  #define DEFAULT_REPORT_INCHES 0 // false
  #define DEFAULT_INVERT_ST_ENABLE 0 // false
  #define DEFAULT_INVERT_LIMIT_PINS 0 // false
  #define DEFAULT_SOFT_LIMIT_ENABLE 0 // false
  #define DEFAULT_HARD_LIMIT_ENABLE 0  // false
  #define DEFAULT_INVERT_PROBE_PIN 0 // false
  #define DEFAULT_LASER_MODE 0 // false
  #define DEFAULT_HOMING_ENABLE 0  // false
  #define DEFAULT_HOMING_DIR_MASK 0 // move positive dir
  #define DEFAULT_HOMING_FEED_RATE 25.0 // mm/min
  #define DEFAULT_HOMING_SEEK_RATE 500.0 // mm/min
  #define DEFAULT_HOMING_DEBOUNCE_DELAY 250 // msec (0-65k)
  #define DEFAULT_HOMING_PULLOFF 1.0 // mm
#endif

#ifdef DEFAULTS_SIMULATOR
  // Settings only for Grbl Simulator (www.github.com/grbl/grbl-sim)
  // Grbl generic default settings. Should work across different machines.
  #define DEFAULT_AXIS1_STEPS_PER_UNIT 1000.0
  #define DEFAULT_AXIS2_STEPS_PER_UNIT 1000.0
  #define DEFAULT_AXIS3_STEPS_PER_UNIT 1000.0
  #define DEFAULT_AXIS1_MAX_RATE 1000.0 // mm/min
  #define DEFAULT_AXIS2_MAX_RATE 1000.0 // mm/min
  #define DEFAULT_AXIS3_MAX_RATE 1000.0 // mm/min
  #define DEFAULT_AXIS1_ACCELERATION (100.0*60*60) // 10*60*60 mm/min^2 = 10 mm/sec^2
  #define DEFAULT_AXIS2_ACCELERATION (100.0*60*60) // 10*60*60 mm/min^2 = 10 mm/sec^2
  #define DEFAULT_AXIS3_ACCELERATION (100.0*60*60) // 10*60*60 mm/min^2 = 10 mm/sec^2
  #define DEFAULT_AXIS1_MAX_TRAVEL 1000.0 // mm NOTE: Must be a positive value.
  #define DEFAULT_AXIS2_MAX_TRAVEL 1000.0 // mm NOTE: Must be a positive value.
  #define DEFAULT_AXIS3_MAX_TRAVEL 1000.0 // mm NOTE: Must be a positive value.
  #define DEFAULT_SPINDLE_RPM_MAX 1000.0 // rpm
  #define DEFAULT_SPINDLE_RPM_MIN 0.0 // rpm
  #define DEFAULT_STEP_PULSE_MICROSECONDS 10
  #define DEFAULT_STEPPING_INVERT_MASK 0
  #define DEFAULT_DIRECTION_INVERT_MASK 0
  #define DEFAULT_STEPPER_IDLE_LOCK_TIME 25 // msec (0-254, 255 keeps steppers enabled)
  #define DEFAULT_STATUS_REPORT_MASK 1 // MPos enabled
  #define DEFAULT_JUNCTION_DEVIATION 0.01 // mm
  #define DEFAULT_ARC_TOLERANCE 0.002 // mm
  #define DEFAULT_REPORT_INCHES 0 // false
  #define DEFAULT_INVERT_ST_ENABLE 0 // false
  #define DEFAULT_INVERT_LIMIT_PINS 0 // false
  #define DEFAULT_SOFT_LIMIT_ENABLE 0 // false
  #define DEFAULT_HARD_LIMIT_ENABLE 0  // false
  #define DEFAULT_INVERT_PROBE_PIN 0 // false
  #define DEFAULT_LASER_MODE 0 // false
  #define DEFAULT_HOMING_ENABLE 0  // false
  #define DEFAULT_HOMING_DIR_MASK 0 // move positive dir
  #define DEFAULT_HOMING_FEED_RATE 25.0 // mm/min
  #define DEFAULT_HOMING_SEEK_RATE 500.0 // mm/min
  #define DEFAULT_HOMING_DEBOUNCE_DELAY 250 // msec (0-65k)
  #define DEFAULT_HOMING_PULLOFF 1.0 // mm
#endif

#ifdef DEFAULTS_RAMPS_BOARD_ORIGINAL
  #define MICROSTEPS_AXIS1 4     // Microstepping = 1/4 pas
  #define STEP_REVS_AXIS1 200    // Moteurs à 200 pas par tour
  #define UNIT_PER_REV_AXIS1 2.0 // 2mm
  #define DEFAULT_AXIS1_STEPS_PER_UNIT (MICROSTEPS_AXIS1*STEP_REVS_AXIS1/UNIT_PER_REV_AXIS1) // 400
  #define MICROSTEPS_AXIS2 4     // Microstepping = 1/4 pas
  #define STEP_REVS_AXIS2 200    // Moteurs à 200 pas par tour
  #define UNIT_PER_REV_AXIS2 2.0 // 2mm
  #define DEFAULT_AXIS2_STEPS_PER_UNIT (MICROSTEPS_AXIS2*STEP_REVS_AXIS2/UNIT_PER_REV_AXIS2)
  #define MICROSTEPS_AXIS3 4     // Microstepping = 1/4 pas
  #define STEP_REVS_AXIS3 200    // Moteurs à 200 pas par tour
  #define UNIT_PER_REV_AXIS3 2.0 // 2mm
  #define DEFAULT_AXIS3_STEPS_PER_UNIT (MICROSTEPS_AXIS3*STEP_REVS_AXIS3/UNIT_PER_REV_AXIS3)
  #define STEP_MAX_FREQUENCY 5000
  #define SECONDS_PER_MINUTE 60
  //#define DEFAULT_AXIS1_MAX_RATE 9000.0 // 9000 mm/min = 9000/60 = 150 mm/sec
  #define DEFAULT_AXIS1_MAX_RATE (STEP_MAX_FREQUENCY/DEFAULT_AXIS1_STEPS_PER_UNIT*SECONDS_PER_MINUTE) // 3000
  //#define DEFAULT_AXIS2_MAX_RATE 9000.0 // 9000 mm/min = 9000/60 = 150 mm/sec
  #define DEFAULT_AXIS2_MAX_RATE (STEP_MAX_FREQUENCY/DEFAULT_AXIS2_STEPS_PER_UNIT*SECONDS_PER_MINUTE)
  //#define DEFAULT_AXIS3_MAX_RATE 300.0  //  300 mm/min =  300/60 =   5 mm/sec
  #define DEFAULT_AXIS3_MAX_RATE (STEP_MAX_FREQUENCY/DEFAULT_AXIS3_STEPS_PER_UNIT*SECONDS_PER_MINUTE)
  #define DEFAULT_AXIS1_ACCELERATION (50.0*60*60) // 300*60*60 mm/min^2 = 300 mm/sec^2
  #define DEFAULT_AXIS2_ACCELERATION (50.0*60*60) // 300*60*60 mm/min^2 = 300 mm/sec^2
  #define DEFAULT_AXIS3_ACCELERATION (50.0*60*60) // 100*60*60 mm/min^2 = 100 mm/sec^2
  #define DEFAULT_AXIS1_MAX_TRAVEL 400.0 // mm
  #define DEFAULT_AXIS2_MAX_TRAVEL 200.0 // mm
  #define DEFAULT_AXIS3_MAX_TRAVEL 200.0 // mm
  #if N_AXIS > 3
    #define DEFAULT_AXIS4_STEPS_PER_UNIT 8.888889 // Direct drive : (200 steps per revolution * 1/16 microsteps)/360°
    #define DEFAULT_AXIS4_MAX_RATE 1440 // °/mn
    #define DEFAULT_AXIS4_ACCELERATION (50.0*60*60) // 100*60*60 mm/min^2 = 100 mm/sec^2
    #define DEFAULT_AXIS4_MAX_TRAVEL 360.0 // °
  #endif
  #if N_AXIS > 4
    #define DEFAULT_AXIS5_STEPS_PER_UNIT 8.888889 // Direct drive : (200 steps per revolution * 1/16 microsteps)/360°
    #define DEFAULT_AXIS5_MAX_RATE 1440 // °/mn
    #define DEFAULT_AXIS5_ACCELERATION (50.0*60*60) // 100*60*60 mm/min^2 = 100 mm/sec^2
    #define DEFAULT_AXIS5_MAX_TRAVEL 180.0 // °
  #endif
  #if N_AXIS > 5
    #define DEFAULT_AXIS6_STEPS_PER_UNIT 8.888889 // Direct drive : (200 steps per revolution * 1/16 microsteps)/360°
    #define DEFAULT_AXIS6_MAX_RATE 1440 // °/mn
    #define DEFAULT_AXIS6_ACCELERATION (50.0*60*60) // 100*60*60 mm/min^2 = 100 mm/sec^2
    #define DEFAULT_AXIS6_MAX_TRAVEL 180.0 // °
  #endif
  #define DEFAULT_SPINDLE_RPM_MAX 12000 // rpm
  #define DEFAULT_SPINDLE_RPM_MIN 550.0 // rpm
  #define DEFAULT_STEP_PULSE_MICROSECONDS 10
  #define DEFAULT_STEPPING_INVERT_MASK 0
  #define DEFAULT_DIRECTION_INVERT_MASK 0
  #define DEFAULT_STEPPER_IDLE_LOCK_TIME 254 // msec (0-254, 255 keeps steppers enabled)
  #define DEFAULT_STATUS_REPORT_MASK 1 // MPos enabled
  #define DEFAULT_JUNCTION_DEVIATION 0.02 // mm
  #define DEFAULT_ARC_TOLERANCE 0.002 // mm
  #define DEFAULT_REPORT_INCHES 0 // false
  #define DEFAULT_INVERT_ST_ENABLE 0 // false
  #define DEFAULT_INVERT_LIMIT_PINS 0 // false
  #define DEFAULT_SOFT_LIMIT_ENABLE 1 // true
  #define DEFAULT_HARD_LIMIT_ENABLE 0  // false
  #define DEFAULT_INVERT_PROBE_PIN 0 // false
  #define DEFAULT_LASER_MODE 0 // false
  #define DEFAULT_HOMING_ENABLE 1  // true
  #define DEFAULT_HOMING_DIR_MASK 0 // move positive dir
  #define DEFAULT_HOMING_FEED_RATE 100.0 // mm/min
  #define DEFAULT_HOMING_SEEK_RATE 500.0 // mm/min
  #define DEFAULT_HOMING_DEBOUNCE_DELAY 250 // msec (0-65k)
  #define DEFAULT_HOMING_PULLOFF 5.0 // mm
#endif

#ifdef DEFAULTS_RAMPS_BOARD
  // Grbl settings for the PulpitRockCNC
  #define MICROSTEPS_AXIS1 8      // Microstepping = 8 --> two of the jumpers installed
  #define STEP_REVS_AXIS1 200     // Motors at 200 steps per revolution
  #define UNIT_PER_REV_AXIS1 1.25 // 1.25 mm/rev leadscrew
  #define DEFAULT_AXIS1_STEPS_PER_UNIT (MICROSTEPS_AXIS1*STEP_REVS_AXIS1/UNIT_PER_REV_AXIS1)
  #define MICROSTEPS_AXIS2 8      // Microstepping = 8 --> two of the jumpers installed
  #define STEP_REVS_AXIS2 200     // Motors at 200 steps per revolution
  #define UNIT_PER_REV_AXIS2 1.25 // 1.25 mm/rev leadscrew
  #define DEFAULT_AXIS2_STEPS_PER_UNIT (MICROSTEPS_AXIS2*STEP_REVS_AXIS2/UNIT_PER_REV_AXIS2)
  #define MICROSTEPS_AXIS3 8      // Microstepping = 8 --> two of jumpers installed
  #define STEP_REVS_AXIS3 200     // Motors at 200 steps per revolution
  #define UNIT_PER_REV_AXIS3 1.25 // 1.25 mm/rev leadscrew
  #define DEFAULT_AXIS3_STEPS_PER_UNIT (MICROSTEPS_AXIS3*STEP_REVS_AXIS3/UNIT_PER_REV_AXIS3)

  #define DEFAULT_AXIS1_MAX_RATE 7*60.0 // mm/min, 7 is max for Pulpit Rock CNC
  #define DEFAULT_AXIS2_MAX_RATE 7*60.0 // mm/min, 7 is max for Pulpit Rock CNC
  #define DEFAULT_AXIS3_MAX_RATE 7*60.0 // mm/min, 7 is max for Pulpit Rock CNC

  #define DEFAULT_AXIS1_ACCELERATION (16.0*60*60) // 16*60*60 mm/min^2 = 16 mm/sec^2
  #define DEFAULT_AXIS2_ACCELERATION (16.0*60*60) // 16*60*60 mm/min^2 = 16 mm/sec^2
  #define DEFAULT_AXIS3_ACCELERATION (16.0*60*60) // 16*60*60 mm/min^2 = 16 mm/sec^2

  // The Pulpit Rock CNC has the following dimensions:
  // X Min = 0
  // X Max = 320
  // Y Min = 0
  // Y Max = 230
  // Z Min = 0
  // Z Max = -75
  #define DEFAULT_AXIS1_MAX_TRAVEL 320.0 // mm 
  #define DEFAULT_AXIS2_MAX_TRAVEL 230.0 // mm 
  #define DEFAULT_AXIS3_MAX_TRAVEL 75.0 // mm (from 0 to -75) 

  #define DEFAULT_SPINDLE_RPM_MAX 12000 // rpm
  #define DEFAULT_SPINDLE_RPM_MIN 550.0 // rpm

  #define DEFAULT_STEP_PULSE_MICROSECONDS 10
  #define DEFAULT_STEPPING_INVERT_MASK 0

  // Note! grbl-mega-5x doesn't use the same direction masks as grbl
  // check https://github.com/fra589/grbl-Mega-5X/wiki/Limit-switches-and-homing
  #define DEFAULT_DIRECTION_INVERT_MASK 4 // x and y move per default, z moves downwards
  #define DEFAULT_STEPPER_IDLE_LOCK_TIME 254 // msec (0-254, 255 keeps steppers enabled)
  // Note! grbl-mega-5x doesn't use the same report mask as grbl
  // check https://github.com/fra589/grbl-Mega-5X/wiki/Grbl-Configuration
  #define DEFAULT_STATUS_REPORT_MASK 1 // Enable MPos: and Disable WPos:
  #define DEFAULT_JUNCTION_DEVIATION 0.02 // mm
  #define DEFAULT_ARC_TOLERANCE 0.002 // mm
  #define DEFAULT_REPORT_INCHES 0 // false
  #define DEFAULT_INVERT_ST_ENABLE 0 // false
  #define DEFAULT_INVERT_LIMIT_PINS 0 // false
  #define DEFAULT_SOFT_LIMIT_ENABLE 1 // true
  #define DEFAULT_HARD_LIMIT_ENABLE 1 // X and Y endstop installed to the minimum (zero point). Z max installed.
  #define DEFAULT_INVERT_PROBE_PIN 0 // false
  #define DEFAULT_LASER_MODE 0 // false
  #define DEFAULT_HOMING_ENABLE 1 // true
  #define DEFAULT_HOMING_DIR_MASK 3 // x and y home in minus direction, but z is inverted (see wiki)
  #define DEFAULT_HOMING_FEED_RATE 50.0 // mm/min (slower feed rate to "bump" the endstops)
  #define DEFAULT_HOMING_SEEK_RATE 1000.0 // mm/min (will saturate to MAX_RATE)
  #define DEFAULT_HOMING_DEBOUNCE_DELAY 250 // msec (0-65k)
  #define DEFAULT_HOMING_PULLOFF 2.0 // mm
#endif

#endif
