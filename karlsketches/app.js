"use strict";


var express = require('express');
var path = require('path');
var logger = require('morgan');
var cookieParser = require('cookie-parser');
var bodyParser = require('body-parser');
var expressWs = require('express-ws');
var vol = require('vol');
var ews = expressWs(express());
var app = ews.app;


function volumeLow(){
  vol.get().then(level => {
    console.log(level);
    //=> 0.45
  });
  
  vol.set(0.25).then(() => {
    console.log('Changed volume to 50%');
  });
  }


function volumeMedium(){
  vol.get().then(level => {
    console.log(level);
    //=> 0.45
  });
  
  vol.set(0.5).then(() => {
    console.log('Changed volume to 50%');
  });
  }

  function volumeHigh(){
    vol.get().then(level => {
      console.log(level);
      //=> 0.45
    });
    
    vol.set(0.75).then(() => {
      console.log('Changed volume to 75%');
    });
    }






  
    



app.ws('/ws', function (ws, req) {
  ws.on('message', function (msg) {
  

	



  if(msg =="lamp"){
    volumeMedium();
    }	
  
   
    
  

    

    var clients = ews.getWss('/ws').clients;
    // Debug print it

    console.log(new Date().toLocaleTimeString() + '> ' + msg);

    // Broadcast it to all other clients
    clients.forEach(c => {
      c.send(msg);
    });
  });
});

//var expressWs = require('express-ws')(app);
app.use(require('middleware-static-livereload')({
  documentRoot: 'public/'
}));

// uncomment after placing your favicon in /public
//app.use(favicon(path.join(__dirname, 'public', 'favicon.ico')));
app.use(logger('dev'));
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({
  extended: false
}));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

// catch 404 and forward to error handler
app.use(function (req, res, next) {
  var err = new Error('Not Found');
  err.status = 404;
  next(err);
});

// error handler
app.use(function (err, req, res, next) {
  if (err.status)
    res.sendStatus(err.status);
  else
    res.sendStatus(500);
});

let port = 5000;

app.listen(port);
console.log('Webserver started: http://localhost:' + port);
module.exports = app;



  
 