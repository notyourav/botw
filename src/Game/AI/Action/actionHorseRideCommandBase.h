#pragma once

#include "Game/AI/Action/actionHorseRideLookWait.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class HorseRideCommandBase : public HorseRideLookWait {
    SEAD_RTTI_OVERRIDE(HorseRideCommandBase, HorseRideLookWait)
public:
    explicit HorseRideCommandBase(const InitArg& arg);
    ~HorseRideCommandBase() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;
};

}  // namespace uking::action
