#pragma once
#include "Graphics.h"

#include <memory>

#include "Camera.h"
#include "GameState.h"
#include "SpriteSheet.h"

#include "SoundManager.h"
#include "Locator.h"
#include "VecRect.h"
#include "TextureManager.h"
#include "Player.h"
#include "AnimationManager.h"
class Game
{
	
	class Direct3DWindow& window;
	Graphics gfx;
	void EndApp();
	Camera m_cam;
	
	_GameState m_gameState = _GameState::paused;
private:
	std::unique_ptr<SoundManager> m_soundFX;
	std::unique_ptr<TextureManager> m_textures;
	std::unique_ptr<Player> m_player;
	std::unique_ptr<AnimationManager> m_animationMgr;
	std::vector<std::unique_ptr<GameObject2D_Dynamic>> m_objects;
public:
	Game(class Direct3DWindow& wnd);
	~Game() {}
	bool Play(const float& deltaTime);
	HRESULT ConstructScene(const float& deltaTime);
	HRESULT RenderScene();
	
	////////////////////////////////////
	// LOGIC
	////////////////////////////////////
	
private:
	
	void LoadAudio();
	void LoadImages();
	void SetUpPlayer();
	void CreateObjects();
};
