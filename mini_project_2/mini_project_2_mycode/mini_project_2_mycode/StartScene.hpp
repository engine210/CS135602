//
//  StartScene.hpp
//  mini_project_2_mycode
//
//  Created by engine210 on 2019/5/24.
//  Copyright © 2019 engine210. All rights reserved.
//

#ifndef StartScene_hpp
#define StartScene_hpp

#include "GameEngine.hpp"
#include "ImageButton.hpp"

class StartScene final : public Engine::IScene {
private:
    ALLEGRO_SAMPLE_INSTANCE* bgmInstance;
public:
    explicit StartScene() = default;
    void Initialize() override;
    void PlayOnClick(int stage);
};

#endif /* StartScene_hpp */
