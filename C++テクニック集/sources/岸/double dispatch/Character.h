/************************************************

技術名		 : Double Dispatch

記述者		 : 岸　将史
記述者更新日 : 2015/01/22

用途		 : 相手に自分のクラス情報を渡す

=================================================

編集者		 :
編集者更新日 : 2015/○○/××

************************************************/
#pragma once
#include <iostream>
#include <string>


// 予め基底クラスは派生クラスを知っている必要がある
class Hara;
class Bassy;
class Kaku;


////////////////
// 基底クラス //
////////////////
class IC_Character{
public:
	IC_Character( std::string name ){ this->name = name; }

	// 自分の情報を渡すメソッド
	virtual void Dispatch( IC_Character* pChara ) = 0;

	virtual void Action( Hara* pHara ) = 0;		// 原ちゃんに対するアクション
	virtual void Action( Bassy* pBassy ) = 0;	// ばっしーに対するアクション
	virtual void Action( Kaku* pKaku ) = 0;		// ゴミ角に対するアクション

	std::string name;
};



class Hara : public IC_Character{
public:
	Hara() : IC_Character("原ちゃん"){}		// コンストラクタ


	// 相手に自分のクラス情報を渡す
	void Dispatch( IC_Character* pChara ) override{ 
		std::cout << name << "「" << pChara->name << "は俺をどう思ってるんだろ？」" << std::endl;
		pChara->Action( this ); 
	}


protected:
	// クラスごとにおける反応
	void Action( Hara* pHara ){ std::cout << name << "（俺だ）" << std::endl; }
	void Action( Bassy* pBassy ){ std::cout << name << "（ばっしー汚い）" << std::endl; }
	void Action( Kaku* pKaku ){ std::cout << name << "（角キモイ）" << std::endl; }

};



class Bassy : public IC_Character{
public:
	Bassy() : IC_Character("ばっしー"){}	// コンストラクタ


	// 相手に自分のクラス情報を渡す
	void Dispatch(IC_Character* pChara) override{ 
		std::cout << name << "「" << pChara->name << "は俺をどう思ってるんだろ？」" << std::endl;
		pChara->Action(this); 
	}


protected:
	// クラスごとにおける反応
	void Action( Hara* pHara ){ std::cout << name << "（原ちゃんでっぶ）" << std::endl; }
	void Action( Bassy* pBassy ){ std::cout << name << "（俺じゃん）" << std::endl; }
	void Action( Kaku* pKaku ){ std::cout << name << "（角めちゃシコ）" << std::endl; }

};



class Kaku : public IC_Character{
public:
	Kaku() : IC_Character("角"){}		// コンストラクタ


	// 相手に自分のクラス情報を渡す
	void Dispatch(IC_Character* pChara) override{ 
		std::cout << name << "「" << pChara->name << "は僕をどう思ってるんだろ？」" << std::endl;
		pChara->Action(this); 
	}

protected:
	// クラスごとにおける反応
	void Action( Hara* pHara ){ std::cout << name << "（原ちゃん頭おかしい）" << std::endl; }
	void Action( Bassy* pBassy ){ std::cout << name << "（ばっしー頭おかしい）" << std::endl; }
	void Action( Kaku* pKaku ){ std::cout << name << "（僕だ）" << std::endl; }

};