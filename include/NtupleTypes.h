#ifndef NTUPLE_TYPES_HH
#define NTUPLE_TYPES_HH

#include "hep_hpc/hdf5/Column.hpp"
#include "hep_hpc/hdf5/Ntuple.hpp"

// start with eventid (64 bits), segment, planecode, float-z
using eventdat_nt_t = hep_hpc::hdf5::Ntuple<
    unsigned long int, unsigned char, unsigned short int, float
    >;
using imgdat_nt_t = hep_hpc::hdf5::Ntuple<hep_hpc::hdf5::Column<float, 3>>;
using arr2dat_nt_t = hep_hpc::hdf5::Ntuple<hep_hpc::hdf5::Column<float, 2>>;
using arrdat_nt_t = hep_hpc::hdf5::Ntuple<hep_hpc::hdf5::Column<float, 1>>;

// using imgdat_nt_t = hep_hpc::hdf5::Ntuple<float, float, float>;
// using imgdat_nt_t = hep_hpc::hdf5::Ntuple<
//     hep_hpc::hdf5::Column<float, 3>,
//     hep_hpc::hdf5::Column<float, 3>,
//     hep_hpc::hdf5::Column<float, 3>
//     >;

#endif
