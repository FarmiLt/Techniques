#include <iostream>


void main(){

#ifdef _DEBUG
	// ���������[�N�`�F�b�J�[
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

}