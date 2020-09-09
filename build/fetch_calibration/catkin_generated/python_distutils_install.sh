#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/glab/fetch_TAMP/src/fetch_ros/fetch_calibration"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/glab/fetch_TAMP/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/glab/fetch_TAMP/install/lib/python2.7/dist-packages:/home/glab/fetch_TAMP/build/fetch_calibration/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/glab/fetch_TAMP/build/fetch_calibration" \
    "/usr/bin/python2" \
    "/home/glab/fetch_TAMP/src/fetch_ros/fetch_calibration/setup.py" \
     \
    build --build-base "/home/glab/fetch_TAMP/build/fetch_calibration" \
    install \
    --root="${DESTDIR-/}" \
    --install-layout=deb --prefix="/home/glab/fetch_TAMP/install" --install-scripts="/home/glab/fetch_TAMP/install/bin"
