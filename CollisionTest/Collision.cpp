#include "Collision.hpp"
#include "Entry.hpp"
//�R���X�g���N�^
Box_Collision::Box_Collision()
{
	col_TagType = Tag::Invalid;	//�擾�@�^�O
	my_TagType = Tag::Invalid;	//���g�@�^�O

	IsTrigger = false;		//�g���K�[�^�C�v
	isCol = false;			//�����������ǂ����H
}
/*
//��`���m�̌�������
void Box_Collision::Intersect( Box_Collision &a)
{
	if ((a.getPosition().x + a.getSize().x > Position->x && Position->x + Size->x > a.getPosition().x)
		&& (a.getPosition().y + a.getSize().y > Position->y && Position->y + Size->y > a.getPosition().y))
	{
		isCol = true;
		col_TagType = a.getMyTag();	//�^�O���擾
		a.setColTag(getMyTag());	//�^�O��ݒ�
		
		if (IsTrigger == false) 
		{

			//�߂荞�ݗʂ��C��
			if (*Vector == VECTOR_RIGHT)
			{
				Position->x = a.getPosition().x - a.getSize().x;
			}
			else if (*Vector == VECTOR_LEFT)
			{
				Position->x = a.getPosition().x + a.getSize().x;
			}
			else if (*Vector == VECTOR_UP)
			{
				Position->y = a.getPosition().y + a.getSize().y;
			}
			else if (*Vector == VECTOR_DOWN)
			{
				Position->y = a.getPosition().y - a.getSize().y;
			}
			else if (*Vector == VECTOR_NONE)
			{
				//�x�N�g�����ݒ肳��Ă��Ȃ��Ƃ�
	
				//�߂荞�ݗʂ��C��
				if (a.getVector() == VECTOR_RIGHT)
				{
					Position->x = a.getPosition().x + a.getSize().x;
				}
				else if (a.getVector() == VECTOR_LEFT)
				{
					Position->x = a.getPosition().x - a.getSize().x;
				}
				else if (a.getVector() == VECTOR_UP)
				{
					Position->y = a.getPosition().y - a.getSize().y;
				}
				else if (a.getVector() == VECTOR_DOWN)
				{
					Position->y = a.getPosition().y + a.getSize().y;
				}
			}
		}	
	}
	else
	{
		//�������Ă��Ȃ�
		isCol = false;
		col_TagType = Tag::Invalid;
		a.setColTag(Tag::Invalid);	
	}
}
*/
// #################################### �擾�@�֌W

//�g���K�[�^�C�v���擾
bool Box_Collision::getTrigger()
{
	return IsTrigger;
}


//���W���擾
glm::ivec2 Box_Collision::getPosition()
{
	return *Position;
}

//�T�C�Y���擾
glm::ivec2 Box_Collision::getSize()
{
	return *Size;
}

//�擾�����^�C�v���擾
Tag Box_Collision::getTag()
{
	return col_TagType;
}

//�������擾
glm::ivec2 Box_Collision::getVector()
{
	return *Vector;
}

//�^�C�v���擾
Tag Box_Collision::getMyTag()
{
	return my_TagType;
}

//�����������ǂ����H
bool Box_Collision::getCol()
{
	return isCol;
}

// #################################### �ݒ�@�֌W

//�g���K�[�^�C�v��ݒ�
void Box_Collision::setTrigger(bool tri)
{
	IsTrigger = tri;
}

//���W��ݒ�
void Box_Collision::setPosition(glm::ivec2 *pos)
{
	Position = pos;
}

// �T�C�Y��ݒ�
void Box_Collision::setSize(glm::ivec2 *size)
{
	Size = size;
}

//�I�u�W�F�N�g�^�C�v��ݒ�
void Box_Collision::setTag(Tag type)
{	
	my_TagType = type;
}

//�I�u�W�F�N�g�^�C�v��ݒ�
void Box_Collision::setVector(glm::ivec2 *vec)
{
	Vector = vec;
}

//�����蔻��̃^�O��ݒ�
void Box_Collision::setColTag(Tag type)
{
	col_TagType = type;
}

//�f�X�g���N�^
Box_Collision::~Box_Collision()
{

}








/*
//��`���m�̌�������
void Box_Collision::Intersect(Box_Collision& a)
{
	if ((a.getPosition().x + a.getSize().x > Position->x && Position->x + Size->x > a.getPosition().x)
		&& (a.getPosition().y + a.getSize().y > Position->y && Position->y + Size->y > a.getPosition().y))
	{
		isCol = true;
		col_TagType = a.getMyTag();	//�^�O���擾
		a.setColTag(getMyTag());	//�^�O��ݒ�

		if (IsTrigger == false)
		{

			//�߂荞�ݗʂ��C��
			if (*Vector == VECTOR_RIGHT)
			{
				Position->x = a.getPosition().x - a.getSize().x;
			}
			else if (*Vector == VECTOR_LEFT)
			{
				Position->x = a.getPosition().x + a.getSize().x;
			}
			else if (*Vector == VECTOR_UP)
			{
				Position->y = a.getPosition().y + a.getSize().y;
			}
			else if (*Vector == VECTOR_DOWN)
			{
				Position->y = a.getPosition().y - a.getSize().y;
			}
			else if (*Vector == VECTOR_NONE)
			{
				//�x�N�g�����ݒ肳��Ă��Ȃ��Ƃ�

				//�߂荞�ݗʂ��C��
				if (a.getVector() == VECTOR_RIGHT)
				{
					Position->x = a.getPosition().x + a.getSize().x;
				}
				else if (a.getVector() == VECTOR_LEFT)
				{
					Position->x = a.getPosition().x - a.getSize().x;
				}
				else if (a.getVector() == VECTOR_UP)
				{
					Position->y = a.getPosition().y - a.getSize().y;
				}
				else if (a.getVector() == VECTOR_DOWN)
				{
					Position->y = a.getPosition().y + a.getSize().y;
				}
			}
		}
	}
	else
	{
		//�������Ă��Ȃ�
		isCol = false;
		col_TagType = Tag::Invalid;
		a.setColTag(Tag::Invalid);
	}
}
*/