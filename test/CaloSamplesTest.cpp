#include "CalibFormats/CaloObjects/interface/CaloSamples.h"
#include <iostream>

int main() {
  DetId detId;
  CaloSamples samples(detId, 10.);
  CaloSamples samples2(detId, 10.);
  double values[10] = {2., 4.,    8., 20.,   32., 28.,   24.,  12., 8., 4.};
  double offset = 5.;
  double offset2 = 30.;
  double expect[10] = {1.6, 3.6, 7.2, 17.6, 29.6, 28.8, 24.8, 14.4, 8.8, 4.8};
  double expect2[10] = {0., 1.6, 3.6, 7.2, 17.6, 29.6, 28.8, 24.8, 14.4, 8.8};

  for(int i = 0; i < 10; ++i) {
    samples[i] = values[i];
    samples2[i] = values[i];
  }
  samples.offsetTime(offset);
  samples2.offsetTime(offset2);

  for(int i = 0; i < 10; ++i) {
    std::cout << i << " " << samples[i] << " " << expect[i] << std::endl;
  }
  for(int i = 0; i < 10; ++i) {
    std::cout << i << " " << samples2[i] << " " << expect2[i] << std::endl;
  }

  return 0;
}

