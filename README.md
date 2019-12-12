# LED-Light-Sculpture
This LED Light Sculputre was originally a little birthday gift I made for a friend, but turned into a little more...so I ended up building a number of them for various occasions :smile:


![Muli-Color Image of LED Sculpture](http://mclemens.mgserver.org/Images/IMG_1170.JPG)


## Getting Started

Due to the nature of this project, the code isn't necessarily transferrable to other domains unless you built an LED sculpture as well (and if you've built a similar project I would love to see what you created! :smile: )

## Built With

* [Arduino Nano] - The microcontroller used
* [WS2812B RGB 5050 LED Array] – LED array inside the sculpture
* [1/8" Cast Acrylic]
* [SPDT (Single Pole, Double Throw) Switch]
* [Momentary Push Button]
* [USB Micro Cable]
* [USB Wall Charger]

## Purchasing Options
Obviously you can browse the Internet for the best deals, but here's the list of items I used for this project:
+ [Arduino Nano](https://www.amazon.com/ELEGOO-Arduino-ATmega328P-Without-Compatible/dp/B0713XK923/ref=sr_1_1_sspa?keywords=arduino+nano&qid=1576016926&sr=8-1-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUFDR0YxUUJCSVc1NEwmZW5jcnlwdGVkSWQ9QTAzOTgwODdaWDlaUVcyNlo5MEUmZW5jcnlwdGVkQWRJZD1BMDY2OTI4OTE3WElKN1FTUlA2WlUmd2lkZ2V0TmFtZT1zcF9hdGYmYWN0aW9uPWNsaWNrUmVkaXJlY3QmZG9Ob3RMb2dDbGljaz10cnVl)
+ [LED array](https://www.amazon.com/gp/product/B01DC0IMRW/ref=ppx_yo_dt_b_asin_title_o09_s01?ie=UTF8&psc=1)
+ [1/8" Cast Acrylic](https://www.amazon.com/gp/product/B07JCGT6VZ/ref=ppx_yo_dt_b_asin_title_o04_s02?ie=UTF8&psc=1)
+ [SPDT Switch](https://www.amazon.com/gp/product/B01N7NCW8N/ref=ppx_yo_dt_b_asin_title_o02_s00?ie=UTF8&psc=1)
+ [Momentary Push Button](https://www.amazon.com/gp/product/B01E38OS7K/ref=ppx_yo_dt_b_asin_title_o09_s00?ie=UTF8&psc=1)
+ [USB Micro Cable](https://www.amazon.com/gp/product/B007NLUI1U/ref=ppx_yo_dt_b_asin_title_o09_s00?ie=UTF8&psc=1)
+ [USB Wall Charger](https://www.amazon.com/gp/product/B07C2QG8BB/ref=ppx_yo_dt_b_asin_title_o09_s01?ie=UTF8&psc=1)

## CAD Files

The necessary STL files are provided in the docs so you can print your own sculpture!  Feel free to modify it how you see fit :smile:

## AI Files

I have provided a template for the circular design that I wanted.  You will need this for cutting the arcylic with a laser cutter or CNC machine.

## Circuit Diagram

If you want to run the lightbox off a 9V battery, the circuit diagram is pictured below.

![Circuit Diagram from LED Sculpture](http://mclemens.mgserver.org/Images/light-box-sketch.png)

If you want to run the lightbox off AC wall power (what the materials listed above are for) then the circuit diagram changes just a bit.  Take the USB micro cable and solder the power (red) wire to the SPDT switch instead of the one coming from the 9V battery.  The ground wire from the micro USB should remain connected to the Arduino Nano. The green and white wires in the USB cord can be cut away...they aren't going to be used here.  You can use the Vin port of the Nano or just plug the other end of the USB micro cable into the USB port and connect the cables accordingly.

## Authors

* **Michael Clemens (mclemcrew)**

## Acknowledgements

S/O to [Sparkfun](https://www.sparkfun.com/news/2742) for their inspiration and providing a lot of templates/demo code for this project.  Honestly, I would bridge the gap between our two approaches and do whatever works best for you and your design.  Make it your own, that's what being a Maker is all about :smile:

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details
