#ifndef ___COLLISION_HPP_
#define ___COLLISION_HPP_

#include "glm/glm.hpp"
//#include "MapChip.hpp"

//�O���錾
enum class StageObjectType;	//�I�u�W�F�N�g�^�C�v

/*####################################################
* ��`���m�̓����蔻�� 
######################################################*/
class Box_Collision
{
public:
	Box_Collision();	//�R���X�g���N�^
	~Box_Collision();	//�f�X�g���N�^
	
	bool Intersect(Box_Collision &a);	//��������

	//�擾�@�֌W
	bool getTrigger();					//�g���K�[�^�C�v���擾
	glm::ivec2 getPosition();			//���W���擾
	glm::ivec2 getSize();				//�T�C�Y���擾
	StageObjectType getObjectType();	//�I�u�W�F�N�g�^�C�v���擾
	glm::ivec2 getVector();				//�������擾

	//�ݒ�@�֌W
	void setTrigger(bool tri);							//�g���K�[�^�C�v��ݒ�
	void setPosition(glm::ivec2 pos);					//���W��ݒ�
	void setSize(glm::ivec2 size);						//�T�C�Y��ݒ�
	void setStageObjectType(StageObjectType type);		//�I�u�W�F�N�g�^�C�v��ݒ�
	void setVector(glm::ivec2 vec);						//�����ݒ�
	
protected:

private:

	bool mIsTrigger;		//�g���K�[�^�C�v���ǂ����H
	StageObjectType Type;	//�I�u�W�F�N�g�^�C�v
	glm::ivec2 mPosition;	//���W
	glm::ivec2 mSize;		//�T�C�Y
	glm::ivec2 mVector;		//����



};


#endif