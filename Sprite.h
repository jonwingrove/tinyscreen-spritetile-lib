#pragma once

class Sprite
{
  public:
  int width;
  int height;
  uint8_t* data;
};

class SpriteInst
{
  public:
  const Sprite* sprite = 0;
  int x = 0;
  int y = 0;
  bool enabled = false;
  bool flip = false;
};

class TileMap8pix
{
  public:
  int xWidth;
  int yHeight;
  int xPixOffset;
  int yPixOffset;
  const Sprite** tilemap;
  
};

void drawSprites(SpriteInst* sprites, int numSprites, TileMap8pix *tilemap, uint8_t bgCol, TinyScreen *display);
