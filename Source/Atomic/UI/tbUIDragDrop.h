//
// Copyright (c) 2014-2015, THUNDERBEAST GAMES LLC All rights reserved
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#pragma once

#include <Atomic/Core/Object.h>

namespace Urho3D
{

class tbUIWidget;
class UILayout;
class tbUIImageWidget;
class tbUITextField;
class tbUIDragObject;

/// UIDragDrop subsystem
class URHO3D_API tbUIDragDrop : public Object
{

    URHO3D_OBJECT(tbUIDragDrop, Object);

public:
    /// Construct.
    tbUIDragDrop(Context* context);
    virtual ~tbUIDragDrop();

    void FileDragEntered();
    void FileDragAddFile(const String& filename);
    void FileDragConclude();

    /// Returns true when dragging an object
    bool GetDraggingObject() { return dragObject_.NotNull(); }

private:

    void HandleUIUpdate(StringHash eventType, VariantMap& eventData);
    void HandleMouseUp(StringHash eventType, VariantMap& eventData);
    void HandleMouseMove(StringHash eventType, VariantMap& eventData);

    void DragEnd();

    // attached to mouse UI
    SharedPtr<UILayout> dragLayout_;
    SharedPtr<tbUIImageWidget> dragImage_;
    SharedPtr<tbUITextField> dragText_;

    SharedPtr<tbUIWidget> currentTargetWidget_;
    SharedPtr<tbUIWidget> dragSourceWidget_;

    SharedPtr<tbUIDragObject> dragObject_;

    // initial mouse down position to handle whether or not to start a drag operation
    IntVector2 mouseDownPosition_;

};


}