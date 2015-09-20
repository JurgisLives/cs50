/**
 * graph.pde
 *
 * Fletcher Harrinton and Yero Rudzinskas 
 * 
 *
 * Read temperature and humidity values from emu serial data sent from arduino to usb and write these values to both a realtime monitor graph and a log file
 *
 * expanded greatly from bare bones based on http://www.arduino.cc/en/Tutorial/Graph
 * focus on graph window and press any key to exit with proper log file write
 * 
 */


import processing.serial.*;

Serial myPort;        // The serial port
int TxPos = 1;         // horizontal position of the graph temp
int HxPos = 1;         // horizontal position of the graph humidity

int sizeX = 600;        // horiz dimension of window
int sizeY = 300;       // vert dimension of window

//int TyPos = 1;         // vert position of the graph temp
//int HyPos = 1;         // vert position of the graph humidity

PrintWriter output;    // create instance of file output for log file


void setup () {
     // set the window size:

     size(sizeX, sizeY);        
     
     // List all the available serial ports
     println(Serial.list());
     // I know that the first port in the serial list on my mac
     // is always my  Arduino, so I open Serial.list()[0].
     // Open whatever port is the one you're using.
     myPort = new Serial(this, Serial.list()[0], 9600);
     // don't generate a serialEvent() unless you get a newline character:
     myPort.bufferUntil('\n');
     // set inital background:
     background(0);
     
     //set output logfile
     output = createWriter( "templog.txt" );
     
}
 
void draw () {
  
  
    if (myPort.available() > 0 ) {
         String data = myPort.readString();
         if ( data != null && data.length() >= 2) {
              output.println( data );
         }
    }
       
  
  //create legend for graph  
  PFont f;
  f = createFont("Arial",16,true); // Arial, 16 point, anti-aliasing on
  textFont(f,16);
  
  stroke(255,34,0);
  fill(255,255,255);
  text("Temperature",10,20);
  fill(255,34,0);
  rect(108,10,10,10);
  
  
  fill(255,255,255);
  text("Humidity",10,40);  
  fill(27,134,200);
  stroke(27,134,200);
  rect(80,30,10,10);   
  
  //draw a dotted baseline
  int add = 0;
  while(add < sizeX)
  {
    stroke(100,100,100);
    line(add +3,200,add+5,200);
    
    add += 5;
  }
  
  
}

 void keyPressed() 
{
    output.flush();  // Writes the remaining data to the file
    output.close();  // Finishes the file
    exit();  // Stops the program
}
  

void serialEvent (Serial myPort) {
  
//-----------------------------------------------------------------------Temp data
  
 // get the ASCII string
 String inString = myPort.readStringUntil('\n');
 
 // check for null serial data
 if (inString != null) {
    
   // if string contains T for temp
     if (inString.contains("T"))
     {
         println("Temp");
         inString = inString.replaceAll("\\D+","");
         
         println(inString);
         println();

         // trim off any whitespace:
         //inString = trim(inString);
         
         if(inString.length()>=2)
         {
         // convert to an int and map to the screen height:
         float inByte = float(inString); 
         inByte = map(inByte, 0, 255, 0, height);  

         // draw the line:
         stroke(255,34,0);
         fill(255,34,0);
         ellipse(TxPos, (height - inByte), 2, 2);
         }
         
            // at the edge of the screen, go back to the beginning
             if (TxPos >= width) {
                 TxPos = 0;
                 background(0);
             } 
             else {
             // increment the horizontal position and save previous positions to connect dots

                TxPos++;
             }
         }
     


//-----------------------------------------------------------------------------------Humid data
    

 // else if string contains H for humid  
     else if (inString.contains("H"))
     {
        println("Humid");
        inString = inString.replaceAll("\\D+","");
        println(inString);

         // trim off any whitespace:
         //inString = trim(inString);
         
         if(inString.length()>=2)
         {
         // convert to an int and map to the screen height:
         float inByte = float(inString); 
         inByte = map(inByte, 0, 255, 0, height);  
         
         
         // draw the line:
         stroke(27,134,200);
         //line(HxPos, height  - inByte -1, HxPos, height - inByte);
         fill(27,134,200);
         ellipse(HxPos, (height - inByte), 2, 2);
         //line(HxPosOld, HyPosOld, HxPos, HyPos);
         }
        // at the edge of the screen, go back to the beginning:
         if (HxPos >= width) {
             HxPos = 0;
             background(0);
         }
         else {
         // increment the horizontal position:
            HxPos++;
         }
     }
 }
}
