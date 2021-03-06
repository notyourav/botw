#pragma once

#include "Game/AI/Action/actionActionWithPosAngReduce.h"
#include "KingSystem/ActorSystem/actAiAction.h"

namespace uking::action {

class FishOnGround : public ActionWithPosAngReduce {
    SEAD_RTTI_OVERRIDE(FishOnGround, ActionWithPosAngReduce)
public:
    explicit FishOnGround(const InitArg& arg);
    ~FishOnGround() override;

    bool init_(sead::Heap* heap) override;
    void enter_(ksys::act::ai::InlineParamPack* params) override;
    void leave_() override;
    void loadParams_() override;

protected:
    void calc_() override;

    // static_param at offset 0x30
    sead::SafeString mASKey_s{};
};

}  // namespace uking::action
