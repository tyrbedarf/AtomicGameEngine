//
// Copyright (c) 2014-2016 THUNDERBEAST GAMES LLC
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

namespace AtomicEditor
{

/// Variable timestep scene update.
URHO3D_EVENT(E_GIZMOEDITMODECHANGED, GizmoEditModeChanged)
{
    URHO3D_PARAM(P_MODE, Mode);            // int
}

URHO3D_EVENT(E_GIZMOAXISMODECHANGED, GizmoAxisModeChanged)
{
    URHO3D_PARAM(P_MODE, Mode);            // int
}

URHO3D_EVENT(E_GIZMOMOVED, GizmoMoved)
{

}

URHO3D_EVENT(E_SCENENODESELECTED, SceneNodeSelected)
{
    URHO3D_PARAM(P_SCENE, Scene);             // Scene
    URHO3D_PARAM(P_NODE, Node);               // Node
    URHO3D_PARAM(P_SELECTED, Selected);       // bool
    URHO3D_PARAM(P_QUIET, Quiet);             // bool (don't record edit event)
}

URHO3D_EVENT(E_SCENEEDITBEGIN, SceneEditBegin)
{
    URHO3D_PARAM(P_SCENE, Scene);             // Scene

}

URHO3D_EVENT(E_SCENEEDITNODEREPARENT, SceneEditNodeReparent)
{
    URHO3D_PARAM(P_NODE, Node);             // Node
    URHO3D_PARAM(P_ADDED, Added);             // Boolean
}


URHO3D_EVENT(E_SCENEEDITEND, SceneEditEnd)
{
    URHO3D_PARAM(P_SCENE, Scene);             // Scene
}

URHO3D_EVENT(E_SCENEEDITSTATECHANGESBEGIN, SceneEditStateChangesBegin)
{

}

URHO3D_EVENT(E_SCENEEDITSTATECHANGE, SceneEditStateChange)
{
    URHO3D_PARAM(P_SERIALIZABLE, Serializable);     // Serializable
}

URHO3D_EVENT(E_SCENEEDITSTATECHANGESEND, SceneEditStateChangesEnd)
{

}

/// A child node has been added to a parent node.
URHO3D_EVENT(E_SCENEEDITNODECREATED, SceneEditNodeCreated)
{
    URHO3D_PARAM(P_NODE, Node);                    // Node pointer
}


/// A child node has been added to a parent node.
URHO3D_EVENT(E_SCENEEDITNODEADDED, SceneEditNodeAdded)
{
    URHO3D_PARAM(P_SCENE, Scene);                  // Scene pointer
    URHO3D_PARAM(P_PARENT, Parent);                // Node pointer
    URHO3D_PARAM(P_NODE, Node);                    // Node pointer
}

/// A child node is about to be removed from a parent node.
URHO3D_EVENT(E_SCENEEDITNODEREMOVED, SceneEditNodeRemoved)
{
    URHO3D_PARAM(P_SCENE, Scene);                  // Scene pointer
    URHO3D_PARAM(P_PARENT, Parent);                // Node pointer
    URHO3D_PARAM(P_NODE, Node);                    // Node pointer
}


/// A child node has been added to a parent node.
URHO3D_EVENT(E_SCENEEDITCOMPONENTADDEDREMOVED, SceneEditComponentAddedRemoved)
{
    URHO3D_PARAM(P_SCENE, Scene);                  // Scene pointer
    URHO3D_PARAM(P_NODE, Node);                    // Node pointer
    URHO3D_PARAM(P_COMPONENT, Component);          // Component pointer
    URHO3D_PARAM(P_REMOVED, Removed);          // bool

}

URHO3D_EVENT(E_SCENEEDITPREFABSAVE, SceneEditPrefabSave)
{
    URHO3D_PARAM(P_NODE, Node);                    // Node pointer
}

URHO3D_EVENT(E_SCENEEDITPREFABREVERT, SceneEditPrefabRevert)
{
    URHO3D_PARAM(P_NODE, Node);                    // Node pointer
}

URHO3D_EVENT(E_SCENEEDITPREFABCOPY, SceneEditPrefabCopy)
{
    URHO3D_PARAM(P_NODE, Node);                    // Node pointer
}

URHO3D_EVENT(E_SCENEEDITPREFABPASTE, SceneEditPrefabPaste)
{
    URHO3D_PARAM(P_NODE, Node);                    // Node pointer
}

URHO3D_EVENT(E_SCENEEDITPREFABBREAK, SceneEditPrefabBreak)
{
    URHO3D_PARAM(P_NODE, Node);                    // Node pointer
}

URHO3D_EVENT(E_SCENEEDITCOMPONENTCOPY, SceneEditComponentCopy)
{
    URHO3D_PARAM(P_COMPONENT, Component);          // Component pointer
}

URHO3D_EVENT(E_SCENEEDITCOMPONENTPASTE, SceneEditComponentPaste)
{
    URHO3D_PARAM(P_COMPONENT, Component);          // Component pointer
    URHO3D_PARAM(P_END, End);                       // bool
}

URHO3D_EVENT(E_SCENEEDITADDREMOVENODES, SceneEditAddRemoveNodes)
{
    URHO3D_PARAM(P_END, End);       // bool
}

URHO3D_EVENT(E_SCENEEDITSCENEMODIFIED, SceneEditSceneModified)
{

}

URHO3D_EVENT(E_CUBEMAPRENDERBEGIN, CubemapRenderBegin)
{

}

URHO3D_EVENT(E_CUBEMAPRENDEREND, CubemapRenderEnd)
{

}

URHO3D_EVENT(E_COMPONENTEDITEND, ComponentEditEnd)
{

}

URHO3D_EVENT(E_COLORCHOOSERCHANGED, ColorChooserChanged)
{
    URHO3D_PARAM(P_WIDGET, Widget); // UIWidget
}

URHO3D_EVENT(E_SELECTIONCREATECOMPONENT, SelectionCreateComponent)
{
    URHO3D_PARAM(P_COMPONENTTYPENAME, ComponentTypeName);   // string
}


}
