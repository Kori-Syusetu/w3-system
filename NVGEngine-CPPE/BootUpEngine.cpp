#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include <string>
#include "../../../../SDL2-2.0.12/SDL2-2.0.12/include/SDL.h"

int main(int argc,char *argv[]) {
	LPCWSTR constitle;
	constitle = (TEXT("Wild Wolf War System"));
	SetConsoleTitleW(constitle);
	//atexit();
	std::cout << "��� Wild Wolf War System���N�����Ă��܂��c\n";
	SDL_Window* window;
	std::cout << "��� SDL�����������Ă��܂��c\n";
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_GAMECONTROLLER | SDL_INIT_TIMER) != 0) {
		std::cerr << "�v���I�� SDL�̏������Ɏ��s���܂����B\n�v���I�F�A�v���P�[�V�������ُ�I�����܂����B[�����R�[�h�FSINIT_ERROR]\n";
		SDL_Quit();
		exit(1);
	}
	std::cout << "��� OpenGL�𗘗p����SDL�E�C���h�E�̍쐬�����݂Ă��܂��B\n";
	window = SDL_CreateWindow(
		"Novels 'G' Engine",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		1280,
		720,
		SDL_WINDOW_OPENGL
		);
	if (window == NULL) {
		//Failed
		std::cerr << "�v���I�� OpenGL�𗘗p����SDL�E�C���h�E�̍쐬�Ɏ��s���܂���\n�v���I�F�A�v���P�[�V�������ُ�I�����܂����B[�����R�[�h�FSINIT_WINER]\n";
		SDL_Quit();
		exit(1);
	}
	else {
		SDL_GLContext glcontex = SDL_GL_CreateContext(window);
		std::cout << "��� �������܂���\n��� ���C�����[�v���J�n���܂����B\n";
	}
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	boolean quitflg = false;
	int color = 0;
	Uint32 start = 0, stop = 0, fpsstorecnt = 0, loopcnt = 0, loopcntf2s = 0, loopcntf2ssrc = 0;
	SDL_SetWindowTitle(window, u8"���̐��E�̗���IF�͑��݂���");
	Uint32 start2 = 0, stop2 = 0, fps = 0, fpslpc = 0;
	start2 = SDL_GetTicks();
	while (!quitflg)
	{
		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				quitflg = true;
				break;
			}
		}

		color = (color + 2) & 0xff;
		SDL_SetRenderDrawColor(renderer, color, color, color, 255);
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);
		loopcnt++;
		loopcntf2ssrc++;
		if (loopcntf2ssrc >= 60) {
			loopcntf2ssrc = 0;
			loopcntf2s++;
			std::string maintitles = u8"���̐��E�̗���IF�͑��݂��� | ";
			maintitles += std::to_string(loopcnt);
			maintitles += u8" Frames | ";
			maintitles += std::to_string(loopcntf2s);
			maintitles += u8" Second";
			maintitles += std::to_string(fps);
			maintitles += u8" FPS";
			const char* maintitle = const_cast<char*>(maintitles.c_str());
			SDL_SetWindowTitle(window, maintitle);
		}
		else {
			std::string maintitles = u8"���̐��E�̗���IF�͑��݂��� | ";
			maintitles += std::to_string(loopcnt);
			maintitles += u8" Frames | ";
			maintitles += std::to_string(loopcntf2s);
			maintitles += u8" Second | ";
			maintitles += std::to_string(fps);
			maintitles += u8" FPS";
			const char* maintitle = const_cast<char*>(maintitles.c_str());
			SDL_SetWindowTitle(window, maintitle);
		}
		//FPS �������j�b�g
		fpsstorecnt++;
		if (fpsstorecnt >= 4) {
			fpsstorecnt = 1;
		}
		stop = SDL_GetTicks();
		stop2 = SDL_GetTicks();
		if ((stop - start < 16) and ((fpsstorecnt == 1) or (fpsstorecnt == 3))) {
			SDL_Delay(17 - (stop - start));
		}
		else if ((stop - start < 16) and (fpsstorecnt == 2)) {
			SDL_Delay(16 - (stop - start));
		}
		if (1000 <= (stop2 - start2)) {
			fps = (fpslpc*((stop2 - start2)/1000));
			fpslpc = 0;
			start2 = SDL_GetTicks();
		}
		fpslpc++;
		start = SDL_GetTicks();
	}
	SDL_DestroyWindow(window);
	SDL_Quit();
	std::cout << "��� �Q�[�����I�����܂����B\n\n���̃��O�R���\�[���͎����I�ɕ����܂����A\n�����Ȃ��ꍇ�͂��̃��O�R���\�[�����I�������邱�Ƃ��ł��܂�\n\n\a";
	return(0);
}
