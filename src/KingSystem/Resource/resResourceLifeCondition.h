#include <agl/Utils/aglParameter.h>
#include <agl/Utils/aglParameterObj.h>
#include <container/seadBuffer.h>
#include "KingSystem/Resource/resResource.h"
#include "KingSystem/Utils/ParamIO.h"

namespace ksys::res {

class LifeCondition : public ParamIO, public Resource {
    void parseArray(const agl::utl::ResParameterObj* data, agl::utl::IParameterObj* obj,
                    sead::Buffer<agl::utl::Parameter<sead::SafeString>>* buffer,
                    const sead::SafeString& key, const sead::SafeString& desc, sead::Heap* heap);

    bool parse_(u8* data, size_t size, sead::Heap* heap) override;

    bool parse(u8* data, size_t size, sead::Heap* heap);

    agl::utl::IParameterObj invalidWeathersObj;
    agl::utl::IParameterObj invalidTimesObj;
    agl::utl::IParameterObj displayDistanceObj;
    agl::utl::IParameterObj deleteWeathersObj;
    agl::utl::IParameterObj deleteTimesObj;
    agl::utl::IParameterObj boundingYObj;
    agl::utl::IParameterObj yLimitAlgorithmObj;

    sead::Buffer<agl::utl::Parameter<sead::SafeString>> mInvalidWeathersBuffer;
    sead::Buffer<agl::utl::Parameter<sead::SafeString>> mInvalidTimesBuffer;
    agl::utl::Parameter<float> displayDistance;
    agl::utl::Parameter<sead::SafeString> boundingY;
    agl::utl::Parameter<sead::SafeString> yLimitAlgorithm;
    sead::Buffer<agl::utl::Parameter<sead::SafeString>> mDeleteWeathersBuffer;
    sead::Buffer<agl::utl::Parameter<sead::SafeString>> mDeleteTimesBuffer;
};

}  // namespace ksys::res