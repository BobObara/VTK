/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkBoostGraphAdapter.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/

// .NAME vtkBoostBetweennessClustering - Implements graph clustering based on
// edge betweenness centrality.
//
// .SECTION Description
//
// This vtk class uses the Boost centrality clustering
// generic algorithm to compute edge betweenness centrality on
// the input graph (a vtkGraph).

// .SECTION See Also
// vtkGraph vtkBoostGraphAdapter

#ifndef __vtkBoostBetweennessClustering_h
#define __vtkBoostBetweennessClustering_h

#include "vtkGraphAlgorithm.h"

class VTK_INFOVIS_EXPORT vtkBoostBetweennessClustering :
  public vtkGraphAlgorithm
{
public:
  static vtkBoostBetweennessClustering* New();
  vtkTypeMacro(vtkBoostBetweennessClustering, vtkGraphAlgorithm);
  void PrintSelf(ostream &os, vtkIndent indent);

  vtkBoostBetweennessClustering();
  virtual ~vtkBoostBetweennessClustering();

  vtkSetMacro(Threshold, double);
  vtkGetMacro(Threshold, double);

  // Description:
  // Get/Set the flag that sets the rule whether or not to use the
  // edge weight array as set using \c SetEdgeWeightArrayName.
  vtkSetMacro(UseEdgeWeightArray, bool);
  vtkBooleanMacro(UseEdgeWeightArray, bool);

  vtkSetMacro(InvertEdgeWeightArray, bool);
  vtkBooleanMacro(InvertEdgeWeightArray, bool);

  // Description:
  // Get/Set the name of the array that needs to be used as the edge weight.
  // The array should be a vtkDataArray.
  vtkGetStringMacro(EdgeWeightArrayName);
  vtkSetStringMacro(EdgeWeightArrayName);


protected:

  virtual int RequestData(vtkInformation* request,
                          vtkInformationVector** inputVector,
                          vtkInformationVector* outputVector);


private:

  double  Threshold;
  bool    UseEdgeWeightArray;
  bool    InvertEdgeWeightArray;
  char*   EdgeWeightArrayName;

  vtkBoostBetweennessClustering(const vtkBoostBetweennessClustering&); // Not implemented.
  void operator=(const vtkBoostBetweennessClustering&); // Not implemented.
};

#endif // __vtkBoostBetweennessClustering_h
