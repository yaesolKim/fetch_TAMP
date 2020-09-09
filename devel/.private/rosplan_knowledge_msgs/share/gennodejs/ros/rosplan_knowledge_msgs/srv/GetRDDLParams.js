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

class GetRDDLParamsRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
    }
    else {
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type GetRDDLParamsRequest
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type GetRDDLParamsRequest
    let len;
    let data = new GetRDDLParamsRequest(null);
    return data;
  }

  static getMessageSize(object) {
    return 0;
  }

  static datatype() {
    // Returns string type for a service object
    return 'rosplan_knowledge_msgs/GetRDDLParamsRequest';
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
    const resolved = new GetRDDLParamsRequest(null);
    return resolved;
    }
};

class GetRDDLParamsResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.horizon = null;
      this.discount_factor = null;
      this.max_nondef_actions = null;
    }
    else {
      if (initObj.hasOwnProperty('horizon')) {
        this.horizon = initObj.horizon
      }
      else {
        this.horizon = 0;
      }
      if (initObj.hasOwnProperty('discount_factor')) {
        this.discount_factor = initObj.discount_factor
      }
      else {
        this.discount_factor = 0.0;
      }
      if (initObj.hasOwnProperty('max_nondef_actions')) {
        this.max_nondef_actions = initObj.max_nondef_actions
      }
      else {
        this.max_nondef_actions = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type GetRDDLParamsResponse
    // Serialize message field [horizon]
    bufferOffset = _serializer.int32(obj.horizon, buffer, bufferOffset);
    // Serialize message field [discount_factor]
    bufferOffset = _serializer.float32(obj.discount_factor, buffer, bufferOffset);
    // Serialize message field [max_nondef_actions]
    bufferOffset = _serializer.int32(obj.max_nondef_actions, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type GetRDDLParamsResponse
    let len;
    let data = new GetRDDLParamsResponse(null);
    // Deserialize message field [horizon]
    data.horizon = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [discount_factor]
    data.discount_factor = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [max_nondef_actions]
    data.max_nondef_actions = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 12;
  }

  static datatype() {
    // Returns string type for a service object
    return 'rosplan_knowledge_msgs/GetRDDLParamsResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '0cf0ef8b4c4b342e8f951535dfe54dba';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32 horizon
    float32 discount_factor
    int32 max_nondef_actions
    
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new GetRDDLParamsResponse(null);
    if (msg.horizon !== undefined) {
      resolved.horizon = msg.horizon;
    }
    else {
      resolved.horizon = 0
    }

    if (msg.discount_factor !== undefined) {
      resolved.discount_factor = msg.discount_factor;
    }
    else {
      resolved.discount_factor = 0.0
    }

    if (msg.max_nondef_actions !== undefined) {
      resolved.max_nondef_actions = msg.max_nondef_actions;
    }
    else {
      resolved.max_nondef_actions = 0
    }

    return resolved;
    }
};

module.exports = {
  Request: GetRDDLParamsRequest,
  Response: GetRDDLParamsResponse,
  md5sum() { return '0cf0ef8b4c4b342e8f951535dfe54dba'; },
  datatype() { return 'rosplan_knowledge_msgs/GetRDDLParams'; }
};
