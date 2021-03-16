#ifndef ___COLLISION_HPP_
#define ___COLLISION_HPP_

#include "glm/glm.hpp"

//�^�O
typedef enum class Tag
{
	Player,
	Enemy,
	Wall,
	Item,
	None,		//���ݒ�


	Invalid,	//�������ĂȂ�
}Tag;


//�v���~�e�B�u�^

typedef struct LineSegment
{
	glm::vec2 mStart;
	glm::vec2 mEnd;


}LineSegment;

typedef struct AABB
{
	glm::vec2 *mMax;
	glm::vec2 *mMin;

}AABB;

typedef struct Sphere
{
	glm::vec2 *mCenter;	
	float *mRadius;		
}Sphere;

/*####################################################
* �����蔻��̊��N���X
######################################################*/

/*�����蔻��̊��N���X
* 
* �@�\�ꗗ
* �g���K�[�^�C�v
* �^�O
* �����������ǂ����H
* 
* 
*/
class Collision
{
public:
	Collision();	//�R���X�g���N�^
	~Collision();	//�f�X�g���N�^
	
	//�@�\
	
	

	//�ݒ�@�֌W
	void setCol(bool b);				//�����������ǂ����H
	void setColTag(Tag type);			//�擾�����^�C�v�ݒ�
	void setVector(glm::vec2* vec);		//�����ݒ�
	void setTriggerType(bool tri);		//�g���K�[�^�C�v��ݒ�
	void setTag(Tag type);				//�^�O��ݒ�
	void setSpeed(glm::vec2 *spp);		//���x��ݒ�

	//�擾�@�֌W
	Tag getMyTag();				//�^�C�v���擾
	bool getTriggerType();		//�g���K�[�^�C�v���擾
	glm::vec2 getVector();		//�������擾
	bool getCol();				//�����������ǂ����H
	Tag getTag();				//�擾�����^�C�v���擾
	glm::vec2 getSpeed();		//���x���擾

private:
	bool IsTrigger;		//�g���K�[�^�C�v���ǂ����H
	Tag my_TagType;		//���g�^�O
	Tag col_TagType;	//�擾�^�O
	glm::vec2 *Vector;	//����
	bool isCol;			//�����������ǂ����H
	glm::vec2 *Speed;	//���x
};


/*####################################################
* ��`�̓����蔻��
######################################################*/

class BoxCollision : public Collision
{
public:
	BoxCollision();		//�R���X�g���N�^
	~BoxCollision();	//�f�X�g���N�^

	void Intersect(BoxCollision &col);

	//�擾�@�֌W
	glm::vec2 getMax();
	glm::vec2 getMin();


	//�ݒ�@�֌W
	void setMax(glm::vec2 *max);
	void setMin(glm::vec2 *min);

	void setMaxValue(glm::vec2 &max);
	void setMinValue(glm::vec2 &min);

private:
	

	glm::vec2 getFixValue(glm::vec2 player_min,glm::vec2 player_max, glm::vec2 block_min,glm::vec2 block_max);	//�␳�ʂ��̂𓾂�



	AABB box;
};





/*####################################################
* ���̓����蔻��
######################################################*/

class CircleCollision : public Collision
{
public:
	CircleCollision();		//�R���X�g���N�^
	~CircleCollision();		//�f�X�g���N�^

	void Intersect(CircleCollision& col);


	//�擾�@�֌W
	float getRadius();		//���a
	glm::vec2 getCenter();	//�ʒu

	//�ݒ�@�֌W
	void setRadius(float *r);				//���a
	void setCenter(glm::vec2 *pos);	//�ʒu

	void setRadiusValue(float r);				//���a
	void setCenterValue(glm::vec2 pos);	//�ʒu


private:
	Sphere sp;
};




#endif