#include "displayHelper.h"
#include "string.h"

// 显示固件信息
void showFirmwareInfo(FastLED_NeoMatrix *matrix, int x, int y, bool clear)
{
  for (int i = 32; i > 0; i--)
  {
    matrix->setCursor(i, 6 + y);
    if (clear)
    {
      matrix->clear();
    }
    matrix->setTextColor(matrix->Color(255, 0, 0));
    matrix->print("G");
    matrix->setTextColor(matrix->Color(255, 127, 0));
    matrix->print("M");
    matrix->setTextColor(matrix->Color(255, 255, 0));
    matrix->print("a");
    matrix->setTextColor(matrix->Color(0, 255, 0));
    matrix->print("t");
    matrix->setTextColor(matrix->Color(0, 255, 255));
    matrix->print("r");
    matrix->setTextColor(matrix->Color(46, 43, 95));
    matrix->print("i");
    matrix->setTextColor(matrix->Color(139, 0, 255));
    matrix->print("x");
    matrix->setTextColor(matrix->Color(255, 255, 255));
    // matrix->print("v0.01");
    matrix->show();
    delay(16);
  }
  delay(1000);
}

// 显示开发者信息
void showChaosgoo(FastLED_NeoMatrix *matrix, bool clear)
{
  // for (int i = 32; i > -64; i--)
  // {
  //   matrix->setCursor(i, 6);
  //   if (clear)
  //   {
  //     matrix->clear();
  //   }
  //   matrix->setTextColor(matrix->Color(255, 165, 0));
  //   matrix->print("Design By ");
  //   matrix->setTextColor(matrix->Color(255, 255, 255));
  //   matrix->print("Chaosgoo.");
  //   matrix->show();
  //   delay(16);
  //}
}

void showContent(FastLED_NeoMatrix *matrix, String str, int x, int y, int color, bool clear)
{
  matrix->setCursor(x, y);
  if (clear)
  {
    matrix->clear();
  }
  // matrix->setTextColor(matrix->Color(((color & 0xff) << 16), ((color & 0xff) << 8), ((color & 0xff) << 0)));
  matrix->setTextColor(color);
  matrix->print(str); // No problem.
  // matrix->show();
}

void showTime(FastLED_NeoMatrix *matrix, int time_h, int time_m, int x, int y, int color, bool clear)
{
  char ctime_h[2];
  char ctime_m[2];
  // 绘制小时数
  if (clear)
  {
    matrix->clear();
  }
  matrix->setCursor(x+1, y);
  matrix->setTextColor(color);
  sprintf(ctime_h, "%02d", time_h);
  
  matrix->print(ctime_h);
  matrix->drawPixel(x + 9, y - 2, matrix->Color(255,187,255));
  matrix->drawPixel(x + 9, y - 4, matrix->Color(255,187,255));
  matrix->setCursor(x + 11, y);
  sprintf(ctime_m, "%02d", time_m);
  matrix->print(ctime_m); 
  matrix->show();
}

void showTime2(FastLED_NeoMatrix *matrix, int time_h, int time_m, int x, int y, int color, bool clear)
{
  char ctime_h[2];
  char ctime_m[2];
  // 绘制小时数
  if (clear)
  {
    matrix->clear();
  }
  matrix->setCursor(x+1, y);
  matrix->setTextColor(color);
  sprintf(ctime_h, "%02d", time_h);
  
  matrix->print(ctime_h);
  //matrix->drawPixel(x + 9, y - 2, 0xfd79);
  //matrix->drawPixel(x + 9, y - 4, 0xfd79);
  matrix->setCursor(x + 11, y);
  sprintf(ctime_m, "%02d", time_m);
  matrix->print(ctime_m); 
  matrix->show();
}
void showDate(FastLED_NeoMatrix *matrix, int date_m, int date_d, int x, int y, int color, bool clear)
{
  // 绘制日期
  char cdate_m[2];
  char cdate_d[2];
  if (clear)
  {
    matrix->clear();
  }
  matrix->setCursor(x, y);
  matrix->setTextColor(color);
  sprintf(cdate_m, "%02d", date_m);
  matrix->print(cdate_m);
  matrix->drawPixel(x + 8, y - 3, matrix->Color(255, 0, 0));
  matrix->drawPixel(x + 9, y - 3, matrix->Color(255, 0, 0));
  matrix->setCursor(x + 11, y);
  sprintf(cdate_d, "%02d", date_d);
  matrix->print(cdate_d); // No problem.
  matrix->show();
}
// 显示WiFi连接中动画帧
void showWiFiConnecting(FastLED_NeoMatrix *matrix, int status, bool clear)
{
  if (clear)
  {
    matrix->clear();
  }
  switch (status)
  {
  case 3:
    matrix->drawPixel(23, 3, 0x07E0);
  case 2:
    matrix->drawPixel(21, 3, 0x07E0);
  case 1:
    matrix->drawPixel(19, 3, 0x07E0);
  case 0:
    matrix->setCursor(5, 6);
    matrix->setTextColor(matrix->Color(255, 255, 255));
    matrix->print("WiFi");
    break;
  }
  matrix->show();
}

// 显示WiFi连接完成动画
void showWiFiDoneAnimation(FastLED_NeoMatrix *matrix, bool clear)
{
  for (int i = 0; i < 8; i++)
  {
    showWiFiConnectDone(matrix, i, true);
    delay(100);
  }
}

// WiFi连接完成动画帧
void showWiFiConnectDone(FastLED_NeoMatrix *matrix, int status, bool clear)
{
  if (clear)
  {
    matrix->clear();
  }
  switch (status)
  {
  case 7:
    matrix->drawPixel(23, 1, 0x07E0);
  case 6:
    matrix->drawPixel(22, 2, 0x07E0);
  case 5:
    matrix->drawPixel(21, 3, 0x07E0);
  case 4:
    matrix->drawPixel(20, 4, 0x07E0);
  case 3:
    matrix->drawPixel(19, 5, 0x07E0);
  case 2:
    matrix->drawPixel(18, 4, 0x07E0);
  case 1:
    matrix->drawPixel(17, 3, 0x07E0);
  case 0:
    matrix->setCursor(2, 6);
    matrix->setTextColor(matrix->Color(255, 255, 255));
    matrix->print("WiFi");
    break;
  }
  matrix->show();
}

// 格式化粉丝数量字符串
const char *formatFollowers(const char *followers, int width, bool clear)
{
  int len = strlen(followers);
  char *dst;
  strcpy(dst, followers);
  while (len < width)
  {
    len++;
    dst += '0';
  }
  return dst;
}
void clearMatrix(FastLED_NeoMatrix *matrix)
{
  matrix->clear();
}
void showTemperature(FastLED_NeoMatrix *matrix, float temp, int x, int y, int color, bool clear)
{
  if (clear)
  {
    matrix->clear();
  }
  matrix->setCursor(x, y);
  if (temp > 30)
  {
    matrix->setTextColor(matrix->Color(213, 0, 0));
  }
  else if (temp > 20)
  {
    matrix->setTextColor(matrix->Color(255, 23, 68));
  }
  else if (temp > 10)
  {
    matrix->setTextColor(matrix->Color(255, 82, 82));
  }
  else if (temp >= 0)
  {
    matrix->setTextColor(matrix->Color(255, 138, 128));
  }
  else if (temp < 0)
  {
    matrix->setTextColor(matrix->Color(213, 0, 0));
  }
  matrix->print(int(temp)); // No problem.
  matrix->setTextColor(matrix->Color(255, 255, 255));
  matrix->print("C"); // No problem.
}

void showHumidity(FastLED_NeoMatrix *matrix, float hum, int x, int y, int color, bool clear)
{
  matrix->setCursor(x, y);
  if (clear)
  {
    matrix->clear();
  }
  matrix->setTextColor(matrix->Color(255, 255, 255));
  matrix->print("H:"); // No problem.
  if (hum > 80)
  {
    matrix->setTextColor(matrix->Color(0, 1, 118));
  }
  else if (hum > 75)
  {
    matrix->setTextColor(matrix->Color(0, 176, 255));
  }
  else if (hum > 70)
  {
    matrix->setTextColor(matrix->Color(64, 196, 255));
  }
  else if (hum > 65)
  {
    matrix->setTextColor(matrix->Color(128, 216, 255));
  }
  else if (hum > 60)
  {
    matrix->setTextColor(matrix->Color(1, 87, 155));
  }
  matrix->print(int(hum)); // No problem.
  matrix->setTextColor(matrix->Color(255, 255, 255));
  matrix->print("%"); // No problem.
  // matrix->show();
}


void showvoltage(FastLED_NeoMatrix *matrix, float voltage, int x, int y, int color, bool clear)
{
  int vv=int((voltage/4.2)*100);
  if(vv>=100)
  {
    vv=100;
  }
  matrix->setCursor(x, y);
  if (clear)
  {
    matrix->clear();
  }
  matrix->setTextColor(matrix->Color(255, 255, 255));
  matrix->print("U:"); // No problem.
  if (vv > 90)
  {
    matrix->setTextColor(matrix->Color(35, 247, 60));
  }
  else if (vv > 75)
  {
    matrix->setTextColor(matrix->Color(47, 144, 235));
  }
  else if (vv > 50)
  {
    matrix->setTextColor(matrix->Color(255, 255, 0));
  }
  else if (vv > 20)
  {
    matrix->setTextColor(matrix->Color(255, 0, 0));
  }
  matrix->print(vv); // No problem.
  matrix->setTextColor(matrix->Color(255, 255, 255));
  matrix->print("%"); // No problem.
  matrix->show();
}


void showFirmwareInfoEnd(FastLED_NeoMatrix *matrix)
{
  for (int y = 6; y < 14; y++)
  {
    matrix->setCursor(2, y);
    matrix->clear();
    matrix->setTextColor(matrix->Color(255, 0, 0));
    matrix->print("H");
    matrix->setTextColor(matrix->Color(255, 127, 0));
    matrix->print("O");
    matrix->setTextColor(matrix->Color(255, 255, 0));
    matrix->print("L");
    matrix->setTextColor(matrix->Color(0, 255, 0));
    matrix->print("O");
    matrix->setTextColor(matrix->Color(0, 255, 255));
    matrix->print("T");
    matrix->show();
    delay(300);
  }
}
void showbluetooth(FastLED_NeoMatrix *matrix)
{
  //matrix->clear();
  for (int x = 2; x > -12; x--)
  {
    matrix->setCursor(x, 6);
    matrix->clear();
    matrix->setTextColor(matrix->Color(255, 0, 0));
    matrix->print("b");
    matrix->print("l");
    matrix->print("u");
    matrix->print("e");
    matrix->print("t");
    matrix->print("o");
    matrix->print("o");
    matrix->print("t");
    matrix->print("h");
    matrix->show();
    delay(200);
  }
}
void showcharge(FastLED_NeoMatrix *matrix)
{
  matrix->clear();
  for (int y = 0; y < 8; y++)
  {
    matrix->setCursor(0, y);
    matrix->clear();
    matrix->setTextColor(matrix->Color(255, 0, 0));
    matrix->print("C");
    matrix->print("H");
    matrix->print("A");
    matrix->print("R");
    matrix->print("G");
    matrix->print("E");
    matrix->show();
    delay(200);
  }
}

void showAnimationString(FastLED_NeoMatrix *matrix, String content, int fromX, int fromY, int toX, int toY, int color)
{
  int xDirection = 1;
  int yDirection = 1;
  if (fromX > toX)
  {
    xDirection = -1;
  }
  else if (fromX == toX)
  {
    xDirection = 0;
  }
  if (fromY > toY)
  {
    yDirection = -1;
  }
  else if (fromY == toY)
  {
    yDirection = 0;
  }
  while (!(fromX == toX && fromY == toY))
  {
    showContent(matrix, content, fromX, fromY, color, true);
    fromX += xDirection;
    fromY += yDirection;
    delay(1000);
  }
}

// 局部清屏
void clearLocal(FastLED_NeoMatrix *matrix, int l, int t, int r, int b)
{
  matrix->drawRect(l, t, r, b, 0xffff);
}

// 显示加号动画
void showPlus(FastLED_NeoMatrix *matrix, int follower, int x, int y, int color, bool clear, int frame)
{
  if (clear)
  {
    matrix->clear();
  }
  matrix->setCursor(x, y);
  switch (frame % 7)
  {
  case 0:
    matrix->drawFastHLine(x, y + 2, 5, color);
    matrix->drawFastVLine(x + 2, y, 5, color);
    break;
  case 1:
    matrix->drawFastHLine(x + 1, y + 2, 3, color);
    matrix->drawFastVLine(x + 2, y + 1, 3, color);
    break;
  case 2:
    matrix->drawPixel(x + 2, y + 2, color);
    break;
  case 3:
    // DO NOTHING
    break;
  case 4:
    matrix->drawPixel(x + 2, y + 2, color);
    break;
  case 5:
    matrix->drawFastHLine(x + 1, y + 2, 3, color);
    matrix->drawFastVLine(x + 2, y + 1, 3, color);
    break;
  case 6:
    matrix->drawFastHLine(x, y + 2, 5, color);
    matrix->drawFastVLine(x + 2, y, 5, color);
    break;
  }
  // matrix->drawFastHLine(0, 7, (frame / 60.0) * 32, matrix->Color(0, 164, 214));
  // matrix->drawFastHLine(0, 0, 32, matrix->Color(0, 0, 0));
  // matrix->drawFastHLine(0, 0, (1.0 - (frame / 60.0)) * 32, matrix->Color(0, 164, 214));
}

void showDecrease(FastLED_NeoMatrix *matrix, int follower, int x, int y, int color, bool clear, int frame)
{
  if (clear)
  {
    matrix->clear();
  }
  matrix->setCursor(x, y);
  switch (frame % 7)
  {
  case 0:
    matrix->drawFastHLine(x, y + 2, 5, color);
    break;
  case 1:
    matrix->drawFastHLine(x + 1, y + 2, 3, color);
    break;
  case 2:
    matrix->drawPixel(x + 2, y + 2, color);
    break;
  case 3:
    // DO NOTHING
    break;
  case 4:
    matrix->drawPixel(x + 2, y + 2, color);
    break;
  case 5:
    matrix->drawFastHLine(x + 1, y + 2, 3, color);
    break;
  case 6:
    matrix->drawFastHLine(x, y + 2, 5, color);
    break;
  }
}

void showHeart(FastLED_NeoMatrix *matrix, int follower, int x, int y, int color, bool clear, int frame)
{
  if (clear)
  {
    matrix->clear();
  }
  if (frame % 10 > 5)
  {
    matrix->fillRect(x + 1, y + 1, 5, 3, color);
    matrix->drawFastHLine(x + 1, y, 2, color);
    matrix->drawFastHLine(x + 4, y, 2, color);
    matrix->drawFastHLine(x + 2, y + 4, 3, color);
    matrix->drawFastVLine(x, y + 1, 2, color);
    matrix->drawFastVLine(x + 6, y + 1, 2, color);
    matrix->drawPixel(x + 3, y + 5, color);
  }
  else
  {
    matrix->fillRect(x + 1, y + 1, 5, 3, color);
    matrix->drawPixel(x + 3, y + 1, 0);
    matrix->drawPixel(x + 1, y + 3, 0);
    matrix->drawPixel(x + 5, y + 3, 0);
    matrix->drawPixel(x + 3, y + 4, color);
  }
}

void showClock(CRGB leds[], FastLED_NeoMatrix *matrix, int x, int y, int color, bool clear, int frame)
{

  if (clear && frame < 6)
  {
    matrix->clear();
  }
  switch (frame)
  {
  case 4:
    matrix->drawPixel(x + 1, y + 1, color);
    matrix->drawPixel(x + 5, y + 1, color);
    matrix->drawPixel(x + 11, y + 1, color);
    matrix->drawPixel(x + 15, y + 1, color);
    break;
  case 3:
    matrix->fillRect(x, y+1, 3, 1, color);
    matrix->fillRect(x + 4, y+1, 3, 1, color);
    matrix->fillRect(x + 10, y+1, 3, 1, color);
    matrix->fillRect(x + 14, y+1, 3, 2, color);
    break;
  case 2:
    matrix->fillRect(x, y, 3, 3, color);
    matrix->fillRect(x + 4, y, 3, 3, color);
    matrix->fillRect(x + 10, y, 3, 3, color);
    matrix->fillRect(x + 14, y, 3, 3, color);
    break;
  case 1:
    matrix->fillRect(x, y, 3, 5, color);
    matrix->fillRect(x + 4, y, 3, 5, color);
    matrix->fillRect(x + 10, y, 3, 5, color);
    matrix->fillRect(x + 14, y, 3, 5, color);
    break;
  case 0:
    break;
  default:
    break;
  }
}
void GetAmplitude(FastLED_NeoMatrix *matrix)
{
  uint16_t color;
  if(FFT_GetDataFlag())
	{
    matrix->clear();
    FFT_Calc();
    int x[20];
    int xx[20];
    for(int i=1;i<=20;i++)
    {
      if(i<=11)
      {
        x[i]=FFT_GetAmplitude(600-50*i)/4;
        
      }
      else
      {
        x[i]=FFT_GetAmplitude(1400-40*i)/4;
      }
      xx[i]=x[i]+1;
      if(x[i]>=6)
      {
        color=0x001f;
      }
      else if(x[i]>=3)
      {
        color=0x051d;
      }
      else 
      {
        color=0x9edd;
      }
      matrix->drawFastVLine(1+i,8,-x[i],color);
      
      matrix->drawPixel(1+i, 7-xx[i], 0xfd79);

    }

    matrix->show(); 
    delay(1);
		FFT_ClrDataFlag(); //准备下一次数
  }
}
void showwether(FastLED_NeoMatrix *matrix,int weathercode,int _temperature)//天气图标
{

  if (weathercode==25)//暴雪
  {
    //功能：雪晴（小雪人）
    //matrix->clear();
    matrix->fillRect(2,1,4,3,matrix->Color(255,255,255));
    matrix->fillRect(1,4,6,4,matrix->Color(255,255,255));
    matrix->drawFastVLine(0,5,2, matrix->Color(205,133,63));
    matrix->drawFastVLine(7,5,2,matrix->Color(205,133,63));
    matrix->drawPixel(1,6,matrix->Color(205,133,63));
    matrix->drawPixel(6,6,matrix->Color(205,133,63));
    matrix->drawFastHLine(3,0,2,matrix->Color(255,0,0));
    matrix->drawFastHLine(3,3,2,matrix->Color(100,100,100));
    matrix->drawPixel(2,2,matrix->Color(0,0,255));
    matrix->drawPixel(5,2,matrix->Color(0,0,255));
    matrix->show();
  }
  if (weathercode==21|weathercode==22|weathercode==23|weathercode==24)//阵 小 中 大 雪
  {
    //小雪
   //matrix->clear();
   matrix->drawFastVLine(3,0,4,matrix->Color(230,255,255));
   matrix->drawFastHLine(2,1,3,matrix->Color(230,255,255));
   matrix->drawFastVLine(1,3,3,matrix->Color(230,255,255));
   matrix->drawFastHLine(0,4,4,matrix->Color(230,255,255));
   matrix->drawFastVLine(4,4,4,matrix->Color(230,255,255));
   matrix->drawFastHLine(3,6,3,matrix->Color(230,255,255));
   matrix->drawFastVLine(6,2,3,matrix->Color(230,255,255));
   matrix->drawFastHLine(4,3,4,matrix->Color(230,255,255));
   matrix->show();
  }
  if (weathercode==0)//晴（国内城市白天晴）
  {
    //白天晴
    matrix->fillRect(2, 3, 4, 2, matrix->Color(255,255,0));
    matrix->fillRect(3, 2, 2, 4, matrix->Color(255,255,0));
    matrix->drawPixel(2, 0, matrix->Color(255,255,0));
    matrix->drawPixel(5, 0, matrix->Color(255,255,0));
    matrix->drawPixel(0, 2, matrix->Color(255,255,0));
    matrix->drawPixel(7, 2, matrix->Color(255,255,0));
    matrix->drawPixel(0, 5, matrix->Color(255,255,0));
    matrix->drawPixel(7, 5, matrix->Color(255,255,0));
    matrix->drawPixel(2, 7, matrix->Color(255,255,0));
    matrix->drawPixel(5, 7, matrix->Color(255,255,0));
    matrix->show();
  }  
  if (weathercode==1)//
  {
    //夜晚晴
    
    matrix->drawFastVLine(0, 3, 3, matrix->Color(190,190,190));
    matrix->drawFastVLine(1, 3, 3, matrix->Color(255,255,255));
    matrix->drawFastHLine(2, 7, 3, matrix->Color(190,190,190));
    matrix->drawPixel(5, 0, matrix->Color(255,255,0));
    matrix->drawPixel(7, 2, matrix->Color(255,255,0));
    matrix->drawPixel(4, 4, matrix->Color(255,255,0));
    matrix->drawPixel(6, 6, matrix->Color(255,255,0));
    matrix->drawPixel(2, 1, matrix->Color(190,190,190));
    matrix->drawPixel(1, 2, matrix->Color(190,190,190));
    matrix->drawPixel(1, 6, matrix->Color(190,190,190));
    matrix->drawPixel(3, 1, matrix->Color(255,255,255));
    matrix->drawPixel(2, 2, matrix->Color(255,255,255));
    matrix->drawPixel(2, 6, matrix->Color(255,255,255));
    matrix->show();
  } 
  if (weathercode==4|weathercode==5|weathercode==7)
  {
    //白多云
    //matrix->clear();
    matrix->drawPixel(2, 0, matrix->Color(255,255,0)); 
    matrix->drawPixel(4, 0, matrix->Color(255,255,0)); 
    matrix->drawPixel(0, 1, matrix->Color(255,255,0)); 
    matrix->drawPixel(0, 3, matrix->Color(255,255,0)); 
    matrix->drawFastHLine(2, 2, 3, matrix->Color(255,255,0));
    matrix->drawPixel(5, 2, matrix->Color(255,255,255)); 
    matrix->fillRect(2, 3, 5, 5, matrix->Color(255,255,255));
    matrix->drawPixel(2, 3, matrix->Color(255,255,0)); 
    matrix->drawFastHLine(4, 3, 3, matrix->Color(180,180,180));
    matrix->drawFastHLine(4, 4, 2, matrix->Color(150,150,150));
    matrix->drawPixel(4, 5, matrix->Color(150,150,150)); 
    matrix->drawFastVLine(1, 5, 2, matrix->Color(180,180,180));
    matrix->drawFastVLine(7, 4, 3, matrix->Color(180,180,180));
    matrix->show();

  }  
  if (weathercode==6|weathercode==8)
  {
    //功能：夜晚多云
   // matrix->clear();
    matrix->drawFastVLine(1, 2, 2, matrix->Color(255,255,255));
    matrix->drawFastVLine(2, 1, 4, matrix->Color(255,255,255));
    matrix->drawFastHLine(2, 4, 2, matrix->Color(255,255,255));
    matrix->drawFastHLine(3, 5, 4, matrix->Color(255,255,255));
    matrix->drawFastHLine(3, 6, 2, matrix->Color(128,128,128));
    matrix->drawPixel(0, 0, matrix->Color(255,255,255)); 
    matrix->drawPixel(3, 0, matrix->Color(255,255,255)); 
    matrix->drawPixel(6, 1, matrix->Color(255,255,0)); 
    matrix->drawPixel(1, 4, matrix->Color(128,128,128)); 
    matrix->drawPixel(7, 4, matrix->Color(255,255,255)); 
    matrix->drawPixel(2, 5, matrix->Color(128,128,128)); 
    matrix->drawPixel(1, 7, matrix->Color(255,255,255));     
    matrix->drawPixel(7, 7, matrix->Color(255,255,255));
    matrix->show();
  } 
  if (weathercode==9)//阴
  {
    //功能：阴
    //matrix->clear();
    matrix->drawFastVLine(1, 2, 2, matrix->Color(100,100,100));
    matrix->drawFastVLine(5, 1, 2, matrix->Color(100,100,100));
    matrix->drawPixel(4, 2, matrix->Color(100,100,100)); 
    matrix->drawPixel(7, 2, matrix->Color(100,100,100)); 
    matrix->drawFastHLine(5, 2, 2, matrix->Color(200,200,200));
    matrix->drawFastHLine(0, 3, 8, matrix->Color(190,190,190));
    matrix->drawPixel(0, 3, matrix->Color(100,100,100)); 
    matrix->drawPixel(3, 3, matrix->Color(100,100,100)); 
    matrix->drawFastHLine(0, 4, 7, matrix->Color(180,180,180));
    matrix->drawFastHLine(0, 5, 7, matrix->Color(150,150,150));
    matrix->drawPixel(0, 5, matrix->Color(100,100,100)); 
    matrix->drawPixel(7, 5, matrix->Color(100,100,100)); 
    matrix->drawFastHLine(1, 6, 6, matrix->Color(110,110,110));
    matrix->show();
  } 
  if (weathercode==10|weathercode==13|weathercode==14|weathercode==15|weathercode==16|weathercode==17|weathercode==18|weathercode==19|weathercode==20)
  {
    //功能：雨
    //matrix->clear();
    matrix->fillRect(1,1, 2 ,4, matrix->Color(255,255,255));
    matrix->fillRect(2,3, 5 ,2, matrix->Color(255,255,255));
    matrix->fillRect(4,1, 4 ,3, matrix->Color(255,255,255));
    matrix->drawPixel(5, 0, matrix->Color(150,150,150)); 
    matrix->drawPixel(4, 1, matrix->Color(150,150,150)); 
    matrix->drawPixel(7, 1, matrix->Color(150,150,150)); 
    matrix->drawPixel(0, 2, matrix->Color(150,150,150)); 
    matrix->drawPixel(1, 4, matrix->Color(150,150,150)); 
    matrix->drawPixel(0, 3, matrix->Color(255,255,255)); 
    matrix->drawPixel(6, 0, matrix->Color(255,255,255)); 
    matrix->drawPixel(1, 5, matrix->Color(0,255,255)); 
    matrix->drawPixel(0, 6, matrix->Color(0,255,255)); 
    matrix->drawPixel(4, 5, matrix->Color(0,255,255)); 
    matrix->drawPixel(3, 6, matrix->Color(0,255,255)); 
    matrix->drawPixel(2, 7, matrix->Color(0,255,255)); 
    matrix->drawPixel(7, 5, matrix->Color(0,255,255)); 
    matrix->drawPixel(6, 6, matrix->Color(0,255,255)); 
    matrix->drawPixel(5, 7, matrix->Color(0,255,255)); 
    matrix->show();
  } 
  if (weathercode==11|weathercode==12)
  {
    //功能：雷雨
    //matrix->clear();
    matrix->fillRect(2,3, 2 ,2, matrix->Color(255,255,255));
    matrix->fillRect(4,2, 2 ,3, matrix->Color(255,255,255));
    matrix->drawFastVLine(1, 3, 2, matrix->Color(100,100,100));
    matrix->drawFastVLine(6, 2, 4, matrix->Color(100,100,100));
    matrix->drawFastHLine(0, 5, 4, matrix->Color(100,100,100));
    matrix->drawFastHLine(2, 2, 2, matrix->Color(100,100,100));
    matrix->drawFastHLine(4, 1, 2, matrix->Color(100,100,100));
    matrix->drawFastHLine(5, 5, 3, matrix->Color(100,100,100));
    matrix->drawPixel(4, 3, matrix->Color(255,255,0)); 
    matrix->drawPixel(3, 4, matrix->Color(255,255,0)); 
    matrix->drawPixel(4, 5, matrix->Color(255,255,0)); 
    matrix->drawPixel(3, 6, matrix->Color(255,255,0)); 
    matrix->drawPixel(2, 7, matrix->Color(255,255,0)); 
    matrix->drawPixel(1, 6, matrix->Color(0,0,255)); 
    matrix->drawPixel(0, 7, matrix->Color(0,0,255)); 
    matrix->drawPixel(6, 6, matrix->Color(0,0,255)); 
    matrix->drawPixel(5, 7, matrix->Color(0,0,255));
    matrix->show();
  } 
  if (weathercode==26|weathercode==27|weathercode==28|weathercode==29|weathercode==32|weathercode==33|weathercode==34|weathercode==35|weathercode==36)
  {
    //功能：风
    //matrix->clear();
    matrix->fillRect(2, 2, 3, 2,matrix->Color(255,255,255));
    matrix->drawFastHLine(0,0, 2, matrix->Color(255,255,255));
    matrix->drawFastHLine(1,1, 2, matrix->Color(255,255,255));
    matrix->drawFastHLine(4,1, 2, matrix->Color(255,255,255));
    matrix->drawFastHLine(5,0, 2, matrix->Color(255,255,255));
    matrix->drawFastHLine(4,4, 3, matrix->Color(255,255,255));
    matrix->drawPixel(6, 5, matrix->Color(255,255,255)); 
    matrix->drawFastVLine(1, 3, 2, matrix->Color(255,255,255)); 
    matrix->drawFastVLine(0, 4, 2, matrix->Color(255,255,255)); 
    matrix->drawFastVLine(3, 4, 4, matrix->Color(130,130,130)); 
    matrix->show();
  } 
  else
  {
    //未知天气
    //matrix->clear();
    matrix->drawFastHLine(4, 5, 3, matrix->Color(255,255,255));
    matrix->drawPixel(1, 1, matrix->Color(255,255,255)); 
    matrix->drawPixel(2, 2, matrix->Color(255,255,255)); 
    matrix->drawPixel(3, 3, matrix->Color(255,255,255)); 
    matrix->drawPixel(2, 4, matrix->Color(255,255,255)); 
    matrix->drawPixel(1, 5, matrix->Color(255,255,255)); 
    
  } 

  
}


