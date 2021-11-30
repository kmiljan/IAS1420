//Base code for server to receive and store data to mysql database
var http = require('http');
var mysql = require('mysql');

var database = mysql.createConnection({
  host: "localhost",
  user: "esp32",
  password: "password",
  database: "data"
});
database.connect(function(error) {
    if (error) throw error;
    console.log("Connected to database!");
    
});

var server = http.createServer ( function(request,response){

    response.writeHead(200,{"Content-Type":"text\plain"});
    if(request.method == "GET")
        {
            response.end("received GET request.")
        }
    else if(request.method == "POST")
        {
            response.end("received POST request."); 
            let body = '';
            request.on('data', chunk => {
                body += chunk.toString();
            });
            request.on('end', () => {
                response.end('ok');
                let jsonObject = JSON.parse(body);
                //console.log(jsonObject);

                var sql = "INSERT INTO esp32data6 (id, humidity, temperature, Requestedventpowerlevel, Humiditychange, Humiditybaseline, Temperaturechange, Temperaturebaseline, Outputenabled, StateID ) VALUES (" +
                0 +","+
                jsonObject.humidity +","+
                jsonObject.temperature +","+
                jsonObject.Requestedventpowerlevel +","+
                jsonObject.Humiditychange +","+
                jsonObject.Humiditybaseline +","+
                jsonObject.Temperaturechange +","+
                jsonObject.Temperaturebaseline +","+
                jsonObject.Outputenabled +",'"+
                jsonObject.StateID +"'"+
                ")";
                    database.query(sql, function (error, result) {
                      if (error) throw error;
                      //console.log("Data inserted");
                    });

            });
        }
    else
        {
            response.end("Undefined request.");
        }
});

server.listen(8080);
console.log("Server running on port 8080");