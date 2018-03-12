var vol = require('vol');
var x = 0;


var five = require("johnny-five"),
  board, photoresistor;

board = new five.Board();

board.on("ready", function() {

  // Create a new `photoresistor` hardware instance.
  photoresistor = new five.Sensor({
    pin: "A3",
    freq: 1000
  });

  photoresistor2 = new five.Sensor({
    pin: "A2",
    freq: 1000
  });

 

var led1 = new five.Led(2);
var led2 = new five.Led(3);
var led3 = new five.Led(4);
var led4 = new five.Led(5);
var led5 = new five.Led(6);

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
    if(this.value > 850){
        
      led2.on();
      
    }
    if(this.value > 880){
      
      led3.on();
    
  }

  if(this.value > 930){
      
    led4.on();
    x = 1;
    
}

if (this.value < 800 && x == 1){
  led3.off();
  led2.off();
  led4.off();
  led5.off();
  
}

if(x == 1){
led5.on();

}

    
});

photoresistor2.on("data", function() {
  console.log(this.value + " resistor2");

  if(this.value > 820){
    x = 2
  }

  if(x == 2){
    led2.on();
    led3.on();
    led4.on();
    led5.on();
    x=0;
  } 
  
});
  
});


function volume0(){
    vol.get().then(level => {
      console.log(level);
      //=> 0.45
    });
    
    vol.set(0).then(() => {
      console.log('Changed volume to 0%');
    });
    }

    function volume20(){
        vol.get().then(level => {
          console.log(level);
          //=> 0.45
        });
        
        vol.set(0.20).then(() => {
          console.log('Changed volume to 20%');
        });
        }

        function volume40(){
            vol.get().then(level => {
              console.log(level);
              //=> 0.45
            });
            
            vol.set(0.40).then(() => {
              console.log('Changed volume to 40%');
            });
            }

            
        function volume60(){
            vol.get().then(level => {
              console.log(level);
              //=> 0.45
            });
            
            vol.set(0.6).then(() => {
              console.log('Changed volume to 60%');
            });
            }

            function volume80(){
                vol.get().then(level => {
                  console.log(level);
                  //=> 0.45
                });
                
                vol.set(0.8).then(() => {
                  console.log('Changed volume to 80%');
                });
                }

                





