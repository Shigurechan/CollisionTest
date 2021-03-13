#ifndef ___COLLISION_HPP_
#define ___COLLISION_HPP_

#include "glm/glm.hpp"
//#include "MapChip.hpp"

//�O���錾
typedef enum class Tag
{
	Player,
	Enemy,
	Wall,
	Item,
	None,		//���ݒ�

	Invalid,	//�������ĂȂ�
}Tag;

/*####################################################
* ��`���m�̓����蔻�� 
######################################################*/
class Box_Collision
{
public:
	Box_Collision();	//�R���X�g���N�^
	~Box_Collision();	//�f�X�g���N�^
	
//	void Intersect(Box_Collision &a);	//��������

protected:
	//�擾�@�֌W
	bool getTrigger();			//�g���K�[�^�C�v���擾
	bool getCol();				//�����������ǂ����H
	glm::ivec2 getPosition();	//���W���擾
	glm::ivec2 getSize();		//�T�C�Y���擾
	Tag getTag();				//�擾�����^�C�v���擾
	Tag getMyTag();				//�^�C�v���擾
	glm::ivec2 getVector();		//�������擾


	//�ݒ�@�֌W
	void setPosition(glm::ivec2 *pos);	//���W��ݒ�
	void setSize(glm::ivec2 *size);		//�T�C�Y��ݒ�
	void setVector(glm::ivec2 *vec);	//�����ݒ�
	void setTrigger(bool tri);			//�g���K�[�^�C�v��ݒ�
	void setTag(Tag type);				//�^�O��ݒ�
	void setColTag(Tag type);			//�����蔻��̃^�O��ݒ�

private:

	bool IsTrigger;	//�g���K�[�^�C�v���ǂ����H
	Tag my_TagType;		//���g�^�O
	Tag col_TagType;	//�擾�^�O

	glm::ivec2 *Position;	//���W
	glm::ivec2 *Size;		//�T�C�Y
	glm::ivec2 *Vector;	//����
	bool isCol;				//�����������ǂ����H


};


#endif