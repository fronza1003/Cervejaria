var express = require('express');
var router = express.Router();

router.post('/init', function(req, res, next) {
  var temp = req.body.temp;
  var time = req.body.time;
  var port = req.app.settings.porta;
  port.write('i-'+ temp + '-' + time + '/n');
  var temp = 0;
  var parser = req.app.settings.parser;
  var ler = (message) => { //Lê os dados
    temp = message;
    res.send(temp);
    parser.removeListener('data', ler);
  }

  parser.on('data', ler);
});

router.post('/cancel', function(req, res, next) {
  var port = req.app.settings.porta;
  port.write('c/n');
  res.send('ok');
});

router.get('/getInfo', function(req, res, next) {
  var temp = 0;
  var parser = req.app.settings.parser;
  var ler = (message) => { //Lê os dados
    temp = message;
    res.send(temp);
    parser.removeListener('data', ler);
  }

  parser.on('data', ler);
});

module.exports = router;
