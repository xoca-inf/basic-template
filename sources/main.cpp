#include "Game/GameUi.h"
#include "W4Framework.h"
#include "Settings/Settings.h"
#include "AdsNetworkWrapper.h"
#include "Audio/AudioManager.h"
#include "Settings/ResourceLibary.h"
#include "FlowUi/Fov/AdaptiveFov.h"
#include "gameFsm.h"

W4_USE_UNSTRICT_INTERFACE

float preloadingTime = 1.0f;

struct SpadesGame : public IGame
{
    void onConfig() override
    {
        Game::Config.StopUpdateWhenFocusLoss = false;
        Game::Config.AutoUsePreloader = false;
    }
    void onStart() override{
        m_isPause = false;
        m_gameRoot = make::sptr<Node>("GameRoot");
        Render::getRoot()->addChild(m_gameRoot);
        m_camera = Render::getScreenCamera();
        m_cameraNode = make::sptr<Node>("CameraNode");
        m_cameraNode->setWorldTranslation(m_camera->getWorldTranslation());
        m_gameRoot->addChild(m_cameraNode);
        m_cameraNode->addChild(m_camera);
        w4::network::ads::start();
        platform::Platform::showLoader();

        W4_LOG_DEBUG("onStart called");
        Settings::instance();       // settings initialization here
        ResourceLibary::instance(); // resource libary initialization here
        initializeFsm();            // FSM initialization here

        w4::network::ads::onVisibleChangeHandler(this, [](void *w4Self, bool result) {
            mute(!result);
            }
        );
        w4::network::ads::onAudioVolumeChangeHandler(this, [](void *w4Self, float volume) {
            auto selfTyped = reinterpret_cast<SpadesGame *>(w4Self);
            Audio::setGlobalGain(volume);
            });

        platform::Platform::showLoader();
    }

    void onResize(const math::size& newSize) override
    {
        Render::getScreenCamera()->setFov(games::benice::utils::AdaptiveFov::getAdaptiveFov(newSize));
        if (m_gameUi != nullptr)
        {
            m_gameUi->updateSize();
        }
    }

    void onPause() override {
        mute(true);
        m_isPause = true;
    }

    void onResume() override {
        mute(false);
        m_isPause = false;
    }

    void onUpdate(float dt) override{
        m_fsm.update(dt); // in case you need to implement onUpdateFunc on some states
    }

    void initializeFsm(){
        m_fsm.state<FSM::States::Preloading>().onEnterFunc = [this](auto&, auto&, auto&){
            platform::Platform::showLoader();

            Timer::addTask(preloadingTime, [this]() {m_fsm.processEvent(FSM::Events::Initialize);  return true; });
        };

        m_fsm.state<FSM::States::Preloading>().onLeaveFunc = [this](auto&, auto&, auto&){
        };

        m_fsm.state<FSM::States::Game>().onEnterFunc = [this](auto&, auto&, auto&) {
            platform::Platform::hideLoader();
            m_fsm.processEvent(FSM::Events::FirstTurn);
        };

        // ----------- FURST TURN ---------------


        m_fsm.state<FSM::States::FirstTurn>().onEnterFunc = [this](auto&, auto&, auto&){
            m_cameraNode->setWorldTranslation(vec3::zero);
            m_cameraNode->setWorldRotation(Rotator(0, 0, 0));
            m_gameUi = make::sptr<GameUi>(m_cameraNode, m_camera, 2.f, 0.f);
            m_gameUi->init(true);
        };


        //launching first state - need to fsm process start
        m_fsm.init<FSM::States::Preloading>(FSM::Events::Initialize);
        W4_LOG_DEBUG("FSM initialized");
    }

private:
    struct FSM{
        enum class Events {
            Initialize,
            FirstTurn,
            SecondTurn,
            Preloading,
            Game
        };
        struct States {
            struct Preloading : w4::fsm::FuncState<Events>
            {
            };
            struct FirstTurn : w4::fsm::FuncState<Events>
            {
            };
            struct SecondTurn : w4::fsm::FuncState<Events>
            {
            };
            struct Game : w4::fsm::FuncState<Events>
            {
            };
        };
        using Type = w4::fsm::FSM<
                // initialization
                w4::fsm::Transition<Events::Initialize, States::Preloading,
                        States::Game>,
                w4::fsm::Transition<Events::FirstTurn, States::Game,
                        States::FirstTurn>,
                w4::fsm::Transition<Events::SecondTurn, States::FirstTurn,
                        States::SecondTurn>>;
    };
    bool m_isPause;

    FSM::Type m_fsm;
    sptr<GameUi> m_gameUi;
    sptr<Node> m_cameraNode;
    sptr<Node> m_gameRoot;
    sptr<Camera> m_camera;

};

W4_RUN(SpadesGame)
