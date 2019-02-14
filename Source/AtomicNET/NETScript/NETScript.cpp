

#include <Atomic/Core/Context.h>

#include "CSComponent.h"
#include "CSComponentAssembly.h"
#include "NETScript.h"

namespace Urho3D
{

void RegisterNETScriptLibrary(Context* context)
{
    CSComponent::RegisterObject(context);
    CSComponentAssembly::RegisterObject(context);
}

}