// WINAPI4.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "WINAPI4.h"
#include "resource.h"
#include <vector>

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: Place code here.

	// Initialize global strings
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_WINAPI4, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINAPI4));

	MSG msg;

	// Main message loop:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINAPI4));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WINAPI4);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // Store instance handle in our global variable

	HWND hWnd = CreateWindowW(szWindowClass, szTitle, NULL,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
using namespace std;

HPEN FonP;
HBRUSH Brush[3];
int radius[3];
int wide[3] = { 3,3,3 };
int low = 50, high = 150;
vector <int> vec;
HBRUSH Brushs1 = CreateSolidBrush(RGB(255, 0, 0));
HBRUSH Brushs2 = CreateSolidBrush(RGB(0, 255, 0));
HBRUSH Brushs3 = CreateSolidBrush(RGB(0, 0, 255));

int min = 50, max = 200;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case ID_CIRCLE1_START:
			if (find(vec.begin(), vec.end(), 0) == vec.end()) vec.push_back(0);
			break;
		case ID_CIRCLE2_START:
			if (find(vec.begin(), vec.end(), 1) == vec.end()) vec.push_back(1);
			break;
		case ID_CIRCLE3_START:
			if (find(vec.begin(), vec.end(), 2) == vec.end()) vec.push_back(2);
			break;
		case ID_CIRCLE1_STOP:
			for (int i = 0; i < vec.size(); i++) if (vec[i] == 0) vec.erase(vec.begin() + i);
			break;
		case ID_CIRCLE2_STOP:
			for (int i = 0; i < vec.size(); i++) if (vec[i] == 1) vec.erase(vec.begin() + i);
			break;
		case ID_CIRCLE3_STOP:
			for (int i = 0; i < vec.size(); i++) if (vec[i] == 2) vec.erase(vec.begin() + i);
			break;
		case IDM_SetColor: 
			DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd,About);
			break;
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		SelectObject(hdc, Brushs1);
		SelectObject(hdc, CreatePen(PS_SOLID, wide[0], RGB(0, 0, 0)));
		Ellipse(hdc, 200 - radius[0], 300 - radius[0], 200 + radius[0], 300 + radius[0]);
		SelectObject(hdc, Brushs2);
		SelectObject(hdc, CreatePen(PS_SOLID, wide[1], RGB(0, 0, 0)));
		Ellipse(hdc, 550 - radius[1], 300 - radius[1], 550 + radius[1], 300 + radius[1]);
		SelectObject(hdc, Brushs3);
		SelectObject(hdc, CreatePen(PS_SOLID, wide[2], RGB(0, 0, 0)));
		Ellipse(hdc, 900 - radius[2], 300 - radius[2], 900 + radius[2], 300 + radius[2]);
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_CREATE: {
		SetTimer(hWnd, 55, 20, NULL);
		for (int i = 0; i < 3; i++)
			radius[i] = 150;
		
		
		Brush[0] = CreateSolidBrush(RGB(150, 20, 20));
		Brush[1] = CreateSolidBrush(RGB(20, 150, 20));
		Brush[2] = CreateSolidBrush(RGB(20, 20, 150));

		break;
	}
	case WM_TIMER: {
		static int x = 3;
		for (auto i : vec) {
			if (radius[i] >= max) {
				x = -3;
			}
			if (radius[i] <= min) {
				x = 3;
			}
			radius[i] += x;
		}
		InvalidateRect(hWnd, NULL, TRUE);
		break;
	}

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		switch (LOWORD(wParam)) {
		case IDC_FR:
			Brush[0] = CreateSolidBrush(RGB(255, 0, 0));
			break;
		case IDC_FG:
			Brush[0] = CreateSolidBrush(RGB(255, 0, 0));
			break;
		case IDC_FB:
			Brush[0] = CreateSolidBrush(RGB(255, 0, 0));
			break;
		case IDC_SR:
			Brush[1] = CreateSolidBrush(RGB(0, 255, 0));
			break;
		case IDC_SG:
			Brush[1] = CreateSolidBrush(RGB(0, 255, 0));
			break;
		case IDC_SB:
			Brush[1] = CreateSolidBrush(RGB(0, 255, 0));
			break;
		case IDC_TR:
			Brush[2] = CreateSolidBrush(RGB(0, 0, 255));
			break;
		case IDC_TG:
			Brush[2] = CreateSolidBrush(RGB(0, 0, 255));
			break;
		case IDC_TB:
			Brush[2] = CreateSolidBrush(RGB(0, 0, 255));
			break;
		case IDC_Fs1:
			wide[0] = 1;
			break;
		case IDC_Fs2:
			wide[0] = 3;
			break;
		case IDC_Fs3:
			wide[0] = 5;
			break;
		case IDC_Ss1:
			wide[1] = 1;
			break;
		case IDC_Ss2:
			wide[1] = 3;
			break;
		case IDC_Ss3:
			wide[1] = 5;
			break;
		case IDC_Ts1:
			wide[2] = 1;
			break;
		case IDC_Ts2:
			wide[2] = 3;
			break;
		case IDC_Ts3:
			wide[2] = 5;
			break;
		}
		break;
	
	}
	return (INT_PTR)FALSE;
}