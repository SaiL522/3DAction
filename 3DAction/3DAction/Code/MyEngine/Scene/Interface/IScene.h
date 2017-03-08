#pragma once

#include "..\ID\SceneID.h"

class Renderer;

/**
@class
@brief シーンマネージャー
@author 有冨勇帆
@date 2017/01/29
*/
class IScene
{
public:
	/**
	@fn
	@brief デストラクタ
	*/
	virtual ~IScene() = default;
	/**
	@fn
	@brief 開始
	*/
	virtual void start() = 0;
	/**
	@fn
	@brief 更新
	@param _deltaTime
	*/
	virtual void update(float _deltaTime) = 0;
	/**
	@fn
	@brief 描画
	*/
	virtual void draw(const Renderer& _renderer) = 0;
	/**
	@fn
	@brief 終了
	*/
	virtual void end() = 0;
	/**
	@fn
	@brief 終了したか？
	@return 終了したか？
	*/
	virtual bool isEnd() = 0;
	/**
	@fn
	@brief 次のシーン
	*/
	virtual SceneID next() = 0;
};