#include "Player.hpp"
#include "Entry.hpp"
#include "Collision.hpp"

Player::Player(Entry* e) : Actor(e)
{
	//�������W
	mPosition.x = 235;
	mPosition.y = 270;

	//�T�C�Y
	mSize.x = 100 - 1;
	mSize.y = 100 - 1;

	//�����蔻���ݒ�

	mCol.setVector(&mVector);
	mCol.setTag(Tag::Player);


	mCol.setMax(&Max);
	mCol.setMin(&mPosition);
	
	mCol.setTag(Tag::Player);


	//mCol.setTrigger(true);
}


//�X�V
void Player::Update()
{
	int speed = 5;
	if (Owner->InputKey->getKeyDownHold(KEY_INPUT_LEFT) > 0 )
	{
		mPosition.x += -speed;
		mVector = VECTOR_LEFT;
	}
	else if (Owner->InputKey->getKeyDownHold(KEY_INPUT_RIGHT) > 0)
	{
		mPosition.x += +speed;
		mVector = VECTOR_RIGHT;
	}
	else if (Owner->InputKey->getKeyDownHold(KEY_INPUT_UP) > 0)
	{
		mPosition.y += -speed;
		mVector = VECTOR_UP;
	}
	else if(Owner->InputKey->getKeyDownHold(KEY_INPUT_DOWN) > 0)
	{
		mPosition.y += +speed;
		mVector = VECTOR_DOWN;
	}
	else {
		speed = 0;
		mVector = glm::ivec2(0,0);

	}
	
	Max = mPosition + mSize;


	printf("player: %d\n", mCol.getTag());



}

//�`��
void Player::Draw()
{

	DrawBox(mPosition.x, mPosition.y, mPosition.x + mSize.x, mPosition.y + mSize.y,GetColor(0,255,0),true);
	DrawFormatString(0,0,GetColor(0,255,0),"# Player Position: %d , %d",mPosition.x,mPosition.y);
}


Player::~Player()
{

}