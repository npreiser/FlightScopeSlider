const fs = require('fs');




var latestdatabucket = [{ "x" : "200", "y" : "200", "size": "300" },{ "x" : "200", "y" : "666", "size": "300" } ]
var currentconfig = {};

var py = undefined;

var service = module.exports = {

    init: function()
    {
        let rawdata = fs.readFileSync('../config.json');
        currentconfig = JSON.parse(rawdata);
    },
    runchildproc: function()
    {
       // added test comment
        console.log("python path: " + process.env.SCOPE_PYTHON_PATH);
        console.log("script path: " + process.env.SCOPE_PYTHON_SCRIPT);
        var spawn = require('child_process').spawn

       
       // py = spawn('/home/pi/.virtualenvs/cv/bin/python', ['/home/pi/A_localGit/FlightScopeEyeball/golf_blob.py'],)
        py = spawn( process.env.SCOPE_PYTHON_PATH, [process.env.SCOPE_PYTHON_SCRIPT],)

        
        py.stdout.on('data', function(data) {
            console.log('stdout: ' + data);
        });
        py.stderr.on('data', function(data){
            console.log('stderr:'+data);
        });
        
        py.stdin.on('data', function(data){
            console.log('stdin:'+data);
        });
        console.log("Started python process");

    },
     storeData: function(data)
     {
         latestdatabucket = data;
     },
     getCalData: function()
     {
         return latestdatabucket;
     },
     getConfig: function()
     {
         return currentconfig;
     },
     setConfig: function(data)
     {
         let stdata = JSON.stringify(data, null, 4);
         fs.writeFileSync('../config.json', stdata);
         currentconfig = data;

        // py.stdin.write("boooger message");
        //console.log("sent python proc a message")
         return currentconfig;
     }
}