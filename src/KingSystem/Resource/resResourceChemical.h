#include <agl/Utils/aglParameter.h>
#include <agl/Utils/aglParameterList.h>
#include <agl/Utils/aglParameterObj.h> 
#include <container/seadBuffer.h>
#include "KingSystem/Resource/resResource.h"
#include "KingSystem/Utils/ParamIO.h"

namespace ksys::res {

class Chemical : public ParamIO, public Resource {
    SEAD_RTTI_OVERRIDE(Chemical, Resource)

    struct ChemHeader : agl::utl::ParameterList, sead::hostio::Node {
        ChemHeader() {
            res_shape_num.init(0, "res_shape_num", "シェイプ", "Min=0 ,Max=10", &header_obj);
        };

        agl::utl::Parameter<u32> res_shape_num;
        agl::utl::ParameterObj header_obj;
    };

    struct ChemRoot : ChemHeader {
        ChemRoot();
        agl::utl::ParameterList body;
        sead::Buffer<sead::BitFlag32> mBuffer1;
        sead::Buffer<sead::BitFlag32> mBuffer2;
        
        u32 getBufferSize();
    };

public:
    Chemical();
    ~Chemical() = default;

    ChemRoot mRoot;
};
//KSYS_CHECK_SIZE_NX150(Chemical, 0x3c0)

}  // namespace ksys::res

    // struct ChemHeader : agl::utl::ParameterList, sead::hostio::Node {
    //     ChemHeader() {
    //         res_shape_num.init(0, "res_shape_num", "シェイプ", "Min=0 ,Max=10", &header_obj);
    //     };

    //     agl::utl::Parameter<u32> res_shape_num;
    //     agl::utl::ParameterObj header_obj;
    // };

    // struct ChemRoot : ChemHeader {
    //     ChemRoot();
    //     agl::utl::ParameterList body;
    //     sead::Buffer<sead::BitFlag32> mBuffer1;
    //     sead::Buffer<sead::BitFlag32> mBuffer2;
        
    //     virtual u32 getBufferSize();
    // };