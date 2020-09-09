execute_process(COMMAND "/home/glab/fetch_TAMP/build/rosplan_rqt/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/glab/fetch_TAMP/build/rosplan_rqt/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
