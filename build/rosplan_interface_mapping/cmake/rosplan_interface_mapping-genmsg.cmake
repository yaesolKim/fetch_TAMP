# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "rosplan_interface_mapping: 0 messages, 3 services")

set(MSG_I_FLAGS "-Igeometry_msgs:/opt/ros/melodic/share/geometry_msgs/cmake/../msg;-Istd_msgs:/opt/ros/melodic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(rosplan_interface_mapping_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/glab/fetch_TAMP/src/rosplan_demos/rosplan_demos_interfaces/rosplan_interface_mapping/srv/AddWaypoint.srv" NAME_WE)
add_custom_target(_rosplan_interface_mapping_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "rosplan_interface_mapping" "/home/glab/fetch_TAMP/src/rosplan_demos/rosplan_demos_interfaces/rosplan_interface_mapping/srv/AddWaypoint.srv" "geometry_msgs/Pose:geometry_msgs/Quaternion:geometry_msgs/Point:geometry_msgs/PoseStamped:std_msgs/Header"
)

get_filename_component(_filename "/home/glab/fetch_TAMP/src/rosplan_demos/rosplan_demos_interfaces/rosplan_interface_mapping/srv/RemoveWaypoint.srv" NAME_WE)
add_custom_target(_rosplan_interface_mapping_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "rosplan_interface_mapping" "/home/glab/fetch_TAMP/src/rosplan_demos/rosplan_demos_interfaces/rosplan_interface_mapping/srv/RemoveWaypoint.srv" ""
)

get_filename_component(_filename "/home/glab/fetch_TAMP/src/rosplan_demos/rosplan_demos_interfaces/rosplan_interface_mapping/srv/CreatePRM.srv" NAME_WE)
add_custom_target(_rosplan_interface_mapping_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "rosplan_interface_mapping" "/home/glab/fetch_TAMP/src/rosplan_demos/rosplan_demos_interfaces/rosplan_interface_mapping/srv/CreatePRM.srv" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages

### Generating Services
_generate_srv_cpp(rosplan_interface_mapping
  "/home/glab/fetch_TAMP/src/rosplan_demos/rosplan_demos_interfaces/rosplan_interface_mapping/srv/RemoveWaypoint.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rosplan_interface_mapping
)
_generate_srv_cpp(rosplan_interface_mapping
  "/home/glab/fetch_TAMP/src/rosplan_demos/rosplan_demos_interfaces/rosplan_interface_mapping/srv/AddWaypoint.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rosplan_interface_mapping
)
_generate_srv_cpp(rosplan_interface_mapping
  "/home/glab/fetch_TAMP/src/rosplan_demos/rosplan_demos_interfaces/rosplan_interface_mapping/srv/CreatePRM.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rosplan_interface_mapping
)

### Generating Module File
_generate_module_cpp(rosplan_interface_mapping
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rosplan_interface_mapping
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(rosplan_interface_mapping_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(rosplan_interface_mapping_generate_messages rosplan_interface_mapping_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/glab/fetch_TAMP/src/rosplan_demos/rosplan_demos_interfaces/rosplan_interface_mapping/srv/AddWaypoint.srv" NAME_WE)
add_dependencies(rosplan_interface_mapping_generate_messages_cpp _rosplan_interface_mapping_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/glab/fetch_TAMP/src/rosplan_demos/rosplan_demos_interfaces/rosplan_interface_mapping/srv/RemoveWaypoint.srv" NAME_WE)
add_dependencies(rosplan_interface_mapping_generate_messages_cpp _rosplan_interface_mapping_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/glab/fetch_TAMP/src/rosplan_demos/rosplan_demos_interfaces/rosplan_interface_mapping/srv/CreatePRM.srv" NAME_WE)
add_dependencies(rosplan_interface_mapping_generate_messages_cpp _rosplan_interface_mapping_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(rosplan_interface_mapping_gencpp)
add_dependencies(rosplan_interface_mapping_gencpp rosplan_interface_mapping_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS rosplan_interface_mapping_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages

### Generating Services
_generate_srv_eus(rosplan_interface_mapping
  "/home/glab/fetch_TAMP/src/rosplan_demos/rosplan_demos_interfaces/rosplan_interface_mapping/srv/RemoveWaypoint.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/rosplan_interface_mapping
)
_generate_srv_eus(rosplan_interface_mapping
  "/home/glab/fetch_TAMP/src/rosplan_demos/rosplan_demos_interfaces/rosplan_interface_mapping/srv/AddWaypoint.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/rosplan_interface_mapping
)
_generate_srv_eus(rosplan_interface_mapping
  "/home/glab/fetch_TAMP/src/rosplan_demos/rosplan_demos_interfaces/rosplan_interface_mapping/srv/CreatePRM.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/rosplan_interface_mapping
)

### Generating Module File
_generate_module_eus(rosplan_interface_mapping
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/rosplan_interface_mapping
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(rosplan_interface_mapping_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(rosplan_interface_mapping_generate_messages rosplan_interface_mapping_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/glab/fetch_TAMP/src/rosplan_demos/rosplan_demos_interfaces/rosplan_interface_mapping/srv/AddWaypoint.srv" NAME_WE)
add_dependencies(rosplan_interface_mapping_generate_messages_eus _rosplan_interface_mapping_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/glab/fetch_TAMP/src/rosplan_demos/rosplan_demos_interfaces/rosplan_interface_mapping/srv/RemoveWaypoint.srv" NAME_WE)
add_dependencies(rosplan_interface_mapping_generate_messages_eus _rosplan_interface_mapping_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/glab/fetch_TAMP/src/rosplan_demos/rosplan_demos_interfaces/rosplan_interface_mapping/srv/CreatePRM.srv" NAME_WE)
add_dependencies(rosplan_interface_mapping_generate_messages_eus _rosplan_interface_mapping_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(rosplan_interface_mapping_geneus)
add_dependencies(rosplan_interface_mapping_geneus rosplan_interface_mapping_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS rosplan_interface_mapping_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages

### Generating Services
_generate_srv_lisp(rosplan_interface_mapping
  "/home/glab/fetch_TAMP/src/rosplan_demos/rosplan_demos_interfaces/rosplan_interface_mapping/srv/RemoveWaypoint.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rosplan_interface_mapping
)
_generate_srv_lisp(rosplan_interface_mapping
  "/home/glab/fetch_TAMP/src/rosplan_demos/rosplan_demos_interfaces/rosplan_interface_mapping/srv/AddWaypoint.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rosplan_interface_mapping
)
_generate_srv_lisp(rosplan_interface_mapping
  "/home/glab/fetch_TAMP/src/rosplan_demos/rosplan_demos_interfaces/rosplan_interface_mapping/srv/CreatePRM.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rosplan_interface_mapping
)

### Generating Module File
_generate_module_lisp(rosplan_interface_mapping
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rosplan_interface_mapping
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(rosplan_interface_mapping_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(rosplan_interface_mapping_generate_messages rosplan_interface_mapping_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/glab/fetch_TAMP/src/rosplan_demos/rosplan_demos_interfaces/rosplan_interface_mapping/srv/AddWaypoint.srv" NAME_WE)
add_dependencies(rosplan_interface_mapping_generate_messages_lisp _rosplan_interface_mapping_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/glab/fetch_TAMP/src/rosplan_demos/rosplan_demos_interfaces/rosplan_interface_mapping/srv/RemoveWaypoint.srv" NAME_WE)
add_dependencies(rosplan_interface_mapping_generate_messages_lisp _rosplan_interface_mapping_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/glab/fetch_TAMP/src/rosplan_demos/rosplan_demos_interfaces/rosplan_interface_mapping/srv/CreatePRM.srv" NAME_WE)
add_dependencies(rosplan_interface_mapping_generate_messages_lisp _rosplan_interface_mapping_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(rosplan_interface_mapping_genlisp)
add_dependencies(rosplan_interface_mapping_genlisp rosplan_interface_mapping_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS rosplan_interface_mapping_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages

### Generating Services
_generate_srv_nodejs(rosplan_interface_mapping
  "/home/glab/fetch_TAMP/src/rosplan_demos/rosplan_demos_interfaces/rosplan_interface_mapping/srv/RemoveWaypoint.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/rosplan_interface_mapping
)
_generate_srv_nodejs(rosplan_interface_mapping
  "/home/glab/fetch_TAMP/src/rosplan_demos/rosplan_demos_interfaces/rosplan_interface_mapping/srv/AddWaypoint.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/rosplan_interface_mapping
)
_generate_srv_nodejs(rosplan_interface_mapping
  "/home/glab/fetch_TAMP/src/rosplan_demos/rosplan_demos_interfaces/rosplan_interface_mapping/srv/CreatePRM.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/rosplan_interface_mapping
)

### Generating Module File
_generate_module_nodejs(rosplan_interface_mapping
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/rosplan_interface_mapping
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(rosplan_interface_mapping_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(rosplan_interface_mapping_generate_messages rosplan_interface_mapping_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/glab/fetch_TAMP/src/rosplan_demos/rosplan_demos_interfaces/rosplan_interface_mapping/srv/AddWaypoint.srv" NAME_WE)
add_dependencies(rosplan_interface_mapping_generate_messages_nodejs _rosplan_interface_mapping_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/glab/fetch_TAMP/src/rosplan_demos/rosplan_demos_interfaces/rosplan_interface_mapping/srv/RemoveWaypoint.srv" NAME_WE)
add_dependencies(rosplan_interface_mapping_generate_messages_nodejs _rosplan_interface_mapping_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/glab/fetch_TAMP/src/rosplan_demos/rosplan_demos_interfaces/rosplan_interface_mapping/srv/CreatePRM.srv" NAME_WE)
add_dependencies(rosplan_interface_mapping_generate_messages_nodejs _rosplan_interface_mapping_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(rosplan_interface_mapping_gennodejs)
add_dependencies(rosplan_interface_mapping_gennodejs rosplan_interface_mapping_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS rosplan_interface_mapping_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages

### Generating Services
_generate_srv_py(rosplan_interface_mapping
  "/home/glab/fetch_TAMP/src/rosplan_demos/rosplan_demos_interfaces/rosplan_interface_mapping/srv/RemoveWaypoint.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rosplan_interface_mapping
)
_generate_srv_py(rosplan_interface_mapping
  "/home/glab/fetch_TAMP/src/rosplan_demos/rosplan_demos_interfaces/rosplan_interface_mapping/srv/AddWaypoint.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rosplan_interface_mapping
)
_generate_srv_py(rosplan_interface_mapping
  "/home/glab/fetch_TAMP/src/rosplan_demos/rosplan_demos_interfaces/rosplan_interface_mapping/srv/CreatePRM.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rosplan_interface_mapping
)

### Generating Module File
_generate_module_py(rosplan_interface_mapping
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rosplan_interface_mapping
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(rosplan_interface_mapping_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(rosplan_interface_mapping_generate_messages rosplan_interface_mapping_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/glab/fetch_TAMP/src/rosplan_demos/rosplan_demos_interfaces/rosplan_interface_mapping/srv/AddWaypoint.srv" NAME_WE)
add_dependencies(rosplan_interface_mapping_generate_messages_py _rosplan_interface_mapping_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/glab/fetch_TAMP/src/rosplan_demos/rosplan_demos_interfaces/rosplan_interface_mapping/srv/RemoveWaypoint.srv" NAME_WE)
add_dependencies(rosplan_interface_mapping_generate_messages_py _rosplan_interface_mapping_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/glab/fetch_TAMP/src/rosplan_demos/rosplan_demos_interfaces/rosplan_interface_mapping/srv/CreatePRM.srv" NAME_WE)
add_dependencies(rosplan_interface_mapping_generate_messages_py _rosplan_interface_mapping_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(rosplan_interface_mapping_genpy)
add_dependencies(rosplan_interface_mapping_genpy rosplan_interface_mapping_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS rosplan_interface_mapping_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rosplan_interface_mapping)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rosplan_interface_mapping
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(rosplan_interface_mapping_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/rosplan_interface_mapping)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/rosplan_interface_mapping
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_eus)
  add_dependencies(rosplan_interface_mapping_generate_messages_eus geometry_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rosplan_interface_mapping)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rosplan_interface_mapping
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(rosplan_interface_mapping_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/rosplan_interface_mapping)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/rosplan_interface_mapping
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_nodejs)
  add_dependencies(rosplan_interface_mapping_generate_messages_nodejs geometry_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rosplan_interface_mapping)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rosplan_interface_mapping\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rosplan_interface_mapping
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(rosplan_interface_mapping_generate_messages_py geometry_msgs_generate_messages_py)
endif()
