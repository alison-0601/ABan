import processing.serial.*;
import oscP5.*;
import netP5.*;

Serial mySerial;

String myString = null;
int nl = 10;
int inpute;

PImage[] webImg;
PImage img;
PImage pngImg;
PImage upImg;

String s;
String r;
int num;
int num1;
String[] url;
String[] url1;
float lasttimecheck;
float timeinterval;

float x;
float y;

OscP5 oscP5;
NetAddress myRemoteLocation;

void setup()
{
  //fullScreen();
  oscP5 = new OscP5(this,1234);
   myRemoteLocation = new NetAddress("127.0.0.1",5555);
  
  String myPort = Serial.list()[2];
  mySerial = new Serial(this, myPort, 9600);
  
  url = loadStrings("list.txt");
//println(url[0]);
  size(1080,720);
  url1 = loadStrings("pnglist.txt");
  
  lasttimecheck = millis();
  timeinterval = 3000;
  
  //url1 = "https://66.media.tumblr.com/db9201a712694192f129d6f8f1b0d326/tumblr_praug0yxVe1xr6esmo1_1280.png";
  //pngImg = loadImage(url1, "png");
  
  
}

void strokechange()
{
 if(millis() >  lasttimecheck + timeinterval)
 {
   lasttimecheck = millis();
   num = int(random(0,7));
   num1 = int(random(0,12));
   x = random(400,400);
   y = random(150,300);
 }
}

void draw(){
  strokechange();
  
  s = url[num];
  r = url1[num1];
//println(num);
  imageMode(CORNERS);
  img = loadImage(s, "jpg");
  upImg = loadImage(r, "png");
  
  //imageMode(CENTER);
  image(img,0,0,1920,1080);
  
   while(mySerial.available()>0)
  {
    myString = mySerial.readStringUntil(nl);
    
    if(myString!=null)
    {
     // println(myString);
      
      String[] splitData = splitTokens(myString, ",");
        
          if(splitData[0].equals("on"))
          {
            //println("1");
            OscMessage myMessage = new OscMessage("/test");
            myMessage.add(0);
            oscP5.send(myMessage, myRemoteLocation); 
            //delay(200);
            imageMode(CENTER);
            image(upImg,x,y,upImg.width*2,upImg.height*2);
}else
{
  OscMessage myMessage = new OscMessage("/test");
            myMessage.add(1);
            oscP5.send(myMessage, myRemoteLocation); 
            //delay(200);
}
    }
  }
}
