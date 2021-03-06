/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkTDxInteractorStyle.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkTDxInteractorStyle - provide 3DConnexion device event-driven interface to the rendering window

// .SECTION Description
// vtkTDxInteractorStyle is an abstract class defining an event-driven
// interface to support 3DConnexion device events send by
// vtkRenderWindowInteractor.
// vtkRenderWindowInteractor forwards events in a platform independent form to
// vtkInteractorStyle which can then delegate some processing to
// vtkTDxInteractorStyle.

// .SECTION See Also
// vtkInteractorStyle vtkRenderWindowInteractor
// vtkTDxInteractorStyleCamera

#ifndef vtkTDxInteractorStyle_h
#define vtkTDxInteractorStyle_h

#include "vtkRenderingCoreModule.h" // For export macro
#include "vtkObject.h"

class vtkTDxMotionEventInfo;
class vtkRenderer;
class vtkTDxInteractorStyleSettings;

class VTKRENDERINGCORE_EXPORT vtkTDxInteractorStyle : public vtkObject
{
public:
  vtkTypeMacro(vtkTDxInteractorStyle,vtkObject);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // Action on motion event. Default implementation is empty.
  // \pre: motionInfo_exist: motionInfo!=0
  virtual void OnMotionEvent(vtkTDxMotionEventInfo *motionInfo);

  // Description:
  // Action on button pressed event. Default implementation is empty.
  virtual void OnButtonPressedEvent(int button);

  // Description:
  // Action on button released event. Default implementation is empty.
  virtual void OnButtonReleasedEvent(int button);

  // Description:
  // Dispatch the events TDxMotionEvent, TDxButtonPressEvent and
  // TDxButtonReleaseEvent to OnMotionEvent(), OnButtonPressedEvent() and
  // OnButtonReleasedEvent() respectively.
  // It is called by the vtkInteractorStyle.
  // This method is virtual for convenient but you should really override
  // the On*Event() methods only.
  // \pre renderer can be null.
  virtual void ProcessEvent(vtkRenderer *renderer,
                            unsigned long event,
                            void *calldata);

  // Description:
  // 3Dconnexion device settings. (sensitivity, individual axis filters).
  // Initial object is not null.
  vtkGetObjectMacro(Settings,vtkTDxInteractorStyleSettings);
  virtual void SetSettings(vtkTDxInteractorStyleSettings *settings);

protected:
  vtkTDxInteractorStyle();
  virtual ~vtkTDxInteractorStyle();

  vtkTDxInteractorStyleSettings *Settings;

  vtkRenderer *Renderer;

private:
  vtkTDxInteractorStyle(const vtkTDxInteractorStyle&) VTK_DELETE_FUNCTION;
  void operator=(const vtkTDxInteractorStyle&) VTK_DELETE_FUNCTION;
};
#endif
