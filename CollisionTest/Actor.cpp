#include "Actor.hpp"

//�R���X�g���N�^
Actor::Actor(Entry* e,glm::vec2 pos ,glm::vec2 vec )
{
	mVector = vec;
	mPosition = pos;
	mSize = glm::vec2(0,0);
	Owner = e;
}

//�������擾
glm::vec2 Actor::getVector()
{
	return mVector;
}

//���W���擾
glm::vec2 Actor::getPosition()
{
	return mPosition;
}

//���W���擾
void Actor::setPosition(glm::vec2 pos)
{
	mPosition = pos;
}




//�f�X�g���N�^
Actor::~Actor()
{

}
