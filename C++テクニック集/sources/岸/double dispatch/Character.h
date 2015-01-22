/************************************************

�Z�p��		 : Double Dispatch

�L�q��		 : �݁@���j
�L�q�ҍX�V�� : 2015/01/22

�p�r		 : ����Ɏ����̃N���X����n��

=================================================

�ҏW��		 :
�ҏW�ҍX�V�� : 2015/����/�~�~

************************************************/
#pragma once
#include <iostream>
#include <string>


// �\�ߊ��N���X�͔h���N���X��m���Ă���K�v������
class Hara;
class Bassy;
class Kaku;


////////////////
// ���N���X //
////////////////
class IC_Character{
public:
	IC_Character( std::string name ){ this->name = name; }

	// �����̏���n�����\�b�h
	virtual void Dispatch( IC_Character* pChara ) = 0;

	virtual void Action( Hara* pHara ) = 0;		// �������ɑ΂���A�N�V����
	virtual void Action( Bassy* pBassy ) = 0;	// �΂����[�ɑ΂���A�N�V����
	virtual void Action( Kaku* pKaku ) = 0;		// �S�~�p�ɑ΂���A�N�V����

	std::string name;
};



class Hara : public IC_Character{
public:
	Hara() : IC_Character("�������"){}		// �R���X�g���N�^


	// ����Ɏ����̃N���X����n��
	void Dispatch( IC_Character* pChara ) override{ 
		std::cout << name << "�u" << pChara->name << "�͉����ǂ��v���Ă�񂾂�H�v" << std::endl;
		pChara->Action( this ); 
	}


protected:
	// �N���X���Ƃɂ����锽��
	void Action( Hara* pHara ){ std::cout << name << "�i�����j" << std::endl; }
	void Action( Bassy* pBassy ){ std::cout << name << "�i�΂����[�����j" << std::endl; }
	void Action( Kaku* pKaku ){ std::cout << name << "�i�p�L���C�j" << std::endl; }

};



class Bassy : public IC_Character{
public:
	Bassy() : IC_Character("�΂����["){}	// �R���X�g���N�^


	// ����Ɏ����̃N���X����n��
	void Dispatch(IC_Character* pChara) override{ 
		std::cout << name << "�u" << pChara->name << "�͉����ǂ��v���Ă�񂾂�H�v" << std::endl;
		pChara->Action(this); 
	}


protected:
	// �N���X���Ƃɂ����锽��
	void Action( Hara* pHara ){ std::cout << name << "�i�������ł��ԁj" << std::endl; }
	void Action( Bassy* pBassy ){ std::cout << name << "�i�������j" << std::endl; }
	void Action( Kaku* pKaku ){ std::cout << name << "�i�p�߂���V�R�j" << std::endl; }

};



class Kaku : public IC_Character{
public:
	Kaku() : IC_Character("�p"){}		// �R���X�g���N�^


	// ����Ɏ����̃N���X����n��
	void Dispatch(IC_Character* pChara) override{ 
		std::cout << name << "�u" << pChara->name << "�͖l���ǂ��v���Ă�񂾂�H�v" << std::endl;
		pChara->Action(this); 
	}

protected:
	// �N���X���Ƃɂ����锽��
	void Action( Hara* pHara ){ std::cout << name << "�i������񓪂��������j" << std::endl; }
	void Action( Bassy* pBassy ){ std::cout << name << "�i�΂����[�����������j" << std::endl; }
	void Action( Kaku* pKaku ){ std::cout << name << "�i�l���j" << std::endl; }

};