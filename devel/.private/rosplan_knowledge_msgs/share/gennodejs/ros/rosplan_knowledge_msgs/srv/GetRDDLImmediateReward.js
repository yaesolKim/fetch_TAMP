// Auto-generated. Do not edit!

// (in-package rosplan_knowledge_msgs.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------


//-----------------------------------------------------------

class GetRDDLImmediateRewardRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.action = null;
    }
    else {
      if (initObj.hasOwnProperty('action')) {
        this.action = initObj.action
      }
      else {
        this.action = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type GetRDDLImmediateRewardRequest
    // Serialize message field [action]
    // Serialize the length for message field [action]
    bufferOffset = _serializer.uint32(obj.action.length, buffer, bufferOffset);
    obj.action.forEach((val) => {
      bufferOffset = std_msgs.msg.String.serialize(val, buffer, bufferOffset);
    });
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type GetRDDLImmediateRewardRequest
    let len;
    let data = new GetRDDLImmediateRewardRequest(null);
    // Deserialize message field [action]
    // Deserialize array length for message field [action]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.action = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.action[i] = std_msgs.msg.String.deserialize(buffer, bufferOffset)
    }
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    object.action.forEach((val) => {
      length += std_msgs.msg.String.getMessageSize(val);
    });
    return length + 4;
  }

  static datatype() {
    // Returns string type for a service object
    return 'rosplan_knowledge_msgs/GetRDDLImmediateRewardRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '82d47d99291b9d7a07526f5be97b9a5e';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    std_msgs/String[] action # Instantiated actions in the last timestep (i.e. goto_Waypoint(kenny, printer)
    
    ================================================================================
    MSG: std_msgs/String
    string data
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new GetRDDLImmediateRewardRequest(null);
    if (msg.action !== undefined) {
      resolved.action = new Array(msg.action.length);
      for (let i = 0; i < resolved.action.length; ++i) {
        resolved.action[i] = std_msgs.msg.String.Resolve(msg.action[i]);
      }
    }
    else {
      resolved.action = []
    }

    return resolved;
    }
};

class GetRDDLImmediateRewardResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.reward = null;
    }
    else {
      if (initObj.hasOwnProperty('reward')) {
        this.reward = initObj.reward
      }
      else {
        this.reward = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type GetRDDLImmediateRewardResponse
    // Serialize message field [reward]
    bufferOffset = _serializer.float64(obj.reward, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type GetRDDLImmediateRewardResponse
    let len;
    let data = new GetRDDLImmediateRewardResponse(null);
    // Deserialize message field [reward]
    data.reward = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 8;
  }

  static datatype() {
    // Returns string type for a service object
    return 'rosplan_knowledge_msgs/GetRDDLImmediateRewardResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '771556160cdcd4a7d44d50647196f540';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64 reward
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new GetRDDLImmediateRewardResponse(null);
    if (msg.reward !== undefined) {
      resolved.reward = msg.reward;
    }
    else {
      resolved.reward = 0.0
    }

    return resolved;
    }
};

module.exports = {
  Request: GetRDDLImmediateRewardRequest,
  Response: GetRDDLImmediateRewardResponse,
  md5sum() { return '837ccfec14d9d69a332bf7294d27c502'; },
  datatype() { return 'rosplan_knowledge_msgs/GetRDDLImmediateReward'; }
};
