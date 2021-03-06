#include "Game/AI/Action/actionForkGelDisableBodyRot.h"

namespace uking::action {

ForkGelDisableBodyRot::ForkGelDisableBodyRot(const InitArg& arg) : ksys::act::ai::Action(arg) {}

ForkGelDisableBodyRot::~ForkGelDisableBodyRot() = default;

bool ForkGelDisableBodyRot::init_(sead::Heap* heap) {
    return ksys::act::ai::Action::init_(heap);
}

void ForkGelDisableBodyRot::enter_(ksys::act::ai::InlineParamPack* params) {
    ksys::act::ai::Action::enter_(params);
}

void ForkGelDisableBodyRot::leave_() {
    ksys::act::ai::Action::leave_();
}

void ForkGelDisableBodyRot::loadParams_() {}

void ForkGelDisableBodyRot::calc_() {
    ksys::act::ai::Action::calc_();
}

}  // namespace uking::action
