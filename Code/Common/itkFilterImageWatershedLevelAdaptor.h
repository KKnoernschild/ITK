/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    itkFilterImageWatershedLevelAdaptor.h
  Language:  C++
  Date:      $Date$
  Version:   $Revision$


  Copyright (c) 2000 National Library of Medicine
  All rights reserved.

  See COPYRIGHT.txt for copyright details.

=========================================================================*/
#ifndef __itkFilterImageWatershedLevelAdaptor_h
#define __itkFilterImageWatershedLevelAdaptor_h
#include "itkFilterImageToImage.h"
#include "itkFilterImageWatershedSegment.h"
#include "itkImage.h"

namespace itk
{
/**
 * \class FilterImageWatershedLevelAdaptor
 * \brief Relabels a basic watershed segmentation labeled image at the flood
 * level percentage specified.
 *
 * This class uses the basic segmentation from a FilterImageWatershedSegment
 * object to merge and relabel segments at a specified flood level.  Note that
 * the maximum Level (1.0) is equal to the Level parameter of the input
 * WatershedSegment object.
 */
template <class TInputImage, class TOutputImage>
class ITK_EXPORT FilterImageWatershedLevelAdaptor :
    public FilterImageToImage< TInputImage, TOutputImage > 
{
public:
  /**
   * Standard "Self" typedef.
   */
  typedef FilterImageWatershedLevelAdaptor Self;

  /**
   * Standard super class typedef support.
   */
  typedef FilterImageToImage< TInputImage, TOutputImage > Superclass;
  
  /** 
   * Smart pointer typedef support 
   */
  typedef SmartPointer<Self> Pointer;

  /**
   * Scalar data type typedef support
   */
  typedef typename TOutputImage::ScalarValueType ScalarValueType;

  /**
   * Compile time image dimensionality support.
   */
  enum {ImageDimension = TOutputImage::ImageDimension };
  
  /**
   * Run-time type information (and related methods)
   */
  itkTypeMacro(FilterImageWatershedLevelAdaptor, FilterImageToImage);
  
  /**
   * Method for creation through the object factory.
   */
  itkNewMacro(Self);

  /**
   * Standard pipeline method.
   */
  void GenerateData();

  /**
   * Standard get set methods for filter parameter.
   */
  itkSetClampMacro(Level, float, 0.0f, 1.0f);
  itkGetMacro(Level, float);

  /**
   * Overridden get and set input methods
   */
  virtual
  WatershedSegmentBasicOutput<TInputImage, TOutputImage>::Pointer
  GetInput()
  {
    return static_cast<WatershedSegmentBasicOutput<TInputImage,
      TOutputImage>*>(this->ProcessObject::GetInput(0).GetPointer());
  }

  virtual
  void SetInput(WatershedSegmentBasicOutput<TInputImage, TOutputImage>* input)
  {
    this->ProcessObject::SetNthInput(0, input);
  }

protected:
  FilterImageWatershedLevelAdaptor() {}
  virtual ~FilterImageWatershedLevelAdaptor() {}
  FilterImageWatershedLevelAdaptor(const Self&) {}
  void operator=(const Self&) {}

private:
  float m_Level;
  
};
  
} // end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkFilterImageWatershedLevelAdaptor.txx"
#endif

#endif
