# Server installation
This server is built usin Node.js, which must be installed to run the server. To install Node.js please see the instructions best suited for your platform online: https://nodejs.org/en/download/
After the install you must run 'npm init' in the Server folder to initialise the server install.

# Database installation
To store data in the database a MySQL database must be installed, either locally or on a remote machine. Then an user must be created, which will be used to interface with the database. The script to create the required table is stored in this folder with the name createTable.sql

# Configuring parameters for the server.
To connect to the database the set parameters must be configured in the DB object in the Server.js file. A port for the HTTP server can also be specified under the serverPort variable.
