#include "KingSystem/Resource/resResourceActorCapture.h"

namespace ksys::res {

static ActorCapture::ActorCaptureConstants sConstants;

const ActorCapture::ActorCaptureConstants& ActorCapture::getConstants() {
    return sConstants;
}

ActorCapture::ActorCapture() : ParamIO("actcapt", 0) {
    addObj(&mCameraInfoObj, "camera_info");
    mCameraInfoObj.position.init(sConstants.cameraPosition, "pos", "カメラ位置", &mCameraInfoObj);
    mCameraInfoObj.direction.init(sConstants.cameraDirection, "at", "カメラ注視点",
                                  &mCameraInfoObj);
    mCameraInfoObj.fov.init(50.0, "fovy", "カメラ画角", &mCameraInfoObj);
    mCameraInfoObj.tilt.init(0.0, "twist", "カメラひねり", &mCameraInfoObj);

    addObj(&mActorInfoObj, "actor_info");
    mActorInfoObj.position.init(sConstants.actorPosition, "pos", "アクタ位置", &mActorInfoObj);
    mActorInfoObj.rotation.init(sConstants.actorRotation, "rotate", "アクタRotate", &mActorInfoObj);
    mActorInfoObj.name.init(sead::SafeString::cEmptyString, "as_name", "適用するASのKey名",
                            &mActorInfoObj);
    mActorInfoObj.applySkelAnim.init(false, "apply_skl_anim",
                                     "スケルタルアニメを検索して直接適用する", &mActorInfoObj);
    mActorInfoObj.frame.init(0.0, "as_frame", "ASのフレーム・経過時間指定", &mActorInfoObj);
    mActorInfoObj.boundingAdjustment.init(false, "adjust_bounding",
                                          "バウンディングを元に位置を調整する", &mActorInfoObj);
    mActorInfoObj.forceIdle.init(false, "force_idle", "強制待機", &mActorInfoObj);
    mActorInfoObj.disableCloth.init(false, "disable_cloth", "クロスを切る", &mActorInfoObj);

    addObj(&mLightInfoObj, "light_info");
    mLightInfoObj.direction.init(sConstants.lightDirection, "dir", "ライト方向", &mLightInfoObj);
}

}  // namespace ksys::res
