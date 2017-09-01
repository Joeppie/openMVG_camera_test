#include <iostream>

#include "openMVG/cameras/Camera_Spherical.hpp"
#include "openMVG/features/feature.hpp"
#include "openMVG/features/sift/SIFT_Anatomy_Image_Describer.hpp"
#include "openMVG/features/svg_features.hpp"
#include "openMVG/image/image_io.hpp"
#include "openMVG/image/image_concat.hpp"
#include "openMVG/matching/regions_matcher.hpp"
#include "openMVG/matching/svg_matches.hpp"
#include "openMVG/multiview/conditioning.hpp"
#include "openMVG/multiview/essential.hpp"
#include "openMVG/multiview/triangulation.hpp"
#include "openMVG/multiview/solver_essential_spherical.hpp"
#include "openMVG/robust_estimation/robust_estimator_ACRansac.hpp"
#include "openMVG/robust_estimation/robust_estimator_ACRansacKernelAdaptator.hpp"
#include "openMVG/sfm/pipelines/sfm_robust_model_estimation.hpp"
#include "openMVG/sfm/sfm_data.hpp"
#include "openMVG/sfm/sfm_data_BA_ceres.hpp"
#include "openMVG/sfm/sfm_data_io.hpp"


using namespace openMVG;
using namespace openMVG::cameras;
using namespace openMVG::geometry;
using namespace openMVG::image;
using namespace openMVG::matching;
using namespace openMVG::robust;
using namespace openMVG::sfm;
using namespace std;


void projectAndDisplayCameraCoords(const Vec2 &cameraCoords)
{
    openMVG::cameras::Intrinsic_Spherical camera(4800,2400);

    Vec2 imageCoords = camera.cam2ima(cameraCoords);

    std::cout <<  "\tthe camera coords {" << cameraCoords.x() << "," << cameraCoords.y() << "} result in:\n";
    std::cout <<  "\tthe image  coords {" << imageCoords.x() << "," << imageCoords.y() << "} result in:" << std::endl;
}

int main()
{
    std::cout << "Top left corner:\n";
    projectAndDisplayCameraCoords({-.5,-.25});
    std::cout << "Top right corner:\n";
    projectAndDisplayCameraCoords({.5,-.25});
    std::cout << "Center of image:\n";
    projectAndDisplayCameraCoords({0,.0});
    std::cout << "Bottom left corner:\n";
    projectAndDisplayCameraCoords({-.5,.25});
    std::cout << "Bottom right corner:\n";
    projectAndDisplayCameraCoords({.5,.25});

    return 0;
}

