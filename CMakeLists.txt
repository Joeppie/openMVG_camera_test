cmake_minimum_required(VERSION 3.5)
project(Spherical_Cam_Test)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)

#todo/note; USER is specific to linux OS, USERNAME is the windows equivalent.
SET(OpenMVG_DIR "/home/$ENV{USER}/openMVG_Build/openMVG_install/share/openMVG/cmake")
find_package(OpenMVG REQUIRED)
find_package(GDAL REQUIRED)

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

include_directories(${OPENMVG_INCLUDE_DIRS})

TARGET_LINK_LIBRARIES(Spherical_Cam_Test
                            ${OPENMVG_LIBRARIES}
                            gdal
                            ${libs}
                    )

target_link_libraries(Spherical_Cam_Test ${libs} ${libs} )

