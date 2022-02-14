// Oblig1.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "Oblig1.h"

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
        /*Ellipse(hdc, x, y, x + 10, y + 10);
        Ellipse(hdc, x + 20, y, x + 30, y + 10);*/
        Rectangle(hdc, x, y -10, x + 10, y);
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
    ~CarList()
    {
        Clear();
    }
    void push(Car* pCar)
    {
        t[m_i++] = pCar;
    }
    void Draw(HDC hdc)
    {
        for (int k = 0; k < m_i; k++)
            t[k]->Draw(hdc);

    }
    void MoveW(int dx, int counter)
    {
        int grense = 400;
        for (int k = 0; k < m_i; k++)
                
        
            if (k == 0) {
                if (counter  == 2 && (t[k]->x)-10 == 480) {
                    
                }
                else {
                    t[k]->x += dx;
                }
               
            }
            else if ((k > 0 ) && (t[k-1]->x) - (t[k]->x) <= 10) {

            }
            else {
                if (counter == 2 && (t[k]->x) - 10 == 480) {

                }
                else {
                    t[k]->x += dx;
                }
            }
    }
    void MoveN(int dy)
    {
        for (int k = 0; k < m_i; k++)
            t[k]->y += dy;
    }
    void Clear()
    {
        for (int k = 0; k < m_i; k++)
            delete t[k];
        m_i = 0;
    }
};

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
int counter = 0;
int n = 0;
static CarList carlistN, carlistW;



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
    LoadStringW(hInstance, IDC_OBLIG1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_OBLIG1));

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



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_OBLIG1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_OBLIG1);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

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
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static int n = 1;
    static int wx = 10, wy = 250;
    static int nx = 550, ny = 0;
    static int wStopp = 400;
    switch (message)
    {

    case WM_CREATE:
        SetTimer(hWnd, 0, 100, (TIMERPROC)NULL);
        SetTimer(hWnd, 1, 3005, (TIMERPROC)NULL);

        break;

    case WM_LBUTTONDOWN:
    {
        carlistN.push(new Car(n++, nx, ny));
        carlistW.push(new Car(n++, wx, wy));
        
        InvalidateRect(hWnd, 0, true);
        break;
    }
    case WM_RBUTTONDOWN:
    {
        RECT screen;
        GetClientRect(hWnd, &screen);

        carlistN.push(new Car(n++, screen.right/2, screen.top));
        InvalidateRect(hWnd, 0, true);

        break;
    }
    case WM_TIMER:
        switch (wParam)
        {    
        case 0:
            carlistW.MoveW(10,counter);
            carlistN.MoveN(10);
            InvalidateRect(hWnd, 0, true);
            break;

        case 1:
            counter = (counter + 1) % 4;
            InvalidateRect(hWnd, 0, true);

            break;

        default:
            break;
        }
        
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

            HBRUSH blackBrush = CreateSolidBrush(RGB(0, 0, 0));
            HBRUSH grayBrush = CreateSolidBrush(RGB(58, 58, 58));
            HBRUSH redBrush = CreateSolidBrush(RGB(255, 0, 0));
            HBRUSH yellowBrush = CreateSolidBrush(RGB(255, 255, 0));
            HBRUSH greenBrush = CreateSolidBrush(RGB(0, 128, 0));

            RECT screen;
            GetClientRect(hWnd, &screen);
            HBRUSH hb = CreateSolidBrush(RGB(255, 0, 0));
            HGDIOBJ hOrg = SelectObject(hdc, hb);
            RECT vei1 = { 0, screen.bottom/3, screen.right, screen.bottom/2 };
            FillRect(hdc, &vei1, blackBrush);
            RECT vei2 = {500, screen.top / 2, 600, screen.bottom};
            FillRect(hdc, &vei2, blackBrush);
            RECT rect = { vei2.right + 10, screen.top, vei2.right+100, vei1.top-10 };
            RECT rect2 = { vei2.left - 10, vei1.bottom+10, vei2.left - 100, vei1.bottom + 200 };
            carlistW.Draw(hdc);
            carlistN.Draw(hdc);

            switch (counter)
            {
            case 0:
            {
                FillRect(hdc, &rect, blackBrush);
                FillRect(hdc, &rect2, blackBrush);

                HGDIOBJ hOrg = SelectObject(hdc, redBrush);
                Ellipse(hdc, rect.left, rect.top, rect.right, rect.bottom/3);

                hOrg = SelectObject(hdc, grayBrush);
                Ellipse(hdc, rect.left, rect.bottom/3, rect.right, rect.bottom * 0.67);
                Ellipse(hdc, rect.left, rect.bottom*0.67, rect.right, rect.bottom);

                Ellipse(hdc, rect2.left, rect2.top, rect2.right, rect2.bottom-125);
                Ellipse(hdc, rect2.left, rect2.bottom-125, rect2.right, rect2.bottom - 65);
                hOrg = SelectObject(hdc, greenBrush);
                Ellipse(hdc, rect2.left, rect2.bottom - 65, rect2.right, rect2.bottom);

                break;
            }
            case 1:
            {
                FillRect(hdc, &rect, blackBrush);
                FillRect(hdc, &rect2, blackBrush);

                HGDIOBJ hOrg = SelectObject(hdc, redBrush);
                Ellipse(hdc, rect.left, rect.top, rect.right, rect.bottom / 3);
                hOrg = SelectObject(hdc, yellowBrush);
                Ellipse(hdc, rect.left, rect.bottom / 3, rect.right, rect.bottom * 0.67);
                Ellipse(hdc, rect2.left, rect2.bottom - 125, rect2.right, rect2.bottom - 65);
                hOrg = SelectObject(hdc, grayBrush);
                Ellipse(hdc, rect.left, rect.bottom * 0.67, rect.right, rect.bottom);

                Ellipse(hdc, rect2.left, rect2.top, rect2.right, rect2.bottom - 125);
                Ellipse(hdc, rect2.left, rect2.bottom - 65, rect2.right, rect2.bottom);
                break;
            }
            case 2: 
            {
                FillRect(hdc, &rect, blackBrush);
                FillRect(hdc, &rect2, blackBrush);

                HGDIOBJ hOrg = SelectObject(hdc, grayBrush);
                Ellipse(hdc, rect.left, rect.top, rect.right, rect.bottom / 3);
                Ellipse(hdc, rect.left, rect.bottom / 3, rect.right, rect.bottom * 0.67);
                Ellipse(hdc, rect2.left, rect2.bottom - 125, rect2.right, rect2.bottom - 65);
                Ellipse(hdc, rect2.left, rect2.bottom - 65, rect2.right, rect2.bottom);
                hOrg = SelectObject(hdc, greenBrush);
                Ellipse(hdc, rect.left, rect.bottom * 0.67, rect.right, rect.bottom);

                hOrg = SelectObject(hdc, redBrush);
                Ellipse(hdc, rect2.left, rect2.top, rect2.right, rect2.bottom - 125);
                
                break;
            }
            case 3:
            {
                FillRect(hdc, &rect, blackBrush);
                FillRect(hdc, &rect2, blackBrush);

                HGDIOBJ hOrg = SelectObject(hdc, grayBrush);
                Ellipse(hdc, rect.left, rect.top, rect.right, rect.bottom / 3);
                Ellipse(hdc, rect.left, rect.bottom * 0.67, rect.right, rect.bottom);
                Ellipse(hdc, rect2.left, rect2.bottom - 65, rect2.right, rect2.bottom);

                hOrg = SelectObject(hdc, yellowBrush);
                Ellipse(hdc, rect.left, rect.bottom / 3, rect.right, rect.bottom * 0.67);
                Ellipse(hdc, rect2.left, rect2.bottom - 125, rect2.right, rect2.bottom - 65);

                hOrg = SelectObject(hdc, redBrush);

                Ellipse(hdc, rect2.left, rect2.top, rect2.right, rect2.bottom - 125);
                break;
            }
           
            default:
                break;
            }

            Sleep(2);

            DeleteObject(blackBrush);
            DeleteObject(grayBrush);
            DeleteObject(redBrush);
            DeleteObject(yellowBrush);
            DeleteObject(greenBrush);


            EndPaint(hWnd, &ps);

        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        KillTimer(hWnd, 0);
        KillTimer(hWnd, 1);
       
        carlistN.Clear();
        carlistW.Clear();

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
