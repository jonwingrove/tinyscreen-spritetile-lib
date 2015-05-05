#include <TinyScreen.h>
#include <SPI.h>
#include <Wire.h>
#include "Sprite.h"


TinyScreen display = TinyScreen(0);

const uint8_t PROGMEM s_Brick0Data[] {0x00,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0x00,0x92,0x92,0x92,0x92,0x92,0x92,0x92
,0x00,0x92,0x92,0x92,0x92,0x92,0x92,0x92
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0xff,0xff,0xff,0xff,0xff,0x00,0xff,0xff
,0x92,0x92,0x92,0x92,0xff,0x00,0x92,0x92
,0x92,0x92,0x92,0x92,0xff,0x00,0x92,0x92
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};
static Sprite s_Brick0 = {8,8, s_Brick0Data};

const uint8_t PROGMEM s_Brick1Data[] {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
,0x92,0x92,0x92,0x92,0x92,0x92,0x92,0xff
,0x92,0x92,0x92,0x92,0x92,0x92,0x92,0xff
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0xff,0xff,0xff,0xff,0x00,0xff,0xff,0xff
,0x92,0x92,0x92,0xff,0x00,0x92,0x92,0x92
,0x92,0x92,0x92,0xff,0x00,0x92,0x92,0x92
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};
static Sprite s_Brick1 = {8,8, s_Brick1Data};

const uint8_t PROGMEM s_Brick2Data[] {0xff,0x00,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0x00,0x92,0x92,0x92,0x92,0x92,0xff
,0xff,0x00,0x92,0x92,0x92,0x92,0x92,0xff
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0xff,0xff,0xff,0xff,0x00,0xff,0xff,0xff
,0x92,0x92,0x92,0xff,0x00,0x92,0x92,0x92
,0x92,0x92,0x92,0xff,0x00,0x92,0x92,0x92
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};
static Sprite s_Brick2 = {8,8, s_Brick2Data};

const uint8_t PROGMEM s_Brick3Data[] {0xff,0x00,0xff,0xff,0xff,0xff,0xff,0xff
,0xff,0x00,0x92,0x92,0x92,0x92,0x92,0xff
,0xff,0x00,0x92,0x92,0x92,0x92,0x92,0xff
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
,0xff,0xff,0xff,0xff,0x00,0xff,0xff,0xff
,0x92,0x92,0x92,0xff,0x00,0x92,0x92,0x92
,0x92,0x92,0x92,0xff,0x00,0x92,0x92,0x92
,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};
static Sprite s_Brick3 = {8,8, s_Brick3Data};


static TileMap8pix s_tileMap = { 
  12,8,0,0, new const Sprite*[96]
{
&s_Brick0,&s_Brick2,&s_Brick0,&s_Brick2,0,0,0,0,&s_Brick0,&s_Brick2,&s_Brick0,&s_Brick2,
&s_Brick1,&s_Brick3,&s_Brick1,&s_Brick3,0,0,0,0,&s_Brick1,&s_Brick3,&s_Brick1,&s_Brick3,
&s_Brick0,&s_Brick2,&s_Brick0,&s_Brick2,0,0,0,0,&s_Brick0,&s_Brick2,&s_Brick0,&s_Brick2,
&s_Brick1,&s_Brick3,&s_Brick1,&s_Brick3,0,0,0,0,&s_Brick1,&s_Brick3,&s_Brick1,&s_Brick3,
&s_Brick0,&s_Brick2,&s_Brick0,&s_Brick2,0,0,0,0,&s_Brick0,&s_Brick2,&s_Brick0,&s_Brick2,
&s_Brick1,&s_Brick3,&s_Brick1,&s_Brick3,0,0,0,0,&s_Brick1,&s_Brick3,&s_Brick1,&s_Brick3,
&s_Brick0,&s_Brick2,&s_Brick0,&s_Brick2,0,0,0,0,&s_Brick0,&s_Brick2,&s_Brick0,&s_Brick2,
&s_Brick1,&s_Brick3,&s_Brick1,&s_Brick3,0,0,0,0,&s_Brick1,&s_Brick3,&s_Brick1,&s_Brick3
}};

const uint8_t PROGMEM s_SoldierData[] PROGMEM {0x00,0x00,0x00,0x00,0x00,0x00,0x49,0xdf,0x00,0x00,0x00,0x00,0x00,0xbf,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x49,0x49,0xdf,0xff,0x00,0x00,0x00,0x00,0x72,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x49,0x00,0x00,0x92,0x00,0x00,0x00,0x00,0x29,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x49,0x49,0x49,0x92,0x00,0x00,0x00,0x00,0x29,0x00,0x00
,0x00,0x00,0x00,0xff,0xe4,0x00,0x00,0x00,0x00,0x8d,0xf6,0x00,0x00,0x29,0x00,0x00
,0x00,0x00,0x49,0x49,0x80,0x80,0x80,0x80,0x8d,0x8d,0x44,0xf6,0x00,0x29,0x00,0x00
,0x00,0x00,0x92,0x49,0x00,0x80,0x80,0xe4,0x8d,0x44,0x44,0xf6,0x52,0x29,0x00,0x00
,0x00,0x49,0x92,0x00,0x00,0x80,0x80,0xe4,0x8d,0x44,0x00,0x44,0x04,0x29,0x00,0x00
,0x00,0x92,0xff,0x00,0x00,0x00,0x00,0xad,0x44,0x00,0x00,0x00,0x92,0xdf,0x00,0x00
,0x00,0x49,0xff,0x00,0x00,0x64,0x64,0xad,0xc9,0xc9,0x84,0x00,0x00,0x92,0x00,0x00
,0x00,0x00,0x00,0x00,0x64,0x00,0x64,0x00,0xc9,0x44,0xc9,0x00,0x00,0x49,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x64,0x64,0x00,0x44,0xc9,0x00,0x00,0x00,0x49,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x49,0x92,0x00,0x49,0xff,0x00,0x00,0x00,0x0a,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x49,0x92,0x00,0x49,0x92,0x00,0x00,0x00,0x0a,0x00,0x00
,0x00,0x00,0x00,0x00,0x00,0x49,0x49,0x00,0x49,0xff,0x00,0x00,0x00,0x0a,0x00,0x00
,0x00,0x00,0x00,0x00,0x49,0x92,0xff,0x00,0x49,0x92,0xff,0x00,0x00,0x0a,0x00,0x00
};
static Sprite s_Soldier = {16,16, s_SoldierData};


SpriteInst sprites[1];

void setup() {

  Wire.begin();
  Serial.begin(9600);
  display.begin();
  
  sprites[0].sprite = &s_Soldier;
  sprites[0].x = 32;
  sprites[0].y = 32;
  sprites[0].enabled = true;
}

int xDir = 1;

void loop() {
  // put your main code here, to run repeatedly:
  drawSprites(sprites,1,&s_tileMap,0x00,&display);
  sprites[0].x += xDir;
  sprites[0].y++;
  if (sprites[0].y == 64 )
  {
    sprites[0].y = -16;
  }
  if (sprites[0].x == 48 )
  {
    xDir = -1;
  }
  if (sprites[0].x == 32 )
  {
    xDir = 1;
  }
}
