

#include "../Core/Object.h"

namespace Urho3D
{

URHO3D_EVENT(E_PREFABSAVE, PrefabSave)
{
    URHO3D_PARAM(P_PREFABCOMPONENT, PrefabComponent); // PrefabComponent Pointer
}

/// Instead of using resource reload system which can be delayed due to file watchers, we explicitly send prefab changes
URHO3D_EVENT(E_PREFABCHANGED, PrefabChanged)
{
    URHO3D_PARAM(P_GUID, GUID); // String
}

}
