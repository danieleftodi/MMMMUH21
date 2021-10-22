#Awesome adventures 🐈😸💩🤠🐾🐁
**of Stig, Cindy, Sebastian, Ulf & Jerry**  🐈

#About

There are a lot of adventure and first person shoot-em and violent games in the world.

So I decided to make this "Awesome adventures" text based game, with a twist.
 
**Don't fall into the trap! ... of violence and killing**

That is how this game started to take shape.


#Abstract

The plot of the game is that you are a newborn kitten that is starting to become aware of yourself, from the stage of:

> *Ohh, loooook - I have diz! What are thoze? Hoz diz workz?!*<p>
> *Ohh, I calz diz: Pawzs!*<p>
> **[Tries-Paws-for-the-1st-time]** <p>
> *Mozstly unzstablezs.* <p>
> **[FALLS-DOWN]** <p>
> *... Buzs I canzs makzs workzs!*

What you do next will be up to your imagination and creativity.


#Etymology

Having played a lot of games, I would say the main inspiration to this games is a cross product of: <p>

* [LucasArts: Monkey Island (series)](https://en.wikipedia.org/wiki/Monkey_Island_(series))
* [LucasArts: Full Throttle](https://www.doublefine.com/games/full-throttle-remastered)
* [Tamagotchi](https://tamagotchi.com)
* [The Elder Scrolls: Skyrim](https://elderscrolls.bethesda.net/skyrim)
* [Skyrim: Very Special Edition](https://www.youtube.com/watch?v=FnEW6dX_BmU)


#Definitions

* Exploration &emsp;&emsp;&emsp; => Places
* Fight &emsp;&emsp;&emsp; => Activities
* Enemy &emsp;&emsp;&emsp; => Frenemies
* Health &emsp;&emsp;&emsp; => Food
* Potion &emsp;&emsp;&emsp; => Water
* Candy &emsp;&emsp;&emsp; => Milk
 

#Structure

**Characters** <br>
* Stig <br>
* Cindy <br>
* Sebastian <br>
* Ulf <br>
* Jerry <br>

**Activities** <br>
* Scratch <br>
* Sniff <br>
* Stretch <br>
* Knead 🐾🐈 <br>
* Hiss <br>
* Sit <br>
* Poop <br>
* Pee <br>
* Purr <br>
* Sleep <br>
* Eat <br>
* Walk <br>
* Run <br>
* Jump <br>
* Climb <p>

**Places** <br>
* neighbours <br>
* closet <br>
* backyard <br>
* Window sill <br>
* Cardboard box <br>
* Masters shoes <br> 
* Cat tree <br>
* Sofa <br>
* Bed <br>
* Litter box <p>

**Frenemies** <br>
* Masters (Mom & Dad)&emsp;&emsp;&emsp;// Friend! <br>
* Children &emsp;&emsp;&emsp;// Enemy || Friend  <br>
* Masters Friend: Erik &emsp;&emsp;&emsp;// ENEMY!!! 😹🐈 <br>
* Other cats &emsp;&emsp;&emsp;// Enemy || Friend <br>
* Adults &emsp;&emsp;&emsp;// Friend <br>
* Dogs &emsp;&emsp;&emsp;// Enemy <br>
* Birds &emsp;&emsp;&emsp;// Enemy <p>

#File structure

Most of the code files (.cpp & .h) are placeholders for future development. But it make it easer to 1st begin to design a structure of  what to code and later populate said space.<p>

**NOTE: this is just a quick overview of the structure, for accurate information, please navigate the file structure and explore the code ...** <p>

| <br>
|--\_BUILD &emsp;&emsp;&emsp;// Build folder for Xcode, where a macOS binary is compiled<br>
|--11_Awesome_adventures_main.cpp&emsp;&emsp;&emsp;// Where the game code begins<br>
|--11_Awesome_adventures.xcodeproj&emsp;&emsp;&emsp;// Xcode project file <br>
| <br>
|-->activities <br>
&emsp;&emsp;&emsp;|-- activity\_climb.cpp <br>
&emsp;&emsp;&emsp;|-- activity\_eat.cpp <br>
&emsp;&emsp;&emsp;|-- activity\_hiss.cpp <br>
&emsp;&emsp;&emsp;|-- activity\_jump.cpp <br>
&emsp;&emsp;&emsp;|-- activity\_knead.cpp <br>
&emsp;&emsp;&emsp;|-- activity\_pee.cpp <br>
&emsp;&emsp;&emsp;|-- activity\_play.cpp &emsp;&emsp;&emsp;// 1st game ability<br>
&emsp;&emsp;&emsp;|-- activity\_poop.cpp <br>
&emsp;&emsp;&emsp;|-- activity\_purr.cpp <br>
&emsp;&emsp;&emsp;|-- activity\_run.cpp <br>
&emsp;&emsp;&emsp;|-- activity\_scratch.cpp <br>
&emsp;&emsp;&emsp;|-- activity\_sit.cpp <br>
&emsp;&emsp;&emsp;|-- activity\_sleep.cpp <br>
&emsp;&emsp;&emsp;|-- activity\_sniff.cpp <br>
&emsp;&emsp;&emsp;|-- activity\_stretch.cpp <br>
&emsp;&emsp;&emsp;|-- activity\_walk.cpp <br>
&emsp;&emsp;&emsp;|-- <br>
| <br>
|-->characters <br>
&emsp;&emsp;&emsp;|-- character\_cindy.cpp<br>
&emsp;&emsp;&emsp;|-- character\_jerry.cpp<br>
&emsp;&emsp;&emsp;|-- character\_sebastian.cpp<br>
&emsp;&emsp;&emsp;|-- character\_stig.cpp &emsp;&emsp;&emsp;// 1st game character<br>
&emsp;&emsp;&emsp;|-- character\_ulf.cpp<br>
| <br>
|-->common <br>
&emsp;&emsp;&emsp;|-- common.cpp&emsp;&emsp;&emsp;// Place everything that is Global and in-common <br>
&emsp;&emsp;&emsp;|-- main.h &emsp;&emsp;&emsp;// Where the game code begins <br>
&emsp;&emsp;&emsp;|-- snippets.h &emsp;&emsp;&emsp;// snippets trash bin - **won't get compiled!**<br>
&emsp;&emsp;&emsp;|-- template.cpp &emsp;&emsp;&emsp;// common template for .cpp file<br>
&emsp;&emsp;&emsp;|-- template.h &emsp;&emsp;&emsp;// common template for .h file<br>
| <br>
|-->menus <br>
&emsp;&emsp;&emsp;|-- main\_menu.cpp &emsp;&emsp;&emsp;// Just the main menu code<br>
&emsp;&emsp;&emsp;|-- menu\_activity\_climb.cpp <br>
&emsp;&emsp;&emsp;|-- menu\_activity\_eat.cpp <br>
&emsp;&emsp;&emsp;|-- menu\_activity\_hiss.cpp <br>
&emsp;&emsp;&emsp;|-- menu\_activity\_jump.cpp <br>
&emsp;&emsp;&emsp;|-- menu\_activity\_knead.cpp <br>
&emsp;&emsp;&emsp;|-- menu\_activity\_pee.cpp <br>
&emsp;&emsp;&emsp;|-- menu\_activity\_play.cpp <br>
&emsp;&emsp;&emsp;|-- menu\_activity\_poop.cpp <br>
&emsp;&emsp;&emsp;|-- menu\_activity\_purr.cpp <br>
&emsp;&emsp;&emsp;|-- menu\_activity\_run.cpp <br>
&emsp;&emsp;&emsp;|-- menu\_activity\_scratch.cpp <br>
&emsp;&emsp;&emsp;|-- menu\_activity\_sit.cpp <br>
&emsp;&emsp;&emsp;|-- menu\_activity\_sleep.cpp <br>
&emsp;&emsp;&emsp;|-- menu\_activity\_sniff.cpp <br>
&emsp;&emsp;&emsp;|-- menu\_activity\_stretch.cpp <br>
&emsp;&emsp;&emsp;|-- menu\_activity\_walk.cpp <br>
&emsp;&emsp;&emsp;|-- menu\_place\_backyard.cpp <br>
&emsp;&emsp;&emsp;|-- menu\_place\_bed.cpp <br>
&emsp;&emsp;&emsp;|-- menu\_place\_cardboard\_box.cpp <br>
&emsp;&emsp;&emsp;|-- menu\_place\_cat\_tree.cpp <br>
&emsp;&emsp;&emsp;|-- menu\_place\_closet.cpp <br>
&emsp;&emsp;&emsp;|-- menu\_place\_litter_box.cpp <br>
&emsp;&emsp;&emsp;|-- menu\_place\_masters\_shoes.cpp <br>
&emsp;&emsp;&emsp;|-- menu\_place\_neighbours.cpp<br>
&emsp;&emsp;&emsp;|-- menu\_place\_sofa.cpp<br>
&emsp;&emsp;&emsp;|-- menu\_place\_window\_sill.cpp<br>
&emsp;&emsp;&emsp;|-- <br>
| <br>
|-->places <br>
&emsp;&emsp;&emsp;|-- place\_backyard.cpp <br>
&emsp;&emsp;&emsp;|-- place\_bed.cpp <br>
&emsp;&emsp;&emsp;|-- place\_cardboard\_box.cpp <br>
&emsp;&emsp;&emsp;|-- place\_cat\_tree.cpp <br>
&emsp;&emsp;&emsp;|-- place\_closet.cpp <br>
&emsp;&emsp;&emsp;|-- place\_litter\_box.cpp <br>
&emsp;&emsp;&emsp;|-- place\_masters\_shoes.cpp <br>
&emsp;&emsp;&emsp;|-- place\_neighbours.cpp <br>
&emsp;&emsp;&emsp;|-- place\_sofa.cpp <br>
&emsp;&emsp;&emsp;|-- place\_window\_sill.cpp <br>
&emsp;&emsp;&emsp;|-- <br>


#