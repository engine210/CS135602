//
//  StartScene.hpp
//  mini_project_2_v3_mycode
//
//  Created by engine210 on 2019/5/26.
//  Copyright © 2019 engine210. All rights reserved.
//

#ifndef StartScene_hpp
#define StartScene_hpp

#include <allegro5/allegro_audio.h>
#include "IScene.hpp"

class StartScene final : public Engine::IScene {
private:
    ALLEGRO_SAMPLE_INSTANCE* bgmInstance;
public:
    explicit StartScene() = default;
    void Initialize() override;
    void StartOnClick();
};

#endif /* StartScene_hpp */
