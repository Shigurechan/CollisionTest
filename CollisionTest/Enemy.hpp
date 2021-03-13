#ifndef ENEMY_HPP
#define ENEMY_HPP
#include "Actor.hpp"
#include "Collision.hpp"

class Actor;
class Entry;


class Enemy : public Actor
{
public:

	Enemy(Entry* e);	//コンストラクタ
	~Enemy();			//デストラクタ

	void Update();		//更新
	void Draw();		//描画

	
private:
	glm::ivec2 mSize;


};

#endif
