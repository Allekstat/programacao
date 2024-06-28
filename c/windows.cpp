
//L ou LP antes das coisas indica que é um pointer
//W antes das coisas indica que é unicode
//HWND hWnd <- isso é tipo o id da janela
//BOOL MoveWindow(HWND hWnd, int X, int Y, int nWidth, int nHeight, BOOL bRepaint); <- isso muda a posição da janela
//int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow); <- isso é o ponto de entrada
//hInstance <- id da instância
//hPrevInstance <- algo descontinuado do windows 16 bits, sempre será 0
//pCmdLine <- argumentos de linha de comando
//nCmdShow <- indica se a janela principal está minimizada, maximizada, ou normal

//#define WIN32_LEAN_AND_MEAN <- fala pro windows não incluir funções do windows 16 bits
#include <windows.h>
#include <windowsx.h>
//#include <iostream>

/*int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {
	MessageBox(NULL, "Oi Windows!", "Mensagem", 0);
	return 0;
}*/

LRESULT CALLBACK WinProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	//char a[255];
	//sprintf(a, "lpCmdLine = %s\nalek", lpCmdLine);
	//MessageBox(NULL, "", "", MB_YESNO | MB_DEFBUTTON2 | MB_ICONQUESTION);
	
	WNDCLASS wndClass;
	HWND hwnd;
	MSG msg;

	wndClass.lpfnWndProc = WinProc;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hInstance = hInstance;
	wndClass.lpszMenuName = NULL;
	wndClass.lpszClassName = "MinhaJanela";
	
	wndClass.style = NULL;
//	wndClass.style = CS_HREDRAW | CS_VREDRAW;

//	LPCSTR lpFileNameIcone = "";
// nao existe	IDI_ICON MeuIcone = LoadIconFromFile();

	LPCSTR lpFileNameCursor = "C:/Users/usuario/Cursores/numix Cursors by abdillahindo & alexgal23/numix link select cursor.cur";
	HCURSOR MeuCursor = LoadCursorFromFile(lpFileNameCursor);

//	wndClass.hIcon = NULL;
	wndClass.hIcon = LoadIcon (NULL, IDI_WINLOGO);
//	wndClass.hIcon = MeuIcone;

//	wndClass.hCursor = NULL;
//	wndClass.hCursor = LoadCursor (NULL, IDC_ARROW);
//	wndClass.hCursor = LoadCursorFromFile(lpFileName);
	wndClass.hCursor = MeuCursor;
	
	
//	wndClass.hbrBackground = (HBRUSH) WHITE_BRUSH;//(HBRUSH) GetStockObject (WHITE_BRUSH); <- argumento -mwindows do compilador resolveu uum erro daqui
//	wndClass.hbrBackground = (HBRUSH) GetStockObject (WHITE_BRUSH);
	wndClass.hbrBackground = NULL;//HBRUSH (COLOR_APPWORKSPACE);//(HBRUSH) COLOR_BACKGROUND + 1;// funciona sem o argumento -mwindows
	
	if (!RegisterClass (&wndClass)) {
		MessageBox (NULL, "Erro no registro da Janela!", "Aplicativo", MB_ICONERROR);
	}
	
//	hwnd = CreateWindow ("MinhaJanela", "Aplicativo", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL,   NULL,    hInstance, NULL);
//            modo janela    nome da class, título,      estilo,              posição x ini,  posição y ini, largura ini,   altura ini,    id pai, id menu, id app,    params

	int TamanhoTelaHorizontal = GetSystemMetrics(SM_CXSCREEN);
	int TamanhoTelaVertical = GetSystemMetrics(SM_CYSCREEN);
	
	#define myFULLSCREENX TamanhoTelaHorizontal
	#define myFULLSCREENY TamanhoTelaVertical
	
/**
	TamanhoTelaHorizontal = 1600 / 2;
	TamanhoTelaVertical = 900 / 2;
/**/
	int Escala = 40;

	RECT Canvas = {0, 0, 16 * Escala, 9 * Escala};

//	ajusta o tamanho da janela com a barra de menu
//	AdjustWindowRectEx(&Canvas, GetWindowStyle(hwnd), GetMenu(hwnd) != NULL, GetWindowExStyle(hwnd));
	AdjustWindowRect(&Canvas, GetWindowStyle(hwnd), GetMenu(hwnd) != NULL);

	int CanvasWidth = Canvas.right - Canvas.left;
	int CanvasHeight = Canvas.bottom - Canvas.top;

	int PosicaoX = GetSystemMetrics(SM_CXSCREEN) / 2 - CanvasWidth / 2;
	int PosicaoY = GetSystemMetrics(SM_CYSCREEN) / 2 - CanvasHeight / 2;
	
	/**/
	
	int ModoDaJanela = WS_POPUP;
/**
	WS_SIZEBOX | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SYSMENU;
	OVERLAPPEDWINDOW <- janela normal
	OVERLAPPED <- sem os botões minimizar, maximizar nem fechar
	POPUP <- modo sem borda *tela cheia*
	MINIMIZEBOX <- mostra o botão pra minimizar
	MAXIMIZEBOX <- mostra o botão pra mazimizar
	SYSMENU <- mostra o botão pra fechar
/**/
	
	
	
//	hwnd = CreateWindow ("MinhaJanela", "Aplicativo", ModoDaJanela, CW_USEDEFAULT, CW_USEDEFAULT, TamanhoTelaHorizontal, TamanhoTelaVertical, NULL,   NULL,    hInstance, NULL);
//         modo tela cheia

	hwnd = CreateWindowEx (NULL, "MinhaJanela", "Aplicativo", ModoDaJanela,/**/ CW_USEDEFAULT/**/,/**/ CW_USEDEFAULT/**/, TamanhoTelaHorizontal, TamanhoTelaVertical, NULL,   NULL,    hInstance, NULL);
//                   estilos extras

	MoveWindow(hwnd, Canvas.left, Canvas.top, myFULLSCREENX, myFULLSCREENY, TRUE);

	ShowWindow(hwnd, nCmdShow);// mostra a janela
	UpdateWindow(hwnd);// força o primeiro WM_PAINT da janela
	
	while (GetMessage (&msg, NULL, 0, 0)) {
		TranslateMessage (&msg);
		DispatchMessage (&msg);
	}
	
	//return 0;
	return (int) msg.wParam;
}
	
LRESULT CALLBACK WinProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	HDC hdc;
	PAINTSTRUCT ps;// isso é a área sobreposta por outra janela para ser repintada
	RECT rect;
	switch(message) {
// mensagens possíveis       WM_ACTIVATE, WM_CLOSE,  WM_CREATE, WM_DESTROY,        WM_MOVE,    WM_MOUSEMOVE,   WM_KEYUP,         WM_KEYDOWN,        WM_PAINT,           WM_SIZE
// acontece quando a janela: ganha foco,  é fechada, é criada,  vai ser destruída, for movida, mouse se mexer, soltar uma tecla, apertar uma tecla, precisa redesenhar, mudar de tamanho
		case WM_PAINT:
			return 0;
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
			
	}
	return DefWindowProc (hwnd, message, wParam, lParam);
}
/**
// DC <- 'device control'?
// HDC hdc = GetDC(hwnd); contexto do dispositivo gráfico
hdc = BeginPaint (hwnd, &ps);
// RECT rect = {0, 0, 100, 25};
GetClientRect (hwnd, &rect);
// TextOut(hdc, 50, 40, 100, 25);
DrawText (hdc, "Minha Janela!", -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);// -1 é o tamanho do texto, -1 significa automátivo
// ReleaseDC(hwnd, hdc);
EndPaint (hwnd, &ps);
/**/
/**

int Escala = 40;

RECT Canvas = {0, 0, 16 * Escala, 9 * Escala};

// ajusta o tamanho da janela com a barra de menu
AdjustWindowRectEx(&Canvas, GetWindowStyle(hwnd), GetMenu(hwnd) != NULL, GetWindowExStyle(hwnd));

int CanvasWidth = Canvas.right - Canvas.left;
int CanvasHeight = Canvas.bottom - Canvas.top;

int PosicaoX = GetSystemMetrics(SM_CXSCREEN) / 2 - CanvasWidth / 2;
int PosicaoY = GetSystemMetrics(SM_CYSCREEN) / 2 - CanvasHeight / 2;

MoveWindow(hwnd, PosicaoX, PosicaoY, CanvasWidth, CanvasHeight, TRUE);

/**/
