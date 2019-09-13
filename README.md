# Digital Timer
 
Include your responses to the bold questions below. Include snippets of code that explain what you did. Deliverables are due next Tuesday. Post your lab reports as README.md pages on your GitHub, and post a link to that on your main class hub page.

## Part A. Solder your LCD panel

Image of header pins soldered into LCD display.
![](Images/20190912_103815.jpg)


Image of LCD on breadboard working.
![](Images/20190912_103917.jpg)

## Part B. Writing to the LCD

Image of LCD on breadboard working.
![](Images/20190912_103917.jpg)
 
**a. What voltage level do you need to power your display?**

The display is powered by 5V

**b. What voltage level do you need to power the display backlight?**

The backlight is powered by 3.3V
   
**c. What was one mistake you made when wiring up the display? How did you fix it?**

I accidently conected DB4 to IO6. Then when I switched DB4 to IO5 and then the LCD display worked perfectly.

**d. What line of code do you need to change to make it flash your name instead of "Hello World"?**

Changed ```lcd.print("hello, world!");``` to ```lcd.print("FJ Fourie");```

Image of LCD display displaying  name and surname.
![](Images/20190912_104123.jpg)
 
**e. Include a copy of your Lowly Multimeter code in your lab write-up.**


## Part C. Using a time-based digital sensor

**Upload a video of your working rotary encoder here.**


## Part D. Make your Arduino sing!

**a. How would you change the code to make the song play twice as fast?**
 
**b. What song is playing?**


## Part E. Make your own timer

**a. Make a short video showing how your timer works, and what happens when time is up!**

**b. Post a link to the completed lab report your class hub GitHub repo.**
