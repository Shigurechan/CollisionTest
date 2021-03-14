#ifndef ___ACTOR_HPP_
#define ___ACTOR_HPP_

#include "glm/glm.hpp"
#include "dxlib.h"

//#include "Entry.hpp"
class Entry;
/*####################################################
* アクター
* 
* 説明
* 全てのゲームオブジェクトはこれを継承する。
######################################################*/

class Actor
{
public:
	Actor(Entry* e,glm::vec2 pos = glm::vec2(0, 0), glm::vec2 vec = glm::vec2(0, 0));	//コンストラクタ
	~Actor();	//デストラクタ

	void virtual Update() = 0;	//計算
	void virtual Draw() = 0;	//描画

	//取得　関係
	glm::vec2 getVector();		//方向
	glm::vec2 getPosition();	//座標

	//設定　関係
	void setPosition(glm::vec2 pos);

protected:

	glm::vec2 mPosition;	//座標
	glm::vec2 mVector;		//方向
	glm::vec2 mSize;		//サイズ
	glm::vec2 mSpeed;		//速度
	Entry* Owner;			//Entry クラス

};


#endif
