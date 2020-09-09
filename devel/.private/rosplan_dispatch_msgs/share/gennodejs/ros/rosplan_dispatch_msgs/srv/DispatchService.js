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

class DispatchServiceRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
    }
    else {
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type DispatchServiceRequest
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type DispatchServiceRequest
    let len;
    let data = new DispatchServiceRequest(null);
    return data;
  }

  static getMessageSize(object) {
    return 0;
  }

  static datatype() {
    // Returns string type for a service object
    return 'rosplan_dispatch_msgs/DispatchServiceRequest';
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
    const resolved = new DispatchServiceRequest(null);
    return resolved;
    }
};

class DispatchServiceResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.success = null;
      this.goal_achieved = null;
    }
    else {
      if (initObj.hasOwnProperty('success')) {
        this.success = initObj.success
      }
      else {
        this.success = false;
      }
      if (initObj.hasOwnProperty('goal_achieved')) {
        this.goal_achieved = initObj.goal_achieved
      }
      else {
        this.goal_achieved = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type DispatchServiceResponse
    // Serialize message field [success]
    bufferOffset = _serializer.bool(obj.success, buffer, bufferOffset);
    // Serialize message field [goal_achieved]
    bufferOffset = _serializer.bool(obj.goal_achieved, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type DispatchServiceResponse
    let len;
    let data = new DispatchServiceResponse(null);
    // Deserialize message field [success]
    data.success = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [goal_achieved]
    data.goal_achieved = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 2;
  }

  static datatype() {
    // Returns string type for a service object
    return 'rosplan_dispatch_msgs/DispatchServiceResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '7e14a3412cb82ba736fcf0fad2853ed3';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool success # True if the dispatch was successful
    bool goal_achieved # True if the goal is achieved after the dispatching
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new DispatchServiceResponse(null);
    if (msg.success !== undefined) {
      resolved.success = msg.success;
    }
    else {
      resolved.success = false
    }

    if (msg.goal_achieved !== undefined) {
      resolved.goal_achieved = msg.goal_achieved;
    }
    else {
      resolved.goal_achieved = false
    }

    return resolved;
    }
};

module.exports = {
  Request: DispatchServiceRequest,
  Response: DispatchServiceResponse,
  md5sum() { return '7e14a3412cb82ba736fcf0fad2853ed3'; },
  datatype() { return 'rosplan_dispatch_msgs/DispatchService'; }
};
