#include "KingSystem/System/NFP.h"
#include <thread/seadThreadUtil.h>

namespace ksys {

SEAD_SINGLETON_DISPOSER_IMPL(NFP);

NFP::NFPThread::NFPThread(sead::ExpHeap* heap, s32 size, s32 priority)
    : DelegateThread("NFP Thread", heap, priority, sead::MessageQueue::BlockType::NonBlocking,
                 0x7FFFFFFF, size, 0x20) {
    _190.makeAllZero();
    _194.makeAllZero();
    
    _270 = -1;
    sRegInfo = 0;
    
    _214 = 8;
    _22C = 8;
                 }

void NFP::NFPThread::calc_(sead::MessageQueue::Element msg) {}

void NFP::init(sead::Heap* parent) {
    mManagerHeap = sead::ExpHeap::create(0x100000, "NFP Manager", parent, 8,
                                         sead::Heap::HeapDirection::cHeapDirection_Forward, false);

    mThread = new NFP::NFPThread(mManagerHeap, 0x8000,
                                 sead::ThreadUtil::ConvertPrioritySeadToPlatform(19));

    if (mThread != nullptr) {
        mThread->start();
        if (mThread != nullptr) {
            mThread->_194.set(NFP::NFPThread::NFPFlag::_800);
            auto lock = sead::makeScopedLock(mThread->mCritSect1);

            mThread->_148[0] = 1;
        }
    }
    mManagerHeap->adjust();
}

}  // namespace ksys
