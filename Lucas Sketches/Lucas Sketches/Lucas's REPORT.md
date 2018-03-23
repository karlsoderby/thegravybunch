#Lucas README

Lucas's report for P2:

I really do feel like i learned a lot more about programming during this joint projcet between the the P2 and PP courses and as far as using programming as a tool in order to convey the "feelings" you want out of your prototype i give it an A+. However i think everyone is on board with the notion that programming can be entirely and utterly annoying sometimes when you cant get things to work the way you want them to and/or they should, this can make you lose hope very fast but i've found that as soon as you sort of pass that bump in the road you come away from the experiance with newly gained knowledge and with new excitement.

As for the programming in this final project i have two sketches, one early drafted and one more developed. The first one can be found in the arduino folder and in it you can see how the Range Finder was used in order to measure distance from the prototype that i was working on. this took a lot of time to wrap my head around. 

the first problem with the rangefinder was that i tried googling tutorials but at first i had a hard time trying to find examples for the sort of thing i was trying to do in my project. i wanted to control LED's depending on the distance from the Range finder. All i could find on the subject used a different type of range finder that only had three pins whilst the one i am using (HCSR-04) has four pins.

However this is a group project so we all helped out in developing eachothers codes and we figured out how to write the code so the LED's light up based on distance.

This for instance means that whenever nothing is closer the "70" from the Range finder the RGB-Led shines orange

if(distance>=70){  
 setColor(100, 0, 100 );  // fade
  delay(100);
}

And the means that whenever something between 60-50 it shines in a different shade of orange

if (distance<60 && distance>=50){
  setColor(200, 0, 200);  // fade
  delay(100);
  }

  and for the second LED (The blue one) This if statement is what makes it turn on whenever you are close
  and turn off when nothings near a certain point using the same principes as above only adding the "else" element in it.

  if (distance<30 && distance>=0){
    digitalWrite(BLUELED, HIGH); 
    //delay (2000);
    
    } else {
      digitalWrite(BLUELED, LOW);
      }


This part was extremely crucial for what i wanted to convey to the user in regards of interactivity, because it give you a response as you are approaching the object and it tells you that something is happening.

As for the crossdevice challange we decided to use the Serial-bridge from the Clints repository as a starting point. After i managed to combine the code with the arduino code from the Serial-bridge folder the fun part was making the prototype have an effect on the localhost:4000 site. I did this by adding a clickable picture in the Index.HTML doc 

<!-- <img id="playBtn" src="https://image.freepik.com/free-icon/play-button_318-42541.jpg" onclick="buttonClick()"> -->

And in the Script.js doc i added an if statement that changed that picture opacity from 0 to 1 when the Range finder was approached (the picture is a playbutton) this is how the if statement was written.

    if (evt.data < 40 ){
                document.getElementById("playBtn").style.opacity = "1.0";
        } else { evt.data > 50;
            document.getElementById("playBtn").style.opacity = "0.0";
          }


On top of all this just to further convey the purpose of the prototype a pianosound played once the image was clicked and here's how to code for that looked.

var ljudfil = new Audio('https://cdn.glitch.com/4350b851-1049-46d1-b36a-4d6d70f18910%2F202242__luckylittleraven__cheerfulpiano.wav?1521472798963');

function buttonClick() {
        ljudfil.play();
      }

As for the main part of this report which is (if i understood it correctly) to talk about the pros and cons of using programming whilst prototyping then i definitley like it as tool. Programming has the great advantage in that it makes your prototype run by itself which means that you can user test whilst not being the room for instance which sometimes can be important for the prototype's purpose aswell as not affecting the user tester by your presence and accidentally "leading" the user tester.

Further, programming helps you control electronics and make your prototype cross device which makes it almost elementary in later stages of prototyping. 

As for cons i have to say that it is very complicated and sometimes that can be bad because it can turn out to be very time consuming and it's easy to get stuck in a hamster wheel of thinking that this has to be done with code. Especially in this course since that's a requirment, but i think it's also important to think outside the box and sometimes reflect on whether or not code is actully needed in order to prototype the experience you want to convey. 