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

#include <Atomic/Core/Object.h>

namespace ToolCore
{


URHO3D_EVENT(E_RESOURCEADDED, ResourceAdded)
{
    URHO3D_PARAM(P_GUID, GUID);                  // string
}

URHO3D_EVENT(E_RESOURCEREMOVED, ResourceRemoved)
{
    URHO3D_PARAM(P_GUID, GUID);                  // string
}

URHO3D_EVENT(E_ASSETIMPORTERROR, AssetImportError)
{
    URHO3D_PARAM(P_PATH, Path);                  // string
    URHO3D_PARAM(P_GUID, GUID);                  // string
    URHO3D_PARAM(P_ERROR, Error);                  // string
}

URHO3D_EVENT(E_ASSETSCANBEGIN, AssetScanBegin)
{
}

URHO3D_EVENT(E_ASSETSCANEND, AssetScanEnd)
{
}

URHO3D_EVENT(E_ASSETNEW, AssetNew)
{
    URHO3D_PARAM(P_GUID, GUID);                  // string
}

URHO3D_EVENT(E_ASSETRENAMED, AssetRenamed)
{
    URHO3D_PARAM(P_ASSET, Asset);                  // asset ptr
}

URHO3D_EVENT(E_ASSETMOVED, AssetMoved)
{
    URHO3D_PARAM(P_ASSET, Asset);                  // asset ptr
    URHO3D_PARAM(P_OLDPATH, OldPath);                  // string

}

}
