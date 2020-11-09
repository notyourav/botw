#pragma once

#include "KingSystem/Map/placementLink.h"
#include "KingSystem/ActorSystem/actBaseProc.h"

namespace ksys {

namespace act {

class LifeRecoverInfo;
class ActorParam;

class Actor : public BaseProc {
public:


    Actor();  // FIXME
    ~Actor() override;

    SEAD_RTTI_OVERRIDE(Actor, BaseProc)

    virtual LifeRecoverInfo* getLifeRecoverInfo();

    void emitSignal(map::MapLinkDefType linkType, bool keepCurrentSignals);

    void emitBasicSigOn();
    void emitBasicSigOff();

    void nullsub_4649();  // Some kind of logging which has been excluded from the build?

    u8 TEMP1[0x3F4];  // FIXME
    ActorParam* mActorParam;
    u8 TEMP2[0x1AC];  // FIXME
    sead::BitFlag32 mEmittedSignalMask;
    u8 TEMP3[0xAC];
    map::PlacementObj* mPlacementObj;
    u8 TEMP4[0x54];  // FIXME
};
KSYS_CHECK_SIZE_NX150(Actor, 0x838);

}  // namespace act

}  // namespace ksys
