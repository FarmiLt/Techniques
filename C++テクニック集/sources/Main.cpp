#include <iostream>


void main(){

#ifdef _DEBUG
	// メモリリークチェッカー
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

}