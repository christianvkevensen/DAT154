// WinCarApp.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "WinCarApp.h"

#define MAX_LOADSTRING 100

class Car
{
public:
    int n;
    int x, y;
    Car(int _n, int _x, int _y) : n(_n), x(_x), y(_y)
    {
    }
    void Draw(HDC hdc)
    {
        Ellipse(hdc, x, y, x + 10, y + 10);
        Ellipse(hdc, x+20, y, x + 30, y + 10);
        Rectangle(hdc, x, y - 10, x + 30,y);

        //cout << n << ": ()==()" << endl;
    }
};
class CarList
{
public:
    Car* t[1000];
    int m_i;
    CarList()
    {
        m_i = 0;
    }
    void push(Car* pCar)
    {
        t[m_i++] = pCar;
    }
    void Draw(HDC hdc)
    {
        for (int k = 0; k < m_i; k++)
            t[k]->Draw(hdc); //  same as (*t[m_i]).Draw();
    }
    void Move(int x) {

    }
    void Clear()
    {
        for (int k = 0; k < m_i; k++)
            delete t[k];
    }
};
// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
static CarList carlist;


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
    LoadStringW(hInstance, IDC_WINCARAPP, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINCARAPP));

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

    return (int) msg.wParam;
}




ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINCARAPP));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINCARAPP);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}


BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static int n = 1;
    static int x = 100, y = 100;
    switch (message)
    {
    case WM_LBUTTONDOWN:
    {
        carlist.push(new Car(n++, x, y));
        x = x + 100;
        InvalidateRect(hWnd, 0, true);
        break;
    }
    case WM_RBUTTONDOWN:
    {
        carlist.Clear();
        x = 100;
        InvalidateRect(hWnd, 0, true);
        break;
    }
    case WM_CREATE:
        /*carlist.push(new Car(1, 100, 100));
        carlist.push(new Car(2, 200, 100));
        carlist.push(new Car(3, 300, 100));
        carlist.push(new Car(4, 400, 100));
        carlist.push(new Car(5, 400, 100));*/

        break;



    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
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
            // TODO: Add any drawing code that uses hdc here...
            HBRUSH hb = CreateSolidBrush(RGB(255, 0, 0));
            HGDIOBJ hOrg = SelectObject(hdc, hb);


            carlist.Draw(hdc);
            EndPaint(hWnd, &ps);

            SelectObject(hdc, hOrg);
            DeleteObject(hb);
        }
        break;
    case WM_DESTROY:
        carlist.Clear();
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
        break;
    }
    return (INT_PTR)FALSE;
}
