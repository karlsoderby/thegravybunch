
if (document.readyState != 'loading') onDocumentReady();
else document.addEventListener('DOMContentLoaded', onDocumentReady);

//Receives a number from the Arduino. In this example a "0" or a "1"
function onDocumentReady() {
    var socket = new ReconnectingWebsocket("ws://" + location.host + "/serial");
    socket.onmessage = function(evt) {
        // Debug: see raw received message
        //console.log(evt.data);

        console.log(evt.data);

         //If photoresistor 1 is triggered from the Arduino, it sends the number "1"
          //The "1" then changes the background to orange and the text to off
        if (evt.data == 1 ) {
           document.body.style.backgroundColor = 'green';
           document.getElementById("svinet").innerHTML = "ON";
           document.getElementById("knapparna").style.color = "white";
           snd.play();
          } 
         
          //If photoresistor 2 is triggered from the Arduino, it sends the number "0"
          //The "0" then changes the background to orange and the text to off

             if(evt.data == 0 ){
                document.body.style.backgroundColor ='orange';
                document.getElementById("svinet").innerHTML = "OFF";
                document.getElementById("knapparna").style.color = "orange";
                snd2.play();
             }  
    };
}

var snd = new Audio("onsound.wav");
var snd2 = new Audio("offsound.wav");

/*
Timer();
function Timer() {
setTimeout(function () {
document.body.style.backgroundColor = 'white';
}, 10000)

}*/