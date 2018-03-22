var five = require("johnny-five"),
  board, photoresistor;

board = new five.Board();

board.on("ready", function() {

  // Create a new `photoresistor` hardware instance.
  photoresistor = new five.Sensor({
    pin: "A0",
    freq: 1000
  });

var led1 = new five.Led(7);
var led2 = new five.Led(8);
var led3 = new five.Led(9);
var led4 = new five.Led(10);
var led5 = new five.Led(11);

//leaves led1 on at all times
led1.on();

  // Inject the `sensor` hardware into
  // the Repl instance's context;
  // allows direct command line access
  board.repl.inject({
    pot: photoresistor, photoresistor2

  });

 // "data" get the current reading from the photoresistor
  photoresistor.on("data", function() {
    console.log(this.value + " resistor 1");

    //turns led2 on if value of photoresistor is over 850
    if(this.value > 850){
      led2.on(); 
    }

    //turns led3 on if value of photoresistor is over 880
    if(this.value > 880){  
      led3.on();  
  }

//turns led4 on if value of photoresistor is over 930
  if(this.value > 930){
    led4.on();
}

//turns led5 on if value of photoresistor is over 950
if(this.value > 950){
led5.on();
}

if (this.value < 800){
  led3.off();
  led2.off();
  led4.off();
  led5.off();
  
}
  
});
  
});



                

                





