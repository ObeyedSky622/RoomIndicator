# RoomIndicator
This was a short project designed to let people know if it is okay to come into my room during the work day. 

There were many similar projects which inspired this one. There was one that used a harddrive magnet, and another that used a big LED tower. This project is a smaller one and uses the IoT environment called Blynk. This application can be controlled from inside the room to let people on the outside know when to walk in, when to knock, and when I cannot be disturbed. This is a simple project that uses a Sprkfun ESP32 Thing Dev module, an arduino UNO, and 3 NeoPixel rings to indicate the room status. 

IMPLEMENTATION:
  I used 3 different neopixel objects so that it is easier to keep track of the indices of the pixels. If I used one long chain of 44 pixels, then in the for loops I would have much more complicated boundaries. Therefore, I thought it best to use three different objects. Basically, I feed the output pins from the ESP32 board into an UNO and then use the UNO to drive the LED rings, I did this because I am not too familiar with blynk sketches but when I tried adding beneath the blynk.run() command, the controller did not like that and it did not perform well.
