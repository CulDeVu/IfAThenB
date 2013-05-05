#include <windows.h>
#include "behavior.h"

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

/*  Make the class name into a global variable  */
char szClassName[ ] = "IFATHENB";

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE,
                     LPSTR,
                     int nCmdShow)
{
  HWND hwnd;               /* This is the handle for our window */
  WNDCLASSEX wincl;        /* Data structure for the windowclass */

  /* The Window structure */
  wincl.hInstance = hThisInstance;
  wincl.lpszClassName = szClassName;
  wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
  wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
  wincl.cbSize = sizeof (WNDCLASSEX);

  /* Use default icon and mouse-pointer */
  wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
  wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
  wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
  wincl.lpszMenuName = NULL;                 /* No menu */
  wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
  wincl.cbWndExtra = 0;                      /* structure or the window instance */
  /* Use Windows's default colour as the background of the window */
  wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

  /* Register the window class, and if it fails quit the program */
  if (!RegisterClassEx (&wincl))
      return 0;

  int width = windowWidth + GetSystemMetrics(SM_CXFIXEDFRAME) * 2;
  int height = windowHeight + GetSystemMetrics(SM_CYFIXEDFRAME) * 2 + GetSystemMetrics(SM_CYCAPTION);

  /* The class is registered, let's create the program*/
  hwnd = CreateWindowEx (
         0,                   /* Extended possibilites for variation */
         szClassName,         /* Classname */
         "IF, THEN",       /* Title Text */
         WS_CAPTION, /* default window */
         CW_USEDEFAULT,       /* Windows decides the position */
         CW_USEDEFAULT,       /* where the window ends up on the screen */
         width,                 /* The programs width */
         height,                 /* and height in pixels */
         HWND_DESKTOP,        /* The window is a child-window to desktop */
         NULL,                /* No menu */
         hThisInstance,       /* Program Instance handler */
         NULL                 /* No Window Creation data */
         );

  /* Make the window visible on the screen */
  ShowWindow (hwnd, SW_SHOW);

  /* Run the message loop. It will run until GetMessage() returns 0 */

  HDC hdc = GetDC(hwnd);

  hBufferDC = CreateCompatibleDC(hdc);
  hBufferBmp = CreateCompatibleBitmap(hdc, windowWidth, windowHeight);
  hOldBufferBmp = (HBITMAP)SelectObject(hBufferDC, hBufferBmp);

  DWORD lastTime = GetTickCount();

  NextLevel();

  while (!bGameOver)
  {
    MSG msg;
    while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
    {
      if (msg.message == WM_QUIT)
        bGameOver = true;
      TranslateMessage(&msg);
      DispatchMessage(&msg);
    }
    if (bGameOver)
      break;

    if (GetAsyncKeyState(VK_ESCAPE))
      break;

    updateGame();
    PaintGame(hBufferDC);

    BitBlt(hdc, 0, 0, windowWidth, windowHeight, hBufferDC, 0, 0, SRCCOPY);

    do
      Sleep(0);
    while (GetTickCount() - lastTime < 15);

    lastTime = GetTickCount();
  }

  SelectObject(hBufferDC, hOldBufferBmp);
  DeleteObject(hBufferBmp);
  DeleteObject(hBufferDC);

  ReleaseDC(hwnd, hdc);

  /* The program return-value is 0 - The value that PostQuitMessage() gave */
  return 0;
}


/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
