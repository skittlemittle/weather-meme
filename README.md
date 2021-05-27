I made this thing to complain about how hot its been lately, summer sucks.

![diagram1](https://raw.githubusercontent.com/skittlemittle/weather-meme/main/graffics/diagram1.jpg)

It measures:

- temperature
- humidity
- wether it is raining or not (look outside a window lmaoaaaa)
- pressure (soon)

When you go close to it itll just show you a bunch of numbers or smth doesnt matter

If you stand at a distance, however, (> 40cm) and admire it, the display is filled
colors showing you the history(the past 64 days) of how much the weather sucked ass.

But what do the colors mea??????n!

color is calculated as RGB:

the color | what it do be meaning tho
----------|-----------
red       | heat (HORRENDOUS!!)
green     | le humidity
blue      | how long it was raining today innit (very cool)

## I made a plate of SPAGHET!

remember the old somebody toucha my spaghet meme? that was a good meme.

Change yo weather settings and such in `sense.hpp`

**saving**

Once it has been dark for 30 minutes itll save the color of the day to eeprom.

A pointer to the current days eeprom address is stored in the last eeprom addresses,
this pointer is a `uint8_t` so its at `EEPROM.length() - sizeof uint8_t`.

Each time a color is saved the address is incremented by one, and so itll just wrap around
the memory innit, the first thing to wear out will be the pointers address coz obviously.

**the colors**

If you wanna change what the colors mean because you disagree with me on what good
weather is just go and completely rewrite `calculateDayColor()` in `rating.cpp`

The color of the day is converted to hsv and a byte representing the hue is returned from
`calculateDayColor()` this way i can just walk around eeprom in simple increments of one.

**night detection**

I dont have an rtc module so I slapped on a light sensor which has a digital output
(its just an LDR with some chip and a tuning pot who cares, I dont).

This light sensor is checked every 5 minutes and its output is stored in an array,
once the array is full I check if the number of `darks` exceed the number of `brights`
and then save the days color if they do, else the array is reset.
