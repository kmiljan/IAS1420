// Base code for server to receive and store data to mysql database.

// Inclusin of Node.js libraries used by the server.
var http = require('http');
var mysql = require('mysql');

// JSON object for storage of database parameters, set these as required for your install.
const DB = {
    tableName: "esp32data6",
    host: "localhost",
    user: "esp32",
    password: "password",
    database: "data",
    port: 3306
}

// Variable for the port of the server to receive data from the ESP32.
serverPort = 8080;

// Database connection initialisation using parameters stored in DB object.
var database = mysql.createConnection({
  host: DB.host,
  user: DB.user,
  password: DB.password,
  database: DB.database,
  port: DB.port
});
database.connect(function(error) {
    if (error) throw error;
    console.log("Connected to database!");
});

// Creation of the server object to specify HTTP connection properties and handle received requests.
var server = http.createServer ( function(request,response){

    // Set HTTP header properties.
    response.writeHead(200,{"Content-Type":"text\plain"});

    // This server only supports POST requests, if another type of request is received, drop the connection and log to console.
    if(request.method == "POST")
        {
            response.end("Received POST request."); 

            // Store received data to the body variable.
            let body = '';
            request.on('data', chunk => {
                body += chunk.toString();
            });

            // Once all data is received end the connection, parse the data to JSON and insert the data into the specified database.
            request.on('end', () => {
                response.end('Ok');

                // Parse the data.
                let jsonObject = JSON.parse(body);

                // Define the sql query.
                let sql = "INSERT INTO " + DB.tableName + "(id, humidity, temperature, Requestedventpowerlevel, Humiditychange, Humiditybaseline, Temperaturechange, Temperaturebaseline, Outputenabled, StateID ) VALUES (" +
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
                
                // Run the sql query against the database.
                database.query(sql, function (error, result) {
                    if (error) throw error;
                    console.log("Data inserted successfully.");
                });

            });
        }
    else
        {
            response.end("Received " + request.method +" request. This type of HTTP request is not supported by this server.");
            console.log("Received " + request.method +" request. This type of HTTP request is not supported by this server.");
        }
});


// Starting of the configured server on specified port.
server.listen(serverPort);
console.log("Server running on port: " +serverPort);
