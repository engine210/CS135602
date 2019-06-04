#ifndef PLAYSCENE_HPP
#define PLAYSCENE_HPP
#include <list>
#include <utility>
#include <vector>
#include <allegro5/allegro_audio.h>

#include "IScene.hpp"
#include "Point.hpp"
#include "StaticImageButton.hpp"

class Turret;
namespace Engine {
	class Group;
	class Image;
	class Label;
}  // namespace Engine

class PlayScene final : public Engine::IScene {
private:
    /*
    //original
	enum TileType {
		TILE_DIRT,
		TILE_FLOOR,
		TILE_OCCUPIED,
	};
    */
    ALLEGRO_SAMPLE_INSTANCE* bgmInstance;
    bool is_mute = false;
    float BGMv;
    float SFXv;
    Engine::StaticImageButton* muteIcon;
    std::shared_ptr<ALLEGRO_BITMAP> imgMute, imgUnmute;
    
protected:
	int lives;
	int money;
	int SpeedMult;
public:
    //new added here from private
    enum TileType {
        TILE_DIRT,
        TILE_FLOOR,
        TILE_OCCUPIED,
    };
	static bool DebugMode;
	static const std::vector<Engine::Point> directions;
	static const int MapWidth, MapHeight;
	static const int BlockSize;
	static const Engine::Point SpawnGridPoint;
	static const Engine::Point EndGridPoint;
	static const std::vector<int> code;
	int MapId;
	float ticks;
	// Map tiles.
	Group* TileMapGroup;
	Group* GroundEffectGroup;
	Group* DebugIndicatorGroup;
	Group* BulletGroup;
	Group* TowerGroup;
	Group* EnemyGroup;
	Group* EffectGroup;
	Group* UIGroup;
	Engine::Label* UIMoney;
	Engine::Label* UILives;
	Engine::Image* imgTarget;
	Turret* preview;
	static std::vector<std::vector<TileType>> mapState;
    static std::vector<std::vector<TileType>> oriMapState; // original map state
	std::vector<std::vector<int>> mapDistance;
	std::list<std::pair<int, float>> enemyWaveData;
	std::list<int> keyStrokes;
	static Engine::Point GetClientSize();
	explicit PlayScene() = default;
	void Initialize() override;
	void Update(float deltaTime) override;
	void Draw() const override;
	void OnMouseDown(int button, int mx, int my) override;
	void OnMouseMove(int mx, int my) override;
	void OnMouseUp(int button, int mx, int my) override;
	void OnKeyDown(int keyCode) override;
	void Hit();
	int GetMoney() const;
	void EarnMoney(int money);
	void ReadMap();
	void ReadEnemyWave();
	void ConstructUI();
	void UIBtnClicked(int id);
	bool CheckSpaceValid(int x, int y);
	std::vector<std::vector<int>> CalculateBFSDistance();
	// void ModifyReadMapTiles();
    
    
    void BGMSlideOnValueChanged(float value);
    void SFXSlideOnValueChanged(float value);
    void MuteOnClick();
    void ExitOnClick();
};
#endif // PLAYSCENE_HPP
