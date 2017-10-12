#include <iostream>
#include <string>

#include "TRandom3.h"
#include "hep_hpc/hdf5/File.hpp"
#include "NtupleTypes.h"

using namespace hep_hpc::hdf5;

void fill_arr_img(std::array<std::array<std::array<float, 2>, 5>, 4>& xs) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 5; ++j) {
            for (int k = 0; k < 4; ++k) {
                xs[i][j][k] = gRandom->Gaus(0.0, 1.0);
            }
        }
    }
}

void fill_arr(std::array<float, 2>& arrs) {
    for (int i = 0; i < 2; ++i) {
        arrs[i] = gRandom->Gaus(0.0, 1.0);
    }
}


int main( int argc, char *argv[]) try {

    File hdffile("demo.h5", H5F_ACC_TRUNC);

    gRandom = new TRandom3();
    unsigned long int evtids[] = {100, 101, 102};
    unsigned char segs[] = {1, 2, 3};
    unsigned short int pcodes[] = {9, 18, 27};
    float zs[] = {4000.0, 4400.0, 4800.0};
    std::array<float, 2> arrs = {0};
    std::array<std::array<std::array<float, 2>, 5>, 4> xs = {0.};

    eventdat_nt_t eventdat(hdffile, "event_data", {"eventids", "segments", "planecodes", "zs"});
    imgdat_nt_t imgdat(hdffile, "img_data", {
            {"hitimes-x", {2, 5, 4}}
            });
    arrdat_nt_t arrdat(hdffile, "arr_data", { {"arrdat", 2} });
    for (int ev = 0; ev < 3; ++ev) {
        eventdat.insert(evtids[ev], segs[ev], pcodes[ev], zs[ev]);
        fill_arr_img(xs);
        // imgdat.insert(xs.data());
        fill_arr(arrs);
        arrdat.insert(arrs.data());
    }

    return 0;

} catch (std::exception const& ex) {
    std::cerr << ex.what() << '\n';
    return 1;
} catch (...) {
    std::cerr << "Unidentifiable exception caught\n";
    return 1;
}
