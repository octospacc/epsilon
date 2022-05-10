#ifndef POINCARE_CDF_FUNCTION_H
#define POINCARE_CDF_FUNCTION_H

#include <poincare/distribution.h>
#include <poincare/distribution_method.h>

namespace Poincare {

class CDFFunction final : public DistributionMethod {
  float EvaluateAtAbscissa(float * x, const Distribution * distribution, const float * parameters) const override {
    return distribution->CumulativeDistributiveFunctionAtAbscissa(x[0], parameters);
  }

  double EvaluateAtAbscissa(double * x, const Distribution * distribution, const double * parameters) const override {
    return distribution->CumulativeDistributiveFunctionAtAbscissa(x[0], parameters);
  }
};

}

#endif