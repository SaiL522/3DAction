#pragma once

#include <memory>
#include <list>

class IGameObject;
class Renderer;

/**
@class
@brief ゲームオブジェクトマネージャー
@author 有冨勇帆
@date 2017/03/07
*/
class GameObjectManager
{
public:
	/**
	@fn
	@brief コンストラクタ
	*/
	GameObjectManager();
	/**
	@fn
	@brief 開始
	*/
	void start();
	/**
	@fn
	@brief 更新
	@param[_deltaTime] １フレーム毎の時間
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
	@brief オブジェクトの追加
	@param[_objct] 追加するオブジェクト
	*/
	void add(std::unique_ptr<IGameObject>* _object);
private:
	//衝突判定
	void collision();
	//オブジェクトを追加
	void addObject();
private:
	//型名省略
	using Obj_Ptr = std::unique_ptr<IGameObject>;
	using Obj_List = std::list<Obj_Ptr>;
private:
	Obj_List m_objs;
	Obj_List m_newObjs;
};