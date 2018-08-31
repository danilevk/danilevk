
"use strict";

let RawMagnetic = require('./RawMagnetic.js');
let ControllerState = require('./ControllerState.js');
let HeightCommand = require('./HeightCommand.js');
let MotorPWM = require('./MotorPWM.js');
let MotorCommand = require('./MotorCommand.js');
let Altitude = require('./Altitude.js');
let ServoCommand = require('./ServoCommand.js');
let RawRC = require('./RawRC.js');
let ThrustCommand = require('./ThrustCommand.js');
let PositionXYCommand = require('./PositionXYCommand.js');
let RuddersCommand = require('./RuddersCommand.js');
let Compass = require('./Compass.js');
let RC = require('./RC.js');
let YawrateCommand = require('./YawrateCommand.js');
let MotorStatus = require('./MotorStatus.js');
let VelocityXYCommand = require('./VelocityXYCommand.js');
let HeadingCommand = require('./HeadingCommand.js');
let Altimeter = require('./Altimeter.js');
let AttitudeCommand = require('./AttitudeCommand.js');
let RawImu = require('./RawImu.js');
let VelocityZCommand = require('./VelocityZCommand.js');
let Supply = require('./Supply.js');

module.exports = {
  RawMagnetic: RawMagnetic,
  ControllerState: ControllerState,
  HeightCommand: HeightCommand,
  MotorPWM: MotorPWM,
  MotorCommand: MotorCommand,
  Altitude: Altitude,
  ServoCommand: ServoCommand,
  RawRC: RawRC,
  ThrustCommand: ThrustCommand,
  PositionXYCommand: PositionXYCommand,
  RuddersCommand: RuddersCommand,
  Compass: Compass,
  RC: RC,
  YawrateCommand: YawrateCommand,
  MotorStatus: MotorStatus,
  VelocityXYCommand: VelocityXYCommand,
  HeadingCommand: HeadingCommand,
  Altimeter: Altimeter,
  AttitudeCommand: AttitudeCommand,
  RawImu: RawImu,
  VelocityZCommand: VelocityZCommand,
  Supply: Supply,
};
