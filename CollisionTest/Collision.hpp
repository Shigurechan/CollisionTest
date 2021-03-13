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
	glm::ivec2 mStart;
	glm::ivec2 mEnd;


}LineSegment;

typedef struct AABB
{
	glm::ivec2 *mMax;
	glm::ivec2 *mMin;

}AABB;

typedef struct Sphere
{
	glm::ivec2 *mCenter;	
	int *mRadius;		
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
	void setVector(glm::ivec2* vec);	//�����ݒ�
	void setTriggerType(bool tri);			//�g���K�[�^�C�v��ݒ�
	void setTag(Tag type);				//�^�O��ݒ�

	//�擾�@�֌W
	Tag getMyTag();				//�^�C�v���擾
	bool getTriggerType();			//�g���K�[�^�C�v���擾
	glm::ivec2 getVector();		//�������擾
	bool getCol();				//�����������ǂ����H
	Tag getTag();				//�擾�����^�C�v���擾


private:
	bool IsTrigger;		//�g���K�[�^�C�v���ǂ����H
	Tag my_TagType;		//���g�^�O
	Tag col_TagType;	//�擾�^�O
	glm::ivec2 *Vector;	//����
	bool isCol;			//�����������ǂ����H
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
	glm::ivec2 getMax();
	glm::ivec2 getMin();


	//�ݒ�@�֌W
	void setMax(glm::ivec2 *max);
	void setMin(glm::ivec2 *min);

	void setMaxValue(glm::ivec2 &max);
	void setMinValue(glm::ivec2 &min);

private:
	AABB box;
};





/*####################################################
* ���̓����蔻��
######################################################*/

class SphereCollision : public Collision
{
public:
	SphereCollision();		//�R���X�g���N�^
	~SphereCollision();		//�f�X�g���N�^

	void Intersect(SphereCollision& col);


	//�擾�@�֌W
	int getRadius();		//���a
	glm::ivec2 getCenter();	//�ʒu

	//�ݒ�@�֌W
	void setRadius(int *r);		//���a
	void setCenter(glm::ivec2 *pos);	//�ʒu

private:
	Sphere sp;
};




#endif