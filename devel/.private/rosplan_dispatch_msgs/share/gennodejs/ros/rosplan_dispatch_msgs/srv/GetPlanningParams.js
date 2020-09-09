// Auto-generated. Do not edit!

// (in-package rosplan_dispatch_msgs.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class GetPlanningParamsRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
    }
    else {
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type GetPlanningParamsRequest
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type GetPlanningParamsRequest
    let len;
    let data = new GetPlanningParamsRequest(null);
    return data;
  }

  static getMessageSize(object) {
    return 0;
  }

  static datatype() {
    // Returns string type for a service object
    return 'rosplan_dispatch_msgs/GetPlanningParamsRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'd41d8cd98f00b204e9800998ecf8427e';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new GetPlanningParamsRequest(null);
    return resolved;
    }
};

class GetPlanningParamsResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.domain_path = null;
      this.problem_path = null;
      this.planner_ready = null;
    }
    else {
      if (initObj.hasOwnProperty('domain_path')) {
        this.domain_path = initObj.domain_path
      }
      else {
        this.domain_path = '';
      }
      if (initObj.hasOwnProperty('problem_path')) {
        this.problem_path = initObj.problem_path
      }
      else {
        this.problem_path = '';
      }
      if (initObj.hasOwnProperty('planner_ready')) {
        this.planner_ready = initObj.planner_ready
      }
      else {
        this.planner_ready = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type GetPlanningParamsResponse
    // Serialize message field [domain_path]
    bufferOffset = _serializer.string(obj.domain_path, buffer, bufferOffset);
    // Serialize message field [problem_path]
    bufferOffset = _serializer.string(obj.problem_path, buffer, bufferOffset);
    // Serialize message field [planner_ready]
    bufferOffset = _serializer.bool(obj.planner_ready, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type GetPlanningParamsResponse
    let len;
    let data = new GetPlanningParamsResponse(null);
    // Deserialize message field [domain_path]
    data.domain_path = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [problem_path]
    data.problem_path = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [planner_ready]
    data.planner_ready = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.domain_path.length;
    length += object.problem_path.length;
    return length + 9;
  }

  static datatype() {
    // Returns string type for a service object
    return 'rosplan_dispatch_msgs/GetPlanningParamsResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'b809da7a1aeeaa475218aad83ae1b3c4';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string domain_path
    string problem_path
    bool planner_ready # True if the planner thread is started
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new GetPlanningParamsResponse(null);
    if (msg.domain_path !== undefined) {
      resolved.domain_path = msg.domain_path;
    }
    else {
      resolved.domain_path = ''
    }

    if (msg.problem_path !== undefined) {
      resolved.problem_path = msg.problem_path;
    }
    else {
      resolved.problem_path = ''
    }

    if (msg.planner_ready !== undefined) {
      resolved.planner_ready = msg.planner_ready;
    }
    else {
      resolved.planner_ready = false
    }

    return resolved;
    }
};

module.exports = {
  Request: GetPlanningParamsRequest,
  Response: GetPlanningParamsResponse,
  md5sum() { return 'b809da7a1aeeaa475218aad83ae1b3c4'; },
  datatype() { return 'rosplan_dispatch_msgs/GetPlanningParams'; }
};
