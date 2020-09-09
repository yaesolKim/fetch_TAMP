// Auto-generated. Do not edit!

// (in-package rosplan_knowledge_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class StatusUpdate {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.last_update_client = null;
      this.last_update_time = null;
    }
    else {
      if (initObj.hasOwnProperty('last_update_client')) {
        this.last_update_client = initObj.last_update_client
      }
      else {
        this.last_update_client = '';
      }
      if (initObj.hasOwnProperty('last_update_time')) {
        this.last_update_time = initObj.last_update_time
      }
      else {
        this.last_update_time = {secs: 0, nsecs: 0};
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type StatusUpdate
    // Serialize message field [last_update_client]
    bufferOffset = _serializer.string(obj.last_update_client, buffer, bufferOffset);
    // Serialize message field [last_update_time]
    bufferOffset = _serializer.time(obj.last_update_time, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type StatusUpdate
    let len;
    let data = new StatusUpdate(null);
    // Deserialize message field [last_update_client]
    data.last_update_client = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [last_update_time]
    data.last_update_time = _deserializer.time(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.last_update_client.length;
    return length + 12;
  }

  static datatype() {
    // Returns string type for a message object
    return 'rosplan_knowledge_msgs/StatusUpdate';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '184cadf1052e240c262af1a764339990';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # A message used to publish a status notification from the Knowledge Base
    # This status notifies that the KB has been updated.
    
    string last_update_client
    time last_update_time
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new StatusUpdate(null);
    if (msg.last_update_client !== undefined) {
      resolved.last_update_client = msg.last_update_client;
    }
    else {
      resolved.last_update_client = ''
    }

    if (msg.last_update_time !== undefined) {
      resolved.last_update_time = msg.last_update_time;
    }
    else {
      resolved.last_update_time = {secs: 0, nsecs: 0}
    }

    return resolved;
    }
};

module.exports = StatusUpdate;
