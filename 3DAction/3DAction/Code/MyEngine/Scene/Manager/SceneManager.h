#pragma once

#include <map>
#include <memory>
#include <string>
#include "..\ID\SceneID.h"

class IScene;
class Renderer;

/**
@class
@brief シーンマネージャー
@author 有冨勇帆
@date 2017/01/29
*/
class SceneManager
{
private:
public:
	/**
	@fn
	@brief コンストラクタ
	*/
	SceneManager();
	/**
	@fn
	@brief デストラクタ
	*/
	~SceneManager() = default;
	/**
	@fn
	@brief 開始
	*/
	void start();
	/**
	@fn
	@brief 更新
	@param[_deltaTime] 毎フレームの時間
	*/
	void update(float _deltaTime);
	/**
	@fn
	@brief 描画
	@param[_renderer] 描画クラス
	*/
	void draw(const Renderer& _renderer);
	/**
	@fn
	@brief 終了
	*/
	void end();
	/**
	@fn
	@brief シーンの追加
	*/
	void addScene(SceneID _id, std::unique_ptr<IScene>* _scene);
	/**
	@fn
	@briefシーンを切り替える
	@param[_id] 切り替えたいシーンＩＤ
	*/
	void changeScene(SceneID _id);
private:
	//シーン切り替え
	void change();
private:
	//型名省略
	using ScenePtr = std::unique_ptr<IScene>;
	using SceneContainer = std::map<SceneID, ScenePtr>;
private:
	//シーン用コンテナ
	SceneContainer m_scenes;
	//現在のシーン
	SceneID m_currentScene;
};