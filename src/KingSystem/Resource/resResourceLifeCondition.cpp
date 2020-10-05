#include <codec/seadHashCRC32.h>
#include "KingSystem/Resource/resResourceLifeCondition.h"

namespace ksys::res {

bool LifeCondition::parse_(u8* data, size_t size, sead::Heap* heap) {
    parse(data, size, heap);
    return true;
}

// NON_MATCHING: two instructions swapped
bool LifeCondition::parse(u8* data, size_t size, sead::Heap* heap) {
    if (!data)
        return true;

    applyResParameterArchive(agl::utl::ResParameterArchive{data});
    const agl::utl::ResParameterArchive archive{data};
    const auto root = archive.getRootList();

    const auto invalidWeathers_obj = agl::utl::getResParameterObj(root, "InvalidWeathers");
    if (invalidWeathers_obj.ptr())
        LifeCondition::parseArray(&invalidWeathers_obj, &invalidWeathersObj,
                                  &mInvalidWeathersBuffer, "InvalidWeathers", "天候", heap);

    const auto invalidTimes_obj = agl::utl::getResParameterObj(root, "InvalidTimes");
    if (invalidTimes_obj.ptr())
        LifeCondition::parseArray(&invalidTimes_obj, &invalidTimesObj, &mInvalidTimesBuffer,
                                  "InvalidTimes", "時間", heap);

    const auto displayDistance_obj = agl::utl::getResParameterObj(root, "DisplayDistance");
    if (displayDistance_obj.ptr()) {
        displayDistance.init(0.0, "Item", "表示距離", &displayDistanceObj);
        addObj(&displayDistanceObj, "DisplayDistance");
        displayDistanceObj.applyResParameterObj(displayDistance_obj, nullptr);
    }

    const auto autoDisplayDistanceAlgorithm_obj =
        agl::utl::getResParameterObj(root, "AutoDisplayDistanceAlgorithm");
    if (autoDisplayDistanceAlgorithm_obj.ptr()) {
        boundingY.init("Bouding.Y", "Item", "自動距離算出アルゴリズム", &boundingYObj);
        addObj(&boundingYObj, "AutoDisplayDistanceAlgorithm");
        boundingYObj.applyResParameterObj(autoDisplayDistanceAlgorithm_obj, nullptr);
    }

    const auto yLimitAlgorithm_obj = agl::utl::getResParameterObj(root, "YLimitAlgorithm");
    if (yLimitAlgorithm_obj.ptr()) {
        yLimitAlgorithm.init("NoLimit", "Item", "Y制限アルゴリズム", &yLimitAlgorithmObj);
        addObj(&yLimitAlgorithmObj, "YLimitAlgorithm");
        yLimitAlgorithmObj.applyResParameterObj(yLimitAlgorithm_obj, nullptr);
    }

    const auto deleteWeathers_obj = agl::utl::getResParameterObj(root, "DeleteWeathers");
    if (deleteWeathers_obj.ptr())
        LifeCondition::parseArray(&deleteWeathers_obj, &deleteWeathersObj, &mDeleteWeathersBuffer,
                                  "DeleteWeathers", "天候", heap);

    const auto deleteTimes_obj = agl::utl::getResParameterObj(root, "DeleteTimes");
    if (deleteTimes_obj.ptr())
        LifeCondition::parseArray(&deleteTimes_obj, &deleteTimesObj, &mDeleteTimesBuffer,
                                  "DeleteTimes", "時間", heap);

    return true;
}

void LifeCondition::parseArray(const agl::utl::ResParameterObj* data, agl::utl::IParameterObj* obj,
                               sead::Buffer<agl::utl::Parameter<sead::SafeString>>* buffer,
                               const sead::SafeString& key, const sead::SafeString& desc,
                               sead::Heap* heap) {
    addObj(obj, key);
    obj->applyResParameterObj(*data, nullptr);

    auto count = data->mPtr->getNumParameters();
    if (count == 0)
        return;

    buffer->allocBufferAssert(count, heap);

    for (int i = 0; i != count; ++i) {
        sead::FormatFixedSafeString<64> s;
        s.format("Item%03d", (i + 1));

        (*buffer)[i].init("", s, desc, obj);
    }

    obj->applyResParameterObj(*data, nullptr);
}

}  // namespace ksys::res