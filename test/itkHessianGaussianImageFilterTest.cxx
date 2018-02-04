/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/

#include "itkHessianGaussianImageFilter.h"
#include "itkUnaryFunctorImageFilter.h"
#include "itkTestingMacros.h"
#include "itkImageRegionIteratorWithIndex.h"
#include "itkMath.h"

int itkHessianGaussianImageFilterTest( int argc, char * argv[] )
{
  const unsigned int                                  Dimension = 2;
  typedef int                                         PixelType;
  typedef itk::Image< PixelType, Dimension >          ImageType;
  typedef itk::HessianGaussianImageFilter<ImageType>  HessianGaussianImageFilterType;

  HessianGaussianImageFilterType::Pointer hess_filter = HessianGaussianImageFilterType::New();

  /* Basic tests. */
  EXERCISE_BASIC_OBJECT_METHODS( hess_filter, HessianGaussianImageFilter, ImageToImageFilter );
  
  /* Exercise basic set/get methods */
  TEST_SET_GET_VALUE(1.0, hess_filter->GetSigma());
  hess_filter->SetSigma(0.5);
  TEST_SET_GET_VALUE(0.5, hess_filter->GetSigma());

  TEST_SET_GET_VALUE(false, hess_filter->GetNormalizeAcrossScale());
  hess_filter->SetNormalizeAcrossScale(true);
  TEST_SET_GET_VALUE(true, hess_filter->GetNormalizeAcrossScale());
  hess_filter->NormalizeAcrossScaleOff();
  TEST_SET_GET_VALUE(false, hess_filter->GetNormalizeAcrossScale());
  hess_filter->NormalizeAcrossScaleOn();
  TEST_SET_GET_VALUE(true, hess_filter->GetNormalizeAcrossScale());

  return EXIT_SUCCESS;
}