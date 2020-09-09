// Auto-generated. Do not edit!

// (in-package rosplan_knowledge_msgs.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class ReloadRDDLDomainProblemRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.problem_path = null;
    }
    else {
      if (initObj.hasOwnProperty('problem_path')) {
        this.problem_path = initObj.problem_path
      }
      else {
        this.problem_path = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ReloadRDDLDomainProblemRequest
    // Serialize message field [problem_path]
    bufferOffset = _serializer.string(obj.problem_path, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ReloadRDDLDomainProblemRequest
    let len;
    let data = new ReloadRDDLDomainProblemRequest(null);
    // Deserialize message field [problem_path]
    data.problem_path = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.problem_path.length;
    return length + 4;
  }

  static datatype() {
    // Returns string type for a service object
    return 'rosplan_knowledge_msgs/ReloadRDDLDomainProblemRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '292d3c8400a7f9aff04549bd1e88094e';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string problem_path
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ReloadRDDLDomainProblemRequest(null);
    if (msg.problem_path !== undefined) {
      resolved.problem_path = msg.problem_path;
    }
    else {
      resolved.problem_path = ''
    }

    return resolved;
    }
};

class ReloadRDDLDomainProblemResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.success = null;
    }
    else {
      if (initObj.hasOwnProperty('success')) {
        this.success = initObj.success
      }
      else {
        this.success = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ReloadRDDLDomainProblemResponse
    // Serialize message field [success]
    bufferOffset = _serializer.bool(obj.success, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ReloadRDDLDomainProblemResponse
    let len;
    let data = new ReloadRDDLDomainProblemResponse(null);
    // Deserialize message field [success]
    data.success = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a service object
    return 'rosplan_knowledge_msgs/ReloadRDDLDomainProblemResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '358e233cde0c8a8bcfea4ce193f8fc15';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool success
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ReloadRDDLDomainProblemResponse(null);
    if (msg.success !== undefined) {
      resolved.success = msg.success;
    }
    else {
      resolved.success = false
    }

    return resolved;
    }
};

module.exports = {
  Request: ReloadRDDLDomainProblemRequest,
  Response: ReloadRDDLDomainProblemResponse,
  md5sum() { return '46f5005f9ac31164db24c532bfe60e3b'; },
  datatype() { return 'rosplan_knowledge_msgs/ReloadRDDLDomainProblem'; }
};
