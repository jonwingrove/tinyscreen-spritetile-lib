#include <TinyScreen.h>
#include <SPI.h>
#include <Wire.h>

#include "Sprite.h"


uint8_t ALPHA = 0xBA;

void drawSprites(SpriteInst* sprites, int numSprites, TileMap8pix *tilemap, uint8_t bgCol, TinyScreen *display)
{
  display->goTo(0,0);
  display->startData();
  
  uint8_t lineBuffer[96];

  
  for(int lines = 0; lines < 64; ++lines)
  {
    if ( tilemap == 0 )
    {
      memset(lineBuffer,bgCol,96);
    }
    else
    {
      memset(lineBuffer,bgCol,96);
      int tileGridY = (lines - tilemap->yPixOffset) / 8;
      int thisY = (lines - tilemap->yPixOffset) - (tileGridY * 8);
      int startX = tilemap->xPixOffset;
      
      int tileGridX = -tilemap->xPixOffset / 8;
      int startPos = (tileGridX * 8)+tilemap->xPixOffset;
      for(int x = startPos; x < 96; x+=8)
      {
        int thisTileStartX = 0;
        int thisTileLength = 8;
        if ( x < 0 )
        {
          thisTileStartX = -x;
          thisTileLength -= thisTileStartX;
        }
        else if ( x > 88 )
        {
          thisTileLength = 96-x;
        }
        if (tileGridX >= 0 && tileGridY >= 0 
        && tileGridX < tilemap->xWidth && tileGridY < tilemap->yHeight && 
            tilemap->tilemap[tileGridX+(tileGridY*tilemap->xWidth)] != 0 )
        {
          memcpy(lineBuffer+x+thisTileStartX,tilemap->tilemap[tileGridX+(tileGridY*tilemap->xWidth)]->data+ (thisTileStartX+(thisY*8)),thisTileLength);
        }
        else
        {
          memset(lineBuffer+x+thisTileStartX,bgCol,thisTileLength);
        }
        tileGridX++;
      }
    }
    for(int index = 0; index < numSprites; ++index)
    {
      if(sprites[index].enabled)
      { 
        const Sprite* spriteType = sprites[index].sprite;
        int curLine = lines - sprites[index].y;
        if ( curLine >= 0 && curLine < spriteType->height )
        {
          for(int x = 0; x < spriteType->width; ++x)
          {
            int tx = x + sprites[index].x;
            if ( tx >= 0 && tx < 96 )
            {
              uint8_t col = sprites[index].flip ? spriteType->data[(spriteType->width-(x+1))+(curLine*spriteType->width)] : spriteType->data[x+(curLine*spriteType->width)];
              if ( col != ALPHA )
              {
                lineBuffer[tx] = col;
              }
            }
          }
        }
      }
    }
    display->writeBuffer(lineBuffer,96);
  }
  
  display->endTransfer();
}
