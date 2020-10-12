#include <agl/Utils/aglParameter.h>
#include <agl/Utils/aglParameterObj.h>
#include <math/seadVector.h>
#include <prim/seadSafeString.h>
#include "KingSystem/Resource/resResource.h"
#include "KingSystem/Utils/ParamIO.h"

namespace ksys::res {

class ActorCapture : public ParamIO, public Resource {
    struct ActorCaptureConstants {
        ActorCaptureConstants() {
            cameraPosition = {0, 2, 5};
            cameraDirection = {0, 2, 0};
            actorPosition = sead::Vector3f::zero;
            actorRotation = sead::Vector3f::zero;
            lightDirection = {0.57206, -0.70711, -0.41563};
        }

        sead::Vector3f cameraPosition;
        sead::Vector3f cameraDirection;
        sead::Vector3f actorPosition;
        sead::Vector3f actorRotation;
        sead::Vector3f lightDirection;
    };

    struct CameraInfo : agl::utl::ParameterObj {
        agl::utl::Parameter<sead::Vector3f> position;
        agl::utl::Parameter<sead::Vector3f> direction;
        agl::utl::Parameter<f32> fov;
        agl::utl::Parameter<f32> tilt;
    };

    struct ActorInfo : agl::utl::ParameterObj {
        agl::utl::Parameter<sead::Vector3f> position;
        agl::utl::Parameter<sead::Vector3f> rotation;
        agl::utl::Parameter<sead::FixedSafeString<32>> name;
        agl::utl::Parameter<bool> applySkelAnim;
        agl::utl::Parameter<f32> frame;
        agl::utl::Parameter<bool> boundingAdjustment;
        agl::utl::Parameter<bool> forceIdle;
        agl::utl::Parameter<bool> disableCloth;
    };

    struct LightInfo : agl::utl::ParameterObj {
        agl::utl::Parameter<sead::Vector3f> direction;
    };

public:
    ActorCapture();

    static ActorCaptureConstants sConstants;
    CameraInfo mCameraInfoObj;
    ActorInfo mActorInfoObj;
    LightInfo mLightInfoObj;
};
KSYS_CHECK_SIZE_NX150(ActorCapture, 0x538);

}  // namespace ksys::res
