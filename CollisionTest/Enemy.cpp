#include "Enemy.hpp"


Enemy::Enemy(Entry* e) : Actor(e)
{
	//初期座標
	mPosition.x = 500;
	mPosition.y = 270;

	//サイズ
	mSize.x = 80;
	mSize.y = 80;


	mCol.setPosition(&mPosition);
	mCol.setSize(&mSize);
	mCol.setTag(Tag::Enemy);

}

//更新
void Enemy::Update()
{

}

//描画
void Enemy::Draw()
{
	DrawBox(mPosition.x, mPosition.y, mPosition.x + mSize.x, mPosition.y + mSize.y, GetColor(200, 0, 0), true);
	DrawFormatString(0, 32, GetColor(200, 0, 0), "# Enemy Position: %d , %d", mPosition.x, mPosition.y);

}


Enemy::~Enemy()
{

}
