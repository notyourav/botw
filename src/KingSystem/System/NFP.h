#pragma once

#include <prim/seadTypedBitFlag.h>
#include <heap/seadDisposer.h>
#include <heap/seadExpHeap.h>
#include <hostio/seadHostIONode.h>
#include <thread/seadDelegateThread.h>

namespace ksys {

class NFP final : public sead::hostio::Node {
    SEAD_SINGLETON_DISPOSER(NFP);

    struct NFPThread : sead::DelegateThread {
        enum class NFPFlag {
            _800 = 0x800,
        };

        NFPThread(sead::ExpHeap* heap, s32 size, s32 priority);

        void calc_(sead::MessageQueue::Element msg);

        static u8 sRegInfo;

        sead::CriticalSection mCritSect1;
        s32 _148[12];
        sead::TypedBitFlag<NFPFlag, u16> _190; // unknown flag
        sead::TypedBitFlag<NFPFlag, u16> _194;

        sead::FixedSafeString<0x30> _1B8;
        sead::ListNode _200;
        s32 _210 = 0;
        s32 _214 = -1;
        sead::ListNode _218;
        s32 _22C = -1;

        sead::CriticalSection _230;

        s32 _270;

        u8 _2A0 = 0; // obvious array of structs
        u8 _2D0 = 0;
        u32 _2D8 = 0;

        u8 _310 = 0;
        u8 _340 = 0;
        u32 _348 = 0;

        u8 _380 = 0;
        u8 _3B0 = 0;
        u32 _3B8 = 0;

        u8 _3F0 = 0;
        u8 _420 = 0;
        u32 _428 = 0;

    };

public:
    void init(sead::Heap* parent);

    sead::ExpHeap* mManagerHeap = nullptr;
    NFPThread* mThread = nullptr;
    bool _38 = false;
};

}  // namespace ksys
