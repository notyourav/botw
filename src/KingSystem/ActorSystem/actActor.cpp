#include "KingSystem/ActorSystem/actActor.h"
#include <thread/seadThread.h>

namespace ksys::act {

void Actor::emitSignal(map::MapLinkDefType linkType, bool keepCurrentSignals) {
    auto thread = sead::ThreadMgr::instance()->getCurrentThread();
    thread->getPriority();

    if (mEmittedSignalMask.isOnBit(static_cast<s32>(linkType)))
        return;

    if (keepCurrentSignals) {
        mEmittedSignalMask.setBit(static_cast<s32>(linkType));
    } else {
        mEmittedSignalMask.makeAllZero();
        mEmittedSignalMask.setBit(static_cast<s32>(linkType));
    }

    auto obj = mPlacementObj;
    if (obj == nullptr)
        return;

    auto linkData = obj->link_data;
    if (linkData == nullptr)
        return;

    auto numLinks = linkData->links_other.num_links;
    if (numLinks == 0)
        return;

    for (int i = 0; i != linkData->links_other.num_links; ++i) {
        auto link = linkData->links_other.links[i];
        if (link.mLinkType == linkType) {
            map::ActorAccessor accessor;
            link.getObjActorWithAccessor(&accessor);
        }
    }
}

void Actor::emitBasicSigOn() {
    emitSignal(map::MapLinkDefType::BasicSig, true);
    emitSignal(map::MapLinkDefType::BasicSigOnOnly, true);
}

}  // namespace ksys::act
