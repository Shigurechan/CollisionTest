#ifndef ENEMY_HPP
#define ENEMY_HPP
#include "Actor.hpp"
#include "Collision.hpp"

class Actor;
class Entry;


class Enemy : public Actor
{
public:

	Enemy(Entry* e);	//�R���X�g���N�^
	~Enemy();			//�f�X�g���N�^

	void Update();		//�X�V
	void Draw();		//�`��

	
private:
	glm::ivec2 mSize;


};

#endif
