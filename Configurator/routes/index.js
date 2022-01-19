var express = require('express');
var router = express.Router();
var service = require('../controllers/service');
var path = require("path");
var app = express();
/* GET home page. */
router.get('/', function(req, res, next) {
  res.render('index', { title: 'Express' });
});

// fetch the cal page.
router.get('/cal', function(req, res, next) {
  res.sendFile(path.join(app.get('views') + '/cal.html'));
});

//set(send) in keypoints from PI>
router.post('/setkeypoints', function(req, res, next) {

  service.storeData(req.body);  //store . and poll
  //console.log(JSON.stringify(req.body))  //for debug
  res.status(200).send("thankyou ")
});

// fetch the cal page.
router.get('/getcaldata', function(req, res, next) {
  res.status(200).send(JSON.stringify(service.getCalData()));
});

router.get('/getconfig', function(req, res, next) {
  res.status(200).send(JSON.stringify(service.getConfig()));
});

router.post('/setconfig', function(req, res, next) {
  service.setConfig(req.body);  //store .
  res.status(200).send(JSON.stringify(service.getConfig())); // return updated config
});
module.exports = router;
