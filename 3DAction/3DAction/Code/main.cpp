#include <GSgame.h>
#include <memory>
#include "MyEngine\Scene\Manager\SceneManager.h"
#include "MyEngine\FrameWork\Manager\ContentManager.h"
#include "MyEngine\FrameWork\Renderer.h"
#include "MyEngine\FrameWork\ID\TexID.h"
#include "MyEngine\Scene\ID\SceneID.h"
#include "MyEngine\Scene\Interface\IScene.h"
#include "MyEngine\Def\GameDef.h"

using Scene_Ptr = std::unique_ptr<IScene>;

/**
@class MyGame
@brief マイゲームクラス
@author Yuuho Aritomi
@date 2017/03/05
*/
class MyGame : public gslib::Game
{
public:
	/**
	@fn
	@brief コンストラクタ
	*/
	MyGame() :
		gslib::Game(static_cast<int>(Screen::WIDTH), static_cast<int> (Screen::HEIGHT), false),
		m_sceneManager(),
		m_contentManager(),
		m_renderer(&m_contentManager)
	{

	}
	/**
	@fn
	@brief デストラクタ
	*/
	~MyGame()
	{

	}

private:
	//開始
	virtual void start() override
	{
		//** ここで読み込む画像を指定
		//** ここまで

		//** ここでシーンを読み込む
		//** ここまで

		m_sceneManager.start();
		m_sceneManager.changeScene(SceneID::NONE);
	}
	//更新
	virtual void update(float _deltaTime) override
	{
		m_sceneManager.update(_deltaTime);
	}
	//描画
	virtual void draw() override
	{
		m_sceneManager.draw(m_renderer);
	}
	//終了
	virtual void end() override
	{
		m_sceneManager.end();
		m_renderer.unloadContent();
	}
private:
	SceneManager m_sceneManager;		//シーンマネージャー
	ContentManager m_contentManager;	//コンテンツマネージャー
	Renderer m_renderer;				//描画クラス
};


int main(int argc, char* argv[])
{
	MyGame game;
	return game.run();
}