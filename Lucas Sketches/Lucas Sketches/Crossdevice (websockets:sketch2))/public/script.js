var lastMsgEl = null;
//the variable for the audiofile
var ljudfil = new Audio('https://cdn.glitch.com/4350b851-1049-46d1-b36a-4d6d70f18910%2F202242__luckylittleraven__cheerfulpiano.wav?1521472798963');

/*var ljudfil2 = new Audio('https://cdn.glitch.com/4350b851-1049-46d1-b36a-4d6d70f18910%2FOne%20tone.wav?1521554956572');*/

if (document.readyState != 'loading') onDocumentReady();
else document.addEventListener('DOMContentLoaded', onDocumentReady);

function handleCommand(d) {
   lastMsgEl.innerHTML =  `text: ${d.text} <br />int: ${d.integer} <br />float: ${d.float}`;
}

function onDocumentReady() {
    var socket = new ReconnectingWebsocket("ws://" + location.host + "/serial");
    var sendFormEl = document.getElementById('sendForm');
    var lastMsg = null;
    lastMsgEl = document.getElementById('lastMsg');
    socket.onmessage = function(evt) {
        // Debug: see raw received message
        //console.log(evt.data);
        
        // Parse message, assuming <Text,Int,Float>
        var d = evt.data.trim();
        if (d.charAt(0) == '<' && d.charAt(d.length-1) == '>') {
            // Looks legit
            d = d.split(',');    
            if (d.length == 3) { // Yes, it has three components as we hoped
                handleCommand({
                    text:d[0].substr(1), 
                    integer: parseInt(d[1]), 
                    float: parseFloat(d[2].substr(0,d.length-1))
                });
                return;          
            }
        }
        
        // Doesn't seem to be formatted correctly, just display as-is
        if (evt.data != lastMsg) {
            lastMsgEl.innerText =  evt.data;
            lastMsg = evt.data;
        }
        
      // depending on distance, showing the playbutton by changing the opacity.
            if (evt.data < 40 ){
                document.getElementById("playBtn").style.opacity = "1.0";
        } else { evt.data > 50;
            document.getElementById("playBtn").style.opacity = "0.0";
          }

      
        // Managing the background color by distance, just to see if it works really.
          /*if (evt.data < 40 ){
            
            document.body.style.backgroundColor = 'red';
          } else { evt.data > 45;
            document.body.style.backgroundColor = 'white';
          }*/
    }
    socket.onopen = function(evt) {
        console.log("Socket opened");
    }

    sendFormEl.addEventListener('submit', function(evt) {
        evt.preventDefault();
        var send = document.getElementById('sendtoSerial').value;
        socket.send(send);  
    })
    }

    /*if (evt.data < 40 ){
        ljudfil2.play();
    }*/

//this function plays the audiofile attached to the "ljudfil" variable.
    function buttonClick() {
        ljudfil.play();
      }