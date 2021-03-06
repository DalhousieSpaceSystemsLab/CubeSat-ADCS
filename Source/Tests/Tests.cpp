#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include "Eigen/Core"
#include "../IGRF/igrf.h"
#include "../Sun_Vector_Reference/sun_vector_reference.h"
#include "../sunVector/Sun_Vector_Estimate.h"
#include "../Errors.h"

using namespace std;

//  Test for IGRF function prototype and inputs
TEST(ADCS_test, ADCS_002_001) {
    Eigen::Vector3d mag_reference(3);
    mag_reference << 0, 0, 0;       //  Initialize matrix
    Eigen::Vector3d& mag = mag_reference;

    //  This should succeed
    uint8_t i = MagReference(-30.56120405, -9.857491524, 577, 2020, 11, 17, mag);
    //  Check for return value
    EXPECT_EQ(i, 0);

    //  These should fail
    //  Arg 1 out of bounds
    i = MagReference(-90, -9.857491524, 577, 2020, 11, 17, mag);
    EXPECT_EQ(i, 2);

    //  Arg 2 out of bounds
    i = MagReference(-30.56120405, 181, 577, 2020, 11, 17, mag);
    EXPECT_EQ(i, 2);

    //  Arg 3 out of bounds
    i = MagReference(-30.56120405, -9.857491524, 601, 2020, 11, 17, mag);
    EXPECT_EQ(i, 2);

    //  Arg 4 out of bounds
    i = MagReference(-30.56120405, -9.857491524, 577, 2025, 11, 17, mag);
    EXPECT_EQ(i, 2);

    //  Arg 5 out of bounds
    i = MagReference(-30.56120405, -9.857491524, 601, 2020, 13, 17, mag);
    EXPECT_EQ(i, 2);

    //  Arg 6 out of bounds
    i = MagReference(-30.56120405, -9.857491524, 601, 2000, 2, 30, mag);
    EXPECT_EQ(i, 2);
}

//  Test for IGRF accuracy
TEST(ADCS_test, ADCS_002_002) {
    const double ACCURACY = 0.0000000001;   //  1e-10
    Eigen::Vector3d mag_reference(3);
    mag_reference << 0, 0, 0;       //  Initialize matrix
    Eigen::Vector3d& mag = mag_reference;
    double geo, phi, h, y, m, d, bx, by, bz;

    ifstream IGRFvalues;
    ofstream IGRFout;
	IGRFvalues.open("../../Matlab/IGRF13/Outputs/validation_output_matlab_nocompare.txt", ifstream::in);
    IGRFout.open("../../Matlab/IGRF13/Outputs/validation_output_cpp_compare.txt", ifstream::out);
    IGRFvalues.setf(std::ios::fixed, std:: ios::floatfield);
    IGRFvalues.precision(25);
    IGRFvalues.width(25);
    IGRFout.setf(std::ios::fixed, std:: ios::floatfield);
    IGRFout.precision(25);
    IGRFout.width(25);

    IGRFout << "lat_geodetic" << '\t' << "phi" << '\t' << "H" << '\t' << "year" << '\t' << "month" << '\t' << "day" << '\t' 
        << "matlab_bx" << '\t' << "matlab_by" << '\t' << "matlab_bz" << '\t' << "cpp_bx" << '\t' << "cpp_by" << '\t' << "cpp_bz" << '\t'
        << "err_bx" << '\t' << "err_by" << '\t' << "err_bz" << endl;

    while(IGRFvalues) {
        IGRFvalues >> geo >> phi >> h >> y >> m >> d >> bx >> by >> bz;
        // cout << geo << '\t' << phi << '\t' << h << '\t' << y << '\t' << m << '\t' << d << '\t' << bx << '\t' << by << '\t' << bz << endl;
        ret_val i = MagReference(geo, phi, h, y, m, d, mag);

        // Check for return value
        EXPECT_EQ(i, 0);

        //  Test for accuracy
        EXPECT_NEAR(bx, mag_reference(0, 0), ACCURACY);
        EXPECT_NEAR(by, mag_reference(1, 0), ACCURACY);
        EXPECT_NEAR(bz, mag_reference(2, 0), ACCURACY);

        IGRFout << geo << '\t' << phi << '\t' << h << '\t' << y << '\t' << m << '\t' << d << '\t' << bx << '\t' << by << '\t' << bz << '\t';
        IGRFout << mag_reference(0, 0) << '\t' << mag_reference(1, 0) << '\t' << mag_reference(2, 0) << '\t';
        IGRFout << bx - mag_reference(0, 0) << '\t' << by - mag_reference(1, 0) << '\t' << bz - mag_reference(2, 0) << endl;
    }

    IGRFvalues.close();
    IGRFout.close();
}

//  Temp test to test prototypes - TODO: Delete this in final release
TEST(ADCS_test, ADCS_temp_1) {
    ret_val x;
    Eigen::Vector3d sun_reference_km(3);
    sun_reference_km << 0, 0, 0;
    Eigen::Vector3d sun_reference_au(3);
    sun_reference_au << 0, 0, 0;
    Eigen::Vector3d& sr_km = sun_reference_km;
    Eigen::Vector3d& sr_au = sun_reference_au;
    x = SunReference(2021, 2, 25, 16.0, sr_km, sr_au);
    cout << "Sun ref return code: " << x << endl;
    cout << "Sun ref km: " << sun_reference_km(0) << '\t' << sun_reference_km(1) << '\t' << sun_reference_km(2) << endl;
    cout << "Sun ref au: " << sun_reference_au(0) << '\t' << sun_reference_au(1) << '\t' << sun_reference_au(2) << endl;

    ret_val z;
    Eigen::Vector3d sun_estimate(3);
    sun_estimate << 0, 0, 0;
    Eigen::Vector3d& sest = sun_estimate;

    Eigen::MatrixXd H(18, 3); 
    H << 0.353553390593274, 0.353553390593274, 0.866025403784439,   \
    -0.482962913144534, 0.12940952255126, 0.866025403784439,       \
    0.12940952255126, -0.482962913144534, 0.866025403784439,       \
    0.353553390593274, -0.353553390593274, -0.866025403784439,     \
    -0.482962913144534, -0.12940952255126, -0.866025403784439,     \
    0.12940952255126, 0.482962913144534, -0.866025403784439,       \
    0.353553390593274, -0.866025403784439, 0.353553390593274,      \
    -0.482962913144534, -0.866025403784439, 0.129409522551261,     \
    0.12940952255126, -0.866025403784439, -0.482962913144534,      \
    0.866025403784439, 0.353553390593274, 0.353553390593274,       \
    0.866025403784439, -0.482962913144534, 0.12940952255126,       \
    0.866025403784439, 0.12940952255126, -0.482962913144534,       \
    -0.353553390593274, 0.866025403784439, 0.353553390593274,      \
    0.482962913144534, 0.866025403784438, 0.12940952255126,        \
    -0.12940952255126, 0.866025403784439, -0.482962913144534,      \
    -0.866025403784439, -0.353553390593274, 0.353553390593274,     \
    -0.866025403784439, 0.482962913144534, 0.12940952255126,       \
    -0.866025403784439, -0.12940952255126, -0.482962913144534;     
    Eigen::MatrixXd y(18, 11);
    y << 0.123, 0.130967612270811, 0.377135928005713, 0.59076591962063, 0.816934384682695, 0.966742779173866, 0.944868713763263, 0.889216301770271, 0.783407950067469, 0.548133172692389, 0.319815381288397,0.123, 0.123, 0.123, 0.123, 0.111961595844537, 0.341764224923488, 0.557272048957507, 0.715084676062322, 0.849987383630956, 0.76156384469285, 0.676570845449204,0.123, 0.123, 0.123, 0.0773581846668051, 0.276114135076797, 0.389291214980021, 0.459417264325129, 0.407954332908722, 0.271839323703902, 0.0792106355927756, 0.123,0.455163574314287, 0.49415145842057, 0.24602994176323, 0.123, 0.123, 0.123, 0.123, 0.123, 0.123, 0.123, 0.123,0.152901077299585, 0.123, 0.123, 0.123, 0.123, 0.123, 0.123, 0.123, 0.123, 0.123, 0.123,0.811298752064704, 0.639206730617248, 0.338613043861541, 0.14000298411472, 0.123, 0.123, 0.123, 0.123, 0.123, 0.123, 0.123,0.123, 0.123, 0.123, 0.0610544742868209, 0.0277839497422417, 0.0877025038757927, 0.123, 0.123, 0.123, 0.123, 0.123,0.123, 0.123, 0.123, 0.123, 0.123, 0.123, 0.123, 0.123, 0.123, 0.123, 0.123,0.123, 0.123, 0.123, 0.123, 0.123, 0.123, 0.123, 0.123, 0.123, 0.123, 0.123,0.462908935785717, 0.758125469502232, 0.903807243633429, 1.0321092617346, 0.972178108404072, 0.866803569447132, 0.719978081708106, 0.574437603019359, 0.328896985343281, 0.0560622760078464, 0.123,0.160646438771015, 0.442069487460261, 0.629185412340883, 0.564816918711387, 0.560131749955158, 0.401698397396354, 0.122655687845572, 0.123, 0.123, 0.123, 0.123,0.819044113536134, 0.955119802424126, 0.85409920379685, 0.693779331548283, 0.479806284656286, 0.250310996224975, 0.123, 0.123, 0.123, 0.123, 0.123,0.108533326057569, 0.123, 0.123, 0.0714466449572279, 0.264743548048546, 0.399506902911591, 0.606943638439035, 0, 0.916174887631988, 0.947372930064753, 0.959653248281681,0.672196655331935, 0.708706032034147, 0.812061786852819, 0.785063209888626, 0.758963339092824, 0.813932775495731, 0.725610962013092, 0, 0, 0.456085848190805, 0.400481470531757,0.723487548910507, 0.45656244041164, 0.235777958771884, 0.122745383748955, 0.0419999264282362, 0.0186839628174622, 0.0485645485819133, 0.0655775997343766, 0.221319660881452, 0.367672016426004, 0.567976809667218,0.123, 0.123, 0.123, 0.123, 0.123, 0.123, 0.123, 0.00432275147725528, 0.257442404894575, 0.344717628193087, 0.34466193991342,0.123, 0.123, 0.123, 0.123, 0.123, 0.123, 0.10547609348447, 0.312419936604549, 0.559069968800139, 0.790136086178088, 0.886895780374395,0.123, 0.123, 0.123, 0.123, 0.123, 0.123, 0.123, 0.123, 0.123, 0.0160062075053025, 0.248106247237668;
    z = SunEstimate(H, y, sest);

    cout << "Sun sensor return code: " << z << endl;
    cout << "Sun sensor: " << sest(0) << '\t' << sest(1) << '\t' << sest(2) << endl;
}
