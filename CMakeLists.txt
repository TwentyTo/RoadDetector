CMAKE_MINIMUM_REQUIRED ( VERSION 3.0.0 FATAL_ERROR)

project(RoadDetector)

if( ${CMAKE_SYSTEM_NAME} STREQUAL "Windows" )
  set(CVNAR_TARGET_NAME "win32")
  set( CVNAR_TARGET_SYSTEM "win32" )
  set( CVNAR_TARGET_ARCH "x86" )
  add_definitions(-DWIN32 "-D_WIN32_WINNT=0x0501"
      "-DWIN32_LEAN_AND_MEAN"
      "-D_CRT_SECURE_NO_WARNINGS"
      "-D_SCL_SECURE_NO_WARNINGS"
      "-D_HAS_ITERATOR_DEBUGGING=0"
   )
elseif( ${CMAKE_SYSTEM_NAME} STREQUAL "Linux" )
   set(CVNAR_TARGET_NAME "linux")
   set( CVNAR_TARGET_SYSTEM "linux" )
   set(CVNAR_HAS_SYSTEM_BOOST ON)
   if(CMAKE_SIZEOF_VOID_P EQUAL 8)
      set( CVNAR_TARGET_ARCH "x86-64" )
   else()
      set( CVNAR_TARGET_ARCH "x86" )
   endif()
endif ()

list(APPEND CMAKE_PREFIX_PATH ${CVNAR_TARGET_LIBS_PATH})
set(Boost_USE_MULTITHREADED ON)
# Build configurations for boost lib
include ( "D:/study/Nir/BoostConfig.cmake" )
include_directories( "D:/work/git/cvnar/cvnar-external-libs/win32-x86/include" )
link_directories    ( "D:/work/git/cvnar/cvnar-external-libs/win32-x86" )
#===============================================================================
# OpenCV configuration.
#===============================================================================
SET(OpenCV_DIR "D:/work/git/cvnar/cvnar-external-libs/win32-x86/lib")
find_package(OpenCV REQUIRED)
include_directories ( ${OpenCV_INCLUDE_DIRS} )
include_directories ( ${OpenCV_INCLUDE_DIRS}/opencv )


set(SOURCE
#    ${SOURCE}
      Main.cpp
	  functions.cpp
#    PARENT_SCOPE
)


set(HEADERS
#    ${HEADERS}
		consts.hpp
		functions.hpp
#    PARENT_SCOPE
)

set(LIBS ${OpenCV_LIBRARIES} ${BOOST_LIB_SET})

add_executable(RoadDetector ${SOURCE} ${HEADERS})

target_link_libraries(RoadDetector ${LIBS})
