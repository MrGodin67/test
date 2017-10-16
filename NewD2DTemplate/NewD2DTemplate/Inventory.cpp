#include "Inventory.h"
#include "Camera.h"
#include "Locator.h"
#include "AnimationManager.h"
GUI_Inventory::GUI_Inventory()
{
	windowFrame = { 100.0f,10.0f,612.0f,522.0f };
	AnimationSequence::SequenceDesc desc;
	desc.desc.image = Locator::ImageManager->GetImage("inventory_back")->GetTexture();
	desc.desc.clipRect = { 0.0f,0.0f,512.0f,512.0f };
	desc.desc.drawRect = windowFrame.ToD2D();
	desc.imageID = "inventory_back";
	desc.indices.push_back(0);
	desc.interval = 0.0f;
	desc.loop = false;
	m_animations["background"].SetRenderDesc(desc);
	m_animations["body"].SetRenderDesc(AnimationManager::GetBody_1( Vec2f(windowFrame.left+64.0f, windowFrame.top+64.0f),384.0f));

}

void GUI_Inventory::Draw(Camera & cam)
{
	cam.Rasterize(m_animations["background"].GetDrawable());
	cam.Rasterize(m_animations["body"].GetDrawable());
}
