
#include "maps.h"
#include <math.h>
#include <vector>

const int tilesX = 25,
          tilesY = 15;

bool bGameOver = false;

const int windowWidth = tilesX * 32,
          windowHeight = tilesY * 32;

HDC hBufferDC;
HBITMAP hBufferBmp;
HBITMAP hOldBufferBmp;

int keys = 0;
bool dispText = false;
int deadCounter = 0;

POINT mainPos = { 1 * 32, 13 * 32 };
POINT mainDir = { 0, 0 };

std::vector<POINT> enemies;
std::vector<int> enemyDirs;

POINT appearBlockPos = { 0, 0 };
int appearBlockCounter = 800000;

void NextLevel()
{
  ++curLevel;
  mainPos.x = 1 * 32;
  mainPos.y = 13 * 32;
  dispText = false;
  keys = 0;
  deadCounter = 0;
  mainDir.x = mainDir.y = 0;

  const int* nextMap;
  if (curLevel == 0)
    nextMap = map0;
  else if (curLevel == 1)
    nextMap = map1;
  else if (curLevel == 2)
    nextMap = map2;
  else if (curLevel == 3)
    nextMap = map3;
  else if (curLevel == 4)
    nextMap = map4;
  else if (curLevel == 5)
    nextMap = map5;
  else if (curLevel == 6)
    nextMap = map6;
  else if (curLevel == 7)
    nextMap = map7;
  else if (curLevel == 8)
    nextMap = map8;
  else if (curLevel == 9)
    nextMap = map9;
  else if (curLevel == 10)
    nextMap = map10;
  else if (curLevel == 11)
    nextMap = map11;
  else if (curLevel == 12)
    nextMap = map12;
  else if (curLevel == 13)
    nextMap = map13;
  else if (curLevel == 14)
    nextMap = map14;
  else if (curLevel == 15)
    nextMap = map14;
  else
  {
    nextMap = map0;
    bGameOver = true;
  }
  memcpy(curMap, nextMap, 25*15*sizeof(int));

  enemies.clear();
  enemyDirs.clear();
  for (int i = 0; i < tilesX * tilesY; ++i)
  {
    if (curMap[i] == 2)
    {
      POINT p = { i % tilesX * 32, i / tilesX * 32 };
      enemies.push_back(p);
      enemyDirs.push_back((rand() % 2) ? -1 : 1);
    }
  }
}

DWORD GetClock()
{
  return GetTickCount();
}

void DrawCube(HDC hdc, int l, int t, int r, int b, COLORREF cr)
{
  HBRUSH color = CreateSolidBrush(cr);
  HBRUSH old = (HBRUSH)SelectObject(hdc, color);
  RoundRect(hdc, l, t, r, b, (r - l) / 4, (b - t) / 4);
  SelectObject(hdc, old);
  DeleteObject(color);
}

#define VOIP void

void updateGame()
{
  ++appearBlockCounter;

  if (GetAsyncKeyState('R'))
  {
    --curLevel;
    NextLevel();
  }

  if (deadCounter)
  {
    ++deadCounter;
    if (GetAsyncKeyState('W'))
    {
      --curLevel;
      NextLevel();
    }
  }
  else if (mainDir.x != 0)
  {
    mainPos.x += 2 * mainDir.x;
    int curTileID = curMap[mainPos.y / 32 * tilesX + mainPos.x / 32];

    if (mainPos.x % 32 == 0)
    {
      mainDir.x = 0;
      if (curTileID == 4)
      {
        mainDir.x = 0;
        mainDir.y = 1;
      }
    }
  }
  else if (mainDir.y != 0)
  {
    mainPos.y += 2 * mainDir.y;
    int curTileID = curMap[mainPos.y / 32 * tilesX + mainPos.x / 32];

    if (mainPos.y % 32 == 0 && mainDir.y == -1 &&
        curMap[mainPos.y / 32 * tilesX + mainPos.x / 32] == 3 &&
        curMap[(mainPos.y / 32 - 1) * tilesX + mainPos.x / 32] == 0)
    {
      appearBlockCounter = 0;
      appearBlockPos.x = mainPos.x;
      appearBlockPos.y = mainPos.y;
    }
    if (mainPos.y % 32 && mainDir.y == -1)
      curMap[(mainPos.y / 32 + 1) * tilesX + mainPos.x / 32] = 0;

    if (mainPos.y % 32 == 0 &&
        curTileID != 3 &&
        curTileID != 4)
    {
      if (mainDir.y == -1)
        curMap[(mainPos.y / 32 + 1) * tilesX + mainPos.x / 32] = 1;
      mainDir.y = 0;
    }
  }
  else if (mainPos.x % 32 == 0 && mainPos.y % 32 == 0)
  {
    int curTileID = curMap[mainPos.y / 32 * tilesX + mainPos.x / 32];
    if (GetAsyncKeyState('D') && mainPos.x < (tilesX - 1) * 32 &&
        curMap[mainPos.y / 32 * tilesX + mainPos.x / 32 + 1] != 1 &&
        curMap[mainPos.y / 32 * tilesX + mainPos.x / 32 + 1] != 8 &&
        (curMap[(mainPos.y / 32 + 1) * tilesX + mainPos.x / 32 + 1] == 1 ||
         curMap[(mainPos.y / 32 + 1) * tilesX + mainPos.x / 32 + 1] == 3))
      mainDir.x += 1;
    if (GetAsyncKeyState('A') && mainPos.x > 0 &&
        curMap[mainPos.y / 32 * tilesX + mainPos.x / 32 - 1] != 1 &&
        curMap[mainPos.y / 32 * tilesX + mainPos.x / 32 - 1] != 8 &&
        (curMap[(mainPos.y / 32 + 1) * tilesX + mainPos.x / 32 - 1] == 1 ||
         curMap[(mainPos.y / 32 + 1) * tilesX + mainPos.x / 32 - 1] == 3))
      mainDir.x += -1;

    if (GetAsyncKeyState('W') && !mainDir.x && !mainDir.y)
    {
      if (curTileID == 3)
        mainDir.y = -1;
      if (curMap[mainPos.y / 32 * tilesX + mainPos.x / 32 + 1] == 4)
        mainDir.x = 1;
      if (curMap[mainPos.y / 32 * tilesX + mainPos.x / 32 - 1] == 4)
        mainDir.x = -1;
      if (curMap[mainPos.y / 32 * tilesX + mainPos.x / 32 + 1] == 8 && keys > 0)
      {
        curMap[mainPos.y / 32 * tilesX + mainPos.x / 32 + 1] = 0;
        --keys;
      }
      if (curMap[mainPos.y / 32 * tilesX + mainPos.x / 32 - 1] == 8 && keys > 0)
      {
        curMap[mainPos.y / 32 * tilesX + mainPos.x / 32 - 1] = 0;
        --keys;
      }
    }
    if (curTileID == 5)
    {
      NextLevel();
    }
    if (curTileID == 7)
      dispText = true;
    if (curTileID == 6)
    {
      curMap[mainPos.y / 32 * tilesX + mainPos.x / 32] = 0;
      ++keys;
    }
  }

  for (int i = 0; i < enemies.size(); ++i)
  {
    POINT p = enemies.at(i);

    if (p.x < mainPos.x + 32 && p.x + 32 > mainPos.x &&
        p.y < mainPos.y + 32 && p.y + 32 > mainPos.y &&
        !deadCounter)
      deadCounter = 1;

    int d = enemyDirs.at(i);
    if (d != 0)
    {
      enemies[i].x += 2 * d;
      //if (enemies.at(i).x % 32 == 0)
        //enemyDirs[i] = 0;
    }

    if (p.x % 32 == 0)
    {
      /*int choice = rand() % 3;
      if (choice == 0 && curMap[p.y / 32 * tilesX + p.x / 32 + 1] != 1 &&
          curMap[p.y / 32 * tilesX + p.x / 32 + 1] != 4)
        enemyDirs[i] = 1;
      else if (choice == 1 && curMap[p.y / 32 * tilesX + p.x / 32 - 1] != 1 &&
               curMap[p.y / 32 * tilesX + p.x / 32 - 1] != 4)
        enemyDirs[i] = -1;
      else if (choice == 2 && mainPos.y == p.y)
      {
        int dir;
        if (mainPos.x == p.x)
          dir = 0;
        else
          dir = (mainPos.x - p.x) / abs(mainPos.x - p.x);
        if (curMap[p.y / 32 * tilesX + p.x / 32 + dir] != 1 &&
            curMap[p.y / 32 * tilesX + p.x / 32 + dir] != 4)
          enemyDirs[i] = dir;
      }*/

      int nextTile = curMap[p.y / 32 * tilesX + p.x / 32 + 1 * d];
      if (nextTile == 1 || nextTile == 4)
        enemyDirs[i] *= -1;
    }
  }
}

void PaintGame(HDC hdc)
{
  {
    RECT r = { 0, 0, windowWidth, windowHeight };
    FillRect(hdc, &r, (HBRUSH)GetStockObject(LTGRAY_BRUSH));
  }

  for (int x = 0; x < tilesX; ++x)
  {
    for (int y = 0; y < tilesY; ++y)
    {
      switch (curMap[y * tilesX + x])
      {
      case 1: // wall
        {
          RECT r = { 0, 0, 32, 32 };
          OffsetRect(&r, x * 32, y * 32);
          FillRect(hdc, &r, (HBRUSH)GetStockObject(DKGRAY_BRUSH));

          InflateRect(&r, -8, -8);
          HBRUSH oldbr = (HBRUSH)SelectObject(hdc, GetStockObject(NULL_BRUSH));
          //HPEN p = (HPEN)CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
          //HPEN oldp = (HPEN)SelectObject(hdc, p);
          Rectangle(hdc, r.left, r.top, r.right, r.bottom);
          //SelectObject(hdc, oldp);
          //DeleteObject(p);
          SelectObject(hdc, oldbr);

          break;
        }

      case 3: // ladder
        {
          RECT r = { 0, 0, 8, 32 };
          HBRUSH br = (HBRUSH)CreateSolidBrush(RGB(127, 51, 0));
          OffsetRect(&r, x * 32, y * 32);
          FillRect(hdc, &r, br);
          OffsetRect(&r, 24, 0);
          FillRect(hdc, &r, br);

          RECT r2 = { 8, 8, 24, 16 };
          OffsetRect(&r2, x * 32, y * 32);
          FillRect(hdc, &r2, br);
          OffsetRect(&r2, 0, 16);
          FillRect(hdc, &r2, br);
          DeleteObject(br);

          HPEN p = (HPEN)CreatePen(PS_SOLID, 3, RGB(81, 34, 0));
          HPEN oldp = (HPEN)SelectObject(hdc, p);
          MoveToEx(hdc, r.left + 2, r.top + 1, NULL);
          LineTo(hdc, r.left + 2, r.top + 32);
          OffsetRect(&r, -24, 0);
          MoveToEx(hdc, r.left + 2, r.top + 1, NULL);
          LineTo(hdc, r.left + 2, r.top + 32);
          SelectObject(hdc, oldp);
          DeleteObject(p);
          break;
        }

      case 4: // pole
        {
          RECT r = { 8, 0, 16, 32 };
          OffsetRect(&r, x * 32, y * 32);
          FillRect(hdc, &r, (HBRUSH)GetStockObject(DKGRAY_BRUSH));
          break;
        }

      case 5: // door
        {
          RECT r = { 4, 12, 28, 32 };
          OffsetRect(&r, x * 32, y * 32);
          FillRect(hdc, &r, (HBRUSH)GetStockObject(BLACK_BRUSH));

          HBRUSH br = (HBRUSH)CreateSolidBrush(RGB(0, 0, 0));
          HBRUSH oldb = (HBRUSH)SelectObject(hdc, br);
          RECT rcircle = { 4, 0, 28, 24 };
          OffsetRect(&rcircle, x * 32, y * 32);
          Ellipse(hdc, rcircle.left, rcircle.top, rcircle.right, rcircle.bottom);
          SelectObject(hdc, oldb);
          DeleteObject(br);
          break;
        }

      case 6: // key
        {
          RECT r = { 8, 4, 24, 20 };
          OffsetRect(&r, x * 32, y * 32);
          //FillRect(hdc, &r, (HBRUSH)GetStockObject(LTGRAY_BRUSH));
          HBRUSH br = (HBRUSH)GetStockObject(NULL_BRUSH);
          HBRUSH oldb = (HBRUSH)SelectObject(hdc, br);
          HPEN p = (HPEN)CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
          HPEN oldp = (HPEN)SelectObject(hdc, p);
          Ellipse(hdc, r.left, r.top, r.right, r.bottom);

          MoveToEx(hdc, 16 + x * 32,  20 + y * 32, NULL);
          LineTo(hdc, 16 + x * 32, 30 + y * 32);
          MoveToEx(hdc, 16 + x * 32,  24 + y * 32, NULL);
          LineTo(hdc, 20 + x * 32, 24 + y * 32);
          MoveToEx(hdc, 16 + x * 32,  28 + y * 32, NULL);
          LineTo(hdc, 20 + x * 32, 28 + y * 32);

          SelectObject(hdc, oldp);
          DeleteObject(p);
          SelectObject(hdc, oldb);
          DeleteObject(br);

          break;
        }

      case 7: // sign
        {
          RECT r = { 1, 1, 31, 16 };
          OffsetRect(&r, x * 32, y * 32);
          //FillRect(hdc, &r, (HBRUSH)GetStockObject(LTGRAY_BRUSH));
          HBRUSH br = (HBRUSH)CreateSolidBrush(RGB(81, 34, 0));
          FillRect(hdc, &r, br);

          RECT r2 = { 12, 16, 20, 32 };
          OffsetRect(&r2, x * 32, y * 32);
          FillRect(hdc, &r2, br);
          DeleteObject(br);
          break;
        }

      case 8: // gate
        {
          RECT r = { 8, 4, 24, 20 };
          OffsetRect(&r, x * 32, y * 32);
          //FillRect(hdc, &r, (HBRUSH)GetStockObject(LTGRAY_BRUSH));

          /*HBRUSH brBorder = (HBRUSH)GetStockObject(NULL_BRUSH);
          HBRUSH oldborder = (HBRUSH)SelectObject(hdc, brBorder);
          Rectangle(hdc, x * 32, y * 32, 32 + x * 32, 32 + y * 32);
          SelectObject(hdc, oldborder);*/

          DrawCube(hdc, x * 32, y * 32, 32 + x * 32, 32 + y * 32, RGB(128, 128, 128));

          HBRUSH br = (HBRUSH)CreateSolidBrush(RGB(0, 0, 0));
          HBRUSH oldb = (HBRUSH)SelectObject(hdc, br);
          Ellipse(hdc, r.left, r.top, r.right, r.bottom);

          RECT r2 = { 12, 12, 20, 28 };
          OffsetRect(&r2, x * 32, y * 32);
          FillRect(hdc, &r2, br);
          SelectObject(hdc, oldb);
          DeleteObject(br);
          break;
        }

      case 9:
        {
          RECT r = { 0, 0, 32, 32 };
          OffsetRect(&r, x * 32, y * 32);
          float angle = 2 * 3.14159f * (((GetTickCount() + 50) % 600) / 600.0f);
          int offy = cos(angle) * 3 - 3;
          int offx = sin(angle) * 3 + 3;

          DrawCube(hdc, r.left + offx, r.top + offy, r.right - offx, r.bottom, RGB(255, 0, 255));
        }
      }
    }
  }

  if (deadCounter < 68)
  {
    float angle = 2 * 3.14159f * ((mainPos.x % 32) / 32.0f + (mainPos.y % 32) / 32.0f);
    int offy = cos(angle) * 3 - 3 + deadCounter / 2;
    int offx = -cos(angle) * 3 + 3 + deadCounter / 2;
    DrawCube(hdc, mainPos.x + offx, mainPos.y + offy,
             mainPos.x + 32 - offx, mainPos.y + 32, RGB(81, 50, 255));
  }

  for (int i = 0; i < enemies.size(); ++i)
  {
    POINT p = enemies.at(i);
    RECT r = { 0, 0, 32, 32 };
    OffsetRect(&r, p.x, p.y);
    float angle = 2 * 3.14159f * ((GetTickCount() % 600) / 600.0f);
    int offy = cos(angle) * 3 - 3;
    int offx = sin(angle) * 3 + 3;

    DrawCube(hdc, r.left + offx, r.top + offy, r.right - offx, r.bottom, RGB(255, 0, 0));
  }

  if (appearBlockCounter < 16 && appearBlockCounter > 0)
  {
    RECT r = { 0, 0, 32, 32 };
    OffsetRect(&r, appearBlockPos.x, appearBlockPos.y);
    InflateRect(&r, -16 + appearBlockCounter, -16 + appearBlockCounter);
    FillRect(hdc, &r, (HBRUSH)GetStockObject(DKGRAY_BRUSH));

    InflateRect(&r, -8, -8);
    HBRUSH oldbr = (HBRUSH)SelectObject(hdc, GetStockObject(NULL_BRUSH));
    //HPEN p = (HPEN)CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    //HPEN oldp = (HPEN)SelectObject(hdc, p);
    Rectangle(hdc, r.left, r.top, r.right, r.bottom);
    //SelectObject(hdc, oldp);
    //DeleteObject(p);
    SelectObject(hdc, oldbr);
  }

  if (dispText)
  {
    SetBkMode(hdc, TRANSPARENT);
    SetTextColor(hdc, RGB(255, 255, 255));
    TextOut(hdc, 40, 5, text[curLevel].c_str(), strlen(text[curLevel].c_str()));
  }
}
