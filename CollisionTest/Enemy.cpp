#include "Enemy.hpp"
#include "Entry.hpp"


Enemy::Enemy(Entry* e) : Actor(e)
{
	//サイズ
	mSize.x = 100;
	mSize.y = 100;

	//初期座標
	mPosition.x = (SCREEN_WIDTH / 2) - (mSize.x / 2);
	mPosition.y = (SCREEN_HEIGHT / 2) - (mSize.y / 2);

	mVector = VECTOR_NONE;
	mCol.setVector(&mVector);
	mCol.setTag(Tag::Player);


	Max = mPosition + mSize;
	mCol.setMax(&Max);
	mCol.setMin(&mPosition);


	mCol.setTag(Tag::Enemy);

}

//更新
void Enemy::Update()
{
	printf("Enemy: %d\n",mCol.getTag());

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
