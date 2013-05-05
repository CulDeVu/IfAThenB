#include <string>

int curMap[25*15];

int curLevel = 0 - 1;

const int map0[25*15] =
{
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
};

const int map1[25*15] =
{
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,3,1,1,1,1,1,1,1,1,1,1,1,1,
1,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,3,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,7,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
};

const int map2[25*15] =
{
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,3,1,1,1,1,1,1,1,1,1,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,3,1,1,1,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,3,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,7,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,3,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
};

const int map3[25*15] =
{
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,3,1,1,1,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,1,
1,0,0,0,0,0,0,0,0,7,0,0,4,0,0,0,0,0,0,0,3,0,0,0,1,
1,0,0,0,0,3,1,1,1,1,1,1,4,0,0,3,1,1,1,1,1,1,1,1,1,
1,0,0,0,0,3,1,0,0,0,0,0,4,0,0,3,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,3,1,0,0,0,0,0,4,0,0,3,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,3,1,0,0,0,0,0,4,0,0,3,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,3,1,0,0,0,0,0,4,0,0,3,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,3,1,0,0,0,0,0,4,0,0,3,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,3,1,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
};

const int map4[25*15] =
{
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,1,1,1,1,1,1,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,4,0,0,0,1,
1,0,0,0,0,0,0,0,0,3,1,1,1,1,1,1,1,1,1,1,4,0,0,0,1,
1,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,4,0,0,0,1,
1,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,4,0,0,0,1,
1,0,0,0,0,0,0,0,0,3,1,0,0,0,0,0,0,2,0,0,0,0,0,7,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
};

const int map5[25*15] =
{
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,1,1,1,1,3,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,1,3,0,0,0,0,0,4,0,7,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,1,1,3,1,1,1,1,4,1,1,1,1,3,1,1,1,0,0,0,1,
1,0,0,0,0,0,0,3,0,0,0,0,4,0,0,0,0,3,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,3,0,0,0,0,4,0,0,0,0,3,0,0,0,0,0,0,1,
1,0,0,0,0,0,1,3,0,0,0,0,0,0,0,2,1,3,0,0,0,0,0,0,1,
1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
};

const int map6[25*15] =
{
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,7,0,0,0,0,6,0,4,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,3,1,1,1,1,1,1,1,1,1,4,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,8,0,0,5,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
};

const int map7[25*15] =
{
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,2,0,0,0,0,2,0,0,0,2,0,0,0,0,0,2,0,0,6,4,1,0,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,4,1,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,4,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,4,0,0,1,
1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,3,0,0,8,5,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
};

const int map8[25*15] =
{
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,3,1,1,1,1,1,1,4,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,4,0,0,0,0,1,
1,0,0,0,0,0,0,0,6,0,0,0,3,0,0,0,0,1,0,4,0,0,0,0,1,
1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,3,1,0,4,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,4,0,0,0,0,1,
1,0,0,0,0,0,0,0,4,0,0,7,0,0,8,0,3,0,0,4,0,0,0,0,1,
1,0,0,0,0,0,0,0,4,3,1,1,3,1,1,1,1,0,0,4,0,0,0,0,1,
1,0,0,0,0,0,0,0,4,3,0,0,3,0,0,0,0,0,0,4,0,0,0,0,1,
1,0,2,0,0,0,0,0,6,3,1,0,3,0,0,0,0,0,0,4,0,0,0,0,1,
1,1,1,1,1,1,1,1,1,1,1,0,3,0,0,0,0,0,0,4,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,4,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,8,0,5,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
};

const int map9[25*15] =
{
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,1,0,0,0,4,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,1,
1,0,0,1,1,1,1,4,1,1,1,1,1,1,1,1,1,1,1,1,3,0,0,0,1,
1,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,1,
1,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,1,
1,0,1,0,0,0,2,0,0,0,4,0,0,7,0,0,6,0,0,0,3,0,0,0,1,
1,0,1,1,1,1,1,1,1,1,4,1,1,1,1,1,1,1,3,0,3,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,3,0,3,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,3,0,3,0,0,0,1,
1,0,0,0,0,0,1,0,2,0,0,0,0,0,0,6,4,0,3,0,3,0,0,0,1,
1,0,0,0,0,0,1,1,1,1,1,3,1,1,1,1,4,0,3,0,3,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,4,0,3,0,3,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,8,3,8,3,8,0,5,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
};

const int map10[25*15] =
{
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,0,0,1,0,2,0,0,6,4,0,0,0,0,0,0,0,0,0,8,0,8,0,5,1,
1,0,0,1,1,1,1,3,1,4,0,0,0,0,0,0,0,3,1,1,1,1,1,1,1,
1,0,0,0,0,0,0,3,0,4,0,0,0,0,0,0,0,3,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,3,0,0,4,0,0,0,1,
1,0,0,0,1,1,1,1,1,1,1,3,1,1,3,1,1,1,1,1,4,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,3,0,0,3,0,0,0,0,0,4,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,3,0,0,3,0,0,4,6,0,0,0,2,0,1,
1,0,0,0,0,0,0,0,0,0,0,3,0,0,3,0,0,4,1,1,1,1,1,1,1,
1,0,0,0,0,0,0,0,0,0,0,3,0,0,3,0,0,4,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,3,0,0,3,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,3,1,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,1,
1,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
};

const int map11[25*15] =
{
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,3,1,1,1,1,1,1,1,1,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,1,0,0,2,0,2,0,1,0,3,0,1,0,2,0,2,0,0,1,0,0,1,
1,0,0,0,1,1,1,1,1,1,0,0,3,0,0,1,1,1,1,1,1,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,1,0,2,0,2,0,0,1,0,3,0,1,0,0,2,0,2,0,1,0,0,1,
1,0,0,0,1,1,1,1,1,1,0,0,3,0,0,1,1,1,1,1,1,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,1,0,0,2,0,2,0,1,0,3,0,1,0,2,0,2,0,0,1,0,0,1,
1,0,0,0,1,1,1,1,1,1,0,0,3,0,0,1,1,1,1,1,1,0,0,0,1,
1,0,0,0,0,0,0,7,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
};

const int map12[25*15] =
{
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,4,1,0,0,0,1,
1,0,0,1,1,1,3,1,1,1,1,1,1,3,1,1,1,1,1,4,1,0,0,0,1,
1,0,0,0,0,0,3,0,0,0,0,0,0,3,0,0,0,0,0,4,0,0,0,0,1,
1,0,0,0,0,0,3,0,0,0,0,0,0,3,0,0,0,0,0,4,0,0,0,0,1,
1,0,0,1,0,0,3,0,0,0,4,0,0,3,0,0,0,4,0,0,1,0,0,0,1,
1,0,0,1,3,1,1,1,1,1,4,3,1,1,1,1,1,4,1,1,1,0,0,0,1,
1,0,0,0,3,0,0,0,0,0,4,3,0,0,0,0,0,4,0,0,0,0,0,0,1,
1,0,0,0,3,0,0,0,0,0,4,3,0,0,0,0,0,4,0,0,0,0,0,0,1,
1,0,0,1,3,0,0,0,1,0,0,3,6,0,2,0,1,0,0,4,1,0,0,0,1,
1,0,0,1,1,1,1,3,1,1,1,1,1,1,1,1,1,1,1,4,1,0,0,0,1,
1,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,1,
1,0,0,0,0,7,0,3,0,0,0,0,0,1,0,0,2,0,0,0,0,8,0,5,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
};

const int map13[25*15] =
{
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,9,0,0,0,0,0,0,0,0,0,0,0,2,0,2,0,2,0,2,0,2,0,1,
1,1,1,1,1,1,1,1,1,1,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,7,0,0,0,0,0,5,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
};

const int map14[25*15] =
{
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,5,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
};

std::string text[] =
{
  "IF 'a' or 'd', THEN I move",
  "IF 'w', THEN I climb",
  "IF she needs rescuing, THEN I will save her",
  "IF 'w', THEN I shimmy down",
  "IF enemy, THEN I die",
  "IF 'r', THEN I get un-stuck",
  "IF 'w' and key, THEN I open",
  "IF enemies on guard, THEN I scurry",
  "IF she's this far deep... then is she worth it?",
  "IF I go around, THEN I come around",
  "IF she's this far down... then she's most likely dead...",
  "IF I go deeper, THEN the stakes get higher",
  "IF I only have one chance, THEN I need to get it right the first time",
  "There she is... but IF I can't get her... I guess then... I can't save her",
  "Oh well. She's just a pink block",
  "\"IF, THEN\", by Daniel Taylor. -- Thanks for playing, guys. Take care."
};

