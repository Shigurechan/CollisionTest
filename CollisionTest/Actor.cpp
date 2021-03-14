#include "Actor.hpp"

//コンストラクタ
Actor::Actor(Entry* e,glm::vec2 pos ,glm::vec2 vec )
{
	mVector = vec;
	mPosition = pos;
	mSize = glm::vec2(0,0);
	Owner = e;
}

//方向を取得
glm::vec2 Actor::getVector()
{
	return mVector;
}

//座標を取得
glm::vec2 Actor::getPosition()
{
	return mPosition;
}

//座標を取得
void Actor::setPosition(glm::vec2 pos)
{
	mPosition = pos;
}




//デストラクタ
Actor::~Actor()
{

}
