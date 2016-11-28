# Boost's configuration.

LIST ( APPEND BOOST_LIB_SET
    thread
    serialization
    chrono
    timer
    date_time
    filesystem
    iostreams
    log
    log_setup
    program_options
    random
    regex
    system
)

IF ( ${CVNAR_TARGET_SYSTEM} STREQUAL "win32" )
  SET (Boost_REALPATH ON)
ENDIF ()

IF ( ${CVNAR_TARGET_SYSTEM} STREQUAL "qnx" )
  SET ( Boost_COMPILER qcc )
ENDIF ()

SET ( Boost_USE_STATIC_LIBS OFF )
SET ( Boost_NO_BOOST_CMAKE ON )

# Boost requires to set this macro when the binary is built as a dynamically loaded library.
# http://www.boost.org/doc/libs/1_57_0/libs/log/doc/html/log/installation/config.html
ADD_DEFINITIONS ( "-DBOOST_ALL_DYN_LINK" )

IF (NOT CVNAR_HAS_SYSTEM_BOOST )
   SET ( BOOST_ROOT "${CVNAR_TARGET_LIBS_PATH}")
   SET ( Boost_NO_SYSTEM_PATHS TRUE )
ENDIF ()

MESSAGE ( STATUS "-- Boost root path: ${BOOST_ROOT}; ${BOOSTROOT}" )
FIND_PACKAGE ( Boost 1.57.0 REQUIRED COMPONENTS ${BOOST_LIB_SET} )
INCLUDE_DIRECTORIES ( "${Boost_INCLUDE_DIRS}" )

SET ( BOOST_LIB_SET ${Boost_LIBRARIES} )

IF ( ${CVNAR_TARGET_SYSTEM} STREQUAL "win32" )
  LIST ( APPEND BOOST_LIB_SET "ws2_32" )
ELSEIF ( ${CVNAR_TARGET_SYSTEM} STREQUAL "qnx" )
  LIST ( APPEND BOOST_LIB_SET "socket" "z" )
ENDIF ()

MESSAGE(STATUS "Boost lib set is : ${BOOST_LIB_SET}")
