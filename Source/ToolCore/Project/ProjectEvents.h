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

using namespace Urho3D;

namespace ToolCore
{

URHO3D_EVENT(E_PROJECTBEGINLOAD, ProjectBeginLoad)
{
    URHO3D_PARAM(P_PROJECTPATH, ProjectPath);   // string
    URHO3D_PARAM(P_PROJECT, Project);           // Project *
}

// Event is triggered once a project has been loaded and after prefs have been loaded
URHO3D_EVENT(E_PROJECTLOADED, ProjectLoaded)
{
    URHO3D_PARAM(P_PROJECTPATH, ProjectPath);   // string (The path to the project that was loaded)
    URHO3D_PARAM(P_PROJECT, Project);           // Project * (The reference to the project)
    URHO3D_PARAM(P_RESULT, Result);             // bool (whether the project loaded successfully)
}

URHO3D_EVENT(E_PROJECTUNLOADED, ProjectUnloaded)
{
}

URHO3D_EVENT(E_PROJECTUSERPREFSAVED, ProjectUserPrefSaved)
{
    URHO3D_PARAM(P_PREFS, Prefs);    // ProjectUserPrefs
}


}
