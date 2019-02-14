

#pragma once

#include "../Scene/Component.h"

namespace Urho3D
{

class URHO3D_API PrefabComponent : public Component
{
    URHO3D_OBJECT(PrefabComponent, Component);

public:

    /// Construct.
    PrefabComponent(Context* context);
    /// Destruct.
    virtual ~PrefabComponent();

    /// Register object factory.
    static void RegisterObject(Context* context);

    void SetPrefabGUID(const String& guid);
    const String& GetPrefabGUID() const { return prefabGUID_; }

    bool SavePrefab();
    void UndoPrefab();
    void BreakPrefab();

protected:

    /// Handle scene node being assigned at creation.
    virtual void OnNodeSet(Node* node);


private:

    void HandlePrefabChanged(StringHash eventType, VariantMap& eventData);

    void LoadPrefabNode();

    String prefabGUID_;

};

}
