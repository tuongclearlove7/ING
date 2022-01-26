
/**
 *	Include Header
 */
#include "Window.h"



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	WndProc
 */
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{

	switch (msg)
	{
	case WM_CREATE:
	{
		return ::DefWindowProc(hwnd, msg, wparam, lparam);
		break;
	}

	case WM_DESTROY:
	{

		::PostQuitMessage(0);
		break;
	}
	case WM_SIZE:
	{
		return ::DefWindowProc(hwnd, msg, wparam, lparam);
		break;
	}
	case WM_MOUSEMOVE:
	{
		return ::DefWindowProc(hwnd, msg, wparam, lparam);
		break;
	}
	case WM_LBUTTONDOWN:
	{
		return ::DefWindowProc(hwnd, msg, wparam, lparam);
		break;
	}
	case WM_MBUTTONDOWN:
	{
		return ::DefWindowProc(hwnd, msg, wparam, lparam);
		break;
	}
	case WM_RBUTTONDOWN:
	{
		return ::DefWindowProc(hwnd, msg, wparam, lparam);
		break;
	}
	case WM_LBUTTONUP:
	{
		return ::DefWindowProc(hwnd, msg, wparam, lparam);
		break;
	}
	case WM_MBUTTONUP:
	{
		return ::DefWindowProc(hwnd, msg, wparam, lparam);
		break;
	}
	case WM_RBUTTONUP:
	{
		return ::DefWindowProc(hwnd, msg, wparam, lparam);
		break;
	}
	case WM_KEYDOWN:
	{
		return ::DefWindowProc(hwnd, msg, wparam, lparam);
		break;
	}
	case WM_KEYUP:
	{
		return ::DefWindowProc(hwnd, msg, wparam, lparam);
		break;
	}
	case WM_MOUSELEAVE:
	{
		return ::DefWindowProc(hwnd, msg, wparam, lparam);
		break;
	}

	default:
		return ::DefWindowProc(hwnd, msg, wparam, lparam);
	}

	return NULL;
}





namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	Window::Window() :
		isMain(false), handle(NULL)
	{

		WindowDesc desc;

		InitWithDesc(desc);

	}

	Window::Window(WindowDesc desc) :
		isMain(false), handle(NULL)
	{

		InitWithDesc(desc);

	}

	Window::~Window() 
	{



	}



	/**
	 *	InitWithDesc, Release Methods
	 */
	void Window::InitWithDesc(WindowDesc desc) {

		/* Create Class */
		WNDCLASSEX wc;
		wc.cbClsExtra = NULL;
		wc.cbSize = sizeof(WNDCLASSEX);
		wc.cbWndExtra = NULL;
		wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);
		wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
		wc.hInstance = NULL;
		wc.lpszClassName = L"INGWindowClass";
		wc.lpszMenuName = L"";
		wc.style = NULL;
		wc.lpfnWndProc = &WndProc;

		if (!::RegisterClassEx(&wc))
			return;

		handle = ::CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, L"INGWindowClass", desc.title,
			WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, desc.clientWidth, desc.clientHeight,
			NULL, NULL, NULL, this);

		WindowManager::GetInstance()->AddWindow(this);

	}

	void Window::Release() 
	{

		delete this;

	}

}