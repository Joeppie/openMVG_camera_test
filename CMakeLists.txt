cmake_minimum_required(VERSION 3.5)
project(Spherical_Cam_Test)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)

#todo/note; USER is specific to linux OS, USERNAME is the windows equivalent.
SET(OpenMVG_DIR "/home/$ENV{USER}/openMVG_Build/openMVG_install/share/openMVG/cmake")
find_package(OpenMVG REQUIRED)
find_package( GDAL REQUIRED)

#set the directories required to link into openMVG.
message(OpenMVG Root install dir is registered as: ${CURRENT_ROOT_INSTALL_DIR})
include_directories("${CURRENT_ROOT_INSTALL_DIR}/include")
include_directories("${CURRENT_ROOT_INSTALL_DIR}/include/openMVG")
include_directories("${CURRENT_ROOT_INSTALL_DIR}/include/openMVG/third_party/histogram")
include_directories("${CURRENT_ROOT_INSTALL_DIR}/include/openMVG/third_party/eigen")

SET(GDAL_INCLUDE_DIR "/usr/include/gdal")
include_directories( ${GDAL_INCLUDE_DIR} )

add_executable(Spherical_Cam_Test ${SOURCE_FILES})

set(libs umfpack
        cxsparse
        stlplus
        glog
        gomp
        ccolamd
        btf
        klu
        cholmod
        lapack
        blas
        camd
        amd
        pthread
        ceres
        )

SET(openMVG_libs "${CURRENT_ROOT_INSTALL_DIR}/lib")


FIND_LIBRARY(openMVG_image openMVG_image ${openMVG_libs})
FIND_LIBRARY(openMVG_image openMVG_image ${openMVG_libs})
FIND_LIBRARY(openMVG_multiview openMVG_multiview ${openMVG_libs})
FIND_LIBRARY(openMVG_features openMVG_features ${openMVG_libs})
FIND_LIBRARY(openMVG_matching openMVG_matching ${openMVG_libs})
FIND_LIBRARY(openMVG_system  openMVG_system ${openMVG_libs})
FIND_LIBRARY(openMVG_sfm openMVG_sfm ${openMVG_libs})
FIND_LIBRARY(openMVG_geometry openMVG_geometry ${openMVG_libs})


TARGET_LINK_LIBRARIES(Spherical_Cam_Test
        ${openMVG_sfm}
        ${openMVG_multiview}
        ${openMVG_image}
        ${openMVG_features}
        ${openMVG_matching}
        ${openMVG_system}
        ${openMVG_geometry}
        ${libs}
        )

target_link_libraries(Spherical_Cam_Test gdal)


link_directories(${CURRENT_ROOT_INSTALL_DIR}/lib)
target_link_libraries(Spherical_Cam_Test ${libs} ${libs} )

