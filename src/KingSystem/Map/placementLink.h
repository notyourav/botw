#include <basis/seadTypes.h>
#include "KingSystem/ActorSystem/actActorLinkConstDataAccess.h"

namespace ksys::map {

enum class MapLinkDefType : u32 {
    BasicSig = 0,
    AxisX = 1,
    AxisY = 2,
    AxisZ = 3,
    NAxisX = 4,
    NAxisY = 5,
    NAxisZ = 6,
    GimmickSuccess = 7,
    VelocityControl = 8,
    BasicSigOnOnly = 9,
    Remains = 10,
    DeadUp = 11,
    LifeZero = 12,
    Stable = 13,
    ChangeAtnSig = 14,
    Create = 15,
    Delete = 16,
    MtxCopyCreate = 17,
    Freeze = 18,
    ForbidAttention = 19,
    SyncLink = 20,
    CopyWaitRevival = 21,
    OffWaitRevival = 22,
    Recreate = 23,
    AreaCol = 24,
    SensorBlind = 25,
    ForSale = 26,
    ModelBind = 27,
    PlacementLOD = 28,
    DemoMember = 29,
    PhysSystemGroup = 30,
    StackLink = 31,
    FixedCs = 32,
    HingeCs = 33,
    LimitHingeCs = 34,
    SliderCs = 35,
    PulleyCs = 36,
    BAndSCs = 37,
    BAndSLimitAngYCs = 38,
    CogWheelCs = 39,
    RackAndPinionCs = 40,
    Reference = 41,
    Invalid = 42,
};

struct ActorAccessor : act::ActorLinkConstDataAccess {
    void triggerLink();
};

struct PlacementLink {
    u8 TEMP[0x8];
    MapLinkDefType mLinkType;

    bool getObjActorWithAccessor(ActorAccessor* accessor);
};

struct PlacementLinkArray {
    u32 num_links;
    PlacementLink* links;
};

struct PlacementLinkData {
    u8 TEMP[0x20];
    PlacementLinkArray links_other;
};

struct PlacementObj {
    u8 TEMP[0x40];
    PlacementLinkData* link_data;
};

}  // namespace ksys::map
