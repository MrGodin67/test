#include "Game.h"
#include "Direct3DWindow.h"




Game::Game(Direct3DWindow & wnd)
	:
	window(wnd),
	gfx(wnd.ScreenWidth(),wnd.ScreenHeight(),wnd.WindowHandle(),
		true, FULL_SCREEN,1000.0f,0.01f),
	m_cam(&gfx,(float)wnd.ScreenWidth(), (float)wnd.ScreenHeight())
{
	LoadAudio();
	LoadImages();
	SetUpPlayer();
	CreateObjects();
}

bool Game::Play(const float& deltaTime)
{
	HRESULT hr;
	if (FAILED(hr = ConstructScene(deltaTime))) { return false; }
	if (FAILED(hr = RenderScene())) { return false; }
	return true;
}

HRESULT Game::ConstructScene(const float& deltaTime)
{
	m_player->Update(deltaTime);
	

	if ((m_objects[0]->GetPosition() - m_objects[1]->GetPosition()).Len() < 200.0f)
	{
		m_objects[0]->SetTarget(m_objects[1].get());
	}
	else
	{
		m_objects[0]->SetTarget(nullptr);
	}
	for (auto& it : m_objects)
		it->Update(deltaTime);
	return S_OK;
}

HRESULT Game::RenderScene()
{
	HRESULT hr;
	hr = gfx.BeginScene(0.0f, 0.0f, 0.0f, 1.0f);
	if (FAILED(hr)) { return hr; }
	
	for (auto& it : m_objects)
		it->Draw(gfx,m_cam);

	hr = gfx.EndScene();
	if (FAILED(hr)) { return hr; }
	return hr;
}

void Game::EndApp()
{
	PostQuitMessage(0);
}

void Game::LoadAudio()
{
	m_soundFX = std::make_unique<SoundManager>();
	
	

}

void Game::LoadImages()
{
	m_animationMgr = std::make_unique<AnimationManager>();
	m_textures = std::make_unique<TextureManager>();
	std::vector<TextureManager::ImageData> v_data;
	TextureManager::ImageData data("main_image", L"image2.png", 32.0f, 32.0f);
	v_data.push_back(data);
	m_textures->LoadImages(v_data);
	Locator::SetImageManager(m_textures.get());
}

void Game::SetUpPlayer()
{
	Animation::RenderDesc desc;
TextureManager::ImageClip clip;
	clip = Locator::ImageManager->GetClip("main_image", 64*7+25);
	desc.clipRect = clip.rect.ToD2D();
	desc.image = clip.bitmap;
	std::vector<int> indices;
	for(int c = 0;c < 8;c++)
	   indices.push_back(64 * 7 + 25 + c);
	desc.drawRect = { 100.0f,100.0f,164.0f,164.0f };
	
	AnimationSequence::SequenceDesc seqDesc(desc, 64 * 7 + 25, 8, 0.15f, "main_image", true, RectF(1.0f, 1.0f, -1.0f, -1.0f));
	m_player = std::make_unique<Player>(seqDesc);
	std::vector<nodeData> d;
	nodeData nd;
	nd.position = Vec2f(20.0f, 20.0f);
	d.push_back(nd);
	nd.position = Vec2f(500.0f, 300.0f);
	d.push_back(nd);
	nd.position = Vec2f(300.0f, 500.0f);
	d.push_back(nd);
	nd.position = Vec2f(700.0f, 100.0f);
	d.push_back(nd);

	nd.position = Vec2f(750.0f, 500.0f);
	d.push_back(nd);
	nd.position = Vec2f(10.0f, 300.0f);
	d.push_back(nd);
	nd.position = Vec2f(300.0f, 500.0f);
	d.push_back(nd);
	nd.position = Vec2f(4.0f, 100.0f);
	d.push_back(nd);
	
	m_player->SetWaypoints(d);

	
}

void Game::CreateObjects()
{
	std::vector<nodeData> d;
	nodeData nd;
	nd.position = Vec2f(20.0f, 20.0f);
	d.push_back(nd);
	nd.position = Vec2f(500.0f, 300.0f);
	d.push_back(nd);
	nd.position = Vec2f(300.0f, 500.0f);
	d.push_back(nd);
	nd.position = Vec2f(700.0f, 100.0f);
	d.push_back(nd);

	nd.position = Vec2f(750.0f, 500.0f);
	d.push_back(nd);
	nd.position = Vec2f(10.0f, 300.0f);
	d.push_back(nd);
	nd.position = Vec2f(300.0f, 500.0f);
	d.push_back(nd);
	nd.position = Vec2f(4.0f, 100.0f);
	d.push_back(nd);
	m_objects.push_back(m_animationMgr->GetEyeTotem({ 100.0f,100.0f }));
	m_objects.back()->SetWaypoints(d);
	m_objects.push_back(m_animationMgr->GetFirePit({ 10.0f,500.0f }));
	m_objects.back()->SetWaypoints(d);
	m_objects.push_back(m_animationMgr->GetTumbleNet({ 500.0f,500.0f }));
	m_objects.back()->SetWaypoints(d);

	m_objects.push_back(m_animationMgr->GetExplosion_1({ 300.0f,300.0f }));
	m_objects.back()->SetWaypoints(d);
}




