#pragma once

#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class KillAllDemoSoundAction : public ksys::act::ai::Action {
    SEAD_RTTI_OVERRIDE(KillAllDemoSoundAction, ksys::act::ai::Action)
public:
    explicit KillAllDemoSoundAction(const InitArg& arg);
    ~KillAllDemoSoundAction() override;

    bool init_(sead::Heap* heap) override;
    void loadParams_() override;

protected:
};

}  // namespace uking::action
