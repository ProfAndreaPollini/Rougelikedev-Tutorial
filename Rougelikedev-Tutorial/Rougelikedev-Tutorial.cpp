// Rougelikedev-Tutorial.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//

#include "Game.h"






int main()
{
	Game::GetInstance().Init();
	Game::GetInstance().Run();	
}
