#include "Enemy.hpp"
#include "Entry.hpp"


Enemy::Enemy(Entry* e) : Actor(e)
{
	//�������W
	mPosition.x = 500;
	mPosition.y = 270;

	//�T�C�Y
	mSize.x = 80;
	mSize.y = 80;

	mVector = VECTOR_NONE;

	mCol.setPosition(&mPosition);
	mCol.setVector(&mVector);
	mCol.setSize(&mSize);
	mCol.setTag(Tag::Enemy);

}

//�X�V
void Enemy::Update()
{
	printf("Enemy Tag: %d\n",mCol.getTag());
}

//�`��
void Enemy::Draw()
{
	DrawBox(mPosition.x, mPosition.y, mPosition.x + mSize.x, mPosition.y + mSize.y, GetColor(200, 0, 0), true);
	DrawFormatString(0, 32, GetColor(200, 0, 0), "# Enemy Position: %d , %d", mPosition.x, mPosition.y);

}


Enemy::~Enemy()
{

}
