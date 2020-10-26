#include "KingSystem/Resource/resResourceChemical.h"

namespace ksys::res {

u32 Chemical::ChemRoot::getBufferSize() {
    return mBuffer1.size();
}

Chemical::Chemical() : ParamIO("chemical", 0) {
    addList(&mRoot, "chemical_root");
}

Chemical::ChemRoot::ChemRoot() {
    addObj(&header_obj, "chemical_header");
    addList(&body, "chemical_body");
}

}  // namespace ksys::res
