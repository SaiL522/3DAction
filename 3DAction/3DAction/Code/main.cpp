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
@brief �}�C�Q�[���N���X
@author Yuuho Aritomi
@date 2017/03/05
*/
class MyGame : public gslib::Game
{
public:
	/**
	@fn
	@brief �R���X�g���N�^
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
	@brief �f�X�g���N�^
	*/
	~MyGame()
	{

	}

private:
	//�J�n
	virtual void start() override
	{
		//** �����œǂݍ��މ摜���w��
		//** �����܂�

		//** �����ŃV�[����ǂݍ���
		//** �����܂�

		m_sceneManager.start();
		m_sceneManager.changeScene(SceneID::NONE);
	}
	//�X�V
	virtual void update(float _deltaTime) override
	{
		m_sceneManager.update(_deltaTime);
	}
	//�`��
	virtual void draw() override
	{
		m_sceneManager.draw(m_renderer);
	}
	//�I��
	virtual void end() override
	{
		m_sceneManager.end();
		m_renderer.unloadContent();
	}
private:
	SceneManager m_sceneManager;		//�V�[���}�l�[�W���[
	ContentManager m_contentManager;	//�R���e���c�}�l�[�W���[
	Renderer m_renderer;				//�`��N���X
};


int main(int argc, char* argv[])
{
	MyGame game;
	return game.run();
}