// Auto-generated. Do not edit!

// (in-package rosplan_knowledge_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let ExprComposite = require('./ExprComposite.js');
let DomainFormula = require('./DomainFormula.js');
let DomainAssignment = require('./DomainAssignment.js');

//-----------------------------------------------------------

class ProbabilisticEffect {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.probability = null;
      this.add_effects = null;
      this.del_effects = null;
      this.assign_effects = null;
    }
    else {
      if (initObj.hasOwnProperty('probability')) {
        this.probability = initObj.probability
      }
      else {
        this.probability = new ExprComposite();
      }
      if (initObj.hasOwnProperty('add_effects')) {
        this.add_effects = initObj.add_effects
      }
      else {
        this.add_effects = [];
      }
      if (initObj.hasOwnProperty('del_effects')) {
        this.del_effects = initObj.del_effects
      }
      else {
        this.del_effects = [];
      }
      if (initObj.hasOwnProperty('assign_effects')) {
        this.assign_effects = initObj.assign_effects
      }
      else {
        this.assign_effects = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ProbabilisticEffect
    // Serialize message field [probability]
    bufferOffset = ExprComposite.serialize(obj.probability, buffer, bufferOffset);
    // Serialize message field [add_effects]
    // Serialize the length for message field [add_effects]
    bufferOffset = _serializer.uint32(obj.add_effects.length, buffer, bufferOffset);
    obj.add_effects.forEach((val) => {
      bufferOffset = DomainFormula.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [del_effects]
    // Serialize the length for message field [del_effects]
    bufferOffset = _serializer.uint32(obj.del_effects.length, buffer, bufferOffset);
    obj.del_effects.forEach((val) => {
      bufferOffset = DomainFormula.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [assign_effects]
    // Serialize the length for message field [assign_effects]
    bufferOffset = _serializer.uint32(obj.assign_effects.length, buffer, bufferOffset);
    obj.assign_effects.forEach((val) => {
      bufferOffset = DomainAssignment.serialize(val, buffer, bufferOffset);
    });
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ProbabilisticEffect
    let len;
    let data = new ProbabilisticEffect(null);
    // Deserialize message field [probability]
    data.probability = ExprComposite.deserialize(buffer, bufferOffset);
    // Deserialize message field [add_effects]
    // Deserialize array length for message field [add_effects]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.add_effects = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.add_effects[i] = DomainFormula.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [del_effects]
    // Deserialize array length for message field [del_effects]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.del_effects = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.del_effects[i] = DomainFormula.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [assign_effects]
    // Deserialize array length for message field [assign_effects]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.assign_effects = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.assign_effects[i] = DomainAssignment.deserialize(buffer, bufferOffset)
    }
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += ExprComposite.getMessageSize(object.probability);
    object.add_effects.forEach((val) => {
      length += DomainFormula.getMessageSize(val);
    });
    object.del_effects.forEach((val) => {
      length += DomainFormula.getMessageSize(val);
    });
    object.assign_effects.forEach((val) => {
      length += DomainAssignment.getMessageSize(val);
    });
    return length + 12;
  }

  static datatype() {
    // Returns string type for a message object
    return 'rosplan_knowledge_msgs/ProbabilisticEffect';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '38057e6bf125b030ee96bd190e741d81';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # Message used to represent a Probabilistic effect 
    rosplan_knowledge_msgs/ExprComposite   probability
    rosplan_knowledge_msgs/DomainFormula[] add_effects # Add effects
    rosplan_knowledge_msgs/DomainFormula[] del_effects # Del effects
    rosplan_knowledge_msgs/DomainAssignment[] assign_effects # Assign effects, mainly used for RDDL Discrete distribution
    ================================================================================
    MSG: rosplan_knowledge_msgs/ExprComposite
    # A message used to represent a numerical expression; composite type (2/2)
    # stores an array of ExprBase as prefix notation
    
    # components
    ExprBase[] tokens
    
    ================================================================================
    MSG: rosplan_knowledge_msgs/ExprBase
    # A message used to represent a numerical expression; base types (1/2)
    
    # expression types
    uint8 CONSTANT = 0
    uint8 FUNCTION = 1
    uint8 OPERATOR = 2
    uint8 SPECIAL  = 3
    
    # operators
    uint8 ADD    = 0
    uint8 SUB    = 1
    uint8 MUL    = 2
    uint8 DIV    = 3
    uint8 UMINUS = 4
    
    # special types
    uint8 HASHT      = 0
    uint8 TOTAL_TIME = 1
    uint8 DURATION   = 2
    
    # expression base type
    uint8 expr_type
    
    # constant value
    float64 constant
    
    # function
    rosplan_knowledge_msgs/DomainFormula function
    
    # operator
    uint8 op
    
    # special
    uint8 special_type
    
    ================================================================================
    MSG: rosplan_knowledge_msgs/DomainFormula
    # A message used to represent an atomic formula from the domain.
    # typed_parameters matches label -> type
    string name
    diagnostic_msgs/KeyValue[] typed_parameters
    
    ================================================================================
    MSG: diagnostic_msgs/KeyValue
    string key # what to label this value when viewing
    string value # a value to track over time
    
    ================================================================================
    MSG: rosplan_knowledge_msgs/DomainAssignment
    # A message used to store the numeric effects of an action
    # Can be grounded or ungrounded
    
    uint8 ASSIGN   = 0
    uint8 INCREASE  = 1
    uint8 DECREASE = 2
    uint8 SCALE_UP = 3
    uint8 SCALE_DOWN = 4
    uint8 ASSIGN_CTS = 5
    
    uint8 assign_type
    
    rosplan_knowledge_msgs/DomainFormula LHS
    rosplan_knowledge_msgs/ExprComposite RHS
    
    bool grounded
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ProbabilisticEffect(null);
    if (msg.probability !== undefined) {
      resolved.probability = ExprComposite.Resolve(msg.probability)
    }
    else {
      resolved.probability = new ExprComposite()
    }

    if (msg.add_effects !== undefined) {
      resolved.add_effects = new Array(msg.add_effects.length);
      for (let i = 0; i < resolved.add_effects.length; ++i) {
        resolved.add_effects[i] = DomainFormula.Resolve(msg.add_effects[i]);
      }
    }
    else {
      resolved.add_effects = []
    }

    if (msg.del_effects !== undefined) {
      resolved.del_effects = new Array(msg.del_effects.length);
      for (let i = 0; i < resolved.del_effects.length; ++i) {
        resolved.del_effects[i] = DomainFormula.Resolve(msg.del_effects[i]);
      }
    }
    else {
      resolved.del_effects = []
    }

    if (msg.assign_effects !== undefined) {
      resolved.assign_effects = new Array(msg.assign_effects.length);
      for (let i = 0; i < resolved.assign_effects.length; ++i) {
        resolved.assign_effects[i] = DomainAssignment.Resolve(msg.assign_effects[i]);
      }
    }
    else {
      resolved.assign_effects = []
    }

    return resolved;
    }
};

module.exports = ProbabilisticEffect;
